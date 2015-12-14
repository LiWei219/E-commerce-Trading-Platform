#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include <winsock2.h>
#include <mswsock.h>
#include <stdio.h>  
#include <winsock.h>
#include <sys/types.h> 
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "mswsock.lib")

using namespace std;
class card;   //card������ 
class bank   //������ 
{
	public:	
	    void function();   //�����û����� 
		void set_account();  //ע�����п�
		void choiceshow();  //����ѡ�� 
		void enter();  //��½
		void del_account();  //ע�����п�
		void onlineservice();  //���Ϸ��� 
		void exit();   //�˳�ϵͳ 
		
	    void load();  //���������û���Ϣ 
		void save();   //������Ϣ
		
	protected:
	    card *account[50];
};
class card:public bank //���п�����������bank������ 
{   
	public:	
        friend class bank;
	    card(string cnum,string pass,string ban,string idn,float m)
	    {
    		cardnum=cnum;passwd=pass;bk=ban;idnum=idn;money=m;
    	}
    	card()
    	{
	    	cardnum='0';passwd='0';bk='0';idnum='0';money=0;
	    }
        void changepasswd();  //�޸����� 
		void savemoney();   //��� 
		void depositmoney();   //ȡ��
		void showinfo();  //��ʾ�û���Ϣ
		void set_money(float m);
		string get_cardnum(){return cardnum;}
		string get_passwd(){return passwd;}
		float get_money(){return money;} 
	
	private:	   
	    string cardnum;  //����
		string passwd;  //���� 
		string bk;   //������������
		string idnum;  //�ֿ������֤��
		float money;   //���ڽ��  		 
};

 int accnum=0;  //�����˻��� 
 int usernum=0;  //��ǰ�û��������е�λ��  	  

//������ 
int main()
{
	 bank bk;
	 bk.function();   //�����û����� 
	 
	 system("pause");
	 return 0;	
}

//�����棬��ʾ���� 
void bank::function()
{
	int n;  //�洢ѡ����� 
    do
    {
	    load();
        cout<<"**********************************************"<<endl;
	    cout<<"*              ��ӭ��������ϵͳ��            *"<<endl;
	    cout<<"*           ��ѡ����Ҫ�Ĳ������:            *"<<endl; 
	    cout<<"*         1.ע�����п�     2.��½            *"<<endl;   
	    cout<<"*         3.ע�����п�     4.�������Ϸ���    *"<<endl;
	    cout<<"*         5.�˳�                             *"<<endl; 
	    cout<<"**********************************************"<<endl;
	    cin>>n;
	
	    while(n<1||n>5)
	   {
		   cout<<"����������������ȷ�Ĳ�����ţ�"<<endl;
		   cin>>n; 
	   }	 
	   switch(n)
	   {
	    	case 1:set_account(); break; //���� 
		    case 2:enter(); break;   //��½ 
		    case 3:del_account(); break;  //ע�� 
		    case 4:onlineservice();  break; //�������Ϸ��� 
		    case 5:exit(); return;  //�˳� 
	    }
	   cin.get();  //�����س������������ 
    }while(1);	
}

//��ȡ��class�������е��û���Ϣ 
void bank::load()
{
	int i=0;
	string cardnum;
	string passwd;
	string banknm;
	string idnum;
	string buffer;
	float money;
	ifstream bankfile;
	bankfile.open("bankdat.txt",ios::in);
	if(!bankfile)
	{
		cerr<<"���ļ�����"<<endl;
		abort(); 
		return;
	}
	bankfile>>buffer;
	bankfile>>accnum;
    bankfile>>buffer;
	//cout<<"��� ���� ���� �������� ���֤�� �����"<<endl;
	while(i<accnum)
	{
		bankfile>>buffer;
		bankfile>>cardnum;
		bankfile>>buffer;
		bankfile>>passwd;
		bankfile>>buffer;
		bankfile>>banknm;
		bankfile>>buffer;
		bankfile>>idnum;
		bankfile>>buffer;
		bankfile>>money;
	
		card* acc=new card(cardnum,passwd,banknm,idnum,money);
		account[i]=acc;		
	    //cout<<i<<" "<<cardnum<<" "<<passwd<<" "<<banknm<<" "<<idnum<<" "<<money<<endl;
	    //cout<<i<<" "<<account[i]->cardnum<<" "<<account[i]->passwd<<" "<<account[i]->bk<<" "<<account[i]->idnum<<" "<<account[i]->money<<endl;
	    i++;
	}	
	bankfile.close();
	if(i==0)
	{
		cout<<"�����û���"<<"��ȡ����������"<<endl; 
	}
	else
        cout<<"��ȡ����������"<<endl;
    return;
}
 
void bank::choiceshow()	//�򿪿�ѡ�����ļ�������ʾ������ 
{
	char banknm;
	ifstream bkfile;
	bkfile.open("bank.txt",ios::in);
	if(!bkfile)
	{
		cerr<<"���ļ�����"<<endl;
		abort();
	}
	while(bkfile.get(banknm))
	{
		cout<<banknm;
	}
	bkfile.close();
}
//ע�����п�
void bank::set_account()
{
	int choice;
	int i=0;
	string numtemp;
	string passwd;
	string passwd1;
	string accbk;
	int flag=1;
	//string passwd1;
	string idnum;
	float money;
	cout<<"��ӭע�����п���"<<endl ;
	choiceshow(); 
	cout<<endl<<"��ѡ�����У�";
	cin>>choice; 
	switch(choice)
	{
		case 0:accbk="�й�����"  ; cout<<"��ѡ�й����У�"<<endl;break;
		case 1:accbk="�й���������"; cout<<"��ѡ�й��������У�"<<endl;break;
		case 2:accbk="�й�ũҵ����"; cout<<"��ѡ�й�ũҵ���У�"<<endl;break;
		case 3:accbk="�й���������"; cout<<"��ѡ�й��������У�"<<endl;break;
		case 4:accbk="��������"; cout<<"��ѡ�������У�"<<endl;break;
		case 5:accbk="��ͨ����"; cout<<"��ѡ��ͨ���У�"<<endl;break;
		case 6:accbk="��������"; cout<<"��ѡ�������У�"<<endl;break;
		case 7:accbk="��������"; cout<<"��ѡ�������У�"<<endl;break;
		case 8:accbk="�ַ�����"; cout<<"��ѡ�ַ����У�"<<endl;break; 		 
	}
	cout<<"��������Ŀ��ţ�(16λ���֣�";
	cin>>numtemp;
	int j=0;
	int flag1=0;
l1:	while(numtemp[j]!='\0')
	{
		if(numtemp[j]>=48&&numtemp[j]<=57)
		    j++;
        else
        {
        	flag1=1;
        	j++;
        }            
	}
	if((flag1!=0)||(j!=16))
    {
    	cout<<"����ֻ��16λ������ɣ����������룡";
		cin>>numtemp; 
		j=0;
		flag1=0;
		goto l1; 
    }
 
    	
	while((i<accnum)&&flag)
    {    if(account[i]->cardnum==numtemp)
        {    
            if(account[i]->bk==accbk)
            {  
                 flag=0;
            }
            else
                 i++;
        }
        else
            i++;
    }
	if(flag==0)
	{   
	     cout<<"��ѡ�����ѱ�ռ�ã��밴�����������һ���˵���";
	     return;
	}

	cout<<"���Ŀ���Ϊ"<<numtemp<<endl;
	
	cout<<"�������������п����루6λ���ֻ���ĸ����";
l4:	cin>>passwd;
    while(passwd.length()!=6)
    {
    	cout<<"����Ϊ6λ���ֻ���ĸ�����������ã�";
    	cin>>passwd;
    }
    cout<<"���ڴ�������ȷ�ϣ�";
	cin>>passwd1;
	if(passwd!=passwd1)
	{
		cout<<"�������벻ƥ�䣡���������ã�";
		goto l4; 
	} 
    
    cout<<"�������������֤�ţ�";
	cin>>idnum;
	
	cout<<"���������Ĵ���";
	cin>>money;
	while(money<0)
	{
		cout<<"��������ȷ���֣�"; 
		cin>>money; 
	}
	
	card *acc=new card(numtemp,passwd,accbk,idnum,money);
	account[accnum]=acc;
	cout<<"�û���Ϣ��������ϣ�ע��ɹ���"<<endl;
	cout<<"���ţ�"<<account[accnum]->cardnum<<endl;
	cout<<"���룺"<<account[accnum]->passwd<<endl;
	cout<<"�������У�"<<account[accnum]->bk<<endl;
	cout<<"���֤�ţ�"<<account[accnum]->idnum<<endl;
	cout<<"����"<<account[accnum]->money<<endl;
	accnum++;
	cout<<accnum<<endl;
	save();
	cin.get(); 
	 
} 

void bank::enter()  //��½ 
{
	int temp,n;
	int i=0;
	string numtemp; 
	int flag=1; 
	string pass;
 	cout<<"���������Ŀ��ţ�";
	cin>>numtemp;
	
	int j=0;
	int flag1=0;
l2:	while(numtemp[j]!='\0')
	{
		if(numtemp[j]>=48&&numtemp[j]<=57)
		    j++;
        else
        {
        	flag1=1;
        	j++;
        }            
	}
	if((flag1!=0)||(j!=16))
    {
    	cout<<"����ֻ��16λ������ɣ����������룡";
		cin>>numtemp; 
		j=0;
		flag1=0;
		goto l2; 
    }
	
	while((i<accnum)&&(flag))
	{
		if(numtemp==account[i]->get_cardnum())
			flag=0;
		else
		    i++;		     
	}
	cout<<i<<endl;
	usernum=i;
	if(flag)
    {
 		cout<<"�����п�������!"<<endl;
		return; 
 	}   
	else
	{
		cout<<"���������룺";
	    cin>>pass;
	    if(pass!=account[i]->get_passwd())
    	{	  
		      cout<<"���벻��ȷ�����������룺"<<endl; 
		      cin>>pass; 
		}    
		else
		{
			if(pass!=account[i]->get_passwd())
			{	  
		      cout<<"���벻��ȷ�����������룺"<<endl; 
		      cin>>pass; 
		    } 
			else
			{
				if(pass!=account[i]->get_passwd())
			    { 
			        cout<<"�������������࣬�������������밴����������ϼ��˵���"<<endl;
			    }
			    else
			    {
    				  cout<<"��½�ɹ���"<<endl; 
			          usernum=i;
			          cout<<i<<endl; 
			          do
                     {
    	                   cout<<"**********************************************"<<endl;
                           cout<<"*            ��ѡ����Ҫ�Ĳ������:           *"<<endl; 
    	                   cout<<"*       1.��ʾ��Ϣ            2.���         *"<<endl;   
	                       cout<<"*       3.�޸�����            4.ȡ��         *"<<endl;
	                       cout<<"*       5.������һ���˵�                     *"<<endl;
                           cout<<"**********************************************"<<endl;
	                       cin>>n;
	
	                       while(n<1||n>5)
	                       {
		                        cout<<"����������������룡"<<endl;
	                            cin>>n;
                           }
                           switch(n)
	                       {
		                        case 1:account[usernum]->showinfo();  break;
	                            case 2:account[usernum]->savemoney(); save(); break;
		                        case 3:account[usernum]->changepasswd(); save(); break;
		                        case 4:account[usernum]->depositmoney(); save(); break;
		                        case 5:return;
	                       } 
                           cin.get(); 
				           cin.get();
                      }while(1);			
    			 }
		     }   			
		 }  
	 } 	  
}



void bank::del_account()
{
	int temp;
	int i=0;
	string numtemp;
	int t=3;
	int flag=1;
	string pass;
	cout<<"���������Ŀ��ţ�";
	cin>>numtemp;
	
	int j=0;
	int flag1=0;
l3:	while(numtemp[j]!='\0')
	{
		if(numtemp[j]>=48&&numtemp[j]<=57)
		    j++;
        else
        {
        	flag1=1;
        	j++;
        }            
	}
	if((flag1!=0)||(j!=16))
    {
    	cout<<"����ֻ��16λ������ɣ����������룡";
		cin>>numtemp; 
		j=0;
		flag1=0;
		goto l3; 
    }
	
	while((i<accnum)&&flag)
	{
		if(numtemp==account[i]->get_cardnum())
		   flag=0;
        else
           i++;
	}
	
	if(flag)
	{
		 cout<<"�����п������ڣ�����������"<<endl;
		 return;
	}
	else
	{
		cout<<"���������룺";
	    cin>>pass;
	    if(pass!=account[i]->get_passwd())
    	{	  
		      cout<<"���벻��ȷ�����������룺"<<endl; 
		      cin>>pass; 
		}    
		else
		{
			if(pass!=account[i]->get_passwd())
			{	  
		      cout<<"���벻��ȷ�����������룺"<<endl; 
		      cin>>pass; 
		    } 
			else
			{
				if(pass!=account[i]->get_passwd())
			    { 
			        cout<<"�������������࣬�������������밴����������ϼ��˵���"<<endl;
			    }
			    else
			    { 
    				 for(int j=i;j<accnum;j++)
			         {
				          account[j]=account[j+1];
			         }
		          	 account[accnum-1]=NULL;
			         accnum--;
			         cout<<"ע���ɹ���"<<endl; 		
   			    }
		     }   			
		 } 				  
	}
	save();
	cin.get();
	return; 	  
}

void bank::onlineservice()
{
	 cout<<"���Ϸ���ʼ������"<<endl;
	 WORD wVersionRequested;
     WSADATA wsaData;
     int err=0;
     string cardaccount;
     string passwd; 
     float pay;
     float money;
     int i=0;
     int flag=1; 
 
     wVersionRequested = MAKEWORD( 2, 2 );
     err = WSAStartup( wVersionRequested, &wsaData );
     
     SOCKET ss=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
 
     SOCKADDR_IN addr;
     int len;
     addr.sin_family=AF_INET;
     addr.sin_addr.s_addr = htonl(INADDR_ANY);
     addr.sin_port = htons(1002);
     len=sizeof(addr);
 
     bind(ss , (PSOCKADDR)&addr , len);
     listen(ss,5);
 
     SOCKET sc=accept(ss,(PSOCKADDR)&addr,&len);
     char buff[1024];
     cardaccount="0000000000000000";
     passwd="000000";
    // cout<<cardaccount.length()<<"length!"<<endl;
     
     memset(buff,0,sizeof(buff));   //��buffer���
     printf("recieve a message:"); 
     recv(sc,buff,1024,0);
    // cout<<buff<<endl;
     while(i<cardaccount.length())
     {
     	cardaccount[i]=buff[i];  //���յ������˻�
     	i++;
     }        
     cout<<cardaccount<<endl;
	 i=0;
	 while((i<accnum)&&(flag))
	{
		if(cardaccount==account[i]->get_cardnum())
			flag=0;
		else
		    i++;		     
	}
//	cout<<i<<endl;
	usernum=i;
	if(flag)
    {
 		memset(buff,0,sizeof(buff));   //��buffer���
        memcpy(buff,"���û������ڣ�֧��ʧ�ܣ�",50);
        printf("Send:");  
        send(sc,buff,50,0);
        printf("\n"); 
 	}   
	else
	{
		  memset(buff,0,sizeof(buff));   //��buffer���
          memcpy(buff,"���������룺",50);
          printf("Send:");     //Ҫ���������� 
          send(sc,buff,50,0);
          printf("���������룺\n");
          
          memset(buff,0,sizeof(buff));   //��buffer���
          printf("Recieve:"); 
          recv(sc,buff,1024,0);
          for(i=0;i<6;i++)
              passwd[i]=buff[i];  //���յ������˻�
          cout<<passwd<<endl;
       //   cout<<account[usernum]->get_passwd()<<endl;
          if(passwd!=account[usernum]->get_passwd())
    	  {
  	    	  memset(buff,0,sizeof(buff));   //��buffer���
              memcpy(buff,"�������֧��ʧ�ܣ�",50);
              printf("Send:");     //Ҫ���������� 
              send(sc,buff,50,0);
              printf("�������֧��ʧ�ܣ�"); 
              printf("\n"); 
  	      }     
		  else
		  {
	          memset(buff,0,sizeof(buff));   //��buffer���
              memcpy(buff,"��Ϣ��ȷ���봫��֧����",50);
              printf("Send:");     //Ҫ���������� 
              send(sc,buff,50,0);
              printf("��Ϣ��ȷ���봫��֧����"); 
              printf("\n");
              
              memset(buff,0,sizeof(buff));   //��buffer���
              printf("Recieve:"); 
              recv(sc,buff,1024,0);
              pay=atof(buff);
              cout<<pay<<endl;
                            
              money=account[usernum]->get_money();
              if(money<pay)
              {
              	 memset(buff,0,sizeof(buff));   //��buffer���
                 memcpy(buff,"�˻����㣬֧��ʧ�ܣ�",50);
                 printf("Send:");     //Ҫ���������� 
                 send(sc,buff,50,0);
                 printf("�˻����㣬֧��ʧ�ܣ�"); 
                 printf("\n");
                 
              }
              else
			  {
  				 account[usernum]->set_money(money-pay);
			     memset(buff,0,sizeof(buff));   //��buffer���
                 memcpy(buff,"֧���ɹ���",50);
                 printf("Send:");     //Ҫ���������� 
                 send(sc,buff,50,0);
                 printf("֧���ɹ����˻�����%.2f",money-pay); 
                 printf("\n");
  				 
               } 
           }
	  }
     closesocket(sc);
     closesocket(ss);
     save();
	      
     return; 	  
}

void bank::save()
{
	int i;
	ofstream bankfile;
	bankfile.open("bankdat.txt",ios::out);
	if(!bankfile)
	{
		cerr<<"���ļ�����"<<endl;
		abort(); 
	}
	else
	{ 
	    cout<<"���� "<<accnum<<" �����п���Ϣ��"<<endl; 
	    bankfile<<"���� "; 
	    bankfile<<accnum;
	    bankfile<<" �����п���Ϣ��"<<endl; 
		for(i=0;i<accnum;i++)
		{
			bankfile<<"���ţ� "; 
			bankfile<<account[i]->cardnum<<endl;
			bankfile<<"���룺 "; 
			bankfile<<account[i]->passwd<<endl;
			bankfile<<"�������У� "; 
			bankfile<<account[i]->bk<<endl;
			bankfile<<"���֤�ţ� "; 
			bankfile<<account[i]->idnum<<endl;
			bankfile<<"�洢�� ";
			bankfile<<account[i]->money<<endl<<endl;
		}
		cout<<"�û����ݱ���ɹ���"<<endl; 
	}
	bankfile.close();
}

void bank::exit()
{
	cout<<endl<<"��л����ʹ�ã��ټ���"<<endl;
	return; 
}

void card::set_money(float m)
{
	money=m;
}

void card::changepasswd()
{
	string str1;
	string str2;
	cout<<"������ԭʼ���룺";
	cin>>str1;
	while(str1!=passwd)
	{
		cout<<"��������������������룺";
		cin>>str1;
	}
	cout<<"�����������룺";
	cin>>str1;
    cout<<"���ڴ����������룺";
    cin>>str2;
	if(str1!=str2)
	   cout<<"��������������벻һ�����밴�����������һ���˵���"<<endl;
    else
	{ 
	     passwd=str1;  
	     cout<<"�����޸ĳɹ�,���μǣ�"<<endl;
	}
	cin.get();
}

void card::savemoney()
{
	float m;
	cout<<"����������";
	cin>>m;
	while(m<0)
	{
		cout<<"����������������룺";
		cin>>m; 
	}
	money=money+m;
	cout<<"���ɹ������д�"<<money<<endl;
	return; 
}

void card::depositmoney()
{
	float m;
	cout<<"������ȡ���";
	cin>>m;
	while(m>money)
	{
		cout<<"ȡ����������д���ϵͳ��֧��͸֧�����������룺";
		cin>>m; 
	} 
	money=money-m;
	cout<<"��ȡ�������"<<money<<endl; 
	return;
}

void card::showinfo()
{
	cout<<"���ţ�"<<cardnum<<endl;
	cout<<"���룺"<<passwd<<endl;
	cout<<"�������У�"<<bk<<endl;
	cout<<"���֤�ţ�"<<idnum<<endl;
	cout<<"��"<<money<<endl;
	return; 
}

