/*����ƽ̨���*/
#include<iostream>
#include<string>
#include<fstream>
#include <stdio.h>
#include<stdlib.h>
#include <winsock2.h>
#include <mswsock.h>
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "mswsock.lib")
using namespace std;

class product   //��Ʒ���� 
{
    public:
        product()   //�޲����Ĺ��캯�� 
        {
        	proid=0;
        	description="No information yet!";
        	oriprice=0;
        	restnum=0;
        }
        product(int pid,string des,float oprice,int rest)   //�в����Ĺ��캯�� 
        {
        	proid=pid;
        	description=des;
        	oriprice=oprice;
        	restnum=rest;
        }
        
        int getproid() {return proid;}   //ͨ���⼸��������ò�Ʒ���˽����Ϣ��ƷID��������ԭ�ۡ�ʣ���� 
        string getdescription() {return description;}
        float getoriprice() {return oriprice;}
        int getrestnum() {return restnum;}
        
        void set_proid(int pid);   //ͨ���⼸�������Բ�Ʒ��˽����Ϣ�������� 
        void set_discription(string des);
        void set_oriprice(float oprice);
        void set_rstnum(int rest);
        
        virtual float getPrice();
        
    private:    //product��˽������ 
	    int proid; 
	    string description;
	    float oriprice;
	    int restnum;
};
void product::set_proid(int pid)//���ò�ƷID 
{
	proid=pid;
}
void product::set_discription(string des)//���ò�Ʒ���� 
{
	description=des;
}
void product::set_oriprice(float oprice)//���ò�Ʒԭ�� 
{
	oriprice=oprice;
}
void product::set_rstnum(int rest)//���ò�Ʒʣ���� 
{
	restnum=rest;
}
float product::getPrice() //�麯�����壬����ԭ�� 
{
	return oriprice;
}

class food:public product //ʳƷ�࣬�̳в�Ʒ�� ����ԭ�������϶����ۿ�ϵ������ر��������� 
{
    public:
	   food()
	   {
   		    product();
   		    discount=1;
   	   }
	   float getdiscount() {return discount;}  //��ȡ�ۿ�ϵ�� 
	   void set_discount(float discnt);   //�����ۿ�ϵ�� 
	   
       virtual float getPrice();
   
    private:
       float discount;	 	
};
void food::set_discount(float discnt) //�����ۿ�ϵ�� 
{
	discount=discnt;
}
float food::getPrice() //�����Ʒ�۸� 
{
	float price;
	price=getoriprice();
	
	return price*discount;
}
class clothes:public product   //�·��࣬�̳в�Ʒ�� ����ԭ�������϶����ۿ�ϵ������ر�����������ͬʳƷ�� 
{
    public:
	   clothes()
	   {
   		    product();
   		    discount=1;
   	   }
	   float getdiscount() {return discount;}
	   void set_discount(float discnt);
	   
       virtual float getPrice();
   
    private:
       float discount;	 	
};
void clothes::set_discount(float discnt)
{
	discount=discnt;
}
float clothes::getPrice()
{
	float price;
	price=getoriprice();
	
	return price*discount;
}
class book:public product  //ͼ���࣬�̳в�Ʒ�� ����ԭ�������϶����ۿ�ϵ������ر�����������ͬʳƷ�� 
{
    public:
	   book()
	   {
   		    product();
   		    discount=1;
   	   } 
	   float getdiscount() {return discount;}
	   void set_discount(float discnt);
	   
       virtual float getPrice();
   
    private:
       float discount;	 	
};
void book::set_discount(float discnt)
{
	discount=discnt;
}
float book::getPrice()
{
	float price;
	price=getoriprice();
	
	return price*discount;
}

class apple:public food //ƻ���࣬�̳�ʳƷ�� 
{
	public:
	    apple()
	    {
    		food();
    	}
	    virtual float getPrice();
};
float apple::getPrice()
{
	float price;
	price=getoriprice();
	return price*getdiscount();  //���㷵���ڴ��ۺ�ļ۸� 
}
class bread:public food  //����࣬�̳�ʳƷ�� 
{
	public:
	    bread()
	    {
    		food();
    	}
	    virtual float getPrice();
};
float bread::getPrice()
{
	float price;
	price=getoriprice();
	return price*getdiscount();
}
class milktea:public food  //�̲��࣬�̳�ʳƷ�� 
{
	public:
	    milktea()
	    {
    		food();
    	}
	    virtual float getPrice();
};
float milktea::getPrice()
{
	float price;
	price=getoriprice();
	return price*getdiscount();
}
class shirt:public clothes  //T���࣬�̳з�װ�� 
{
	public:
	    shirt()
	    {
    		clothes();
    	}
	    virtual float getPrice();
};
float shirt::getPrice()
{
	float price;
	price=getoriprice();
	return price*getdiscount();
}
class skirt:public clothes   //ȹ���࣬�̳з�װ��
{
	public:
	    skirt()
	    {
    		clothes();
    	}
	    virtual float getPrice();
};
float skirt::getPrice()
{
	float price;
	price=getoriprice();
	return price*getdiscount();
}
class pants:public clothes   //�����࣬�̳з�װ��
{
	public:
	    pants()
	    {
    		clothes();
    	}
	    virtual float getPrice();
};
float pants::getPrice()
{
	float price;
	price=getoriprice();
	return price*getdiscount();
}
class CPrimer:public book  //C++Primer�࣬�̳�ͼ���� 
{
	public:
	    CPrimer()
	    {
    		book();
    	}
	    virtual float getPrice();
};
float CPrimer::getPrice()
{
	float price;
	price=getoriprice();
	return price*getdiscount();
}
class EffectiveC:public book  //Effective C++�࣬�̳�ͼ���� 
{
	public:
	    EffectiveC()
	    {
    		book();
    	}
	    virtual float getPrice();
};
float EffectiveC::getPrice()
{
	float price;
	price=getoriprice();
	return price*getdiscount();
}

class HeadFirstJava:public book  //Head First Java�࣬�̳�ͼ���� 
{
	public:
	    HeadFirstJava()
	    {
    		book();
    	}
	    virtual float getPrice();
};
float HeadFirstJava::getPrice()
{
	float price;
	price=getoriprice();
	return price*getdiscount();
}

class plantform
{
	public:
	    plantform();
	    
    	void set_username(string name);  //�����û����������Լ����ﳵ��Ӧ����� 
		void set_passwd(string pass);
		void set_shopcart(int i,int n);
		void set_total(float m); 
		void set_cardnum(int n);  //�����п��� 
		void set_cardaccount(int i,string account);  //���п��˺� 
		
	    float gettotal();  //�����ܼ� 
	    string getusername();  //��ȡ�û��� 
	    string getpasswd();   //��ȡ�û�����
		int getshopcart(int n); //��ȡ�û����ﳵ��Ϣ 
		int getcardnum();   //��ȡ���п��� 
		string getcardaccount(int n);  //��ȡ���п��˺� 
	    	    
	    void function();  //���ܽ��� 
	    void load();  //�����û���Ϣ
	    void loadproduct();  //������Ʒ��Ϣ 
		void loaddis();   //���ص�ǰ�Żݻ
		 
	    void saveuser();  //�����û���Ϣ 
	    void setaccount();  //ע���û� 
	    void login();  //��½ 
	    void logoff();   //�˳���½
		void quit();  //�˳�ϵͳ 
				    
	    void showproduct();  //�鿴��Ʒ
		void showdiscount();  //�鿴�Ż� 
		void showinfo();   //�鿴������Ϣ 
		void showshopcart();  //�鿴���ﳵ 
	    void addshopcart();  //���빺�ﳵ
		void delshopcart();   //ɾ�����ﳵ����Ʒ
	    void order();  //�ύ���� 
	    void payingonline();  //����֧�� 
	          		
	private:
	    string username; //�û��� 
		string passwd;  //���� 
        int shopcart[9];  //���ﳵ 
		float total;  	//�û������ܼ� 
		int cardnum;   //���п����� 
		string cardaccount[5];  //���п��˻� 
		
};

//ȫ�ֱ��� 
 
plantform userptr[50];   
int curuser;   //��ǰ�û����
int usernum;   //�û�����
string temp;   //���ڱ�־�Ż���Ϣ 
float fooddis=1;   //�����Ʒ�Ż��ۿ� 
float clothdis=1;
float bookdis=1;  

//����Ʒ���� 
apple app;
bread bre;
milktea milkt;
shirt shi;
skirt ski;
pants pan;
CPrimer CPri;
EffectiveC EffectC;
HeadFirstJava HeadFJ;

int pronum;   //��Ʒ�������� 
int enough=0;   //�Żݻ����enough��sub 
int sub=0;


//�������ڲ����� 
plantform::plantform()  //���캯����ʼ�� 
{
	int i;
	username='0';
	passwd='0';
	for(i=0;i<9;i++)
	    shopcart[i]=0;
	total=0;
	cardnum=0;
	for(i=0;i<5;i++)
	     cardaccount[i]='0';
}

void plantform::set_username(string usernm)//�����û��� 
{
	username=usernm;
}
void plantform::set_passwd(string pass)//�������� 
{
	passwd=pass;
}
void plantform::set_shopcart(int i,int n) //���ù��ﳵ���� 
{
	shopcart[i]=n;
}

void plantform::set_total(float m) //����Ӧ����� 
{
	total=m;
} 

void plantform::set_cardnum(int n)
{
	cardnum=n;
} 

void plantform::set_cardaccount(int i,string account)
{
	cardaccount[i]=account;
}
	
//��ȡ���ڲ�����,��ǰ�û���Ϣ
float plantform::gettotal()
{
	return userptr[curuser].total;
}

string plantform::getusername()
{
	return userptr[curuser].username;
}

string plantform::getpasswd()
{
	return userptr[curuser].passwd;
}

int plantform::getshopcart(int n)
{
	return userptr[curuser].shopcart[n];
}

int plantform::getcardnum()   //��ȡ���п��� 
{
	return userptr[curuser].cardnum;
}

string plantform::getcardaccount(int n)  //��ȡ���п��˺�
{
	return userptr[curuser].cardaccount[n];
} 

//���ܺ��� 
void plantform::function()
{
	int n;
	load();
	loadproduct();
	loaddis();
	do
	{	
		cout<<"*************************************"<<endl;
	    cout<<"*        ��ӭ�������ƽ̨��         *"<<endl;
	    cout<<"*          ��ѡ�������             *"<<endl;
	    cout<<"*    1.ע���û�      2.��½         *"<<endl;
	    cout<<"*    3.�˳���¼      4.�鿴��Ʒ��Ϣ *"<<endl;
	    cout<<"*    5.�鿴�Żݻ  6.�˳�ϵͳ     *"<<endl;
		cout<<"*************************************"<<endl;
		
		cin>>n;
		while(n<1||n>6)
		{
			cout<<"����������������ȷ�Ĳ�����ţ�"<<endl;
			cin>>n;
		} 
		switch(n)
		{
			case 1:setaccount();  break;  //ע�����û�
			case 2:login();  break;  //��½
			case 3:logoff();  break;  //�˳���¼ 
			case 4:showproduct();  break;  //�鿴��Ʒ��Ϣ 
			case 5:showdiscount();  break;  //�鿴�Ż���Ϣ 
			case 6:quit();  return;  //�˳�����ƽ̨ϵͳ 
		} 
	    cin.get();
	}while(1);
}

//�������û���Ϣ���浽�ṹ 
void plantform::load()
{
	int i=0;
	int j=0;
	int flag=0;
	int n;
	string buffer;
	string usernm;
	string passwd;
	float money;
	int cardnum;
	string cardaccount;
	
	ifstream userfile;
	userfile.open("userdat.txt",ios::in);
    if(!userfile)
    {
	   cerr<<"���ļ�����"<<endl;
	   abort();
	   return;	 
    }
    
	userfile>>buffer;
	userfile>>usernum;  //��ȡ�û�����  ȫ�ֱ��� 
	userfile>>buffer;
	
	while(i<usernum)
	{
		curuser=i;
		userfile>>buffer;    //���ļ��е����ݴ���ṹ�� 
		userfile>>usernm;
		userptr[i].set_username(usernm);
		userfile>>buffer;
		userfile>>passwd;
		userptr[i].set_passwd(passwd);
		userfile>>buffer;
		for(j=0;j<9;j++)
		{
			userfile>>n;
			userptr[i].set_shopcart(j,n);
		}
        userfile>>buffer;
		userfile>>money;
		userptr[i].set_total(money);
		userfile>>buffer;
		userfile>>cardnum;
		userptr[i].set_cardnum(cardnum);
		if(cardnum==0)
		{
			userfile>>buffer;
			userfile>>buffer;
			cardaccount='0';
			userptr[i].set_cardaccount(0,cardaccount);
		}
		else
		{
            userfile>>buffer;
			for(j=0;j<cardnum-1;j++)
			{
				userfile>>cardaccount;
				userfile>>buffer;
				userptr[i].set_cardaccount(j,cardaccount);				
			}
			userfile>>cardaccount;
			userptr[i].set_cardaccount(j,cardaccount);		    
		}				
		i++;  
	}    
	userfile.close();
	if(i==0)
	{
		cout<<"�����û���Ϣ��"<<endl; 
	}
	else
	    cout<<usernum<<"��ȡ�û�����������"<<endl;
	    
  /*	 for(i=0;i<usernum;i++)
	 {
 		curuser=i;
 		cout<<"��ţ�"<<curuser<<endl;
 		showinfo();
 	 }    */	     
    return;
} 
void plantform::loadproduct()
{
    int i=0;

	int proid;
	string des;
	float oprice;
	int rest;
	float discnt;
	string buffer;
	
	ifstream profile;
	profile.open("product.txt",ios::in);
	if(!profile)
	{
		cerr<<"���ļ�����"<<endl;
		abort();
		return;
	}	
	profile>>buffer;
	profile>>pronum;
	profile>>buffer;
	
	while(i<pronum)
	{
		profile>>buffer;
		profile>>proid; 
		profile>>buffer;
		profile>>des;
		profile>>buffer;
		profile>>oprice;
		profile>>buffer;
		profile>>rest;
		profile>>buffer;
		profile>>discnt;
		
		switch(i)
		{
		    case 0: app.set_proid(proid); app.set_discription(des); app.set_oriprice(oprice); app.set_rstnum(rest); app.set_discount(discnt);  break;  
			case 1: bre.set_proid(proid); bre.set_discription(des); bre.set_oriprice(oprice); bre.set_rstnum(rest); bre.set_discount(discnt);  break;  
			case 2: milkt.set_proid(proid); milkt.set_discription(des); milkt.set_oriprice(oprice); milkt.set_rstnum(rest); milkt.set_discount(discnt);  break;  
			case 3: shi.set_proid(proid); shi.set_discription(des); shi.set_oriprice(oprice); shi.set_rstnum(rest); shi.set_discount(discnt);  break;  
			case 4: ski.set_proid(proid); ski.set_discription(des); ski.set_oriprice(oprice); ski.set_rstnum(rest); ski.set_discount(discnt); break;  
			case 5: pan.set_proid(proid); pan.set_discription(des); pan.set_oriprice(oprice); pan.set_rstnum(rest); pan.set_discount(discnt);  break;  
			case 6: CPri.set_proid(proid); CPri.set_discription(des); CPri.set_oriprice(oprice); CPri.set_rstnum(rest); CPri.set_discount(discnt); break;  
			case 7: EffectC.set_proid(proid); EffectC.set_discription(des); EffectC.set_oriprice(oprice); EffectC.set_rstnum(rest); EffectC.set_discount(discnt);  break;  
			case 8: HeadFJ.set_proid(proid); HeadFJ.set_discription(des); HeadFJ.set_oriprice(oprice); HeadFJ.set_rstnum(rest); HeadFJ.set_discount(discnt); break;  
		}		
		i++; 
	}
	
	profile.close();
	cout<<"��ȡ��Ʒ��Ϣ������"<<endl; 
}

void plantform::loaddis()
{
	string buffer;
	ifstream disfile;
	disfile.open("discount.txt",ios::in);
	
	if(!disfile)
	{
		cerr<<"���ļ�����"<<endl;
	    abort();
	    return;	
	}
	disfile>>temp;
	if(temp=="�Żݣ�")
	{
		disfile>>buffer;
		disfile>>enough;
		disfile>>buffer;
		disfile>>sub;
		
		
		disfile>>buffer;
		disfile>>fooddis;	
		app.set_discount(fooddis);
		bre.set_discount(fooddis);
		milkt.set_discount(fooddis);
		
		disfile>>buffer;
		disfile>>clothdis;		
		shi.set_discount(clothdis);
		ski.set_discount(clothdis);
		pan.set_discount(clothdis); 
		
		disfile>>buffer;
		disfile>>bookdis;			
		CPri.set_discount(bookdis); 
		EffectC.set_discount(bookdis);
		HeadFJ.set_discount(bookdis);
	} 
	else
	{
		cout<<"�����Ż���Ϣ��"<<endl;
	}
	disfile.close();
	return;	
} 

void plantform::showproduct()
{
	int i=0;
    int proid;
	string des;
	float oprice;
	int rest;
	float discnt;	
	cout<<"���� "<<pronum<<" ����Ʒ��"<<endl; 
	
	while(i<pronum)
	{
		switch(i)
		{
		    case 0: proid=app.getproid(); des=app.getdescription(); oprice=app.getoriprice(); rest=app.getrestnum(); discnt=app.getdiscount(); break;  
			case 1: proid=bre.getproid(); des=bre.getdescription(); oprice=bre.getoriprice(); rest=bre.getrestnum(); discnt=bre.getdiscount(); break;  
			case 2: proid=milkt.getproid(); des=milkt.getdescription(); oprice=milkt.getoriprice(); rest=milkt.getrestnum(); discnt=milkt.getdiscount(); break;   
			case 3: proid=shi.getproid(); des=shi.getdescription(); oprice=shi.getoriprice(); rest=shi.getrestnum(); discnt=shi.getdiscount(); break;   
			case 4: proid=ski.getproid(); des=ski.getdescription(); oprice=ski.getoriprice(); rest=ski.getrestnum(); discnt=ski.getdiscount(); break;    
			case 5: proid=pan.getproid(); des=pan.getdescription(); oprice=pan.getoriprice(); rest=pan.getrestnum(); discnt=pan.getdiscount(); break;  
			case 6: proid=CPri.getproid(); des=CPri.getdescription(); oprice=CPri.getoriprice(); rest=CPri.getrestnum(); discnt=CPri.getdiscount(); break;    
			case 7: proid=EffectC.getproid(); des=EffectC.getdescription(); oprice=EffectC.getoriprice(); rest=EffectC.getrestnum(); discnt=EffectC.getdiscount(); break;    
			case 8: proid=HeadFJ.getproid(); des=HeadFJ.getdescription(); oprice=HeadFJ.getoriprice(); rest=HeadFJ.getrestnum(); discnt=HeadFJ.getdiscount(); break;    
		}		
	
		cout<<"��ƷID��"<<proid<<endl;; 
		cout<<"��Ʒ������"<<des<<endl;
		cout<<"��Ʒԭ�ۣ�"<<oprice<<endl;
		cout<<"��Ʒʣ������"<<rest<<endl;
		cout<<"��Ʒ�ۿۣ�"<<discnt<<endl<<endl;
				
		i++; 
	}

	cout<<"��ӭѡ����"<<endl;
	return;	
}

void plantform::showdiscount()
{
	if(temp=="�Żݣ�")
	{
		cout<<"�Żݣ�"<<endl;
		cout<<"��"<<enough<<"��"<<sub<<"!"<<endl; 
		cout<<"ʳƷȫ��"<<fooddis*10<<"��"<<endl; 
		cout<<"��װȫ��"<<clothdis*10<<"��"<<endl;
		cout<<"ͼ��ȫ��"<<bookdis*10<<"��"<<endl;
	} 
	else
	    cout<<"�����Ż���Ϣ��"<<endl; 
} 

void plantform::setaccount()
{
	int i=0;
	int j;
	int num;
	string newuser;
	string pass;
	string pass1;
	int cardnum;
	string cardaccount;
    
    cout<<"�����������û�����" ;
    cin>>newuser;
    
    while((i<usernum)&&(newuser!=userptr[i].getusername()))
    {
    	i++;
    }
	
	if(newuser==userptr[i].getusername())
    {
    	cout<<"���û����ѱ�ռ�ã��밴�����������һ���˵���"<<endl;
    	return;
    }
	else
	{
        cout<<"�����û���Ϊ"<<newuser<<endl;
        userptr[usernum].set_username(newuser);
		cout<<"�������������룺";
		cin>>pass;
		cout<<"���ٴ�������ȷ�ϣ�";
		cin>>pass1;
		while(pass!=pass1)
		{
			cout<<"�������벻ƥ�䣬���������룺";
			cin>>pass;
		    cout<<"���ٴ�������ȷ�ϣ�";
		    cin>>pass1;			 
		} 
		userptr[usernum].set_passwd(pass);
		for(j=0;j<9;j++)
        userptr[usernum].set_shopcart(j,0);            
		userptr[usernum].set_total(0);
		cout<<"����������п��˺�����";
		cin>>cardnum;
		if(cardnum==0)
		{
			userptr[usernum].set_cardnum(0);
			cardaccount='0';
			userptr[usernum].set_cardaccount(0,cardaccount);
		} 
		else
		{
			for(j=0;j<cardnum;j++)
			{
			    userptr[usernum].set_cardnum(cardnum);
				cout<<"�������"<<j+1<<"�����п��˺ţ�";
				cin>>cardaccount;
			    userptr[usernum].set_cardaccount(j,cardaccount);
			}
		}
		
	    curuser=usernum;
		cout<<"�û���Ϣ��������ϣ�ע��ɹ���"<<endl;
		cout<<"�û�����"<<userptr[usernum].getusername()<<endl;
		cout<<"���룺"<<userptr[usernum].getpasswd()<<endl;
		cout<<"���ﳵ���տ���Ҳ��"<<endl;
		cout<<"Ӧ������ܼƣ�"<<userptr[usernum].gettotal()<<endl;
		cout<<"�����п�����"<<userptr[usernum].getcardnum()<<endl;
		for(j=0;j<userptr[i].getcardnum();j++)
		{
			cout<<"�����˺�"<<j+1<<": "<<userptr[i].getcardaccount(j)<<endl;
		}
		cout<<endl;
		
		usernum++;
		cout<<usernum<<endl;
		saveuser();
		cin.get();
	}		
}

void plantform::login()
{
	int i=0;
	int choice;
	string usernm;
	string pass;
	
	cout<<"�����������û�����"<<endl;
	cin>>usernm;
    curuser=i;
	while((i<usernum)&&(usernm!=userptr[i].getusername()))
	{
		i++;
		curuser=i;
	}
	
	cout<<curuser<<endl;
	if(i==usernum)
	     cout<<"���û��������ڣ��밴�����������һ���˵���"<<endl;
    else
    {
    	cout<<"���������룺"<<endl;
    	cin>>pass;
    	while(pass!=userptr[i].getpasswd())
    	{
	    	cout<<"����������������룡"<<endl;
	    	cin>>pass;
	    }
	    cout<<"��½�ɹ���"<<endl;
	    curuser=i;
	    do
	    {
    		cout<<"*****************************************"<<endl;
			cout<<"*         ��ѡ����Ҫ�Ĳ�����ţ�        *"<<endl;
			cout<<"*          0.�鿴������Ϣ               *"<<endl; 
			cout<<"*          1.�鿴���ﳵ                 *"<<endl;
			cout<<"*          2.�����Ʒ�����ﳵ           *"<<endl;
			cout<<"*          3.�ύ����                   *"<<endl;
			cout<<"*          4.ɾ�����ﳵ����Ʒ           *"<<endl;
			cout<<"*          5.������һ��˵�             *"<<endl;
			cout<<"*****************************************"<<endl;
			
			cin>>choice;
			while(choice<0||choice>5)
			{
				cout<<"����������������룡"<<endl;
				cin>>choice;
			}
			switch(choice)
			{
				case 0: showinfo();  break; 
				case 1: showshopcart(); break;
				case 2: addshopcart(); break;
				case 3: order();  break;
				case 4: delshopcart();  break; 
				case 5: return;
			}
			cin.get();
    	}while(1);
     }
}

void plantform::saveuser()
{
	int i;
	int j;
	ofstream userfile;
	userfile.open("userdat.txt",ios::out);
	if(!userfile)
	{
		cerr<<"���ļ�����"<<endl;
		abort();
	}
	else
	{
		cout<<"���� "<<usernum<<" ���û��˺ţ�" <<endl;
		userfile<<"���� ";
		userfile<<usernum;
		userfile<<" ���û��˺ţ�"<<endl;
		for(i=0;i<usernum;i++)
		{
			curuser=i;
			userfile<<"�û����� ";
			userfile<<userptr[i].getusername()<<endl;
			userfile<<"���룺 ";
			userfile<<userptr[i].getpasswd()<<endl;
			userfile<<"���ﳵ�� ";
			for(j=0;j<9;j++) 
			{
				userfile<<userptr[i].getshopcart(j)<<" ";
			}
			userfile<<endl;
			userfile<<"Ӧ���ܽ� ";
			userfile<<userptr[i].gettotal()<<endl;
			userfile<<"�����˻����� "<<userptr[i].getcardnum()<<endl;
			if(userptr[i].getcardnum()==0)
			{
				userfile<<"�����˺�: ��"<<endl;
			}
			else
			{
				for(j=0;j<userptr[i].getcardnum();j++)
		       {
			       userfile<<"�����˺�"<<j+1<<": "<<userptr[i].getcardaccount(j)<<endl;
		       }
			}
		    userfile<<endl;					 
		} 
		cout<<"�û����ݱ���ɹ���"<<endl;
	}
	userfile.close();
}

void plantform::logoff()
{
	curuser=0;
	cout<<"���˳���¼,ллʹ�ã�"<<endl;
	return;
}

void plantform::quit() 
{
	cout<<"��л����ʹ�ã��ټ���"<<endl;
	return;
}

void plantform::showinfo()
{
     int flag=0;
     int j;
     cout<<"�û�����"<<userptr[curuser].getusername()<<endl;
     cout<<"���룺"<<userptr[curuser].getpasswd()<<endl;
     cout<<"���ﳵ��"; 
  	 for(j=0;j<9;j++)
	{
		if(userptr[curuser].getshopcart(j)==0)
		    continue;
        else
		{
            switch(j)
            {
           	    case 0: cout<<"ƻ����"<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
	           	case 1: cout<<"�����"<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
	           	case 2: cout<<"�̲裺"<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
	           	case 3: cout<<"T����"<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
	           	case 4: cout<<"ȹ�ӣ�"<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
	           	case 5: cout<<"���ӣ�"<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
	           	case 6: cout<<"C++Primer��"<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
	           	case 7: cout<<"EffectiveC++��"<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
	           	case 8: cout<<"HeadFirstJava��"<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
            }
         }
	} 
	cout<<endl;
	if(flag==0)
        cout<<"�տ���Ҳ�������ӵ㶫���ɣ�"<<endl;  
	cout<<"Ӧ�����Żݽ����ύ����ʱ���㣩��"<<userptr[curuser].gettotal()<<endl;
	cout<<"�����˻�����"<<userptr[curuser].getcardnum()<<endl;
	for(j=0;j<userptr[curuser].getcardnum();j++)
	{
		cout<<"�����˺�"<<j+1<<": "<<userptr[curuser].getcardaccount(j);
	}
	cout<<endl;	
	return; 
}

void plantform::showshopcart()
{
	int i;
	int flag=0;
	int j;
	i=curuser;
	cout<<curuser<<endl;
	cout<<"���ﳵ��"<<endl;
	for(j=0;j<9;j++)
	{
		if(userptr[i].getshopcart(j)==0)
		    continue;
        else
        {
           	switch(j)
           	{
	           		case 0: cout<<"ƻ����"<<userptr[i].getshopcart(j)<<" "; flag=1; break;
	            	case 1: cout<<"�����"<<userptr[i].getshopcart(j)<<" "; flag=1; break;
	            	case 2: cout<<"�̲裺"<<userptr[i].getshopcart(j)<<" "; flag=1; break;
	            	case 3: cout<<"T����"<<userptr[i].getshopcart(j)<<" "; flag=1; break;
	            	case 4: cout<<"ȹ�ӣ�"<<userptr[i].getshopcart(j)<<" "; flag=1; break;
	            	case 5: cout<<"���ӣ�"<<userptr[i].getshopcart(j)<<" "; flag=1; break;
	            	case 6: cout<<"C++Primer��"<<userptr[i].getshopcart(j)<<" "; flag=1; break;
	            	case 7: cout<<"EffectiveC++��"<<userptr[i].getshopcart(j)<<" "; flag=1; break;
	            	case 8: cout<<"HeadFirstJava��"<<userptr[i].getshopcart(j)<<" "; flag=1; break;
					 
            }
	    }
	} 
	if(flag==0)
	   cout<<"�տ���Ҳ��"<<endl;
	cout<<endl;  
    return;
}

void plantform::addshopcart()
{
	int choice;
	int num;
	float totalmoney;
	float totalnow;
	int rest;
	int temp;
	temp=curuser;
	
     cout<<"��������Ҫ��ӵ���ƷID��"; 
     cin>>choice;
     cout<<"���������������";
	 cin>>num; 
     
     if(choice==0)
     {
     	if(app.getrestnum()==0)
     	   cout<<"��Ʒ���¼ܣ���ѡ��������"<<endl;
        else
        {
        	while(app.getrestnum()<num)
        	{
	        	 cout<<"��Ʒʣ����Ϊ"<<app.getrestnum()<<"�����ʵ���������";
				 cin>>num; 
	        }
	        totalnow=num*app.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(0,userptr[curuser].getshopcart(0)+num);
	        app.set_rstnum(app.getrestnum()-num);
	        cout<<"�ѽ�"<<num<<"��ƻ�����빺�ﳵ��"<<endl;	       			   
        }
     }
     else  if(choice==1)
     {
     	if(bre.getrestnum()==0)
     	   cout<<"��Ʒ���¼ܣ���ѡ��������"<<endl;
        else
        {
        	while(bre.getrestnum()<num)
        	{
	        	 cout<<"��Ʒʣ����Ϊ"<<bre.getrestnum()<<"�����ʵ���������";
				 cin>>num; 
	        }
	        totalnow=num*bre.getPrice();
            //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
            userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(1,userptr[curuser].getshopcart(1)+num);
	        bre.set_rstnum(bre.getrestnum()-num);
	        cout<<"�ѽ�"<<num<<"��������빺�ﳵ��"<<endl;
	     		   
        }
     }
     else  if(choice==2)
     {
     	if(milkt.getrestnum()==0)
     	   cout<<"��Ʒ���¼ܣ���ѡ��������"<<endl;
        else
        {
        	while(milkt.getrestnum()<num)
        	{
	        	 cout<<"��Ʒʣ����Ϊ"<<milkt.getrestnum()<<"�����ʵ���������";
				 cin>>num; 
	        }
	        totalnow=num*milkt.getPrice();
            //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
            userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(2,userptr[curuser].getshopcart(2)+num);
	        milkt.set_rstnum(milkt.getrestnum()-num);
	        cout<<"�ѽ�"<< num<<"���̲���빺�ﳵ��"<<endl;
	 		   
        }
     }
	 else  if(choice==3)
     {
     	if(shi.getrestnum()==0)
     	   cout<<"��Ʒ���¼ܣ���ѡ��������"<<endl;
        else
        {
        	while(shi.getrestnum()<num)
        	{
	        	 cout<<"��Ʒʣ����Ϊ"<<shi.getrestnum()<<"�����ʵ���������";
				 cin>>num; 
	        }
	        totalnow=num*shi.getPrice();
            //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
            userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(3,userptr[curuser].getshopcart(3)+num);
	        shi.set_rstnum(shi.getrestnum()-num);
	        cout<<"�ѽ�"<< num<<"��T�����빺�ﳵ��"<<endl;
	  		   
        }
     }
	 else  if(choice==4)
     {
     	if(ski.getrestnum()==0)
     	   cout<<"��Ʒ���¼ܣ���ѡ��������"<<endl;
        else
        {
        	while(ski.getrestnum()<num)
        	{
	        	 cout<<"��Ʒʣ����Ϊ"<<ski.getrestnum()<<"�����ʵ���������";
				 cin>>num; 
	        }
	        totalnow=num*ski.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(4,userptr[curuser].getshopcart(4)+num);
	        ski.set_rstnum(ski.getrestnum()-num);
	        cout<<"�ѽ�"<< num<<"��ȹ�Ӽ��빺�ﳵ��"<<endl;
	   		   
        }
     }
	 else  if(choice==5)
     {
     	if(pan.getrestnum()==0)
     	   cout<<"��Ʒ���¼ܣ���ѡ��������"<<endl;
        else
        {
        	while(pan.getrestnum()<num)
        	{
	        	 cout<<"��Ʒʣ����Ϊ"<<pan.getrestnum()<<"�����ʵ���������";
				 cin>>num; 
	        }
	        totalnow=num*pan.getPrice();
            //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
            userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
            userptr[curuser].set_shopcart(5,userptr[curuser].getshopcart(5)+num);
	        pan.set_rstnum(pan.getrestnum()-num);
	        cout<<"�ѽ�"<< num<<"��������빺�ﳵ��"<<endl;
	     		   
        }
     }
	 else  if(choice==6)
     {
     	if(CPri.getrestnum()==0)
     	   cout<<"��Ʒ���¼ܣ���ѡ��������"<<endl;
        else
        {
        	while(CPri.getrestnum()<num)
        	{
	        	 cout<<"��Ʒʣ����Ϊ"<<CPri.getrestnum()<<"�����ʵ���������";
				 cin>>num; 
	        }
	        totalnow=num*CPri.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
            userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
            userptr[curuser].set_shopcart(6,userptr[curuser].getshopcart(6)+num);
	        CPri.set_rstnum(CPri.getrestnum()-num);
	        cout<<"�ѽ�"<<num<<"��C++Primer���빺�ﳵ��"<<endl;
	     		   
        }
     }
	 else  if(choice==7)
     {
     	if(EffectC.getrestnum()==0)
     	   cout<<"��Ʒ���¼ܣ���ѡ��������"<<endl;
        else
        {
        	while(EffectC.getrestnum()<num)
        	{
	        	 cout<<"��Ʒʣ����Ϊ"<<EffectC.getrestnum()<<"�����ʵ���������";
				 cin>>num; 
	        }
	        totalnow=num*EffectC.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
            userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
            userptr[curuser].set_shopcart(7,userptr[curuser].getshopcart(7)+num);
	        EffectC.set_rstnum(EffectC.getrestnum()-num);
	        cout<<"�ѽ�"<< num<<"��Effective C++���빺�ﳵ��"<<endl;
	      		   
        }
     } 
     else  if(choice==8)
     {
     	if(HeadFJ.getrestnum()==0)
     	   cout<<"��Ʒ���¼ܣ���ѡ��������"<<endl;
        else
        {
        	while(HeadFJ.getrestnum()<num)
        	{
	        	 cout<<"��Ʒʣ����Ϊ"<<HeadFJ.getrestnum()<<"�����ʵ���������";
				 cin>>num; 
	        }
	        totalnow=num*HeadFJ.getPrice();
            //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
            userptr[curuser].set_shopcart(8,userptr[curuser].getshopcart(8)+num);
	        HeadFJ.set_rstnum(HeadFJ.getrestnum()-num);
	        cout<<"�ѽ�"<< num<<"��HeadFirstJava���빺�ﳵ��"<<endl;
	    		   
        }
     }
	 else
	 {
 		cout<<"�������ݴ����밴�����������һ���˵��鿴��Ʒ��Ϣ��"<<endl;
 	} 
 	saveuser();
 	curuser=temp;
 	return;
}

void plantform::delshopcart()
{
	int choice;
	int num;
	float totalmoney;
	float totalnow;
	int rest;
	int temp;
	temp=curuser;
	
	 showshopcart();
	
     cout<<"��������Ҫɾ������ƷID��"; 
     cin>>choice;
     cout<<"������ɾ��������";
	 cin>>num; 
     
     if(choice==0)
     {
     	if(userptr[curuser].getshopcart(0)==0)
     	   cout<<"δ��ƻ�����빺�ﳵ����ѡ��������"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(0)<num)
        	{
	        	 cout<<"���ﳵ�и���Ʒ����"<<userptr[curuser].getshopcart(0)<<"������������ȷ���֣�";
				 cin>>num; 
	        }
	        totalnow=num*app.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(0,userptr[curuser].getshopcart(0)-num);
	        app.set_rstnum(app.getrestnum()+num);
	        cout<<"�ѽ�"<< num<<"��ƻ���ӹ��ﳵ��ɾ����"<<endl;
	       			   
        }
     }
     else  if(choice==1)
     {
     	if(userptr[curuser].getshopcart(1)==0)
     	   cout<<"δ��������빺�ﳵ����ѡ��������"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(1)<num)
        	{
	        	 cout<<"���ﳵ�и���Ʒ����"<<userptr[curuser].getshopcart(1)<<"������������ȷ���֣�";
				 cin>>num; 
	        }
	        totalnow=num*bre.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(1,userptr[curuser].getshopcart(1)-num);
	        bre.set_rstnum(bre.getrestnum()+num);
	        cout<<"�ѽ�"<< num<<"������ӹ��ﳵ��ɾ����"<<endl;
	       			   
        }
     }
     else  if(choice==2)
     {
     	if(userptr[curuser].getshopcart(2)==0)
     	   cout<<"δ���̲���빺�ﳵ����ѡ��������"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(2)<num)
        	{
	        	 cout<<"���ﳵ�и���Ʒ����"<<userptr[curuser].getshopcart(2)<<"������������ȷ���֣�";
				 cin>>num; 
	        }
	        totalnow=num*milkt.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(2,userptr[curuser].getshopcart(2)-num);
	        milkt.set_rstnum(milkt.getrestnum()+num);
	        cout<<"�ѽ�"<< num<<"���̲�ӹ��ﳵ��ɾ����"<<endl;
	       			   
        }
     }
	 else  if(choice==3)
     {
     	if(userptr[curuser].getshopcart(3)==0)
     	   cout<<"δ��T�����빺�ﳵ����ѡ��������"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(3)<num)
        	{
	        	 cout<<"���ﳵ�и���Ʒ����"<<userptr[curuser].getshopcart(3)<<"������������ȷ���֣�";
				 cin>>num; 
	        }
	        totalnow=num*shi.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(3,userptr[curuser].getshopcart(3)-num);
	        shi.set_rstnum(shi.getrestnum()+num);
	        cout<<"�ѽ�"<< num<<"��T���ӹ��ﳵ��ɾ����"<<endl;
	       			   
        }
     }
	 else  if(choice==4)
     {
     	if(userptr[curuser].getshopcart(4)==0)
     	   cout<<"δ��ȹ�Ӽ��빺�ﳵ����ѡ��������"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(4)<num)
        	{
	        	 cout<<"���ﳵ�и���Ʒ����"<<userptr[curuser].getshopcart(4)<<"������������ȷ���֣�";
				 cin>>num; 
	        }
	        totalnow=num*ski.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(4,userptr[curuser].getshopcart(4)-num);
	        ski.set_rstnum(ski.getrestnum()+num);
	        cout<<"�ѽ�"<< num<<"��ȹ�Ӵӹ��ﳵ��ɾ����"<<endl;
	       			   
        }
     }
	 else  if(choice==5)
     {
     	if(userptr[curuser].getshopcart(5)==0)
     	   cout<<"δ��������빺�ﳵ����ѡ��������"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(5)<num)
        	{
	        	 cout<<"���ﳵ�и���Ʒ����"<<userptr[curuser].getshopcart(5)<<"������������ȷ���֣�";
				 cin>>num; 
	        }
	        totalnow=num*pan.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(5,userptr[curuser].getshopcart(5)-num);
	        pan.set_rstnum(pan.getrestnum()+num);
	        cout<<"�ѽ�"<< num<<"������ӹ��ﳵ��ɾ����"<<endl;
	       			   
        }
     }
	 else  if(choice==6)
     {
     	if(userptr[curuser].getshopcart(6)==0)
     	   cout<<"δ��C++Primer���빺�ﳵ����ѡ��������"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(6)<num)
        	{
	        	 cout<<"���ﳵ�и���Ʒ����"<<userptr[curuser].getshopcart(6)<<"������������ȷ���֣�";
				 cin>>num; 
	        }
	        totalnow=num*CPri.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(6,userptr[curuser].getshopcart(6)-num);
	        CPri.set_rstnum(CPri.getrestnum()+num);
	        cout<<"�ѽ�"<< num<<"��C++Primer�ӹ��ﳵ��ɾ����"<<endl;
	       			   
        }
     }
	 else  if(choice==7)
     {
     	if(userptr[curuser].getshopcart(7)==0)
     	   cout<<"δ��EffectiveC++���빺�ﳵ����ѡ��������"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(7)<num)
        	{
	        	 cout<<"���ﳵ�и���Ʒ����"<<userptr[curuser].getshopcart(7)<<"������������ȷ���֣�";
				 cin>>num; 
	        }
	        totalnow=num*EffectC.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(7,userptr[curuser].getshopcart(7)-num);
	        EffectC.set_rstnum(EffectC.getrestnum()+num);
	        cout<<"�ѽ�"<< num<<"��Effective C++�ӹ��ﳵ��ɾ����"<<endl;
	       			   
        }
     }
     else if(choice==8)
     {
     	if(userptr[curuser].getshopcart(8)==0)
     	   cout<<"δ��HeadFirstJava���빺�ﳵ����ѡ��������"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(8)<num)
        	{
	        	 cout<<"���ﳵ�и���Ʒ����"<<userptr[curuser].getshopcart(8)<<"������������ȷ���֣�";
				 cin>>num; 
	        }
	        totalnow=num*HeadFJ.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(8,userptr[curuser].getshopcart(8)-num);
	        HeadFJ.set_rstnum(HeadFJ.getrestnum()+num);
	        cout<<"�ѽ�"<< num<<"��HeadFirstJava�ӹ��ﳵ��ɾ����"<<endl;
	       			   
        }
     }
	 else
	 {
 		cout<<"�������ݴ����밴�����������һ���˵��鿴��Ʒ��Ϣ��"<<endl;
 	 } 
 	saveuser();
 	curuser=temp;
 	return;
}

void plantform::order()
{
	float money;
	float last;
	int i;
	int choice;
	money=userptr[curuser].gettotal();
	if((enough!=0)&&(sub!=0))
	{
		i=money/enough;
    	last=money-i*sub;
	}
	
	cout<<"�����ύ�ɹ������踶��"<<last<<"!"<<endl;
	userptr[curuser].set_total(last);
	if(last!=0)
	{
		cout<<"��ѡ��֧����ʽ�� 1.����֧��   2.��������"<<endl;
	    cin>>choice;
	    while((choice!=1)&&(choice!=2))
	   {
		    cout<<"����������������룡"<<endl;
		    cin>>choice;
	   }
	   if(choice==1)
	        payingonline();
       else
            cout<<"������Ʒ�������������ڴ���"<<endl;
	 }
	 else
	 {
 		cout<<"��ѡ����Ʒ�����ﳵ��"<<endl;
 	 }
	
	return; 
}

void plantform::payingonline()
{
	WORD wVersionRequested;
    WSADATA wsaData;
    int err=0;
    int choice;
    int cardnum;
    string cardaccount;
    char buff[1024];
    char key[10];
    float total; 
    int j; 
    int flag=0;
    int temp;
    temp=curuser;
 
    wVersionRequested = MAKEWORD( 2, 2 );
    err = WSAStartup( wVersionRequested, &wsaData ); 
    SOCKET sc=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
 
    SOCKADDR_IN addr;
    int len;
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(1002);
    len=sizeof(addr);
    connect(sc, (struct sockaddr *)&addr, len);
    cout<<curuser;
    cardnum=userptr[curuser].getcardnum();
    cout<<"�����п�����"<<cardnum<<endl;
  if(userptr[curuser].getcardnum()==0)
  {
    	cout<<"�����п��󶨣�������������ϼ��˵���"<<endl;
  }
  else
  {
	for(j=0;j<userptr[curuser].getcardnum();j++)
	{
	    cout<<"�����˺�"<<j+1<<": "<<userptr[curuser].getcardaccount(j)<<endl;
	}
    if(cardnum==1)
        cardaccount=userptr[curuser].getcardaccount(0);
    else
    {
    	cout<<"��������ѡ�����п���ţ�"<<endl;
    	cin>>choice;
    	cardaccount=userptr[curuser].getcardaccount(choice-1);
    }
    cout<<cardaccount;
    memset(buff,0,sizeof(buff));   //��buffer���
	int i;
	for(i=0;i<cardaccount.length();i++)    //���������˻� 
        buff[i]=cardaccount[i];
    buff[i]='\0';
    printf("send a message:");  
    send(sc,buff,1024,0);
    cout<<buff;
    printf("\n");
    

    memset(buff,0,sizeof(buff));   //��buffer���
    printf("recieve a message:");  //�յ������������ʾ 
    recv(sc,buff,1024,0);
    cout<<buff<<endl;
    if(buff=="���û������ڣ�֧��ʧ�ܣ�")
    {
    	return;
    } 
    
    memset(buff,0,sizeof(buff));   //��buffer���
    printf("send a message: ");
	cin>>key;  
   // fgets(key, 1024, stdin);   //�������� 
    send(sc,key,10,0);
    printf("\n");
    
    memset(buff,0,sizeof(buff));   //��buffer���
    printf("recieve a message:");  //�յ���������ʾ 
    recv(sc,buff,1024,0);
    cout<<buff<<endl;
    if(buff=="�������֧��ʧ�ܣ�")
    {
    	return;
    } 
    
    memset(buff,0,sizeof(buff));   //��buffer���
    printf("send a message: ");  
    total=userptr[curuser].gettotal();  //����֧����� 
    sprintf(buff, "%5.2f",total);
    send(sc,buff,1024,0);
    cout<<total;
    printf("\n");
   
    memset(buff,0,sizeof(buff));   //��buffer���
    printf("recieve a message:");  //�յ�������Ϣ 
    recv(sc,buff,1024,0);
    cout<<buff<<endl;
      	int temp;
        cout<<"1"<<endl;
    	    for(i=0;i<9;i++)
            {  
    	       temp=userptr[curuser].getshopcart(i);
    	       if(temp!=0)
    	       {    
                     userptr[curuser].set_shopcart(i,0);
                     cout<<userptr[curuser].getshopcart(i)<<" ";
               }
    	           
            }
            cout<<endl;
            userptr[curuser].set_total(0);                
  }
  closesocket(sc);
  saveuser(); 
  curuser=temp;
  return;
}

int main()
{
	plantform plaform;
	plaform.function();
		
	system("pause");
	return 0;
}



