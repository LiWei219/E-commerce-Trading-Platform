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
class card;   //card类声明 
class bank   //银行类 
{
	public:	
	    void function();   //进入用户界面 
		void set_account();  //注册银行卡
		void choiceshow();  //银行选择 
		void enter();  //登陆
		void del_account();  //注销银行卡
		void onlineservice();  //网上服务 
		void exit();   //退出系统 
		
	    void load();  //下载已有用户信息 
		void save();   //保存信息
		
	protected:
	    card *account[50];
};
class card:public bank //银行卡集成银行类bank的属性 
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
        void changepasswd();  //修改密码 
		void savemoney();   //存款 
		void depositmoney();   //取款
		void showinfo();  //显示用户信息
		void set_money(float m);
		string get_cardnum(){return cardnum;}
		string get_passwd(){return passwd;}
		float get_money(){return money;} 
	
	private:	   
	    string cardnum;  //卡号
		string passwd;  //密码 
		string bk;   //所属银行名称
		string idnum;  //持卡人身份证号
		float money;   //卡内金额  		 
};

 int accnum=0;  //已有账户数 
 int usernum=0;  //当前用户在数组中的位置  	  

//主函数 
int main()
{
	 bank bk;
	 bk.function();   //进入用户界面 
	 
	 system("pause");
	 return 0;	
}

//主界面，显示功能 
void bank::function()
{
	int n;  //存储选择变量 
    do
    {
	    load();
        cout<<"**********************************************"<<endl;
	    cout<<"*              欢迎进入银行系统！            *"<<endl;
	    cout<<"*           请选择需要的操作序号:            *"<<endl; 
	    cout<<"*         1.注册银行卡     2.登陆            *"<<endl;   
	    cout<<"*         3.注销银行卡     4.进入网上服务    *"<<endl;
	    cout<<"*         5.退出                             *"<<endl; 
	    cout<<"**********************************************"<<endl;
	    cin>>n;
	
	    while(n<1||n>5)
	   {
		   cout<<"操作错误，请输入正确的操作序号！"<<endl;
		   cin>>n; 
	   }	 
	   switch(n)
	   {
	    	case 1:set_account(); break; //开户 
		    case 2:enter(); break;   //登陆 
		    case 3:del_account(); break;  //注销 
		    case 4:onlineservice();  break; //进入网上服务 
		    case 5:exit(); return;  //退出 
	    }
	   cin.get();  //保留回车在输入队列中 
    }while(1);	
}

//读取用class保存所有的用户信息 
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
		cerr<<"打开文件错误！"<<endl;
		abort(); 
		return;
	}
	bankfile>>buffer;
	bankfile>>accnum;
    bankfile>>buffer;
	//cout<<"序号 卡号 密码 银行名称 身份证号 存款金额"<<endl;
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
		cout<<"暂无用户！"<<"读取资料正常！"<<endl; 
	}
	else
        cout<<"读取资料正常！"<<endl;
    return;
}
 
void bank::choiceshow()	//打开可选银行文件，并显示其内容 
{
	char banknm;
	ifstream bkfile;
	bkfile.open("bank.txt",ios::in);
	if(!bkfile)
	{
		cerr<<"打开文件错误！"<<endl;
		abort();
	}
	while(bkfile.get(banknm))
	{
		cout<<banknm;
	}
	bkfile.close();
}
//注册银行卡
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
	cout<<"欢迎注册银行卡！"<<endl ;
	choiceshow(); 
	cout<<endl<<"请选择银行：";
	cin>>choice; 
	switch(choice)
	{
		case 0:accbk="中国银行"  ; cout<<"已选中国银行！"<<endl;break;
		case 1:accbk="中国建设银行"; cout<<"已选中国建设银行！"<<endl;break;
		case 2:accbk="中国农业银行"; cout<<"已选中国农业银行！"<<endl;break;
		case 3:accbk="中国工商银行"; cout<<"已选中国工商银行！"<<endl;break;
		case 4:accbk="民生银行"; cout<<"已选民生银行！"<<endl;break;
		case 5:accbk="交通银行"; cout<<"已选交通银行！"<<endl;break;
		case 6:accbk="中信银行"; cout<<"已选中信银行！"<<endl;break;
		case 7:accbk="招商银行"; cout<<"已选招商银行！"<<endl;break;
		case 8:accbk="浦发银行"; cout<<"已选浦发银行！"<<endl;break; 		 
	}
	cout<<"请输入你的卡号：(16位数字）";
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
    	cout<<"卡号只由16位数字组成，请重新输入！";
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
	     cout<<"所选卡号已被占用，请按输入键返回上一级菜单！";
	     return;
	}

	cout<<"您的卡号为"<<numtemp<<endl;
	
	cout<<"请设置您的银行卡密码（6位数字或字母）：";
l4:	cin>>passwd;
    while(passwd.length()!=6)
    {
    	cout<<"密码为6位数字或字母，请重新设置：";
    	cin>>passwd;
    }
    cout<<"请在此输入以确认：";
	cin>>passwd1;
	if(passwd!=passwd1)
	{
		cout<<"两次输入不匹配！请重新设置：";
		goto l4; 
	} 
    
    cout<<"请输入您的身份证号：";
	cin>>idnum;
	
	cout<<"请输入您的存款金额：";
	cin>>money;
	while(money<0)
	{
		cout<<"请输入正确数字！"; 
		cin>>money; 
	}
	
	card *acc=new card(numtemp,passwd,accbk,idnum,money);
	account[accnum]=acc;
	cout<<"用户信息已输入完毕！注册成功！"<<endl;
	cout<<"卡号："<<account[accnum]->cardnum<<endl;
	cout<<"密码："<<account[accnum]->passwd<<endl;
	cout<<"所属银行："<<account[accnum]->bk<<endl;
	cout<<"身份证号："<<account[accnum]->idnum<<endl;
	cout<<"存款金额："<<account[accnum]->money<<endl;
	accnum++;
	cout<<accnum<<endl;
	save();
	cin.get(); 
	 
} 

void bank::enter()  //登陆 
{
	int temp,n;
	int i=0;
	string numtemp; 
	int flag=1; 
	string pass;
 	cout<<"请输入您的卡号：";
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
    	cout<<"卡号只由16位数字组成，请重新输入！";
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
 		cout<<"该银行卡不存在!"<<endl;
		return; 
 	}   
	else
	{
		cout<<"请输入密码：";
	    cin>>pass;
	    if(pass!=account[i]->get_passwd())
    	{	  
		      cout<<"密码不正确，请重新输入："<<endl; 
		      cin>>pass; 
		}    
		else
		{
			if(pass!=account[i]->get_passwd())
			{	  
		      cout<<"密码不正确，请重新输入："<<endl; 
		      cin>>pass; 
		    } 
			else
			{
				if(pass!=account[i]->get_passwd())
			    { 
			        cout<<"密码错误次数过多，本卡已锁定，请按输入键返回上级菜单！"<<endl;
			    }
			    else
			    {
    				  cout<<"登陆成功！"<<endl; 
			          usernum=i;
			          cout<<i<<endl; 
			          do
                     {
    	                   cout<<"**********************************************"<<endl;
                           cout<<"*            请选择需要的操作序号:           *"<<endl; 
    	                   cout<<"*       1.显示信息            2.存款         *"<<endl;   
	                       cout<<"*       3.修改密码            4.取款         *"<<endl;
	                       cout<<"*       5.返回上一级菜单                     *"<<endl;
                           cout<<"**********************************************"<<endl;
	                       cin>>n;
	
	                       while(n<1||n>5)
	                       {
		                        cout<<"输入错误，请重新输入！"<<endl;
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
	cout<<"请输入您的卡号：";
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
    	cout<<"卡号只由16位数字组成，请重新输入！";
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
		 cout<<"该银行卡不存在，请重新输入"<<endl;
		 return;
	}
	else
	{
		cout<<"请输入密码：";
	    cin>>pass;
	    if(pass!=account[i]->get_passwd())
    	{	  
		      cout<<"密码不正确，请重新输入："<<endl; 
		      cin>>pass; 
		}    
		else
		{
			if(pass!=account[i]->get_passwd())
			{	  
		      cout<<"密码不正确，请重新输入："<<endl; 
		      cin>>pass; 
		    } 
			else
			{
				if(pass!=account[i]->get_passwd())
			    { 
			        cout<<"密码错误次数过多，本卡已锁定，请按输入键返回上级菜单！"<<endl;
			    }
			    else
			    { 
    				 for(int j=i;j<accnum;j++)
			         {
				          account[j]=account[j+1];
			         }
		          	 account[accnum-1]=NULL;
			         accnum--;
			         cout<<"注销成功！"<<endl; 		
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
	 cout<<"网上服务开始。。。"<<endl;
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
     
     memset(buff,0,sizeof(buff));   //将buffer清空
     printf("recieve a message:"); 
     recv(sc,buff,1024,0);
    // cout<<buff<<endl;
     while(i<cardaccount.length())
     {
     	cardaccount[i]=buff[i];  //接收到银行账户
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
 		memset(buff,0,sizeof(buff));   //将buffer清空
        memcpy(buff,"该用户不存在，支付失败！",50);
        printf("Send:");  
        send(sc,buff,50,0);
        printf("\n"); 
 	}   
	else
	{
		  memset(buff,0,sizeof(buff));   //将buffer清空
          memcpy(buff,"请输入密码：",50);
          printf("Send:");     //要求输入密码 
          send(sc,buff,50,0);
          printf("请输入密码：\n");
          
          memset(buff,0,sizeof(buff));   //将buffer清空
          printf("Recieve:"); 
          recv(sc,buff,1024,0);
          for(i=0;i<6;i++)
              passwd[i]=buff[i];  //接收到银行账户
          cout<<passwd<<endl;
       //   cout<<account[usernum]->get_passwd()<<endl;
          if(passwd!=account[usernum]->get_passwd())
    	  {
  	    	  memset(buff,0,sizeof(buff));   //将buffer清空
              memcpy(buff,"密码错误，支付失败！",50);
              printf("Send:");     //要求输入密码 
              send(sc,buff,50,0);
              printf("密码错误，支付失败！"); 
              printf("\n"); 
  	      }     
		  else
		  {
	          memset(buff,0,sizeof(buff));   //将buffer清空
              memcpy(buff,"信息正确，请传送支付金额！",50);
              printf("Send:");     //要求输入密码 
              send(sc,buff,50,0);
              printf("信息正确，请传送支付金额！"); 
              printf("\n");
              
              memset(buff,0,sizeof(buff));   //将buffer清空
              printf("Recieve:"); 
              recv(sc,buff,1024,0);
              pay=atof(buff);
              cout<<pay<<endl;
                            
              money=account[usernum]->get_money();
              if(money<pay)
              {
              	 memset(buff,0,sizeof(buff));   //将buffer清空
                 memcpy(buff,"账户余额不足，支付失败！",50);
                 printf("Send:");     //要求输入密码 
                 send(sc,buff,50,0);
                 printf("账户余额不足，支付失败！"); 
                 printf("\n");
                 
              }
              else
			  {
  				 account[usernum]->set_money(money-pay);
			     memset(buff,0,sizeof(buff));   //将buffer清空
                 memcpy(buff,"支付成功！",50);
                 printf("Send:");     //要求输入密码 
                 send(sc,buff,50,0);
                 printf("支付成功！账户余额：￥%.2f",money-pay); 
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
		cerr<<"打开文件错误！"<<endl;
		abort(); 
	}
	else
	{ 
	    cout<<"共有 "<<accnum<<" 张银行卡信息！"<<endl; 
	    bankfile<<"共有 "; 
	    bankfile<<accnum;
	    bankfile<<" 张银行卡信息！"<<endl; 
		for(i=0;i<accnum;i++)
		{
			bankfile<<"卡号： "; 
			bankfile<<account[i]->cardnum<<endl;
			bankfile<<"密码： "; 
			bankfile<<account[i]->passwd<<endl;
			bankfile<<"所属银行： "; 
			bankfile<<account[i]->bk<<endl;
			bankfile<<"身份证号： "; 
			bankfile<<account[i]->idnum<<endl;
			bankfile<<"存储金额： ";
			bankfile<<account[i]->money<<endl<<endl;
		}
		cout<<"用户数据保存成功！"<<endl; 
	}
	bankfile.close();
}

void bank::exit()
{
	cout<<endl<<"感谢您的使用，再见！"<<endl;
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
	cout<<"请输入原始密码：";
	cin>>str1;
	while(str1!=passwd)
	{
		cout<<"密码输入错误，请重新输入：";
		cin>>str1;
	}
	cout<<"请输入新密码：";
	cin>>str1;
    cout<<"请在此输入新密码：";
    cin>>str2;
	if(str1!=str2)
	   cout<<"你输入的两次密码不一样，请按输入键返回上一级菜单！"<<endl;
    else
	{ 
	     passwd=str1;  
	     cout<<"密码修改成功,请牢记！"<<endl;
	}
	cin.get();
}

void card::savemoney()
{
	float m;
	cout<<"请输入存入金额：";
	cin>>m;
	while(m<0)
	{
		cout<<"输入错误，请重新输入：";
		cin>>m; 
	}
	money=money+m;
	cout<<"存款成功！现有存款￥"<<money<<endl;
	return; 
}

void card::depositmoney()
{
	float m;
	cout<<"请输入取款金额：";
	cin>>m;
	while(m>money)
	{
		cout<<"取款金额高于已有存款，本系统不支持透支，请重新输入：";
		cin>>m; 
	} 
	money=money-m;
	cout<<"请取款！现有余额￥"<<money<<endl; 
	return;
}

void card::showinfo()
{
	cout<<"卡号："<<cardnum<<endl;
	cout<<"密码："<<passwd<<endl;
	cout<<"所属银行："<<bk<<endl;
	cout<<"身份证号："<<idnum<<endl;
	cout<<"存款："<<money<<endl;
	return; 
}

