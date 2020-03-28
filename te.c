//获取主机ip地址：gethostbyname
#include<sys/socket.h>
#include<netdb.h>  //gethostbyname 函数头文件 函数返回struct hostent类型的指针
#include<stdio.h>
#include <stdlib.h>
#include <arpa / inet.h> //inet_ntop 函数
int main(int argc,char *argv[])
{
	struct sockaddr_in localaddr;
	struct sockaddr		opaddr;

	int sockfd;
	char *host,**paddr;
	struct hostent *ptr;
	char strbuf[1024];
	sockfd=socket(AF_INET,SOCK_STREAM,0);


	host=argv[1];
	ptr=gethostbyname(host);
	for(paddr=ptr->h_aliases;*paddr!=NULL;paddr++)  
		printf("\talias:%s\n",*paddr);
	switch(ptr->h_addrtype)
	{
		case AF_INET:
			paddr=ptr->h_addr_list;
			for(;*paddr!=NULL;paddr++)
				printf("%s ip is %s\n",host,inet_ntop(AF_INET,*paddr,strbuf,sizeof(strbuf)));
		
		break;
	}




}
