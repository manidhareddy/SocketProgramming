/****************************
Date: 12-10-2025
Author: Manidhar Reddy
FileName: udpcli.cpp
Sample udp client server program
**********************************/
/* sample UDP client*/
#include "cliserv.h"
int main(int argc,char* argv[])
{
    struct sockaddr_in serv;
    char request[REQUEST], replay[REPLAY];
    int sockfd,n;

    if(argc != 2)
        err_quit(''usage: udpcli <IP address of server>");
    if((sockfd = socket(PF_INET,SOCK_DGRAM,0)) < 0)
        err_sys("socket error");
    
    memset(&serv,0,sizeof(serv));

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr(agrv[1]); // ip address
    serv.sin_port = htons(UDP_SERV_PORT); // set port nu

    /* form request[] --------------*/

    if(sendto(sockfd,request,REQUEST,0,(SA) &serv, sizeof(serv)) != REQUEST)
            err_sys("sendto error");
    if((n = recvfrom(sockfd,reply,REPLY,0,(SA) NULL, (int*)NULL)) < 0 )
            err_sys("recvfrom error");
    
    /* process "n" bytes of replay[]................*/

    for(int i = 0 ;i < n ;i++){
            std::cout << replay[i] ;
    }
        std::cout << std::endl; 
}