

## Protocal
A defined set of standards that computers must follow in order to communicate properly.

## Computer Networking 
The name we're given to the full scope of how computers communicate with each other.

## OSI Model (Open Systems Interconnection (OSI))

| # | Layer name   | Protocol (examples)                 | Protocol Data Unit (PDU)            | Addressing (typical)                      |
|:--:|:-------------|:------------------------------------|:------------------------------------|:------------------------------------------|
| 7  | Application  | HTTP, FTP, SMTP, DNS                | Data                                | Application identifiers (URLs, email)     |
| 6  | Presentation | TLS/SSL, MIME                       | Data                                | N/A (handled at application level)        |
| 5  | Session      | NetBIOS, RPC, PPTP                  | Data                                | Session IDs / sockets                     |
| 4  | Transport    | TCP, UDP, SCTP                      | Segment (TCP) / Datagram (UDP)     | Port numbers (endpoints)                  |
| 3  | Network      | IP (IPv4/IPv6), ICMP                | Packet                              | IP addresses                              |
| 2  | Data Link    | Ethernet, PPP, ARP                  | Frame                               | MAC addresses (physical/Link-layer)       |
| 1  | Physical     | Ethernet PHY, DSL, RS-232 (examples)| Bits                                | Physical medium / electrical signals      |

The OSI model defines a hierarchical architecture that logically partitions the functions required to support system-to-system communication.

## TCP Model

| # | Layer name   | Protocol (examples)                 | Protocol Data Unit (PDU)            | Addressing (typical)                      |
|:--:|:-------------|:------------------------------------|:------------------------------------|:------------------------------------------|
| 5  | Application  | HTTP, FTP, SMTP, DNS                | Messages                               | Application identifiers (URLs, email)     |
| 4  | Transport    | TCP, UDP, SCTP                      | Segment (TCP) / Datagram (UDP)     | Port numbers (endpoints)                  |
| 3  | Network      | IP (IPv4/IPv6), ICMP                | Packet / Datagram                             | IP addresses                              |
| 2  | Data Link    | Ethernet, PPP, ARP                  | Frame                               | MAC addresses (physical/Link-layer)       |
| 1  | Physical     | Ethernet PHY, DSL, RS-232 (examples)| Bits                                | Physical medium / electrical signals      |


### Physical Layer:-
Represents the physical devices that interconnect computers.

### Data Link Layer (Network interface / network access):-
Responsible for defining a common way to interpreting these signals so network devices can communicate.

-> The <b>Ethernet </b> standards also define a protocol responsible for getting data to nodes on the same network or link.

### Network layer:-
Allows different networks to communicate with each other through devices known as routers.

## Internetwork
A collection of networks connected together through routers , the most famous of these being the internet.

The physical layer deals with physical devices like cables and connectors.

IP (Internet protocol) is the heart of the internet and most smaller network around the world.

### Transport layer:-
Sorts out which client and server programs are supposed to get that data.
Sends data to the right appliaction on that node(port).

#### TCP - Transmission control protocol
 - Connection Oriented protocol.
 - First acknowledge the session between the two computers that are communicating.
 - Two computers verify a connection before any communication take place.

 ![alt text](./assert/TCP_Three_way_handshake.png)

 - Guarantess the delivery of the data.
 - If a data packet doesn't arrive then TCP will resend it.

#### UDP - User Datagram Protocol
- Connectionless Oriented protocol.
- UDP is known as the "fire-and-forget" protocol.
- UDP is faster than TCP.

### Appliaction
Browser or any program.


![alt text](./assert/image.png)


## References:-
https://www.giac.org/paper/gsec/1417/osi-model-overview/102634