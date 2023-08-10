#ifndef _MENU_H
#define _MENU_H
typedef struct VipCard
{
	char Number[100];      //卡号
	//char Password[100];    //密码
	double money;  //余额
	int or;//注册后变为1
}VIPcard;

typedef struct User         //车主信息
{
	char name[10];          //车主姓名
	char phone[12];         //手机号
	char LicensePlate[30];//车牌
	int id;   //身份,1是VIP,0是普通用户
	//VIPcard vipcard;
	int OR;                 //是否已经停车
	//int caror;//是否是首次停车，0是，1不是
	char vipNumber[100];      //卡号
//	char vipPassword[100];    //密码
	double vipmoney;           //余额
	int oneCoupon;         //一元优惠券
	int twoCoupon;         //二元优惠券
}User;   //用户
VIPcard vipcard[25]={
	{"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},
	{"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},
	{"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},
	{"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},
	{"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},
	
};
struct StringCarTime//时间的字符显示
{
	char year[5];
	char mon[3];
	char day[3];
	char hour[3];
	char min[3];
	char sec[3];
};
struct NumberCarTime//时间的数字显示
{
	int year;
	int mon;
	int day;
	int hour;
	int min;
	int sec;
};
typedef struct ParkingSpace //车位信息
{
	int or;                  //是否有车
	int orvip;
	char name[10];           //车主
	char phone[12];          //电话
	char LicensePlate[10];   //车牌
	struct tm * tStartTime;    //进库时间
	struct tm * tEndTime;     //出库时间
	struct StringCarTime StringStartTime;
	struct StringCarTime StringEndTime;
	struct NumberCarTime NumberStartTime;
	struct NumberCarTime NumberEndTime;
	int oneCoupon;         //一元优惠券
	int twoCoupon;         //二元优惠券
}ParkingSpace; //车位
typedef struct administrator
{
	char name[10];
	char password[10];
}Admin;
Admin admin={"admin","123456789"}; 
typedef User DataType;
#define MaxSize 100
typedef struct
{
	DataType list[MaxSize];
	int size;
}SeqList;

void ListInitiate(SeqList *L);
int ListLength(SeqList L);
int ListInsert(SeqList *L,int i,DataType x);
int ListDelete(SeqList *L,int i,DataType *x);
int ListGet(SeqList L,int i,DataType *x);

void ListInitiate(SeqList *L)
{
	L->size=0;
}
int ListLength(SeqList L)
{	
	return L.size;
}
int ListInsert(SeqList *L,int i,DataType x)
{
	int j;
	if(L->size>=MaxSize)
	{
		printf("顺序表已满无法插入！\n");
		return 0;
	}
	else if(i<0||i>L->size)
	{
		//printf("参数i不合法！\n");
		return 0; 
	}
	else
	{
		for(j=L->size;j>i;j--)
		{
			L->list[j]=L->list[j-1];
		}
		L->list[i]=x;
		L->size++;
		return 1;
	}
}
int  ListDelete(SeqList *L,int i,DataType *x)
{
	int j;
	if(L->size<=0)
	{
		printf("顺序表已空无数据元素可删！\n");
		return 0;
	}
	else if(i<0||i>L->size-1)
	{
		//printf("参数i不合法！\n");
		return 0;
	}
	else
	{
		*x=L->list[i]; 
		for(j=i+1;j<=L->size-1;j++)
		{
			L->list[j-1]=L->list[j];
		}
		L->size--;
		return 1;
	} 
}

int ListGet(SeqList L,int i,DataType *x)
{
	if(i<0||i>L.size-1)
	{
		printf("参数i不合法！\n");
		return 0;
	}

	else
	{
		*x=L.list[i];
		return 1; 
	}
} 

void login(ParkingSpace ps[][10],SeqList*L,int *s,int vip);//登录
void CarInquire(ParkingSpace ps[][10],SeqList*L,int *s,int vip);//空余车位查询
void GetCar(ParkingSpace ps[][10],SeqList*L,int *s,int vip);//获取车辆信息
void CarOut(ParkingSpace ps[][10],SeqList*L,int *s,int vip);//车辆退出车位
void CarIn(ParkingSpace ps[][10],SeqList *L,int i,int j,int m);//车辆进库
void CarInformationRegistration(ParkingSpace ps[10][10],SeqList*L,int *s,int vip);//车辆信息登记
void UserInformationDisplay(ParkingSpace ps[10][10],SeqList*L,int *s,int vip);//车辆进库登记
void menu(ParkingSpace ps[10][10],SeqList*L,int *s,int vip);//菜单
void ReturnMenu(ParkingSpace ps[10][10],SeqList*L,int *s,int vip);//返回菜单函数
void CarDisplay(ParkingSpace ps[10][10],SeqList*L,int *s,int vip);//车位显示
void PaymentEnquiry(ParkingSpace ps[10][10],SeqList*L,int i,int j,int *s,int vip);//付款查询
void itoaStartTime(ParkingSpace ps[10][10],SeqList*L,int i,int j);//进库时间获取
void itoaEndTime(ParkingSpace ps[10][10],SeqList*L,int i,int j);//出库时间获取
double timedifference(ParkingSpace ps[10][10],SeqList*L,int i,int j,int* p,int *s,int vip);//时间差函数
double Pay(ParkingSpace ps[10][10],SeqList*L,int i,int j,int b,int c,int* q,int *s, int vip);//计费说明
void VipCardRecharge(ParkingSpace ps[10][10],SeqList*L,int *s,int vip);//会员卡充值
void ResetAndDelete(ParkingSpace ps[10][10],SeqList*L,int *s,int vip);//重置和删除
void VIPregistration(ParkingSpace ps[10][10],SeqList*L,int* a,VIPcard vipcard[25],int vip);//会员注册
void ChangePassword(ParkingSpace ps[10][10],SeqList*L,int* s,int vip);//修改密码
void CarWirteFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip);//写入用户 
void CarReadFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip);//读取用户 
void VIPReadFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip);//读取会员 
void VIPWirteFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip);//写入会员 
void PSWirteFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip);//写入车位 
void PSReadFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip);//读取车位 



void login(ParkingSpace ps[][10],SeqList*L,int *s,int vip)//登录
{
	char name[10],password[10];
	int i=0,m,n;
	for(m=0;m<5;m++)
	{
		for(n=0;n<5;n++)
		{
			ps[m][n].or=0;
		}
	}
	//FILE *fp=fopen("user.txt","w");/*以写模式("w")打开文件user.txt,如果不存在,会自动创建*/
	CarReadFile(ps,L,s,vip);
	VIPReadFile(ps,L,s,vip);//读取会员 
	PSReadFile(ps,L,s,vip);
	 //printf("asdasdasdasd");
		while(i<3)
	{	
		printf(" ===========================\n");
	    
		printf("┃       **欢迎使用**      ┃\n");
		
		printf("┃       停车管理系统      ┃\n");
		
		printf(" ===========================\n");
		
		printf("┃       管理员登陆        ┃\n");
		
		printf("┃     请输入账号和密码    ┃\n");
		
		printf(" ===========================\n");
		
		printf("输入%d次错误将自动结束程序！\n",3-i);
		
		printf("账号：");
		scanf("%s",name);
		
		printf("密码：");
		scanf("%s",password);
		if(strcmp(name,admin.name)==0&&strcmp(password,admin.password)==0)
		{
		
			printf("*登陆成功*");
		system("cls");
			i=4;
			menu(ps,L,s,vip);
			break;
		}
		else
		{
			
			printf("输入的账号或密码错误！\n");
			//printf("\033c");
			system("cls");

		}
		i++;
		if(i==3)
		{
			
			printf("程序已关闭！\n");
			exit(0);
			//break;
		}
	}
}


void  CarDisplay(ParkingSpace ps[10][10],SeqList*L,int *s,int vip)
{
	int i,j;
	
	printf("================================================================\n");
	
	printf("*                             车位                            *\n");
	
	printf("================================================================\n");
	
	printf("                           *会员车位*\n");
	
	printf("\n");
	//printf("                            ");
	for(i=0;i<vip;i++)
	{
		for(j=0;j<5;j++)
		{	

			if(ps[i][j].or==1)
			{
				
				printf(" [%d][%d]有车  ",i+1,j+1);
			}
			else
			{   
				printf(" [%d][%d]无车  ",i+1,j+1);
			}

		}
		
		printf("\n");
	}
	
	printf("\n");
	
	printf("                           *普通车位*\n");
	printf("\n");
	for(i=vip;i<5;i++)
	{
		
		for(j=0;j<5;j++)
		{	 
			if(ps[i][j].or==1)
			{
				printf(" [%d][%d]有车  ",i+1,j+1);
			}
			else
			{
				printf(" [%d][%d]无车  ",i+1,j+1);
			}

		}
		printf("\n");
	}
}
void CarInquire(ParkingSpace ps[][10],SeqList*L,int *s,int vip)//车位查询
{
	int i,j,n=0,m,r=0,q=0;
	
	char k,M,I,J;
	User user,x;
	while(1)
	{
		CarDisplay(ps,L,s,vip);
		printf("选择编号：[0]返回菜单 [1]车位选择\n");
		printf("请输入数字：");
		scanf(" %c",&k);
		if(k=='0')
		{
			system("cls");
			break;
		}
		else if(k=='1')
		{
			system("cls");
			break;
		}
		else
		{
			system("cls");
			printf("输入有误请重新输入！\n");
		}
	}
	if(k=='0')
		menu(ps,L,s,vip);
	if(k=='1')
	{
		CarDisplay(ps,L,s,vip);
		printf("****等待停车用户****\n");
		if(ListLength(*L)==0)
		{
			n=1;
		}
		for(i=0;i<ListLength(*L);i++)
		{  
			ListGet(*L,i,&x);
			if(x.OR==0)
			{
				if(x.id==1)
				{
					printf("*VIP用户* ");
				}
				else
				{
					printf("*普通用户* ");
				}
				printf("[%d] ",i);
				printf("车主姓名：%s",x.name);
				printf("汽车车牌：%s ",x.LicensePlate);
				printf("电话号码：%s ",x.phone);
				printf("\n");
				//n=0;
				
				//break;
			}
			   if(n==0)
		{
			
			printf("输入编号：");
			scanf("%d",&m); 
			if(ListGet(*L,m,&user)==0)
			{
				printf("输入数字有误！\n");
				ReturnMenu(ps,L,s,vip);
			}
			if(user.OR==1)
			{
				
				printf("输入数字有误！\n");
				ReturnMenu(ps,L,s,vip);
			}
			
			printf("选择停车位编号：\n");
			
			printf("排：");
			scanf(" %c",&I);
			i=I-'0';
			
			printf("列：");
			scanf(" %c",&J);
			j=J-'0';
			if((i<=5&&i>=1)&&(j<=5&&j>=1))
			{  
				if(user.id==0&&i<=vip&&j<=5)
				{
					
					printf("你不是VIP用户，无法使用VIP车位！\n");
				} 
				else
				{
					if(ps[i-1][j-1].or!=1)
					{
						CarIn(ps,L,i-1,j-1,m);
						
						printf("停车成功！\n");
						ListDelete(L,m,&user);
						user.OR=1;
						ListInsert(L,m,user);
						PSWirteFile(ps,L,s,vip);//写入车位 
						CarWirteFile(ps,L,s,vip);
					}
					else
					{
						
						printf("该车位已有车辆停放！请重新选择车位！\n");
					}
				}
			}else
			{
				
				printf("输入的车位有误！");
				ReturnMenu(ps,L,s,vip);
			}
		}
			//r=r+1;
			if(i==ListLength(*L))
			{

				//n=1;
				printf("无法找到待停车用户！\n");
                 ReturnMenu(ps,L,s,vip);
			}
				
		}	  

		
		/*if(==1)
		{
				
			
		}*/

		
	}

}
void GetCar(ParkingSpace ps[][10],SeqList*L,int *s,int vip)//获取车辆信息
{
	int i,j,a;
	
	char I,J,A;
	CarDisplay(ps,L,s,vip);
	
	printf("选择编号：[0]返回菜单 [1]获取信息\n");
	
	printf("请输入数字：");
	scanf(" %c",&A);
	a=A-'0';
	if(a==0)
	{   system("cls");
	menu(ps,L,s,vip);
	}
	else if(a==1)
	{
	
		printf("输入车位号获取车辆信息：\n");
		printf("\n");
		printf("排：");
		scanf(" %c",&I);
		i=I-'0';
		printf("列：");
		scanf(" %c",&J);
		j=J-'0';
		printf("\n");
		if((i<=5&&i>=1)&&(j<=5&&j>=1))
		{
if(ps[i-1][j-1].or==1)
		{
			printf("车主信息\n");
			if(ps[i-1][j-1].orvip==1)
			{
				printf("*VIP用户* \n");
			}
			else
			{
				printf("*普通用户* \n");
			}
			printf("车主姓名：%s\n",ps[i-1][j-1].name);
			printf("车牌：%s\n",ps[i-1][j-1].LicensePlate);
			printf("车主电话号码：%s\n",ps[i-1][j-1].phone);
			ReturnMenu(ps,L,s,vip);
		}
		else
		{
			printf("此车位没有停车，无法获取车辆信息！\n");
			ReturnMenu(ps,L,s,vip);
		}	
		
		}
		else
		{
			printf("输入车位有误！\n");
			ReturnMenu(ps,L,s,vip);
		}
	}

	else
	{
		printf("输入数字有误！\n");
		ReturnMenu(ps,L,s,vip);
	}
}
void CarOut(ParkingSpace ps[][10],SeqList*L,int *s,int vip)//车辆退出车位
{
	int i,j,m=0,n,k;
	char I,J,A;
	time_t t; 
	User user,x;
	CarDisplay(ps,L,s,vip);
	printf("\n选择编号：[0]返回菜单 [1]退出车位\n");
	printf("请输入数字：\n");
	scanf(" %c",&A);
	if(A=='0')
	{
		system("cls");
		menu(ps,L,s,vip);
	}
	else if(A=='1')
	{
		printf("选择车位退出车辆\n");
		printf("\n");
		printf("排：");
		scanf(" %c",&I);
		i=I-'0';
		printf("列：");
		scanf(" %c",&J);
		j=J-'0';
		printf("\n");
		if((i<=5&&i>=1)&&(j<=5&&j>=1))
		{
			if(ps[i-1][j-1].or==1)
			{
				//ps[i-1][j-1].or=2;
				time (&t);//获取Unix时间戳。
				ps[i-1][j-1].tEndTime= localtime (&t);//转为时间结构。
				itoaEndTime(ps,L,i-1,j-1);
				//m=i,n=j;
				if(ListLength(*L)==0)
				{
					printf("用户人数为0\n");
					ReturnMenu(ps,L,s,vip);
				}
				for(k=0;k<ListLength(*L);k++)
				{
					ListGet(*L,k,&x);
					//printf("%d",strlen(x.LicensePlate));
					//printf("%d",strlen(ps[i-1][j-1].LicensePlate));
					m++;
					if(strcmp(ps[i-1][j-1].LicensePlate,x.LicensePlate)==0)
					{  	
					    printf("车辆成功移出车位！\n");
					    PaymentEnquiry(ps,L,i-1,j-1,s,vip);
						ListDelete(L,i,&x);
						x.OR=2;
						ListInsert(L,i,x);
					    CarWirteFile(ps,L,s,vip);
						printf("\n");
						ReturnMenu(ps,L,s,vip);
						break;
					}
					if(m==ListLength(*L))
					{
						printf("没有与车位信息相对应的用户！\n");
						ReturnMenu(ps,L,s,vip);
					}
				 }
			}
			else
			{
				printf("该车位没有车辆停放!无法进行操作！\n");
				ReturnMenu(ps,L,s,vip);
			}
			
		}
		else
		{
			printf("输入的车位有误！\n");
			ReturnMenu(ps,L,s,vip);
		}
	}
	else
	{
		printf("输入数字有误!\n");
		ReturnMenu(ps,L,s,vip);
	}
}
void CarIn(ParkingSpace ps[][10],SeqList *L,int i,int j,int m)//车辆进库
{
	User x;
	time_t t; 
	ListGet(*L,m-1,&x);
	strcpy(ps[i][j].name,x.name);
	strcpy(ps[i][j].phone,x.phone);
	strcpy(ps[i][j].LicensePlate,x.LicensePlate);
	ps[i][j].or=1;
	if(x.id==1)
	ps[i][j].orvip=1;
	else
	ps[i][j].orvip=0;
	ps[i][j].oneCoupon=x.oneCoupon;
	ps[i][j].twoCoupon=x.twoCoupon;
	time (&t);//获取Unix时间戳。
	ps[i][j].tStartTime= localtime (&t);//转为时间结构。
	itoaStartTime(ps,L,i,j);
}

void CarInformationRegistration(ParkingSpace ps[10][10],SeqList*L,int *s,int vip)//车辆信息登记
{
	User user[25],x;
	int i,j,k,m,r=0,n;
	char J,A;
	char number[100];
	char password[100];
	VIPReadFile(ps,L,s,vip);//读取会员 
 	i=ListLength(*L);
	
	printf(" ===========================\n");
	
	printf("┋       停车信息登记      ┋\n");
	
	printf(" ===========================\n");
	
	printf("选择编号：[0]返回菜单 [1]信息登记\n");
   
	printf("请输入数字：");
	scanf(" %c",&A);
	if(A=='0')
	{
		system("cls");
		menu(ps,L,s,vip);
	}		
	else if(A=='1')
	{
		
		printf("输入姓名：");
		scanf("%s",user[i].name);
		
		printf("输入车牌：");
		scanf("%s",user[i].LicensePlate);
		
		printf("输入电话：");
		scanf("%s",user[i].phone);
		user[i].id=0;
		if(ListLength(*L)==0)
		{
			user[i].OR=0;
			user[i].oneCoupon=4;
			user[i].twoCoupon=2;
			r=2;
		}
		for(m=0;m<ListLength(*L);m++)
		{
			ListGet(*L,m,&x);

			if(strcmp(user[i].LicensePlate,x.LicensePlate)==0)
			{
				//user[i].OR=0;
				if(x.OR==0||x.OR==1||x.OR==2)
				{
					
					printf("该操作不合法！\n");
					ReturnMenu(ps,L,s,vip);
					break;
				}
				else
			    {
					r=1;
			        n=m;
					break;
				}
				//break;
			}
			else
			{
				r=2;
			}
		}
		if(r==1)
		{

			ListDelete(L,n,&x);
			x.OR=0;
			ListInsert(L,n,x);
			CarWirteFile(ps,L,s,vip);//写文件
			printf("*欢迎你再次光临！*\n");
			ReturnMenu(ps,L,s,vip);
		}
		if(r==2)
			//user[i].caror=0;
		{	        
		user[i].OR=0;
		user[i].oneCoupon=4;
		user[i].twoCoupon=2;
		
		printf("是否为VIP用户:是[0] 否[1]\n");
		
		printf("请输入数字：");
		scanf(" %c",&J);
		j=J-'0';
		if(j==0)
		{
			
			printf("请输入会员卡账号：");
			scanf("%s",number);
			
		//	printf("请输入密码：");
		//	scanf("%s",password);
			for(k=0;k<25;k++)
			{
				if(strcmp(number,vipcard[k].Number)==0)
				{
					user[i].id=1;
					strcpy(user[i].vipNumber,vipcard[k].Number);
					user[i].vipmoney=vipcard[k].money;
					break;

				}


			}
			if(k==25)
			{   
				printf("输入账号有误！\n");
				
				ReturnMenu(ps,L,s,vip);
			}
		}
		else if(j==1)
		{
			user[i].id=0;
			
		}
		else
		{
			
			printf("输入数字有误！\n");
			ReturnMenu(ps,L,s,vip);
		}
		   ListInsert(L,i,user[i]);	
		   CarWirteFile(ps,L,s,vip);//写文件
		if(user[i].id==1)
		{
			
			printf("信息登记成功！\n");
			
		    printf("首次登记信息，送4张一元优惠券，2张二元优惠券！\n");
		}
		else
		{
			
			printf("信息登记成功！\n");
			
		    printf("首次登记信息，送4张一元优惠券，2张二元优惠券！\n");
		}
		ReturnMenu(ps,L,s,vip);
		}
	}
	else
	{  
		printf("输入数字有误！\n");
		ReturnMenu(ps,L,s,vip);
	}

}
void UserInformationDisplay(ParkingSpace ps[10][10],SeqList*L,int *s,int vip)//用户信息查询
{
	int i,a;
	char A,B;
	User x;
	VIPReadFile(ps,L,s,vip);//读取会员 
	printf("\n选择编号：[0]返回菜单 [1]信息查询\n");
	printf("请输入数字：");
	scanf(" %c",&B);
	if(B=='0')
	{
		system("cls");
		menu(ps,L,s,vip);
	}
	else if(B=='1')
	{
		printf("用户信息查询\n");
		if(ListLength(*L)==0)
		{
			printf("没有用户登记!\n");
			ReturnMenu(ps,L,s,vip);
		}
		for(i=0;i<ListLength(*L);i++)
		{
			ListGet(*L,i,&x);
			printf("[%d]  ",i);
			if(x.OR==0)
				printf(" [未停车] \n");
			if(x.OR==1)
				printf(" [已停车] \n");
			/*if(x.OR==2)
				printf(" [已出库，待缴费] \n");*/
			if(x.OR==3)
				printf("[已缴费,并开出] \n");
			if(x.id==1)
			{
				printf("*VIP用户* \n");
			}
			else
			{
				printf("*普通用户* \n");
			}
			printf("车主姓名：%s \n",x.name);
			printf("汽车车牌：%s  \n",x.LicensePlate);
			printf("电话号码：%s  \n",x.phone);

			if(x.id==1)
			{
				printf(" 会员卡余额：%.2f（元）\n",x.vipmoney);
			}
			printf(" 一元优惠券数量：%d（个）\n",x.oneCoupon);
			printf(" 二元优惠券数量：%d（个）\n",x.twoCoupon);
			printf("\n");
		}
		printf("是否对用户进行操作：[0]是 [1]否\n");
		printf("请输入数字：");
		scanf(" %c",&A);
		a=A-'0';
		if(a==0)
			ResetAndDelete(ps,L,s,vip);//重置和删除
		else if(a==1)
			ReturnMenu(ps,L,s,vip);
		else
		{
			printf("输入数字有误！\n");
			ReturnMenu(ps,L,s,vip);
		}
	}
	else
	{
		printf("输入数字有误！\n");
		ReturnMenu(ps,L,s,vip);
	}
}
void ReturnMenu(ParkingSpace ps[10][10],SeqList*L,int *s,int vip)//返回菜单函数
{
	int k;
	char K;
	
	printf("是否返回菜单：是[0]\n");
	

	while(1)
	{
		
		printf("请输入数字：");;
		scanf(" %c",&K);
		printf("\b");;
		k=K-'0';
		if(k==0)
		{
			system("cls");
			break;
		}
		else
		{
			system("cls");
			
			printf("输入有误请重新输入！\n");
			
			printf("[0]返回菜单\n");
			
	       printf("请输入数字：");
		}
	}	
	menu(ps,L,s,vip);
}
void itoaStartTime(ParkingSpace ps[10][10],SeqList*L,int i,int j)
{
	ps[i][j].NumberStartTime.year=ps[i][j].tStartTime->tm_year+1900;
	ps[i][j].NumberStartTime.mon=ps[i][j].tStartTime->tm_mon+1;
	ps[i][j].NumberStartTime.day=ps[i][j].tStartTime->tm_mday;
	ps[i][j].NumberStartTime.hour=ps[i][j].tStartTime->tm_hour;
	ps[i][j].NumberStartTime.min=ps[i][j].tStartTime->tm_min;
	ps[i][j].NumberStartTime.sec= ps[i][j].tStartTime->tm_sec;
	itoa(ps[i][j].tStartTime->tm_year+1900,ps[i][j].StringStartTime.year,10);
	itoa(ps[i][j].tStartTime->tm_mon+1,ps[i][j].StringStartTime.mon,10);
	itoa(ps[i][j].tStartTime->tm_mday,ps[i][j].StringStartTime.day,10);
	itoa(ps[i][j].tStartTime->tm_hour,ps[i][j].StringStartTime.hour,10);
	itoa(ps[i][j].tStartTime->tm_min,ps[i][j].StringStartTime.min,10);
	itoa(ps[i][j].tStartTime->tm_sec,ps[i][j].StringStartTime.sec,10);
}
void itoaEndTime(ParkingSpace ps[10][10],SeqList*L,int i,int j)
{
	ps[i][j].NumberEndTime.year=ps[i][j].tEndTime->tm_year+1900;
	ps[i][j].NumberEndTime.mon=ps[i][j].tEndTime->tm_mon+1;
	ps[i][j].NumberEndTime.day=ps[i][j].tEndTime->tm_mday;
	ps[i][j].NumberEndTime.hour=ps[i][j].tEndTime->tm_hour;
	ps[i][j].NumberEndTime.min=ps[i][j].tEndTime->tm_min;
	ps[i][j].NumberEndTime.sec= ps[i][j].tEndTime->tm_sec;
	itoa(ps[i][j].tEndTime->tm_year+1900,ps[i][j].StringEndTime.year,10);
	itoa(ps[i][j].tEndTime->tm_mon+1,ps[i][j].StringEndTime.mon,10);
	itoa(ps[i][j].tEndTime->tm_mday,ps[i][j].StringEndTime.day,10);
	itoa(ps[i][j].tEndTime->tm_hour,ps[i][j].StringEndTime.hour,10);
	itoa(ps[i][j].tEndTime->tm_min,ps[i][j].StringEndTime.min,10);
	itoa( ps[i][j].tEndTime->tm_sec,ps[i][j].StringEndTime.sec,10);
}
void PaymentEnquiry(ParkingSpace ps[10][10],SeqList*L,int i,int j,int *s,int vip)//付款查询
{
	int p,q;
	User x;

	char A;
	double cost;
	VIPReadFile(ps,L,s,vip);//读取会员 
	printf("********收费说明********\n");
	printf("*停车时间小于等于1小时，按一小时计费,每小时收费3元*\n");
	printf("*停车大于1小时且小于2小时，多于1小时的部分，按每小时收费4元*\n");
	printf("*停车大于2小时且小于3小时，多于2小时的部分，按每小时收费5元*\n");
	printf("*停车大于3小时，多于3小时的部分，按每小时收费6元*\n");
	printf("\n选择编号：[0]返回菜单 [1]付款查询\n");
	printf("请输入数字：");
	scanf(" %c",&A);
	if(A=='0')
	{
		system("cls");
		menu(ps,L,s,vip);
	}
	else if(A=='1')
	{
		

				for(p=0;p<ListLength(*L);p++)
				{     
					ListGet(*L,p,&x);
					if(ps[i][j].or==1&&strcmp(ps[i][j].LicensePlate,x.LicensePlate)==0)
					{        

						printf("【%d】\n",p);
						if(ps[i][j].orvip==1)
						{
							printf("*VIP用户* \n");
						}
						else
						{
							printf("*普通用户* \n");
						}
						printf("车主信息\n");
						printf("车主姓名：%s\n",ps[i][j].name);
						printf("车牌：%s\n",ps[i][j].LicensePlate);
						printf("车主电话号码：%s\n",ps[i][j].phone);
						printf ( "进库时间：%s/%s/%s %s:%s:%s\n",ps[i][j].StringStartTime.year,ps[i][j].StringStartTime.mon,ps[i][j].StringStartTime.day,ps[i][j].StringStartTime.hour,ps[i][j].StringStartTime.min,ps[i][j].StringStartTime.sec);
						printf ( "出库时间：%s/%s/%s %s:%s:%s\n",ps[i][j].StringEndTime.year,ps[i][j].StringEndTime.mon,ps[i][j].StringEndTime.day,ps[i][j].StringEndTime.hour,ps[i][j].StringEndTime.min,ps[i][j].StringEndTime.sec);
						printf("停车时间：");
						cost=timedifference(ps,L,i,j,&q,s,vip);
						ListDelete(L,p,&x);
						if(q==0)
							x.oneCoupon--;
						if(q==1)
							x.twoCoupon--;
						x.OR=3;
						if(x.id==1)
						{
							if(x.vipmoney-cost>0) 
					   	x.vipmoney=x.vipmoney-cost;
						else
						{
							printf("余额不足！请充值！\n");
							ReturnMenu(ps,L,s,vip);
						}
						}
						ListInsert(L,p,x);
						ps[i][j].or=0;
						CarWirteFile(ps,L,s,vip);//写文件
						PSWirteFile(ps,L,s,vip);//写入车位 
						printf("已缴费！\n"); 

					}

				}
			
		
		ReturnMenu(ps,L,s,vip);
	}
	else
	{
		printf("输入数字有误！\n");
		ReturnMenu(ps,L,s,vip);
	}
}
double Pay(ParkingSpace ps[10][10],SeqList*L,int i,int j,int b,int c,int* q,int *s, int vip)
{
	double cost;
	char Q;
	if((b==0&&c<=59)||b==1)//小于1分钟
		cost=3;
	if(b>1&&b<=2)//大于1分钟小于2分钟,多于1分钟的按分钟4元
		cost=3+(b-1)*4;
	if(b>2&&b<=3)//大于2分钟小于3分钟,多于2分钟的按每分钟5元
		cost=7+(b-2)*5;
	if(b>3)//大于分钟，多于3分钟按分钟6元算
		cost=12+(b-3)*6;
	printf("\n***待缴费的用户***\n");
	if(ps[i][j].orvip==1)
	{
		printf("你是会员可以享受九折优惠！\n");
		cost=cost*0.9;
	}
	printf("是否使用优惠券：[0]1元优惠券 [1]2元优惠券 [2]不使用优惠券\n");
	printf("请输入数字：");
	scanf(" %c",&Q);
	*q=Q-'0';
	if(*q==0)
	{
		if(ps[i][j].oneCoupon>1)
		{	cost=cost-1;
		printf("已使用一张一元优惠券！\n");
		}
		else
		{
			printf("一元优惠券数量不足！不能使用优惠券！\n");
			*q=2;
		}
	}
	else if(*q==1)
	{
		if(ps[i][j].twoCoupon>1)
		{
			cost=cost-2;
			printf("已使用一张二元优惠券！\n");
		}
		else
		{
			printf("二元优惠券数量不足！不能使用优惠券！\n");
			*q=2;
		}
	}
	else if(*q==2)
	{

		cost=cost;	
		printf("没有使用优惠券！\n");
	}
	else
	{	printf("输入有误！\n");              
	ReturnMenu(ps,L,s,vip);
	}
	printf("\n收费：%.2f（元）\n",cost);
	return cost;
}
double timedifference(ParkingSpace ps[10][10],SeqList*L,int i,int j,int* p,int *s,int vip)//时间差函数
{   double cost;
int a,b,c;
int year1,mon1,day1,h1, m1=0, s1;
int year2,mon2,day2,h2, m2=0, s2;
int year,mon,day;
year1=ps[i][j].NumberStartTime.year;
mon1=ps[i][j].NumberStartTime.mon;
day1=ps[i][j].NumberStartTime.day;
h1=ps[i][j].NumberStartTime.hour;
m1=ps[i][j].NumberStartTime.min;
s1=ps[i][j].NumberStartTime.sec;
year2=ps[i][j].NumberEndTime.year;
mon2=ps[i][j].NumberEndTime.mon;
day2=ps[i][j].NumberEndTime.day;
h2=ps[i][j].NumberEndTime.hour;
m2=ps[i][j].NumberEndTime.min;
s2=ps[i][j].NumberEndTime.sec;
if (h1 * 3600 + m1 * 60 + s1 < h2 * 3600 + m2 * 60 + s2)
{
	a = h2 - h1, b = m2 - m1, c = s2 - s1;
	if (c < 0)
	{
		c = 60 + c;
		b--;
	}
	if (b < 0)
	{
		b = b + 60;
		a--;
	}
}
else
{
	a = h1 - h2, b = m1 - m2, c = s1 - s2;
	if (c < 0)
	{
		c = 60 + c;
		b--;
	}
	if (b < 0)
	{
		b = b + 60;
		a--;
	}
}
if(year1>year2)
{
	year=year1-year2;
}
else
{
	year=year2-year1;

}
if(mon1>mon2)
{
	mon=mon1-mon2;
}
else
{
	mon=mon2-mon1;
}
if(day1>day2)
{
	day=day1-day2;
}
else
{
	day=day2-day1;
}
printf("%d小时%02d分%02d秒\n",a,b,c);
cost=Pay(ps,L,i,j,b,c,p ,s,vip);
return cost;
}
void VipCardRecharge(ParkingSpace ps[10][10],SeqList*L,int *s,int vip)//会员卡充值
{
	User user,x;
	int i,n=0,k;
	char K,A;
	double moneyplus;
	char MONEYPLUS[100000];
	char number[5];
	VIPReadFile(ps,L,s,vip);//读取会员 
	printf("\n选择编号：[0]返回菜单 [1]余额充值\n");
	printf("请输入数字：");
	scanf(" %c",&A);
	if(A=='0')
	{
		system("cls");
		menu(ps,L,s,vip);
	}
	else if(A=='1')
	{
		for(i=0;i<ListLength(*L);i++)
		{
			ListGet(*L,i,&x);
			printf("[%d] ",i);
			if(x.id==1)
			{
				printf("*VIP用户* ");
			}
			else
			{
				printf("*普通用户* ");
			}
			printf("车主姓名：%s  ",x.name);
			printf("汽车车牌：%s  ",x.LicensePlate);
			printf("电话号码：%s  ",x.phone);
			if(x.id==1)
			{
				printf("会员卡余额：%.2lf（元）",x.vipmoney);
			}
			printf("\n");
		}
		printf("请选择充值的账户：");
		scanf(" %c",&K);
		k=K-'0';
		ListGet(*L,k,&user);
		if(user.id==1)
		{
			printf("请输入会员卡号：");
			scanf("%s",number);
			for(i=0;i<5;i++)
			{
				if(strcmp(number,user.vipNumber)==0)
				{

					n=1;
				}

			}
			if(n==0)
			{
				printf("输入账号或密码有误！");
				ReturnMenu(ps,L,s,vip);
			}
			if(n==1)
			{  
				printf("请输入充值金额（元）：");
				scanf("%s",MONEYPLUS);
				moneyplus=atof(MONEYPLUS);
				user.vipmoney=user.vipmoney+moneyplus; 
				ListDelete(L,k,&x);
				ListInsert(L,k,user);
				CarWirteFile(ps,L,s,vip);//写文件
				printf("充值成功！\n");
			}
		}
		else
			printf("用户不是会员！\n");
		ReturnMenu(ps,L,s,vip);
	}
	else
	{
		printf("输入数字有误！\n");
		ReturnMenu(ps,L,s,vip);
	}
}
void ResetAndDelete(ParkingSpace ps[10][10],SeqList*L,int *s,int vip)//重置和删除
{
	User x,user;
	int a,i,k,m;
	char I,A,M;
	//Admin z;
//	Admin admin;
	char name[20],password[20];
	printf("请选择用户编号：");
	scanf(" %c",&I);
	i=I-'0';
	k=ListGet(*L,i,&x);
	if(k==0)
	{
		printf("输入有误！\n");
		ReturnMenu(ps,L,s,vip);
	}
	printf("请选择编号：[0]用户查询 [1]删除用户\n");
	printf("请输入数字：");
	scanf(" %c",&A);
	a=A-'0';
	if(a==0)
	{
		system("cls");
		UserInformationDisplay(ps,L,s,vip);
	}
	else if(a==1)
	{
		printf("数据删除后不可恢复！请慎重！\n");
		printf("再次确认是否删除用户：[0]是 [1]否\n");
		printf("请输入数字：");
		scanf(" %c",&M);
		m=M-'0';
		if(m==0)
		{
			printf("现在要确认管理员身份!\n");
			printf("账号：");
			scanf("%s",name);
			printf("密码：");
			scanf("%s",password);
			if((strcmp(name,admin.name)==0)&&(strcmp(password,admin.password)==0))
			{
				ListDelete(L,i,&user);
				printf("用户已删除！\n");
				ReturnMenu(ps,L,s,vip);
			}
			else
			{
				printf("验证管理员失败！无法进行本次操作！\n");
				ReturnMenu(ps,L,s,vip);
			}
		}
		else if(m==1)
		{
			//system("cls");
			ReturnMenu(ps,L,s,vip);
		}
		else
		{
			printf("输入数字有误！\n");
			ReturnMenu(ps,L,s,vip);
		}
	}
	else 
	{
		printf("输入数字有误！\n");
		ReturnMenu(ps,L,s,vip);
	}

}
void VIPregistration(ParkingSpace ps[10][10],SeqList*L,int* s,VIPcard vipcard[25],int vip)//会员注册
{
	int q=0;
	int i,m,r=0,a;
	char A,Number[100],Password[100];
	VIPReadFile(ps,L,s,vip);//读取会员 
	printf("******会员菜单******\n");

	printf("\n选择编号：[0]返回菜单 [1]会员注册\n");
	printf("请输入数字：");
	scanf(" %c",&A);
	a=A-'0';
	if(a==0)
	{
		system("cls");
		menu(ps,L,s,vip);
	}
	if(a==1)
	{
		for(i=0;i<25;i++)
		{
			if(vipcard[i].or==1)
				q=q+1;
		}
		if(q<=24)
			printf("会员名额还剩：%d 名\n",25-q);
		if(q>24)
		{
			printf("会员已满！无法注册！\n");
			ReturnMenu(ps,L,s,vip);
		}
		printf("账号：");
		scanf("%s",Number);
		//printf("密码：");
		//scanf("%s",Password);
		for(i=0;i<25;i++)
		{
			if(strcmp(Number,vipcard[i].Number)==0)
			{
				printf("会员已注册！请重新注册！\n");
				r=1;
				break;

			}
		}
		if(r==0)
		{
		strcpy(vipcard[q].Number,Number);
	//	
		vipcard[q].or=1;
	//	*s=*s+1;
		VIPWirteFile(ps,L,s,vip);//写入会员 
		printf("会员注册成功！\n");
		ReturnMenu(ps,L,s,vip);
		}
		if(r==1)
			ReturnMenu(ps,L,s,vip);
	}
	/*else if(A==2)
	{
		system("cls");
		//ChangePassword(ps,L,s,vip);
	}*/
	else
	{
		printf("输入数字有误！\n");
		ReturnMenu(ps,L,s,vip);
	}
}
/*void ChangePassword(ParkingSpace ps[10][10],SeqList*L,int* s,int vip)//改密码
{
	int i,m,r=0;
	char A;
	//VIPcard vipcard;
	char Number[100];
	char OldPassword[100];
	char NewPassword[100];
	VIPReadFile(ps,L,s,vip);//读取会员 
	printf("===修改密码===\n");
	printf("\n选择编号：[0]会员菜单 [1]修改密码\n");
	printf("请输入数字：");
	scanf(" %c",&A);
	if(A=='0')
	{
		system("cls");
		VIPregistration(ps,L,s,vipcard,vip);
	}
	if(A=='1')
	{
		printf("账号：");
		scanf("%s",Number);
		printf("旧密码：");
		scanf("%s",OldPassword);
		printf("新密码：");
		scanf("%s",NewPassword);

		for(i=0;i<25;i++)
		{
			if(strcmp(Number,vipcard[i].Number)==0)
			{
				m=i;
				r=1;
				break;
			}
		}
		if(r==0)
		{
			printf("输入账号或密码有误！\n");
			ReturnMenu(ps,L,s,vip);
		}
		if(r==1)
		{  
			if(strcmp(OldPassword,vipcard[m].Password)!=0)
			{
				printf("旧密码输入错误！\n");
				ReturnMenu(ps,L,s,vip);
			}
			for(i=0;NewPassword[i]!='\0';i++)
			{
				if((('0'>NewPassword[i])||('9'<NewPassword[i]))&&(('A'>NewPassword[i])||('Z'>NewPassword[i]))&&(('a'>NewPassword[i])||('z'<NewPassword[i])))
				{
					printf("输入非法字符！\n");
					ReturnMenu(ps,L,s,vip);
					break;

				}
				if(m==18)
				{
					printf("密码输入超过18位！");
					ReturnMenu(ps,L,s,vip);
					break;

				}
			}

			if(strcmp(NewPassword,vipcard[m].Password)==0)
			{
				printf("旧密码不能跟新密码相同！\n");
				ReturnMenu(ps,L,s,vip);
			}
			strcpy(vipcard[m].Password,NewPassword);
			printf("密码修改成功！\n");
		}
	}
	else
	{
		printf("输入数字有误！\n");
		ReturnMenu(ps,L,s,vip);
	}

}*/
void CarWirteFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip)//写入用户 
{
	int i=0;
	User x;
	char I[5],id[3],OR[3],money[100000],oneCoupon[5],twoCoupon[5],length[5],LicensePlate[30];
	FILE *fp=fopen("user.txt","w");/*以写模式("w")打开文件user.txt,如果不存在,会自动创建*/
    itoa(ListLength(*L),length,10);
	fputs("用户人数\n",fp);
	strcat(length,"\n");
	fputs(length,fp);//表的长度 
	for(i=0;i<ListLength(*L);i++)
	{
		ListGet(*L,i,&x);
		itoa(i,I,10);
		itoa(x.id,id,10);
		itoa(x.OR,OR,10);
		itoa(x.oneCoupon,oneCoupon,10);
		itoa(x.twoCoupon,twoCoupon,10);
		itoa(x.vipmoney,money,10);
		strcat(I,"\n");
		strcat(id,"\n");
		strcat(OR,"\n");
		strcat(x.name,"\n");
		strcpy(LicensePlate,x.LicensePlate);
		strcat(LicensePlate,"\n");
		strcat(x.vipNumber,"\n");
	//	strcat(x.vipPassword,"\n");
		strcat(money,"\n");
		strcat(x.phone,"\n");
		strcat(oneCoupon,"\n");
		strcat(twoCoupon,"\n");
		fputs("编号\n",fp);//编号 
		fputs(I,fp);//编号 
		fputs("身份信息\n",fp);
		fputs(id,fp);//身份信息
		fputs("停车状况\n",fp);
		fputs(OR,fp);//停车状况
		if(x.id==0)
			fputs("普通用户\n",fp);
		if(x.id==1)
		    fputs("会员用户\n",fp);
		fputs("姓名\n",fp);    
		fputs(x.name,fp);//姓名 
		fputs("车牌\n",fp);    
		fputs(LicensePlate,fp);//车牌
		if(x.id==1)
		{	
		    fputs("会员卡账号\n",fp);
			fputs(x.vipNumber,fp);//会员卡账号
		//	fputs("会员卡密码\n",fp);
		//	fputs(x.vipPassword,fp);//会员卡密码
			fputs("会员卡余额\n",fp);
			fputs(money,fp);//会员卡余额
			
		}
		fputs("电话号码\n",fp);
		fputs(x.phone,fp);//电话
		fputs("一元优惠券\n",fp);
		fputs(oneCoupon,fp);//一元优惠券 
		fputs("二元优惠券\n",fp);
		fputs(twoCoupon,fp);//二元优惠券 
	    fputs("\n",fp);//换行 

	}
//printf("写入成功！\n");
fclose(fp);//关闭文件
	//ReturnMenu(ps,L,s,vip);
}
void VIPWirteFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip)//写入会员 
{
	int i;
	char or[3],number[100],I[5];
	//VIPcard vipcard[25];
	FILE *fp=fopen("vip.txt","w");//以写模式("w")打开文件user.txt,如果不存在,会自动创建
	
//	fputs(length,fp);//表的长度 
	//fputs("\n",fp); 
	for(i=0;i<25;i++)
	{   
		if(vipcard[i].or==1)

	{	//itoa(i,I,10);
		//strcat(I,"\n");
	      //fputs("\n",fp);//
		// fputs(I,fp);//
		itoa(vipcard[i].or,or,10);
	      strcat(or,"\n");
		  strcpy(number,vipcard[i].Number);
		strcat(number,"\n");
		 fputs("会员状态\n",fp);//
		fputs(or,fp);//注册会员后变为1
		 fputs("会员账号\n",fp);//
	    fputs(number,fp);//vip账号
		  //fputs(' ',fp);//v
		}	
		else
		{
			 fputs("会员状态\n",fp);//
			 fputs("未激活\n",fp);//
			//  fputs(' ',fp);//
		}
		

	}
//printf("写入成功！\n");
fclose(fp);//关闭文件
	//ReturnMenu(ps,L,s,vip);
}
void PSWirteFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip)//写入车位 
{
	int i,j;
	char or[3],orvip[3],oneCoupon[5],twoCoupon[5],Syear[7],Smon[7],Sday[7],Shour[7],Smin[7],Ssec[7],name[20],LicensePlate[30],phone[20];//Eyear[7],Emon[7],Eday[7],Ehour[7],Emin[7],Esec[7];
	//VIPcard vipcard[25];
	FILE *fp=fopen("ps.txt","w");//以写模式("w")打开文件user.txt,如果不存在,会自动创建
	
//	fputs(length,fp);//表的长度 
	//fputs("\n",fp); 
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			
			if(ps[i][j].or==1||ps[i][j].or==2)
			{
			 itoa(ps[i][j].or,or,10);//车位是否有车
			 strcat(or,"\n");
			 itoa(ps[i][j].orvip,orvip,10);//车主是否为vip
			 strcat(orvip,"\n");
			 itoa(ps[i][j].oneCoupon,oneCoupon,10);//
			 itoa(ps[i][j].twoCoupon,twoCoupon,10);//
			 itoa(ps[i][j].NumberStartTime.year,Syear,10);//
			 itoa(ps[i][j].NumberStartTime.mon,Smon,10);//
			 itoa(ps[i][j].NumberStartTime.day,Sday,10);//
			 itoa(ps[i][j].NumberStartTime.hour,Shour,10);//
			 itoa(ps[i][j].NumberStartTime.min,Smin,10);//
			 itoa(ps[i][j].NumberStartTime.sec,Ssec,10);//
			 strcat(oneCoupon,"\n");
			 strcat(twoCoupon,"\n");
			 strcpy(name,ps[i][j].name);
			  strcpy(LicensePlate,ps[i][j].LicensePlate);
			   strcpy(phone,ps[i][j].phone);
			strcat(name,"\n");//车主姓名
			 strcat(LicensePlate,"\n");//车牌
			 strcat(phone,"\n");//电话号码
			strcat(Syear,"\n");
			strcat(Smon,"\n");
			strcat(Sday,"\n");
			strcat(Shour,"\n");
			strcat(Smin,"\n");
			strcat(Ssec,"\n");
			fputs("车位信息\n",fp);//
			fputs(or,fp);//
			fputs("用户身份\n",fp);//
			fputs(orvip,fp);//
			fputs("用户姓名\n",fp);//
			fputs(name,fp);//
			fputs("车牌\n",fp);//
			fputs(LicensePlate,fp);//
			fputs("电话号码\n",fp);//
            fputs(phone,fp);//
			fputs("入库时间\n",fp);//
			fputs(Syear,fp);//
			fputs(Smon,fp);//
			fputs(Sday,fp);//
			fputs(Shour,fp);//
			fputs(Smin,fp);//
			fputs(Ssec,fp);//
			fputs("一元优惠券\n",fp);//
			fputs(oneCoupon,fp);//
			fputs("二元优惠券\n",fp);//
			fputs(twoCoupon,fp);
			fputs("\n",fp);
			
			}
			/*else if(ps[i][j].or==2)
			{
			itoa(ps[i][j].or,or,10);//车位是否有车
			 strcat(or,"\n");
			 itoa(ps[i][j].orvip,orvip,10);//车主是否为vip
			 strcat(orvip,"\n");
			 itoa(ps[i][j].oneCoupon,oneCoupon,10);//
			 itoa(ps[i][j].twoCoupon,twoCoupon,10);//
			 itoa(ps[i][j].NumberStartTime.year,Syear,10);//
			 itoa(ps[i][j].NumberStartTime.mon,Smon,10);//
			 itoa(ps[i][j].NumberStartTime.day,Sday,10);//
			 itoa(ps[i][j].NumberStartTime.hour,Shour,10);//
			 itoa(ps[i][j].NumberStartTime.min,Smin,10);//
			 itoa(ps[i][j].NumberStartTime.sec,Ssec,10);//
			/* itoa(ps[i][j].NumberEndTime.year,Eyear,10);//
			 itoa(ps[i][j].NumberEndTime.mon,Emon,10);//
			 itoa(ps[i][j].NumberEndTime.day,Eday,10);//
			 itoa(ps[i][j].NumberEndTime.hour,Ehour,10);//
			 itoa(ps[i][j].NumberEndTime.min,Emin,10);//
			 itoa(ps[i][j].NumberEndTime.sec,Esec,10);//
			 
			 strcat(oneCoupon,"\n");
			strcat(twoCoupon,"\n");
			 strcat(oneCoupon,"\n");
			 strcat(twoCoupon,"\n");
			 strcpy(name,ps[i][j].name);
			  strcpy(LicensePlate,ps[i][j].LicensePlate);
			   strcpy(phone,ps[i][j].phone);
			strcat(name,"\n");//车主姓名
			 strcat(LicensePlate,"\n");//车牌
			 strcat(phone,"\n");//电话号码
			strcat(Syear,"\n");
			strcat(Smon,"\n");
			strcat(Sday,"\n");
			strcat(Shour,"\n");
			strcat(Smin,"\n");
			strcat(Ssec,"\n");
			/*strcat(Eyear,"\n");
			strcat(Emon,"\n");
			strcat(Eday,"\n");
			strcat(Ehour,"\n");
			strcat(Emin,"\n");
			strcat(Esec,"\n");
			
			fputs(or,fp);//
			fputs(orvip,fp);//
			fputs(name,fp);//
			fputs(LicensePlate,fp);//
            fputs(phone,fp);//
			fputs(Syear,fp);//
			fputs(Smon,fp);//
			fputs(Sday,fp);//
			fputs(Shour,fp);//
			fputs(Smin,fp);//
			fputs(Ssec,fp);//
			fputs(Eyear,fp);//
			fputs(Emon,fp);//
			fputs(Eday,fp);//
			fputs(Ehour,fp);//
			fputs(Emin,fp);//
			fputs(Esec,fp);//
			
			fputs(oneCoupon,fp);//
			fputs(twoCoupon,fp);
			fputs("\n",fp);
			
			}*/
			if(ps[i][j].or==0)
			{
				itoa(ps[i][j].or,or,10);//车位是否有车
			    strcat(or,"\n");
				fputs("车位信息\n",fp);//
				fputs(or,fp);//
				fputs("\n",fp);
			}
		}
	}
//printf("写入成功！\n");
fclose(fp);//关闭文件
	//ReturnMenu(ps,L,s,vip);
}
void CarReadFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip)//读取用户 
{
	int i,length;
	int flen=0;
	User user;
	char Length[5],id[3],OR[3],a[100],oneCoupon[10],twoCoupon[10],money[100000];
    FILE *fp=fopen("user.txt","r");//以读模式("r")打开文件user.txt
 if(fp==NULL)  //打开文件
   {
	   printf("**EORRO**\n");
       printf("没有找到user.txt文件\n");
	   printf("请在C文件所在目录下创建user.txt文件,再运行本程序！\n");
	   system("pause");
	   exit(0);
	   
    }
      fseek(fp,0,SEEK_END);//到文件结尾
      flen=ftell(fp);//获取文件大小
      fseek(fp,0,SEEK_SET);//返回到文件头
if(flen==0)
{
//	printf("文件内无数据无法进行读取！\n"); 
} 
else
{
	
	//printf("文件可读！\n");
	fscanf(fp,"%s",a);
	fscanf(fp,"%s",Length);
	sscanf( Length, "%d", &length ); 
	for(i=0;i<length;i++)
	{	
	fscanf(fp,"%s",a);//编号 
	fscanf(fp,"%s",a);//0
	fscanf(fp,"%s",a);//身份信息  
	fscanf(fp,"%s",id);//0 
	fscanf(fp,"%s",a);//停车状况  
    fscanf(fp,"%s",OR);//0 
    fscanf(fp,"%s",a);//普通用户 
	fscanf(fp,"%s",a);//姓名 
	fscanf(fp,"%s",user.name);//xxx 
	fscanf(fp,"%s",a);//车牌
	fscanf(fp,"%s",user.LicensePlate);//xxx
	if(strcmp(id,"1")==0)
	{
			fscanf(fp,"%s",a);//会员卡账号 
			fscanf(fp,"%s",user.vipNumber);//xxx 
		//	fscanf(fp,"%s",a);//会员卡密码 
			//fscanf(fp,"%s",user.vipPassword);//xxx 
			fscanf(fp,"%s",a);//会员卡余额 
			fscanf(fp,"%s",money);//xxx
	}
	fscanf(fp,"%s",a);//电话号码
	fscanf(fp,"%s",user.phone);//xxx
	fscanf(fp,"%s",a);//一元优惠券 
	fscanf(fp,"%s",oneCoupon);//xxx
	fscanf(fp,"%s",a);//二元优惠券 
	fscanf(fp,"%s",twoCoupon);//xxx
//	fscanf(fp,"%s",a);//换行 
   // strcpy(user.id,id);
    sscanf( id, "%d", &user.id ); 
    sscanf( OR, "%d", &user.OR ); 
    sscanf( oneCoupon, "%d", &user.oneCoupon ); 
    sscanf( twoCoupon, "%d", &user.twoCoupon ); 
    user.vipmoney=atof(money);
	//ListDelete(L,i,&x);
    ListInsert(L,i,user);
	}
}
fclose(fp); //关闭文件
	//ReturnMenu(ps,L,s,vip);
}
void VIPReadFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip)//读取会员 
{
	int i;
//	User user;
	char or[10],a[200];
	int flen;
    FILE *fp=fopen("vip.txt","r");//以读模式("r")打开文件user.txt
 if(fp==NULL)  //打开文件
    {
       printf("**EORRO**\n");
       printf("没有找到vip.txt文件\n");
	   printf("请在C文件所在目录下创建vip.txt文件,再运行本程序！\n");
	   system("pause");
	   exit(0);
    }
fseek(fp,0,SEEK_END);//到文件结尾
flen=ftell(fp);//获取文件大小
fseek(fp,0,SEEK_SET);//返回到文件头
if(flen==0)
{
//	printf("文件内无数据无法进行读取！\n"); 
} 
else
{
	for(i=0;i<25;i++)
	{
		 //   fscanf(fp,"%s",a);
          //  fscanf(fp,"%s",a);
			fscanf(fp,"%s",a);
			fscanf(fp,"%s",or);//注册会员后为1
			sscanf(or, "%d", &vipcard[i].or ); 
			if(vipcard[i].or==1)
		    { 
				fscanf(fp,"%s",a);
				fscanf(fp,"%s",vipcard[i].Number);//会员卡账号 
				//fscanf(fp,"%s",a);
			}
			else
			{
				fscanf(fp,"%s",a);
				fscanf(fp,"%s",a);
				
			}
			
			
    }
      fclose(fp); //关闭文件
	//ReturnMenu(ps,L,s,vip);
}
}
void PSReadFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip)//读取车位
{
	int i,j,k;
	int flen=0;
	User user;
	char a[3],or[5],orvip[3],oneCoupon[10],twoCoupon[10],b[100],name[20],LicensePlate[20],phone[20];
    FILE *fp=fopen("ps.txt","r");//以读模式("r")打开文件user.txt
 if(fp==NULL)  //打开文件
   {
	   printf("**EORRO**\n");
       printf("没有找到ps.txt文件\n");
	   printf("请在C文件所在目录下创建ps.txt文件,再运行本程序！\n");
	   system("pause");
	   exit(0);
	   
    }
      fseek(fp,0,SEEK_END);//到文件结尾
      flen=ftell(fp);//获取文件大小
      fseek(fp,0,SEEK_SET);//返回到文件头
if(flen==0)
{
//	printf("文件内无数据无法进行读取！\n"); 
} 
else
{
	
	//printf("文件可读！\n");
	
	for(i=0;i<5;i++)
	{	
		for(j=0;j<5;j++)
		{
			fscanf(fp,"%s",b);// 
			fscanf(fp,"%s",or);// 
			sscanf( or, "%d", &ps[i][j].or ); 
			if(ps[i][j].or==0)
			{
				//fscanf(fp,"%s",a);//xxx
			}
			if(ps[i][j].or==1)
			{
				fscanf(fp,"%s",b);// 
				fscanf(fp,"%s",orvip);//
				fscanf(fp,"%s",b);// 
			    fscanf(fp,"%s",ps[i][j].name);//
				fscanf(fp,"%s",b);// 
				fscanf(fp,"%s",ps[i][j].LicensePlate);//
				fscanf(fp,"%s",b);// 
				fscanf(fp,"%s",ps[i][j].phone);//
				fscanf(fp,"%s",b);// 
				fscanf(fp,"%s",ps[i][j].StringStartTime.year);//
				fscanf(fp,"%s",ps[i][j].StringStartTime.mon);//
				fscanf(fp,"%s",ps[i][j].StringStartTime.day);//
				fscanf(fp,"%s",ps[i][j].StringStartTime.hour);//
				fscanf(fp,"%s",ps[i][j].StringStartTime.min);//
				fscanf(fp,"%s",ps[i][j].StringStartTime.sec);//
				sscanf( ps[i][j].StringStartTime.year, "%d", &ps[i][j].NumberStartTime.year ); 
				sscanf(  ps[i][j].StringStartTime.mon, "%d", &ps[i][j].NumberStartTime.mon ); 
				sscanf(  ps[i][j].StringStartTime.day, "%d", &ps[i][j].NumberStartTime.day ); 
				sscanf( ps[i][j]. StringStartTime.hour, "%d", &ps[i][j].NumberStartTime.hour ); 
				sscanf(  ps[i][j].StringStartTime.min, "%d", &ps[i][j].NumberStartTime.min ); 
				sscanf(  ps[i][j].StringStartTime.sec, "%d", &ps[i][j].NumberStartTime.sec ); 
				fscanf(fp,"%s",b);// 
				fscanf(fp,"%s",oneCoupon);//xxx
				fscanf(fp,"%s",b);// 
				fscanf(fp,"%s",twoCoupon);//xxx
				//fscanf(fp,"%s",a);//xxx
				sscanf(orvip, "%d", &ps[i][j].orvip ); 
				sscanf(oneCoupon, "%d", &ps[i][j].oneCoupon ); 
				sscanf(twoCoupon, "%d", &ps[i][j].twoCoupon ); 

			} 
		}
	
	}
}
fclose(fp); //关闭文件
	//ReturnMenu(ps,L,s,vip);
}
void menu(ParkingSpace ps[10][10],SeqList*L,int* s,int vip)//菜单
{
	int i;
	char I;
	VIPReadFile(ps,L,s,vip);//读取会员 
	
	printf("==================功能菜单==================\n");
	
	printf("      [1]车辆进库登记  [2]空余车位查询\n");
	
	printf("      [3]获取车位信息  [4]退出车位\n");
	
	printf("      [5]用户信息查询  [6]会员卡充值\n");

	printf("      [7]会员注册      [8]退出程序\n");
	
//	printf("      [0]退出程序\n");
	
	printf("===========================================\n");
	
	printf("      请输入命令编号：");
	scanf(" %c",&I);
	i=I-'0';
	switch(i)
	{
	/*case 0:
		{
			system("cls");
			
			printf("程序已关闭！\n");
			exit(0);
		}break;*/
	case 1:
		{
			system("cls");
			CarInformationRegistration(ps,L,s,vip);	
		}break;
	case 2:
		{
			system("cls");
			CarInquire(ps,L,s,vip);
		}break;
	case 3:
		{
			system("cls");
			GetCar(ps,L,s,vip);
		}break;
	case 4:
		{
			system("cls");
			CarOut(ps,L,s,vip);
		}break;
	case 5:
		{
			system("cls");
			UserInformationDisplay(ps,L,s,vip);
		}break;
	case 6:
		{
			system("cls");
	        VipCardRecharge(ps,L,s,vip);
		}break;
	case 7:
		{
			system("cls");
				VIPregistration(ps,L,s,vipcard,vip);//会员注册
		}break;
	case 8:
		{
		 system("cls");	
			printf("程序已关闭！\n");
			exit(0);
		}break;

	default:
	{
		
		printf("输入数字有误！\n");
		ReturnMenu(ps,L,s,vip);
	}
  }
}
#endif
