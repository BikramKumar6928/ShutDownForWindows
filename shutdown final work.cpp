//made by Bikram Kumar(Bikram-sama)
//final work till now.. can mention time in either h m or s.. nothing mentioned it will take minutes write a for abort
#include<iostream>
#include<string.h>
#include<cstring>
#include<stdlib.h> 
using namespace std;
long stringToLong(string s)
{
	long x=0;
	for(int i=0;i<s.length();i++)
	{
		char a=s.at(i);
		x=x*10+(a-'0');
	}
	return x;
}
string longToString(long x)
{
	long y=x;
	int l=0;
	while(y!=0)
	{
		l++;
		y=y/10;
	}
	char s[l];
	for(int i=l-1;i>=0;i--)
	{
		s[i]=(x%10)+'0';
		x=x/10;
	}
	string a=s;
	return s;
}
int main(){
	cout<<" --------------------------------------------------------------------------"<<endl;
	cout<<"|                            Made by Bikram Kumar                          |"<<endl;
	cout<<"|This program can help you to shutdown your PC after a specified           |"<<endl;
	cout<<"|                                 time-interval                            |"<<endl;
	cout<<"|1. Type 'xhymzs' (here x,y,z are integers making the PC to shutdown after |"<<endl;
	cout<<"|                   x hours y minutes and z seconds).                      |"<<endl;
	cout<<"|                    DO NOT INCLUDE ANY SPACES IN BETWEEN THE VALUES       |"<<endl;
	cout<<"|2. Type 'a' to abort the previously scheduled shutdown.                   |"<<endl;	
	cout<<" --------------------------------------------------------------------------"<<endl;	
	int ch=0;
	string s,h="0",m="0",sec="0";
	getline(cin,s);
	string p=s;
	if(s=="a"){
		system("shutdown -a");
		exit(1);
	}
	for(int i=0;i<s.length();i++){
		char a=s.at(i);
		if(a=='h'||a==' '){
			ch=1;
			h=s.substr(0,i);
			s=s.substr(i+1);
			break;  
		}
	}
	for(int i=0;i<s.length();i++){
		char a=s.at(i);
		if(a=='m'||a==' '){
			ch=1;
			m=s.substr(0,i);
			s=s.substr(i+1);
			break;  
		}
	}
	for(int i=0;i<s.length();i++){
		char a=s.at(i);
		if(a=='s'||a==' '){
			ch=1;
			sec=s.substr(0,i);
			s=s.substr(i+1);
			break;  
		}}
	long hi=stringToLong(h);
	long mi=stringToLong(m);
	long seci=stringToLong(sec);
	long a1=(hi*3600) + (mi*60) + (seci);
	//cout<<a1;
	s=longToString(a1);
	if(ch==0){
		long min=stringToLong(p);
		min=min*60;
		p=longToString(min);
		s=p;
	}
	string s1="shutdown -s -t "+s;
	system(s1.c_str());
	return 0;
}
