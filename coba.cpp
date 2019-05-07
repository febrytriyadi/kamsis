#include <stdio.h>
#include <iostream>
#include <dirent.h>

using namespace std;
int main(){
	dirent *d;
	int ui=0;
	char _a;
	string b,_user,mac,find,cari;
	FILE *data=fopen("/root/datauserpass.txt","a+");
	DIR *a=opendir(".");
	if (a==NULL){
		printf("failed");
	}else{
		while((d=readdir(a))!=NULL){
//			printf("%s\n",d->d_name);
			b=d->d_name;
			if ((b.length()>2)&&(b[2]==':')){
//				cout<<b;
				FILE* fl=fopen(b.c_str(),"r");
				if (getc(fl)==EOF) {fclose(fl);system(("rm "+b).c_str());}
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
						while (true){
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
							if(find=="userName") break;
						}
						getc(fl);
						getc(fl);
						getc(fl);
//						cout<<find;
						while((_a=getc(fl))!='"') _user=_user+_a;
//							cout<<_user<<endl;
						char _usermac[]={"       "};
						mac="";
						find="";
						ui=0;
						while(true){
							_a=getc(fl);
							if ((_a=='u')&&(ui==0)) {_usermac[ui]=_a; ui=1;}
							else if ((_a=='s')&&(ui==1)) {_usermac[ui]=_a;  ui=2;}
							else if ((_a=='e')&&(ui==2)) {_usermac[ui]=_a; ui=3;}
							else if ((_a=='r')&&(ui==3)) {_usermac[ui]=_a; ui=4;}
							else if ((_a=='M')&&(ui==4)){_usermac[ui]=_a; ui=5;}
							else if ((_a=='a')&&(ui==5)){_usermac[ui]=_a; ui=6;}
							else if ((_a=='c')&&(ui==6)){_usermac[ui]=_a;}
							else ui=0;
							find=_usermac;
							if (find=="userMac") break;
						}
						getc(fl);
						getc(fl);
						getc(fl);
						while((_a=getc(fl))!='"') mac=mac+_a;
						fprintf(data,"%s\t\t\t\t\t\t\t%s\n",_user.c_str(),mac.c_str());
						fclose(fl);
					}
				}
				system(("mv "+b+" /root/TelkomTune/").c_str());
			}
		}
	}
//	string b,c;
//	cin>>b;
//	cin>>c;
//	fprintf(a,"%s\t\t\t\t\t\t\t%s\n",b.c_str(),c.c_str());
//	fclose(a);
	closedir(a);
	fclose(data);
	return 0;
}
