/*
 * Fetch IP address of a given DNS
 * Author : Manidhar Reddy
 * Date : 15-04-2025
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>

#include <sys/types.h> // use for data types in socket
#include <sys/socket.h> // socket programming api
#include <netdb.h> //provide functions and structures to work with DNS and hostnames
#include <arpa/inet.h> //text reprsentation of ip addresses
#include <netinet/in.h> //ipv4 and ipv6 structs


int main(){

	struct addrinfo hints, *res, *p;
	int status;
	std::string hostName;
	char ipstr[INET6_ADDRSTRLEN];
	
	std::cout << "showip : ";
	std::cin >> hostName; // Take input from cLI
	
	memset(&hints,0,sizeof(hints));
	
	hints.ai_family = AF_UNSPEC;// any AF_INET or AF_INET6
	hints.ai_socktype = SOCK_STREAM; //TCP

	if((status = getaddrinfo(hostName.c_str(),NULL,&hints,&res)) != 0){
		std::cout << "failed to create struct addrinfo \n" ;
		return 2;
	}

	std::cout << "IP address for given hostname : \n";
	
	//iterate over linked list 
	for(p = res; p != NULL ; p = p->ai_next){
		
		void *addr;
		char *ipver;

		if(p->ai_family == AF_INET){ // IPv4
			struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
			addr = &(ipv4->sin_addr);
			ipver = "IPv4";
		}else{
			struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
			addr = &(ipv6->sin6_addr);
			ipver = "IPv6";
		}
		
		//convert the IP to a string and print it;
		inet_ntop(p->ai_family,addr,ipstr,sizeof ipstr);
		std::cout << ipver << " : " << ipstr << "\n";
	}
	freeaddrinfo(res);
	return 0;
}



