#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if_arp.h>
#include <net/if.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv) {
	struct ifreq ifr;
	int s;

	s = socket(AF_INET, SOCK_DGRAM, 0);
	assert(s != -1);

	strcpy(ifr.ifr_name, "wln1");
	ifr.ifr_hwaddr.sa_data[0] = 0xC0;
	ifr.ifr_hwaddr.sa_data[1] = 0x87;
	ifr.ifr_hwaddr.sa_data[2] = 0xEB;
	ifr.ifr_hwaddr.sa_data[3] = 0x35;
	ifr.ifr_hwaddr.sa_data[4] = 0x8B;
	ifr.ifr_hwaddr.sa_data[5] = 0xB7;
	ifr.ifr_hwaddr.sa_family = ARPHRD_ETHER;
	assert(ioctl(s, SIOCSIFHWADDR, &ifr) != -1);

	return EXIT_SUCCESS;
}