#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
//#include<unistd.h>
#include<time.h>
#include<conio.h>
#include<malloc.h>
#include"menu.h"

int main()
{
	SeqList myList;
	///eqList *L;
	//int q=1;
	//int *s=&q;
	//SeqList1 adminmyList;
	int a=0;//会员人数初始化
	//int e=0;//管理员初始化
	int vip=1;//vip指会员车位的排数
	ParkingSpace ps[10][10];
	ListInitiate(&myList);
	//ListInitiate(L);
	//CarInformationRegistration(ps,L,s,vip);	
 login(ps,&myList,&a,vip);
   system("pause");
	return 0;
}


