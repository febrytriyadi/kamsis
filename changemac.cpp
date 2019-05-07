#include <iostream>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void usleep( float seconds ){
    clock_t end;
    end = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < end) {}
}

void  setMac(char * mac)
{
	char cmd[64];
	//network interface
	char nwkInf[7]="wlan0";

	memset(cmd,0X00,64);
	
	//command to link down network
	sprintf((char *)cmd,(const char *)"ip link set %s down",nwkInf);
	system((const char *)cmd); 
	usleep(0.5);
	
	memset(cmd,0X00,64);
	//command to set MAC address
	sprintf((char *)cmd,(const char *)"ifconfig %s hw ether %s",nwkInf,mac);
	system((const char *)cmd);
	usleep(0.5);

	memset(cmd,0X00,64);
	//command to link up network
	sprintf((char *)cmd,(const char *)"ip link set %s up",nwkInf);
	system((const char *)cmd);
	usleep(0.5);

}

int main()
{
	char * mac;
	cin>>mac;
    //funcion call to set MAC address
	//setMac("67:45:C4:AC:2F:CA");
	return 0;
}