

## Protocal
A defined set of standards that computers must follow in order to communicate properly.

## Computer Networking 
The name we're given to the full scope of how computers communicate with each other.

## Network Layers Summary

| # | Layer name   | Protocol (examples)                 | Protocol Data Unit (PDU)            | Addressing (typical)                      |
|:--:|:-------------|:------------------------------------|:------------------------------------|:------------------------------------------|
| 7  | Application  | HTTP, FTP, SMTP, DNS                | Data                                | Application identifiers (URLs, email)     |
| 6  | Presentation | TLS/SSL, MIME                       | Data                                | N/A (handled at application level)        |
| 5  | Session      | NetBIOS, RPC, PPTP                  | Data                                | Session IDs / sockets                     |
| 4  | Transport    | TCP, UDP, SCTP                      | Segment (TCP) / Datagram (UDP)     | Port numbers (endpoints)                  |
| 3  | Network      | IP (IPv4/IPv6), ICMP                | Packet                              | IP addresses                              |
| 2  | Data Link    | Ethernet, PPP, ARP                  | Frame                               | MAC addresses (physical/Link-layer)       |
| 1  | Physical     | Ethernet PHY, DSL, RS-232 (examples)| Bits                                | Physical medium / electrical signals      |