///////////////////////////////////////////////////////////////////////////////
// Original author: Jeff Lundgren [jlundgre@igate.sprint.com]
//
// Compiled in Visual Studio .NET & Windows XP
//
// Author: Khalid Shaikh [Shake@ShakeNet.com]
// Date:   March 20, 2002
//
// Desc:
//			Gets your host name and displays all IP addresses associated 
//			with your PC.
//
// Modifications:
//			Displays multiple IPs & no MFC required.
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <sys/socket.h>
#pragma comment(lib, "wsock32.lib")

int main(int argc, char *argv[])
{
	WORD wVersionRequested;
	WSADATA wsaData;
	char name[255];
	PHOSTENT hostinfo;
	wVersionRequested = MAKEWORD( 1, 1 );
	char *ip;

	if ( WSAStartup( wVersionRequested, &wsaData ) == 0 )
		if( gethostname ( name, sizeof(name)) == 0)
		{
			printf("Host name: %s\n", name);

			if((hostinfo = gethostbyname(name)) != NULL)
			{
				int nCount = 0;
				while(hostinfo->h_addr_list[nCount])
				{
					ip = inet_ntoa (*(struct in_addr *)hostinfo->h_addr_list[nCount]);

					printf("IP #%d: %s\n", ++nCount, ip);
				}
			}
		}
	return 0;
}

