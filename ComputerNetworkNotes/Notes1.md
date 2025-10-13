***************************
Date: 12-10-2025
Author: Manidhar Reddy
****************************

TCP/IP illustrated

DNS :-
 Client request to domain name system(DNS) server asking for the ip address corresponding to a domain name, follwoed by the servers response.

 UDP Client-server
 The Client sends a request to the server, the server process rhe request and sends back a reply.


The <br>socket<\br> function creates a UDP socket, returning a nonnegative descriptor to the process. 

 if((sockfd = socket(PF_INET,SOCK_DGRAM,0)) < 0)


 Fill in server's address:-

     memset(&serv,0,sizeof(serv));

-> An internet socket address structure is first zeroed out using <br>memset<\br>.

And then filled with IP address and port number of the server. 

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr(agrv[1]); // ip address
    serv.sin_port = htons(UDP_SERV_PORT); // set port nu

    #define UDP_SERV_PORT in cliserv.h

    gethostbyname and getservbyname

    Form request and send it to server:-

    sendto -> this causes a single UDP datagram to be sent to the server
    fixed-size request (REQUEST)
    fixed-sized replay(REPLY)

    A real application woild allocate room for its maximum-sized request and reply


    Read and process reply from server:-

    if((n = recvfrom(sockfd,reply,REPLY,0,(SA) NULL, (int*)NULL)) < 0 )
            err_sys("recvfrom error");

    Call to recvfrom blocks the process (puts it to sleep) until a datagram arrives for the client. The client then process the replay  and terminates.

    If request or reply lost then that program runs forever because there is not timeout for recvfrom.

    In the cliserv.h header we #define SA to be struct sockaddr *,that is, a pointer to a generic socket address structure.

    Socket functions requires a pointer to a socket address structure, that pointer must be cast to a pointer to a generic address structure.

    This is becuase the socket functions predate the ANSI C Standard, So the void pointer type was not available in early 1980s when these functions were developed.

    





