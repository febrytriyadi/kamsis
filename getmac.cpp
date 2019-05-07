#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    const int size = 256;
    int jum=0;
    char ip_address[size];
    int hw_type;
    int flags;
    char mac_address[size];
    char mask[size];
    char device[size];
    string mac;

    FILE* fp = fopen("/proc/net/arp", "r");
    if(fp == NULL)
    {
        perror("Error opening /proc/net/arp");
    }

    char line[size];
    fgets(line, size, fp);    // Skip the first line, which consists of column headers.
    while(fgets(line, size, fp))
    {
        sscanf(line, "%s 0x%x 0x%x %s %s %s",
               ip_address,
               &hw_type,
               &flags,
               mac_address,
               mask,
               device);
	mac=mac_address;
	if ((mac!="58:69:6c:4c:ad:c7")&&(mac!="00:00:00:00:00:00")){
	jum++;
        printf("IP = %s, MAC = %s \n", ip_address, mac_address);
	}
    }
    printf("%d",jum);

    fclose(fp);
}
