#ifndef _MENU_H
#define _MENU_H
typedef struct VipCard
{
	char Number[100];      //����
	//char Password[100];    //����
	double money;  //���
	int or;//ע����Ϊ1
}VIPcard;

typedef struct User         //������Ϣ
{
	char name[10];          //��������
	char phone[12];         //�ֻ���
	char LicensePlate[30];//����
	int id;   //���,1��VIP,0����ͨ�û�
	//VIPcard vipcard;
	int OR;                 //�Ƿ��Ѿ�ͣ��
	//int caror;//�Ƿ����״�ͣ����0�ǣ�1����
	char vipNumber[100];      //����
//	char vipPassword[100];    //����
	double vipmoney;           //���
	int oneCoupon;         //һԪ�Ż�ȯ
	int twoCoupon;         //��Ԫ�Ż�ȯ
}User;   //�û�
VIPcard vipcard[25]={
	{"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},
	{"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},
	{"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},
	{"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},
	{"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},
	
};
struct StringCarTime//ʱ����ַ���ʾ
{
	char year[5];
	char mon[3];
	char day[3];
	char hour[3];
	char min[3];
	char sec[3];
};
struct NumberCarTime//ʱ���������ʾ
{
	int year;
	int mon;
	int day;
	int hour;
	int min;
	int sec;
};
typedef struct ParkingSpace //��λ��Ϣ
{
	int or;                  //�Ƿ��г�
	int orvip;
	char name[10];           //����
	char phone[12];          //�绰
	char LicensePlate[10];   //����
	struct tm * tStartTime;    //����ʱ��
	struct tm * tEndTime;     //����ʱ��
	struct StringCarTime StringStartTime;
	struct StringCarTime StringEndTime;
	struct NumberCarTime NumberStartTime;
	struct NumberCarTime NumberEndTime;
	int oneCoupon;         //һԪ�Ż�ȯ
	int twoCoupon;         //��Ԫ�Ż�ȯ
}ParkingSpace; //��λ
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
		printf("˳��������޷����룡\n");
		return 0;
	}
	else if(i<0||i>L->size)
	{
		//printf("����i���Ϸ���\n");
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
		printf("˳����ѿ�������Ԫ�ؿ�ɾ��\n");
		return 0;
	}
	else if(i<0||i>L->size-1)
	{
		//printf("����i���Ϸ���\n");
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
		printf("����i���Ϸ���\n");
		return 0;
	}

	else
	{
		*x=L.list[i];
		return 1; 
	}
} 

void login(ParkingSpace ps[][10],SeqList*L,int *s,int vip);//��¼
void CarInquire(ParkingSpace ps[][10],SeqList*L,int *s,int vip);//���೵λ��ѯ
void GetCar(ParkingSpace ps[][10],SeqList*L,int *s,int vip);//��ȡ������Ϣ
void CarOut(ParkingSpace ps[][10],SeqList*L,int *s,int vip);//�����˳���λ
void CarIn(ParkingSpace ps[][10],SeqList *L,int i,int j,int m);//��������
void CarInformationRegistration(ParkingSpace ps[10][10],SeqList*L,int *s,int vip);//������Ϣ�Ǽ�
void UserInformationDisplay(ParkingSpace ps[10][10],SeqList*L,int *s,int vip);//��������Ǽ�
void menu(ParkingSpace ps[10][10],SeqList*L,int *s,int vip);//�˵�
void ReturnMenu(ParkingSpace ps[10][10],SeqList*L,int *s,int vip);//���ز˵�����
void CarDisplay(ParkingSpace ps[10][10],SeqList*L,int *s,int vip);//��λ��ʾ
void PaymentEnquiry(ParkingSpace ps[10][10],SeqList*L,int i,int j,int *s,int vip);//�����ѯ
void itoaStartTime(ParkingSpace ps[10][10],SeqList*L,int i,int j);//����ʱ���ȡ
void itoaEndTime(ParkingSpace ps[10][10],SeqList*L,int i,int j);//����ʱ���ȡ
double timedifference(ParkingSpace ps[10][10],SeqList*L,int i,int j,int* p,int *s,int vip);//ʱ����
double Pay(ParkingSpace ps[10][10],SeqList*L,int i,int j,int b,int c,int* q,int *s, int vip);//�Ʒ�˵��
void VipCardRecharge(ParkingSpace ps[10][10],SeqList*L,int *s,int vip);//��Ա����ֵ
void ResetAndDelete(ParkingSpace ps[10][10],SeqList*L,int *s,int vip);//���ú�ɾ��
void VIPregistration(ParkingSpace ps[10][10],SeqList*L,int* a,VIPcard vipcard[25],int vip);//��Աע��
void ChangePassword(ParkingSpace ps[10][10],SeqList*L,int* s,int vip);//�޸�����
void CarWirteFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip);//д���û� 
void CarReadFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip);//��ȡ�û� 
void VIPReadFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip);//��ȡ��Ա 
void VIPWirteFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip);//д���Ա 
void PSWirteFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip);//д�복λ 
void PSReadFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip);//��ȡ��λ 



void login(ParkingSpace ps[][10],SeqList*L,int *s,int vip)//��¼
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
	//FILE *fp=fopen("user.txt","w");/*��дģʽ("w")���ļ�user.txt,���������,���Զ�����*/
	CarReadFile(ps,L,s,vip);
	VIPReadFile(ps,L,s,vip);//��ȡ��Ա 
	PSReadFile(ps,L,s,vip);
	 //printf("asdasdasdasd");
		while(i<3)
	{	
		printf(" ===========================\n");
	    
		printf("��       **��ӭʹ��**      ��\n");
		
		printf("��       ͣ������ϵͳ      ��\n");
		
		printf(" ===========================\n");
		
		printf("��       ����Ա��½        ��\n");
		
		printf("��     �������˺ź�����    ��\n");
		
		printf(" ===========================\n");
		
		printf("����%d�δ����Զ���������\n",3-i);
		
		printf("�˺ţ�");
		scanf("%s",name);
		
		printf("���룺");
		scanf("%s",password);
		if(strcmp(name,admin.name)==0&&strcmp(password,admin.password)==0)
		{
		
			printf("*��½�ɹ�*");
		system("cls");
			i=4;
			menu(ps,L,s,vip);
			break;
		}
		else
		{
			
			printf("������˺Ż��������\n");
			//printf("\033c");
			system("cls");

		}
		i++;
		if(i==3)
		{
			
			printf("�����ѹرգ�\n");
			exit(0);
			//break;
		}
	}
}


void  CarDisplay(ParkingSpace ps[10][10],SeqList*L,int *s,int vip)
{
	int i,j;
	
	printf("================================================================\n");
	
	printf("*                             ��λ                            *\n");
	
	printf("================================================================\n");
	
	printf("                           *��Ա��λ*\n");
	
	printf("\n");
	//printf("                            ");
	for(i=0;i<vip;i++)
	{
		for(j=0;j<5;j++)
		{	

			if(ps[i][j].or==1)
			{
				
				printf(" [%d][%d]�г�  ",i+1,j+1);
			}
			else
			{   
				printf(" [%d][%d]�޳�  ",i+1,j+1);
			}

		}
		
		printf("\n");
	}
	
	printf("\n");
	
	printf("                           *��ͨ��λ*\n");
	printf("\n");
	for(i=vip;i<5;i++)
	{
		
		for(j=0;j<5;j++)
		{	 
			if(ps[i][j].or==1)
			{
				printf(" [%d][%d]�г�  ",i+1,j+1);
			}
			else
			{
				printf(" [%d][%d]�޳�  ",i+1,j+1);
			}

		}
		printf("\n");
	}
}
void CarInquire(ParkingSpace ps[][10],SeqList*L,int *s,int vip)//��λ��ѯ
{
	int i,j,n=0,m,r=0,q=0;
	
	char k,M,I,J;
	User user,x;
	while(1)
	{
		CarDisplay(ps,L,s,vip);
		printf("ѡ���ţ�[0]���ز˵� [1]��λѡ��\n");
		printf("���������֣�");
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
			printf("�����������������룡\n");
		}
	}
	if(k=='0')
		menu(ps,L,s,vip);
	if(k=='1')
	{
		CarDisplay(ps,L,s,vip);
		printf("****�ȴ�ͣ���û�****\n");
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
					printf("*VIP�û�* ");
				}
				else
				{
					printf("*��ͨ�û�* ");
				}
				printf("[%d] ",i);
				printf("����������%s",x.name);
				printf("�������ƣ�%s ",x.LicensePlate);
				printf("�绰���룺%s ",x.phone);
				printf("\n");
				//n=0;
				
				//break;
			}
			   if(n==0)
		{
			
			printf("�����ţ�");
			scanf("%d",&m); 
			if(ListGet(*L,m,&user)==0)
			{
				printf("������������\n");
				ReturnMenu(ps,L,s,vip);
			}
			if(user.OR==1)
			{
				
				printf("������������\n");
				ReturnMenu(ps,L,s,vip);
			}
			
			printf("ѡ��ͣ��λ��ţ�\n");
			
			printf("�ţ�");
			scanf(" %c",&I);
			i=I-'0';
			
			printf("�У�");
			scanf(" %c",&J);
			j=J-'0';
			if((i<=5&&i>=1)&&(j<=5&&j>=1))
			{  
				if(user.id==0&&i<=vip&&j<=5)
				{
					
					printf("�㲻��VIP�û����޷�ʹ��VIP��λ��\n");
				} 
				else
				{
					if(ps[i-1][j-1].or!=1)
					{
						CarIn(ps,L,i-1,j-1,m);
						
						printf("ͣ���ɹ���\n");
						ListDelete(L,m,&user);
						user.OR=1;
						ListInsert(L,m,user);
						PSWirteFile(ps,L,s,vip);//д�복λ 
						CarWirteFile(ps,L,s,vip);
					}
					else
					{
						
						printf("�ó�λ���г���ͣ�ţ�������ѡ��λ��\n");
					}
				}
			}else
			{
				
				printf("����ĳ�λ����");
				ReturnMenu(ps,L,s,vip);
			}
		}
			//r=r+1;
			if(i==ListLength(*L))
			{

				//n=1;
				printf("�޷��ҵ���ͣ���û���\n");
                 ReturnMenu(ps,L,s,vip);
			}
				
		}	  

		
		/*if(==1)
		{
				
			
		}*/

		
	}

}
void GetCar(ParkingSpace ps[][10],SeqList*L,int *s,int vip)//��ȡ������Ϣ
{
	int i,j,a;
	
	char I,J,A;
	CarDisplay(ps,L,s,vip);
	
	printf("ѡ���ţ�[0]���ز˵� [1]��ȡ��Ϣ\n");
	
	printf("���������֣�");
	scanf(" %c",&A);
	a=A-'0';
	if(a==0)
	{   system("cls");
	menu(ps,L,s,vip);
	}
	else if(a==1)
	{
	
		printf("���복λ�Ż�ȡ������Ϣ��\n");
		printf("\n");
		printf("�ţ�");
		scanf(" %c",&I);
		i=I-'0';
		printf("�У�");
		scanf(" %c",&J);
		j=J-'0';
		printf("\n");
		if((i<=5&&i>=1)&&(j<=5&&j>=1))
		{
if(ps[i-1][j-1].or==1)
		{
			printf("������Ϣ\n");
			if(ps[i-1][j-1].orvip==1)
			{
				printf("*VIP�û�* \n");
			}
			else
			{
				printf("*��ͨ�û�* \n");
			}
			printf("����������%s\n",ps[i-1][j-1].name);
			printf("���ƣ�%s\n",ps[i-1][j-1].LicensePlate);
			printf("�����绰���룺%s\n",ps[i-1][j-1].phone);
			ReturnMenu(ps,L,s,vip);
		}
		else
		{
			printf("�˳�λû��ͣ�����޷���ȡ������Ϣ��\n");
			ReturnMenu(ps,L,s,vip);
		}	
		
		}
		else
		{
			printf("���복λ����\n");
			ReturnMenu(ps,L,s,vip);
		}
	}

	else
	{
		printf("������������\n");
		ReturnMenu(ps,L,s,vip);
	}
}
void CarOut(ParkingSpace ps[][10],SeqList*L,int *s,int vip)//�����˳���λ
{
	int i,j,m=0,n,k;
	char I,J,A;
	time_t t; 
	User user,x;
	CarDisplay(ps,L,s,vip);
	printf("\nѡ���ţ�[0]���ز˵� [1]�˳���λ\n");
	printf("���������֣�\n");
	scanf(" %c",&A);
	if(A=='0')
	{
		system("cls");
		menu(ps,L,s,vip);
	}
	else if(A=='1')
	{
		printf("ѡ��λ�˳�����\n");
		printf("\n");
		printf("�ţ�");
		scanf(" %c",&I);
		i=I-'0';
		printf("�У�");
		scanf(" %c",&J);
		j=J-'0';
		printf("\n");
		if((i<=5&&i>=1)&&(j<=5&&j>=1))
		{
			if(ps[i-1][j-1].or==1)
			{
				//ps[i-1][j-1].or=2;
				time (&t);//��ȡUnixʱ�����
				ps[i-1][j-1].tEndTime= localtime (&t);//תΪʱ��ṹ��
				itoaEndTime(ps,L,i-1,j-1);
				//m=i,n=j;
				if(ListLength(*L)==0)
				{
					printf("�û�����Ϊ0\n");
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
					    printf("�����ɹ��Ƴ���λ��\n");
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
						printf("û���복λ��Ϣ���Ӧ���û���\n");
						ReturnMenu(ps,L,s,vip);
					}
				 }
			}
			else
			{
				printf("�ó�λû�г���ͣ��!�޷����в�����\n");
				ReturnMenu(ps,L,s,vip);
			}
			
		}
		else
		{
			printf("����ĳ�λ����\n");
			ReturnMenu(ps,L,s,vip);
		}
	}
	else
	{
		printf("������������!\n");
		ReturnMenu(ps,L,s,vip);
	}
}
void CarIn(ParkingSpace ps[][10],SeqList *L,int i,int j,int m)//��������
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
	time (&t);//��ȡUnixʱ�����
	ps[i][j].tStartTime= localtime (&t);//תΪʱ��ṹ��
	itoaStartTime(ps,L,i,j);
}

void CarInformationRegistration(ParkingSpace ps[10][10],SeqList*L,int *s,int vip)//������Ϣ�Ǽ�
{
	User user[25],x;
	int i,j,k,m,r=0,n;
	char J,A;
	char number[100];
	char password[100];
	VIPReadFile(ps,L,s,vip);//��ȡ��Ա 
 	i=ListLength(*L);
	
	printf(" ===========================\n");
	
	printf("��       ͣ����Ϣ�Ǽ�      ��\n");
	
	printf(" ===========================\n");
	
	printf("ѡ���ţ�[0]���ز˵� [1]��Ϣ�Ǽ�\n");
   
	printf("���������֣�");
	scanf(" %c",&A);
	if(A=='0')
	{
		system("cls");
		menu(ps,L,s,vip);
	}		
	else if(A=='1')
	{
		
		printf("����������");
		scanf("%s",user[i].name);
		
		printf("���복�ƣ�");
		scanf("%s",user[i].LicensePlate);
		
		printf("����绰��");
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
					
					printf("�ò������Ϸ���\n");
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
			CarWirteFile(ps,L,s,vip);//д�ļ�
			printf("*��ӭ���ٴι��٣�*\n");
			ReturnMenu(ps,L,s,vip);
		}
		if(r==2)
			//user[i].caror=0;
		{	        
		user[i].OR=0;
		user[i].oneCoupon=4;
		user[i].twoCoupon=2;
		
		printf("�Ƿ�ΪVIP�û�:��[0] ��[1]\n");
		
		printf("���������֣�");
		scanf(" %c",&J);
		j=J-'0';
		if(j==0)
		{
			
			printf("�������Ա���˺ţ�");
			scanf("%s",number);
			
		//	printf("���������룺");
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
				printf("�����˺�����\n");
				
				ReturnMenu(ps,L,s,vip);
			}
		}
		else if(j==1)
		{
			user[i].id=0;
			
		}
		else
		{
			
			printf("������������\n");
			ReturnMenu(ps,L,s,vip);
		}
		   ListInsert(L,i,user[i]);	
		   CarWirteFile(ps,L,s,vip);//д�ļ�
		if(user[i].id==1)
		{
			
			printf("��Ϣ�Ǽǳɹ���\n");
			
		    printf("�״εǼ���Ϣ����4��һԪ�Ż�ȯ��2�Ŷ�Ԫ�Ż�ȯ��\n");
		}
		else
		{
			
			printf("��Ϣ�Ǽǳɹ���\n");
			
		    printf("�״εǼ���Ϣ����4��һԪ�Ż�ȯ��2�Ŷ�Ԫ�Ż�ȯ��\n");
		}
		ReturnMenu(ps,L,s,vip);
		}
	}
	else
	{  
		printf("������������\n");
		ReturnMenu(ps,L,s,vip);
	}

}
void UserInformationDisplay(ParkingSpace ps[10][10],SeqList*L,int *s,int vip)//�û���Ϣ��ѯ
{
	int i,a;
	char A,B;
	User x;
	VIPReadFile(ps,L,s,vip);//��ȡ��Ա 
	printf("\nѡ���ţ�[0]���ز˵� [1]��Ϣ��ѯ\n");
	printf("���������֣�");
	scanf(" %c",&B);
	if(B=='0')
	{
		system("cls");
		menu(ps,L,s,vip);
	}
	else if(B=='1')
	{
		printf("�û���Ϣ��ѯ\n");
		if(ListLength(*L)==0)
		{
			printf("û���û��Ǽ�!\n");
			ReturnMenu(ps,L,s,vip);
		}
		for(i=0;i<ListLength(*L);i++)
		{
			ListGet(*L,i,&x);
			printf("[%d]  ",i);
			if(x.OR==0)
				printf(" [δͣ��] \n");
			if(x.OR==1)
				printf(" [��ͣ��] \n");
			/*if(x.OR==2)
				printf(" [�ѳ��⣬���ɷ�] \n");*/
			if(x.OR==3)
				printf("[�ѽɷ�,������] \n");
			if(x.id==1)
			{
				printf("*VIP�û�* \n");
			}
			else
			{
				printf("*��ͨ�û�* \n");
			}
			printf("����������%s \n",x.name);
			printf("�������ƣ�%s  \n",x.LicensePlate);
			printf("�绰���룺%s  \n",x.phone);

			if(x.id==1)
			{
				printf(" ��Ա����%.2f��Ԫ��\n",x.vipmoney);
			}
			printf(" һԪ�Ż�ȯ������%d������\n",x.oneCoupon);
			printf(" ��Ԫ�Ż�ȯ������%d������\n",x.twoCoupon);
			printf("\n");
		}
		printf("�Ƿ���û����в�����[0]�� [1]��\n");
		printf("���������֣�");
		scanf(" %c",&A);
		a=A-'0';
		if(a==0)
			ResetAndDelete(ps,L,s,vip);//���ú�ɾ��
		else if(a==1)
			ReturnMenu(ps,L,s,vip);
		else
		{
			printf("������������\n");
			ReturnMenu(ps,L,s,vip);
		}
	}
	else
	{
		printf("������������\n");
		ReturnMenu(ps,L,s,vip);
	}
}
void ReturnMenu(ParkingSpace ps[10][10],SeqList*L,int *s,int vip)//���ز˵�����
{
	int k;
	char K;
	
	printf("�Ƿ񷵻ز˵�����[0]\n");
	

	while(1)
	{
		
		printf("���������֣�");;
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
			
			printf("�����������������룡\n");
			
			printf("[0]���ز˵�\n");
			
	       printf("���������֣�");
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
void PaymentEnquiry(ParkingSpace ps[10][10],SeqList*L,int i,int j,int *s,int vip)//�����ѯ
{
	int p,q;
	User x;

	char A;
	double cost;
	VIPReadFile(ps,L,s,vip);//��ȡ��Ա 
	printf("********�շ�˵��********\n");
	printf("*ͣ��ʱ��С�ڵ���1Сʱ����һСʱ�Ʒ�,ÿСʱ�շ�3Ԫ*\n");
	printf("*ͣ������1Сʱ��С��2Сʱ������1Сʱ�Ĳ��֣���ÿСʱ�շ�4Ԫ*\n");
	printf("*ͣ������2Сʱ��С��3Сʱ������2Сʱ�Ĳ��֣���ÿСʱ�շ�5Ԫ*\n");
	printf("*ͣ������3Сʱ������3Сʱ�Ĳ��֣���ÿСʱ�շ�6Ԫ*\n");
	printf("\nѡ���ţ�[0]���ز˵� [1]�����ѯ\n");
	printf("���������֣�");
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

						printf("��%d��\n",p);
						if(ps[i][j].orvip==1)
						{
							printf("*VIP�û�* \n");
						}
						else
						{
							printf("*��ͨ�û�* \n");
						}
						printf("������Ϣ\n");
						printf("����������%s\n",ps[i][j].name);
						printf("���ƣ�%s\n",ps[i][j].LicensePlate);
						printf("�����绰���룺%s\n",ps[i][j].phone);
						printf ( "����ʱ�䣺%s/%s/%s %s:%s:%s\n",ps[i][j].StringStartTime.year,ps[i][j].StringStartTime.mon,ps[i][j].StringStartTime.day,ps[i][j].StringStartTime.hour,ps[i][j].StringStartTime.min,ps[i][j].StringStartTime.sec);
						printf ( "����ʱ�䣺%s/%s/%s %s:%s:%s\n",ps[i][j].StringEndTime.year,ps[i][j].StringEndTime.mon,ps[i][j].StringEndTime.day,ps[i][j].StringEndTime.hour,ps[i][j].StringEndTime.min,ps[i][j].StringEndTime.sec);
						printf("ͣ��ʱ�䣺");
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
							printf("���㣡���ֵ��\n");
							ReturnMenu(ps,L,s,vip);
						}
						}
						ListInsert(L,p,x);
						ps[i][j].or=0;
						CarWirteFile(ps,L,s,vip);//д�ļ�
						PSWirteFile(ps,L,s,vip);//д�복λ 
						printf("�ѽɷѣ�\n"); 

					}

				}
			
		
		ReturnMenu(ps,L,s,vip);
	}
	else
	{
		printf("������������\n");
		ReturnMenu(ps,L,s,vip);
	}
}
double Pay(ParkingSpace ps[10][10],SeqList*L,int i,int j,int b,int c,int* q,int *s, int vip)
{
	double cost;
	char Q;
	if((b==0&&c<=59)||b==1)//С��1����
		cost=3;
	if(b>1&&b<=2)//����1����С��2����,����1���ӵİ�����4Ԫ
		cost=3+(b-1)*4;
	if(b>2&&b<=3)//����2����С��3����,����2���ӵİ�ÿ����5Ԫ
		cost=7+(b-2)*5;
	if(b>3)//���ڷ��ӣ�����3���Ӱ�����6Ԫ��
		cost=12+(b-3)*6;
	printf("\n***���ɷѵ��û�***\n");
	if(ps[i][j].orvip==1)
	{
		printf("���ǻ�Ա�������ܾ����Żݣ�\n");
		cost=cost*0.9;
	}
	printf("�Ƿ�ʹ���Ż�ȯ��[0]1Ԫ�Ż�ȯ [1]2Ԫ�Ż�ȯ [2]��ʹ���Ż�ȯ\n");
	printf("���������֣�");
	scanf(" %c",&Q);
	*q=Q-'0';
	if(*q==0)
	{
		if(ps[i][j].oneCoupon>1)
		{	cost=cost-1;
		printf("��ʹ��һ��һԪ�Ż�ȯ��\n");
		}
		else
		{
			printf("һԪ�Ż�ȯ�������㣡����ʹ���Ż�ȯ��\n");
			*q=2;
		}
	}
	else if(*q==1)
	{
		if(ps[i][j].twoCoupon>1)
		{
			cost=cost-2;
			printf("��ʹ��һ�Ŷ�Ԫ�Ż�ȯ��\n");
		}
		else
		{
			printf("��Ԫ�Ż�ȯ�������㣡����ʹ���Ż�ȯ��\n");
			*q=2;
		}
	}
	else if(*q==2)
	{

		cost=cost;	
		printf("û��ʹ���Ż�ȯ��\n");
	}
	else
	{	printf("��������\n");              
	ReturnMenu(ps,L,s,vip);
	}
	printf("\n�շѣ�%.2f��Ԫ��\n",cost);
	return cost;
}
double timedifference(ParkingSpace ps[10][10],SeqList*L,int i,int j,int* p,int *s,int vip)//ʱ����
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
printf("%dСʱ%02d��%02d��\n",a,b,c);
cost=Pay(ps,L,i,j,b,c,p ,s,vip);
return cost;
}
void VipCardRecharge(ParkingSpace ps[10][10],SeqList*L,int *s,int vip)//��Ա����ֵ
{
	User user,x;
	int i,n=0,k;
	char K,A;
	double moneyplus;
	char MONEYPLUS[100000];
	char number[5];
	VIPReadFile(ps,L,s,vip);//��ȡ��Ա 
	printf("\nѡ���ţ�[0]���ز˵� [1]����ֵ\n");
	printf("���������֣�");
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
				printf("*VIP�û�* ");
			}
			else
			{
				printf("*��ͨ�û�* ");
			}
			printf("����������%s  ",x.name);
			printf("�������ƣ�%s  ",x.LicensePlate);
			printf("�绰���룺%s  ",x.phone);
			if(x.id==1)
			{
				printf("��Ա����%.2lf��Ԫ��",x.vipmoney);
			}
			printf("\n");
		}
		printf("��ѡ���ֵ���˻���");
		scanf(" %c",&K);
		k=K-'0';
		ListGet(*L,k,&user);
		if(user.id==1)
		{
			printf("�������Ա���ţ�");
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
				printf("�����˺Ż���������");
				ReturnMenu(ps,L,s,vip);
			}
			if(n==1)
			{  
				printf("�������ֵ��Ԫ����");
				scanf("%s",MONEYPLUS);
				moneyplus=atof(MONEYPLUS);
				user.vipmoney=user.vipmoney+moneyplus; 
				ListDelete(L,k,&x);
				ListInsert(L,k,user);
				CarWirteFile(ps,L,s,vip);//д�ļ�
				printf("��ֵ�ɹ���\n");
			}
		}
		else
			printf("�û����ǻ�Ա��\n");
		ReturnMenu(ps,L,s,vip);
	}
	else
	{
		printf("������������\n");
		ReturnMenu(ps,L,s,vip);
	}
}
void ResetAndDelete(ParkingSpace ps[10][10],SeqList*L,int *s,int vip)//���ú�ɾ��
{
	User x,user;
	int a,i,k,m;
	char I,A,M;
	//Admin z;
//	Admin admin;
	char name[20],password[20];
	printf("��ѡ���û���ţ�");
	scanf(" %c",&I);
	i=I-'0';
	k=ListGet(*L,i,&x);
	if(k==0)
	{
		printf("��������\n");
		ReturnMenu(ps,L,s,vip);
	}
	printf("��ѡ���ţ�[0]�û���ѯ [1]ɾ���û�\n");
	printf("���������֣�");
	scanf(" %c",&A);
	a=A-'0';
	if(a==0)
	{
		system("cls");
		UserInformationDisplay(ps,L,s,vip);
	}
	else if(a==1)
	{
		printf("����ɾ���󲻿ɻָ��������أ�\n");
		printf("�ٴ�ȷ���Ƿ�ɾ���û���[0]�� [1]��\n");
		printf("���������֣�");
		scanf(" %c",&M);
		m=M-'0';
		if(m==0)
		{
			printf("����Ҫȷ�Ϲ���Ա���!\n");
			printf("�˺ţ�");
			scanf("%s",name);
			printf("���룺");
			scanf("%s",password);
			if((strcmp(name,admin.name)==0)&&(strcmp(password,admin.password)==0))
			{
				ListDelete(L,i,&user);
				printf("�û���ɾ����\n");
				ReturnMenu(ps,L,s,vip);
			}
			else
			{
				printf("��֤����Աʧ�ܣ��޷����б��β�����\n");
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
			printf("������������\n");
			ReturnMenu(ps,L,s,vip);
		}
	}
	else 
	{
		printf("������������\n");
		ReturnMenu(ps,L,s,vip);
	}

}
void VIPregistration(ParkingSpace ps[10][10],SeqList*L,int* s,VIPcard vipcard[25],int vip)//��Աע��
{
	int q=0;
	int i,m,r=0,a;
	char A,Number[100],Password[100];
	VIPReadFile(ps,L,s,vip);//��ȡ��Ա 
	printf("******��Ա�˵�******\n");

	printf("\nѡ���ţ�[0]���ز˵� [1]��Աע��\n");
	printf("���������֣�");
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
			printf("��Ա���ʣ��%d ��\n",25-q);
		if(q>24)
		{
			printf("��Ա�������޷�ע�ᣡ\n");
			ReturnMenu(ps,L,s,vip);
		}
		printf("�˺ţ�");
		scanf("%s",Number);
		//printf("���룺");
		//scanf("%s",Password);
		for(i=0;i<25;i++)
		{
			if(strcmp(Number,vipcard[i].Number)==0)
			{
				printf("��Ա��ע�ᣡ������ע�ᣡ\n");
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
		VIPWirteFile(ps,L,s,vip);//д���Ա 
		printf("��Աע��ɹ���\n");
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
		printf("������������\n");
		ReturnMenu(ps,L,s,vip);
	}
}
/*void ChangePassword(ParkingSpace ps[10][10],SeqList*L,int* s,int vip)//������
{
	int i,m,r=0;
	char A;
	//VIPcard vipcard;
	char Number[100];
	char OldPassword[100];
	char NewPassword[100];
	VIPReadFile(ps,L,s,vip);//��ȡ��Ա 
	printf("===�޸�����===\n");
	printf("\nѡ���ţ�[0]��Ա�˵� [1]�޸�����\n");
	printf("���������֣�");
	scanf(" %c",&A);
	if(A=='0')
	{
		system("cls");
		VIPregistration(ps,L,s,vipcard,vip);
	}
	if(A=='1')
	{
		printf("�˺ţ�");
		scanf("%s",Number);
		printf("�����룺");
		scanf("%s",OldPassword);
		printf("�����룺");
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
			printf("�����˺Ż���������\n");
			ReturnMenu(ps,L,s,vip);
		}
		if(r==1)
		{  
			if(strcmp(OldPassword,vipcard[m].Password)!=0)
			{
				printf("�������������\n");
				ReturnMenu(ps,L,s,vip);
			}
			for(i=0;NewPassword[i]!='\0';i++)
			{
				if((('0'>NewPassword[i])||('9'<NewPassword[i]))&&(('A'>NewPassword[i])||('Z'>NewPassword[i]))&&(('a'>NewPassword[i])||('z'<NewPassword[i])))
				{
					printf("����Ƿ��ַ���\n");
					ReturnMenu(ps,L,s,vip);
					break;

				}
				if(m==18)
				{
					printf("�������볬��18λ��");
					ReturnMenu(ps,L,s,vip);
					break;

				}
			}

			if(strcmp(NewPassword,vipcard[m].Password)==0)
			{
				printf("�����벻�ܸ���������ͬ��\n");
				ReturnMenu(ps,L,s,vip);
			}
			strcpy(vipcard[m].Password,NewPassword);
			printf("�����޸ĳɹ���\n");
		}
	}
	else
	{
		printf("������������\n");
		ReturnMenu(ps,L,s,vip);
	}

}*/
void CarWirteFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip)//д���û� 
{
	int i=0;
	User x;
	char I[5],id[3],OR[3],money[100000],oneCoupon[5],twoCoupon[5],length[5],LicensePlate[30];
	FILE *fp=fopen("user.txt","w");/*��дģʽ("w")���ļ�user.txt,���������,���Զ�����*/
    itoa(ListLength(*L),length,10);
	fputs("�û�����\n",fp);
	strcat(length,"\n");
	fputs(length,fp);//��ĳ��� 
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
		fputs("���\n",fp);//��� 
		fputs(I,fp);//��� 
		fputs("�����Ϣ\n",fp);
		fputs(id,fp);//�����Ϣ
		fputs("ͣ��״��\n",fp);
		fputs(OR,fp);//ͣ��״��
		if(x.id==0)
			fputs("��ͨ�û�\n",fp);
		if(x.id==1)
		    fputs("��Ա�û�\n",fp);
		fputs("����\n",fp);    
		fputs(x.name,fp);//���� 
		fputs("����\n",fp);    
		fputs(LicensePlate,fp);//����
		if(x.id==1)
		{	
		    fputs("��Ա���˺�\n",fp);
			fputs(x.vipNumber,fp);//��Ա���˺�
		//	fputs("��Ա������\n",fp);
		//	fputs(x.vipPassword,fp);//��Ա������
			fputs("��Ա�����\n",fp);
			fputs(money,fp);//��Ա�����
			
		}
		fputs("�绰����\n",fp);
		fputs(x.phone,fp);//�绰
		fputs("һԪ�Ż�ȯ\n",fp);
		fputs(oneCoupon,fp);//һԪ�Ż�ȯ 
		fputs("��Ԫ�Ż�ȯ\n",fp);
		fputs(twoCoupon,fp);//��Ԫ�Ż�ȯ 
	    fputs("\n",fp);//���� 

	}
//printf("д��ɹ���\n");
fclose(fp);//�ر��ļ�
	//ReturnMenu(ps,L,s,vip);
}
void VIPWirteFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip)//д���Ա 
{
	int i;
	char or[3],number[100],I[5];
	//VIPcard vipcard[25];
	FILE *fp=fopen("vip.txt","w");//��дģʽ("w")���ļ�user.txt,���������,���Զ�����
	
//	fputs(length,fp);//��ĳ��� 
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
		 fputs("��Ա״̬\n",fp);//
		fputs(or,fp);//ע���Ա���Ϊ1
		 fputs("��Ա�˺�\n",fp);//
	    fputs(number,fp);//vip�˺�
		  //fputs(' ',fp);//v
		}	
		else
		{
			 fputs("��Ա״̬\n",fp);//
			 fputs("δ����\n",fp);//
			//  fputs(' ',fp);//
		}
		

	}
//printf("д��ɹ���\n");
fclose(fp);//�ر��ļ�
	//ReturnMenu(ps,L,s,vip);
}
void PSWirteFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip)//д�복λ 
{
	int i,j;
	char or[3],orvip[3],oneCoupon[5],twoCoupon[5],Syear[7],Smon[7],Sday[7],Shour[7],Smin[7],Ssec[7],name[20],LicensePlate[30],phone[20];//Eyear[7],Emon[7],Eday[7],Ehour[7],Emin[7],Esec[7];
	//VIPcard vipcard[25];
	FILE *fp=fopen("ps.txt","w");//��дģʽ("w")���ļ�user.txt,���������,���Զ�����
	
//	fputs(length,fp);//��ĳ��� 
	//fputs("\n",fp); 
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			
			if(ps[i][j].or==1||ps[i][j].or==2)
			{
			 itoa(ps[i][j].or,or,10);//��λ�Ƿ��г�
			 strcat(or,"\n");
			 itoa(ps[i][j].orvip,orvip,10);//�����Ƿ�Ϊvip
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
			strcat(name,"\n");//��������
			 strcat(LicensePlate,"\n");//����
			 strcat(phone,"\n");//�绰����
			strcat(Syear,"\n");
			strcat(Smon,"\n");
			strcat(Sday,"\n");
			strcat(Shour,"\n");
			strcat(Smin,"\n");
			strcat(Ssec,"\n");
			fputs("��λ��Ϣ\n",fp);//
			fputs(or,fp);//
			fputs("�û����\n",fp);//
			fputs(orvip,fp);//
			fputs("�û�����\n",fp);//
			fputs(name,fp);//
			fputs("����\n",fp);//
			fputs(LicensePlate,fp);//
			fputs("�绰����\n",fp);//
            fputs(phone,fp);//
			fputs("���ʱ��\n",fp);//
			fputs(Syear,fp);//
			fputs(Smon,fp);//
			fputs(Sday,fp);//
			fputs(Shour,fp);//
			fputs(Smin,fp);//
			fputs(Ssec,fp);//
			fputs("һԪ�Ż�ȯ\n",fp);//
			fputs(oneCoupon,fp);//
			fputs("��Ԫ�Ż�ȯ\n",fp);//
			fputs(twoCoupon,fp);
			fputs("\n",fp);
			
			}
			/*else if(ps[i][j].or==2)
			{
			itoa(ps[i][j].or,or,10);//��λ�Ƿ��г�
			 strcat(or,"\n");
			 itoa(ps[i][j].orvip,orvip,10);//�����Ƿ�Ϊvip
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
			strcat(name,"\n");//��������
			 strcat(LicensePlate,"\n");//����
			 strcat(phone,"\n");//�绰����
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
				itoa(ps[i][j].or,or,10);//��λ�Ƿ��г�
			    strcat(or,"\n");
				fputs("��λ��Ϣ\n",fp);//
				fputs(or,fp);//
				fputs("\n",fp);
			}
		}
	}
//printf("д��ɹ���\n");
fclose(fp);//�ر��ļ�
	//ReturnMenu(ps,L,s,vip);
}
void CarReadFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip)//��ȡ�û� 
{
	int i,length;
	int flen=0;
	User user;
	char Length[5],id[3],OR[3],a[100],oneCoupon[10],twoCoupon[10],money[100000];
    FILE *fp=fopen("user.txt","r");//�Զ�ģʽ("r")���ļ�user.txt
 if(fp==NULL)  //���ļ�
   {
	   printf("**EORRO**\n");
       printf("û���ҵ�user.txt�ļ�\n");
	   printf("����C�ļ�����Ŀ¼�´���user.txt�ļ�,�����б�����\n");
	   system("pause");
	   exit(0);
	   
    }
      fseek(fp,0,SEEK_END);//���ļ���β
      flen=ftell(fp);//��ȡ�ļ���С
      fseek(fp,0,SEEK_SET);//���ص��ļ�ͷ
if(flen==0)
{
//	printf("�ļ����������޷����ж�ȡ��\n"); 
} 
else
{
	
	//printf("�ļ��ɶ���\n");
	fscanf(fp,"%s",a);
	fscanf(fp,"%s",Length);
	sscanf( Length, "%d", &length ); 
	for(i=0;i<length;i++)
	{	
	fscanf(fp,"%s",a);//��� 
	fscanf(fp,"%s",a);//0
	fscanf(fp,"%s",a);//�����Ϣ  
	fscanf(fp,"%s",id);//0 
	fscanf(fp,"%s",a);//ͣ��״��  
    fscanf(fp,"%s",OR);//0 
    fscanf(fp,"%s",a);//��ͨ�û� 
	fscanf(fp,"%s",a);//���� 
	fscanf(fp,"%s",user.name);//xxx 
	fscanf(fp,"%s",a);//����
	fscanf(fp,"%s",user.LicensePlate);//xxx
	if(strcmp(id,"1")==0)
	{
			fscanf(fp,"%s",a);//��Ա���˺� 
			fscanf(fp,"%s",user.vipNumber);//xxx 
		//	fscanf(fp,"%s",a);//��Ա������ 
			//fscanf(fp,"%s",user.vipPassword);//xxx 
			fscanf(fp,"%s",a);//��Ա����� 
			fscanf(fp,"%s",money);//xxx
	}
	fscanf(fp,"%s",a);//�绰����
	fscanf(fp,"%s",user.phone);//xxx
	fscanf(fp,"%s",a);//һԪ�Ż�ȯ 
	fscanf(fp,"%s",oneCoupon);//xxx
	fscanf(fp,"%s",a);//��Ԫ�Ż�ȯ 
	fscanf(fp,"%s",twoCoupon);//xxx
//	fscanf(fp,"%s",a);//���� 
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
fclose(fp); //�ر��ļ�
	//ReturnMenu(ps,L,s,vip);
}
void VIPReadFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip)//��ȡ��Ա 
{
	int i;
//	User user;
	char or[10],a[200];
	int flen;
    FILE *fp=fopen("vip.txt","r");//�Զ�ģʽ("r")���ļ�user.txt
 if(fp==NULL)  //���ļ�
    {
       printf("**EORRO**\n");
       printf("û���ҵ�vip.txt�ļ�\n");
	   printf("����C�ļ�����Ŀ¼�´���vip.txt�ļ�,�����б�����\n");
	   system("pause");
	   exit(0);
    }
fseek(fp,0,SEEK_END);//���ļ���β
flen=ftell(fp);//��ȡ�ļ���С
fseek(fp,0,SEEK_SET);//���ص��ļ�ͷ
if(flen==0)
{
//	printf("�ļ����������޷����ж�ȡ��\n"); 
} 
else
{
	for(i=0;i<25;i++)
	{
		 //   fscanf(fp,"%s",a);
          //  fscanf(fp,"%s",a);
			fscanf(fp,"%s",a);
			fscanf(fp,"%s",or);//ע���Ա��Ϊ1
			sscanf(or, "%d", &vipcard[i].or ); 
			if(vipcard[i].or==1)
		    { 
				fscanf(fp,"%s",a);
				fscanf(fp,"%s",vipcard[i].Number);//��Ա���˺� 
				//fscanf(fp,"%s",a);
			}
			else
			{
				fscanf(fp,"%s",a);
				fscanf(fp,"%s",a);
				
			}
			
			
    }
      fclose(fp); //�ر��ļ�
	//ReturnMenu(ps,L,s,vip);
}
}
void PSReadFile(ParkingSpace ps[10][10],SeqList*L,int* s,int vip)//��ȡ��λ
{
	int i,j,k;
	int flen=0;
	User user;
	char a[3],or[5],orvip[3],oneCoupon[10],twoCoupon[10],b[100],name[20],LicensePlate[20],phone[20];
    FILE *fp=fopen("ps.txt","r");//�Զ�ģʽ("r")���ļ�user.txt
 if(fp==NULL)  //���ļ�
   {
	   printf("**EORRO**\n");
       printf("û���ҵ�ps.txt�ļ�\n");
	   printf("����C�ļ�����Ŀ¼�´���ps.txt�ļ�,�����б�����\n");
	   system("pause");
	   exit(0);
	   
    }
      fseek(fp,0,SEEK_END);//���ļ���β
      flen=ftell(fp);//��ȡ�ļ���С
      fseek(fp,0,SEEK_SET);//���ص��ļ�ͷ
if(flen==0)
{
//	printf("�ļ����������޷����ж�ȡ��\n"); 
} 
else
{
	
	//printf("�ļ��ɶ���\n");
	
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
fclose(fp); //�ر��ļ�
	//ReturnMenu(ps,L,s,vip);
}
void menu(ParkingSpace ps[10][10],SeqList*L,int* s,int vip)//�˵�
{
	int i;
	char I;
	VIPReadFile(ps,L,s,vip);//��ȡ��Ա 
	
	printf("==================���ܲ˵�==================\n");
	
	printf("      [1]��������Ǽ�  [2]���೵λ��ѯ\n");
	
	printf("      [3]��ȡ��λ��Ϣ  [4]�˳���λ\n");
	
	printf("      [5]�û���Ϣ��ѯ  [6]��Ա����ֵ\n");

	printf("      [7]��Աע��      [8]�˳�����\n");
	
//	printf("      [0]�˳�����\n");
	
	printf("===========================================\n");
	
	printf("      �����������ţ�");
	scanf(" %c",&I);
	i=I-'0';
	switch(i)
	{
	/*case 0:
		{
			system("cls");
			
			printf("�����ѹرգ�\n");
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
				VIPregistration(ps,L,s,vipcard,vip);//��Աע��
		}break;
	case 8:
		{
		 system("cls");	
			printf("�����ѹرգ�\n");
			exit(0);
		}break;

	default:
	{
		
		printf("������������\n");
		ReturnMenu(ps,L,s,vip);
	}
  }
}
#endif
