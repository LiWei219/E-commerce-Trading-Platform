/*电商平台设计*/
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

class product   //产品基类 
{
    public:
        product()   //无参数的构造函数 
        {
        	proid=0;
        	description="No information yet!";
        	oriprice=0;
        	restnum=0;
        }
        product(int pid,string des,float oprice,int rest)   //有参数的构造函数 
        {
        	proid=pid;
        	description=des;
        	oriprice=oprice;
        	restnum=rest;
        }
        
        int getproid() {return proid;}   //通过这几个函数获得产品类的私有信息产品ID、描述、原价、剩余量 
        string getdescription() {return description;}
        float getoriprice() {return oriprice;}
        int getrestnum() {return restnum;}
        
        void set_proid(int pid);   //通过这几个函数对产品的私有信息进行设置 
        void set_discription(string des);
        void set_oriprice(float oprice);
        void set_rstnum(int rest);
        
        virtual float getPrice();
        
    private:    //product的私有数据 
	    int proid; 
	    string description;
	    float oriprice;
	    int restnum;
};
void product::set_proid(int pid)//设置产品ID 
{
	proid=pid;
}
void product::set_discription(string des)//设置产品描述 
{
	description=des;
}
void product::set_oriprice(float oprice)//设置产品原价 
{
	oriprice=oprice;
}
void product::set_rstnum(int rest)//设置产品剩余量 
{
	restnum=rest;
}
float product::getPrice() //虚函数定义，返回原价 
{
	return oriprice;
}

class food:public product //食品类，继承产品类 ，在原来基础上多了折扣系数的相关变量及操作 
{
    public:
	   food()
	   {
   		    product();
   		    discount=1;
   	   }
	   float getdiscount() {return discount;}  //获取折扣系数 
	   void set_discount(float discnt);   //设置折扣系数 
	   
       virtual float getPrice();
   
    private:
       float discount;	 	
};
void food::set_discount(float discnt) //设置折扣系数 
{
	discount=discnt;
}
float food::getPrice() //计算产品价格 
{
	float price;
	price=getoriprice();
	
	return price*discount;
}
class clothes:public product   //衣服类，继承产品类 ，在原来基础上多了折扣系数的相关变量及操作，同食品类 
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
class book:public product  //图书类，继承产品类 ，在原来基础上多了折扣系数的相关变量及操作，同食品类 
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

class apple:public food //苹果类，继承食品类 
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
	return price*getdiscount();  //计算返回在打折后的价格 
}
class bread:public food  //面包类，继承食品类 
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
class milktea:public food  //奶茶类，继承食品类 
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
class shirt:public clothes  //T恤类，继承服装类 
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
class skirt:public clothes   //裙子类，继承服装类
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
class pants:public clothes   //长裤类，继承服装类
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
class CPrimer:public book  //C++Primer类，继承图书类 
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
class EffectiveC:public book  //Effective C++类，继承图书类 
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

class HeadFirstJava:public book  //Head First Java类，继承图书类 
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
	    
    	void set_username(string name);  //设置用户名、密码以及购物车及应付金额 
		void set_passwd(string pass);
		void set_shopcart(int i,int n);
		void set_total(float m); 
		void set_cardnum(int n);  //绑定银行卡数 
		void set_cardaccount(int i,string account);  //银行卡账号 
		
	    float gettotal();  //计算总价 
	    string getusername();  //获取用户名 
	    string getpasswd();   //获取用户密码
		int getshopcart(int n); //获取用户购物车信息 
		int getcardnum();   //获取银行卡数 
		string getcardaccount(int n);  //获取银行卡账号 
	    	    
	    void function();  //功能界面 
	    void load();  //下载用户信息
	    void loadproduct();  //下载商品信息 
		void loaddis();   //下载当前优惠活动
		 
	    void saveuser();  //保存用户信息 
	    void setaccount();  //注册用户 
	    void login();  //登陆 
	    void logoff();   //退出登陆
		void quit();  //退出系统 
				    
	    void showproduct();  //查看商品
		void showdiscount();  //查看优惠 
		void showinfo();   //查看个人信息 
		void showshopcart();  //查看购物车 
	    void addshopcart();  //加入购物车
		void delshopcart();   //删除购物车中商品
	    void order();  //提交订单 
	    void payingonline();  //网上支付 
	          		
	private:
	    string username; //用户名 
		string passwd;  //密码 
        int shopcart[9];  //购物车 
		float total;  	//用户订单总价 
		int cardnum;   //银行卡数量 
		string cardaccount[5];  //银行卡账户 
		
};

//全局变量 
 
plantform userptr[50];   
int curuser;   //当前用户序号
int usernum;   //用户数量
string temp;   //用于标志优惠信息 
float fooddis=1;   //各类产品优惠折扣 
float clothdis=1;
float bookdis=1;  

//各商品声明 
apple app;
bread bre;
milktea milkt;
shirt shi;
skirt ski;
pants pan;
CPrimer CPri;
EffectiveC EffectC;
HeadFirstJava HeadFJ;

int pronum;   //商品种类数量 
int enough=0;   //优惠活动：满enough减sub 
int sub=0;


//设置类内部数据 
plantform::plantform()  //构造函数初始化 
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

void plantform::set_username(string usernm)//设置用户名 
{
	username=usernm;
}
void plantform::set_passwd(string pass)//设置密码 
{
	passwd=pass;
}
void plantform::set_shopcart(int i,int n) //设置购物车内容 
{
	shopcart[i]=n;
}

void plantform::set_total(float m) //设置应付金额 
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
	
//获取类内部数据,当前用户信息
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

int plantform::getcardnum()   //获取银行卡数 
{
	return userptr[curuser].cardnum;
}

string plantform::getcardaccount(int n)  //获取银行卡账号
{
	return userptr[curuser].cardaccount[n];
} 

//功能函数 
void plantform::function()
{
	int n;
	load();
	loadproduct();
	loaddis();
	do
	{	
		cout<<"*************************************"<<endl;
	    cout<<"*        欢迎进入电商平台！         *"<<endl;
	    cout<<"*          请选择操作：             *"<<endl;
	    cout<<"*    1.注册用户      2.登陆         *"<<endl;
	    cout<<"*    3.退出登录      4.查看商品信息 *"<<endl;
	    cout<<"*    5.查看优惠活动  6.退出系统     *"<<endl;
		cout<<"*************************************"<<endl;
		
		cin>>n;
		while(n<1||n>6)
		{
			cout<<"操作错误，请输入正确的操作序号！"<<endl;
			cin>>n;
		} 
		switch(n)
		{
			case 1:setaccount();  break;  //注册新用户
			case 2:login();  break;  //登陆
			case 3:logoff();  break;  //退出登录 
			case 4:showproduct();  break;  //查看商品信息 
			case 5:showdiscount();  break;  //查看优惠信息 
			case 6:quit();  return;  //退出电商平台系统 
		} 
	    cin.get();
	}while(1);
}

//将已有用户信息保存到结构 
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
	   cerr<<"打开文件错误！"<<endl;
	   abort();
	   return;	 
    }
    
	userfile>>buffer;
	userfile>>usernum;  //获取用户人数  全局变量 
	userfile>>buffer;
	
	while(i<usernum)
	{
		curuser=i;
		userfile>>buffer;    //将文件中的数据存入结构中 
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
		cout<<"暂无用户信息！"<<endl; 
	}
	else
	    cout<<usernum<<"读取用户资料正常！"<<endl;
	    
  /*	 for(i=0;i<usernum;i++)
	 {
 		curuser=i;
 		cout<<"序号："<<curuser<<endl;
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
		cerr<<"打开文件错误！"<<endl;
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
	cout<<"读取商品信息正常！"<<endl; 
}

void plantform::loaddis()
{
	string buffer;
	ifstream disfile;
	disfile.open("discount.txt",ios::in);
	
	if(!disfile)
	{
		cerr<<"打开文件错误！"<<endl;
	    abort();
	    return;	
	}
	disfile>>temp;
	if(temp=="优惠！")
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
		cout<<"暂无优惠信息！"<<endl;
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
	cout<<"共有 "<<pronum<<" 种商品！"<<endl; 
	
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
	
		cout<<"产品ID："<<proid<<endl;; 
		cout<<"产品描述："<<des<<endl;
		cout<<"产品原价："<<oprice<<endl;
		cout<<"产品剩余量："<<rest<<endl;
		cout<<"产品折扣："<<discnt<<endl<<endl;
				
		i++; 
	}

	cout<<"欢迎选购！"<<endl;
	return;	
}

void plantform::showdiscount()
{
	if(temp=="优惠！")
	{
		cout<<"优惠！"<<endl;
		cout<<"满"<<enough<<"减"<<sub<<"!"<<endl; 
		cout<<"食品全场"<<fooddis*10<<"折"<<endl; 
		cout<<"服装全场"<<clothdis*10<<"折"<<endl;
		cout<<"图书全场"<<bookdis*10<<"折"<<endl;
	} 
	else
	    cout<<"暂无优惠信息！"<<endl; 
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
    
    cout<<"请输入您的用户名：" ;
    cin>>newuser;
    
    while((i<usernum)&&(newuser!=userptr[i].getusername()))
    {
    	i++;
    }
	
	if(newuser==userptr[i].getusername())
    {
    	cout<<"该用户名已被占用，请按输入键返回上一级菜单！"<<endl;
    	return;
    }
	else
	{
        cout<<"您的用户名为"<<newuser<<endl;
        userptr[usernum].set_username(newuser);
		cout<<"请输入您的密码：";
		cin>>pass;
		cout<<"请再次输入以确认：";
		cin>>pass1;
		while(pass!=pass1)
		{
			cout<<"两次输入不匹配，请重新输入：";
			cin>>pass;
		    cout<<"请再次输入以确认：";
		    cin>>pass1;			 
		} 
		userptr[usernum].set_passwd(pass);
		for(j=0;j<9;j++)
        userptr[usernum].set_shopcart(j,0);            
		userptr[usernum].set_total(0);
		cout<<"请输入绑定银行卡账号数：";
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
				cout<<"请输入第"<<j+1<<"张银行卡账号：";
				cin>>cardaccount;
			    userptr[usernum].set_cardaccount(j,cardaccount);
			}
		}
		
	    curuser=usernum;
		cout<<"用户信息已输入完毕！注册成功！"<<endl;
		cout<<"用户名："<<userptr[usernum].getusername()<<endl;
		cout<<"密码："<<userptr[usernum].getpasswd()<<endl;
		cout<<"购物车：空空如也！"<<endl;
		cout<<"应付金额总计："<<userptr[usernum].gettotal()<<endl;
		cout<<"绑定银行卡数："<<userptr[usernum].getcardnum()<<endl;
		for(j=0;j<userptr[i].getcardnum();j++)
		{
			cout<<"银行账号"<<j+1<<": "<<userptr[i].getcardaccount(j)<<endl;
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
	
	cout<<"请输入您的用户名："<<endl;
	cin>>usernm;
    curuser=i;
	while((i<usernum)&&(usernm!=userptr[i].getusername()))
	{
		i++;
		curuser=i;
	}
	
	cout<<curuser<<endl;
	if(i==usernum)
	     cout<<"此用户名不存在！请按输入键返回上一级菜单！"<<endl;
    else
    {
    	cout<<"请输入密码："<<endl;
    	cin>>pass;
    	while(pass!=userptr[i].getpasswd())
    	{
	    	cout<<"密码错误，请重新输入！"<<endl;
	    	cin>>pass;
	    }
	    cout<<"登陆成功！"<<endl;
	    curuser=i;
	    do
	    {
    		cout<<"*****************************************"<<endl;
			cout<<"*         请选择需要的操作序号：        *"<<endl;
			cout<<"*          0.查看个人信息               *"<<endl; 
			cout<<"*          1.查看购物车                 *"<<endl;
			cout<<"*          2.添加商品到购物车           *"<<endl;
			cout<<"*          3.提交订单                   *"<<endl;
			cout<<"*          4.删除购物车中商品           *"<<endl;
			cout<<"*          5.返回上一层菜单             *"<<endl;
			cout<<"*****************************************"<<endl;
			
			cin>>choice;
			while(choice<0||choice>5)
			{
				cout<<"输入错误，请重新输入！"<<endl;
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
		cerr<<"打开文件错误！"<<endl;
		abort();
	}
	else
	{
		cout<<"共有 "<<usernum<<" 个用户账号！" <<endl;
		userfile<<"共有 ";
		userfile<<usernum;
		userfile<<" 个用户账号！"<<endl;
		for(i=0;i<usernum;i++)
		{
			curuser=i;
			userfile<<"用户名： ";
			userfile<<userptr[i].getusername()<<endl;
			userfile<<"密码： ";
			userfile<<userptr[i].getpasswd()<<endl;
			userfile<<"购物车： ";
			for(j=0;j<9;j++) 
			{
				userfile<<userptr[i].getshopcart(j)<<" ";
			}
			userfile<<endl;
			userfile<<"应付总金额： ";
			userfile<<userptr[i].gettotal()<<endl;
			userfile<<"银行账户数： "<<userptr[i].getcardnum()<<endl;
			if(userptr[i].getcardnum()==0)
			{
				userfile<<"银行账号: 无"<<endl;
			}
			else
			{
				for(j=0;j<userptr[i].getcardnum();j++)
		       {
			       userfile<<"银行账号"<<j+1<<": "<<userptr[i].getcardaccount(j)<<endl;
		       }
			}
		    userfile<<endl;					 
		} 
		cout<<"用户数据保存成功！"<<endl;
	}
	userfile.close();
}

void plantform::logoff()
{
	curuser=0;
	cout<<"已退出登录,谢谢使用！"<<endl;
	return;
}

void plantform::quit() 
{
	cout<<"感谢您的使用，再见！"<<endl;
	return;
}

void plantform::showinfo()
{
     int flag=0;
     int j;
     cout<<"用户名："<<userptr[curuser].getusername()<<endl;
     cout<<"密码："<<userptr[curuser].getpasswd()<<endl;
     cout<<"购物车："; 
  	 for(j=0;j<9;j++)
	{
		if(userptr[curuser].getshopcart(j)==0)
		    continue;
        else
		{
            switch(j)
            {
           	    case 0: cout<<"苹果："<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
	           	case 1: cout<<"面包："<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
	           	case 2: cout<<"奶茶："<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
	           	case 3: cout<<"T恤："<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
	           	case 4: cout<<"裙子："<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
	           	case 5: cout<<"裤子："<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
	           	case 6: cout<<"C++Primer："<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
	           	case 7: cout<<"EffectiveC++："<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
	           	case 8: cout<<"HeadFirstJava："<<userptr[curuser].getshopcart(j)<<" "; flag=1; break;
            }
         }
	} 
	cout<<endl;
	if(flag==0)
        cout<<"空空如也！快来加点东西吧！"<<endl;  
	cout<<"应付金额（优惠将在提交订单时计算）："<<userptr[curuser].gettotal()<<endl;
	cout<<"银行账户数："<<userptr[curuser].getcardnum()<<endl;
	for(j=0;j<userptr[curuser].getcardnum();j++)
	{
		cout<<"银行账号"<<j+1<<": "<<userptr[curuser].getcardaccount(j);
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
	cout<<"购物车："<<endl;
	for(j=0;j<9;j++)
	{
		if(userptr[i].getshopcart(j)==0)
		    continue;
        else
        {
           	switch(j)
           	{
	           		case 0: cout<<"苹果："<<userptr[i].getshopcart(j)<<" "; flag=1; break;
	            	case 1: cout<<"面包："<<userptr[i].getshopcart(j)<<" "; flag=1; break;
	            	case 2: cout<<"奶茶："<<userptr[i].getshopcart(j)<<" "; flag=1; break;
	            	case 3: cout<<"T恤："<<userptr[i].getshopcart(j)<<" "; flag=1; break;
	            	case 4: cout<<"裙子："<<userptr[i].getshopcart(j)<<" "; flag=1; break;
	            	case 5: cout<<"裤子："<<userptr[i].getshopcart(j)<<" "; flag=1; break;
	            	case 6: cout<<"C++Primer："<<userptr[i].getshopcart(j)<<" "; flag=1; break;
	            	case 7: cout<<"EffectiveC++："<<userptr[i].getshopcart(j)<<" "; flag=1; break;
	            	case 8: cout<<"HeadFirstJava："<<userptr[i].getshopcart(j)<<" "; flag=1; break;
					 
            }
	    }
	} 
	if(flag==0)
	   cout<<"空空如也！"<<endl;
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
	
     cout<<"请输入想要添加的商品ID："; 
     cin>>choice;
     cout<<"请输入添加数量：";
	 cin>>num; 
     
     if(choice==0)
     {
     	if(app.getrestnum()==0)
     	   cout<<"商品已下架，请选择其他！"<<endl;
        else
        {
        	while(app.getrestnum()<num)
        	{
	        	 cout<<"商品剩余量为"<<app.getrestnum()<<"，请适当减少需求：";
				 cin>>num; 
	        }
	        totalnow=num*app.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(0,userptr[curuser].getshopcart(0)+num);
	        app.set_rstnum(app.getrestnum()-num);
	        cout<<"已将"<<num<<"斤苹果加入购物车！"<<endl;	       			   
        }
     }
     else  if(choice==1)
     {
     	if(bre.getrestnum()==0)
     	   cout<<"商品已下架，请选择其他！"<<endl;
        else
        {
        	while(bre.getrestnum()<num)
        	{
	        	 cout<<"商品剩余量为"<<bre.getrestnum()<<"，请适当减少需求：";
				 cin>>num; 
	        }
	        totalnow=num*bre.getPrice();
            //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
            userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(1,userptr[curuser].getshopcart(1)+num);
	        bre.set_rstnum(bre.getrestnum()-num);
	        cout<<"已将"<<num<<"个面包加入购物车！"<<endl;
	     		   
        }
     }
     else  if(choice==2)
     {
     	if(milkt.getrestnum()==0)
     	   cout<<"商品已下架，请选择其他！"<<endl;
        else
        {
        	while(milkt.getrestnum()<num)
        	{
	        	 cout<<"商品剩余量为"<<milkt.getrestnum()<<"，请适当减少需求：";
				 cin>>num; 
	        }
	        totalnow=num*milkt.getPrice();
            //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
            userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(2,userptr[curuser].getshopcart(2)+num);
	        milkt.set_rstnum(milkt.getrestnum()-num);
	        cout<<"已将"<< num<<"杯奶茶加入购物车！"<<endl;
	 		   
        }
     }
	 else  if(choice==3)
     {
     	if(shi.getrestnum()==0)
     	   cout<<"商品已下架，请选择其他！"<<endl;
        else
        {
        	while(shi.getrestnum()<num)
        	{
	        	 cout<<"商品剩余量为"<<shi.getrestnum()<<"，请适当减少需求：";
				 cin>>num; 
	        }
	        totalnow=num*shi.getPrice();
            //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
            userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(3,userptr[curuser].getshopcart(3)+num);
	        shi.set_rstnum(shi.getrestnum()-num);
	        cout<<"已将"<< num<<"件T恤加入购物车！"<<endl;
	  		   
        }
     }
	 else  if(choice==4)
     {
     	if(ski.getrestnum()==0)
     	   cout<<"商品已下架，请选择其他！"<<endl;
        else
        {
        	while(ski.getrestnum()<num)
        	{
	        	 cout<<"商品剩余量为"<<ski.getrestnum()<<"，请适当减少需求：";
				 cin>>num; 
	        }
	        totalnow=num*ski.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(4,userptr[curuser].getshopcart(4)+num);
	        ski.set_rstnum(ski.getrestnum()-num);
	        cout<<"已将"<< num<<"件裙子加入购物车！"<<endl;
	   		   
        }
     }
	 else  if(choice==5)
     {
     	if(pan.getrestnum()==0)
     	   cout<<"商品已下架，请选择其他！"<<endl;
        else
        {
        	while(pan.getrestnum()<num)
        	{
	        	 cout<<"商品剩余量为"<<pan.getrestnum()<<"，请适当减少需求：";
				 cin>>num; 
	        }
	        totalnow=num*pan.getPrice();
            //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
            userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
            userptr[curuser].set_shopcart(5,userptr[curuser].getshopcart(5)+num);
	        pan.set_rstnum(pan.getrestnum()-num);
	        cout<<"已将"<< num<<"条长裤加入购物车！"<<endl;
	     		   
        }
     }
	 else  if(choice==6)
     {
     	if(CPri.getrestnum()==0)
     	   cout<<"商品已下架，请选择其他！"<<endl;
        else
        {
        	while(CPri.getrestnum()<num)
        	{
	        	 cout<<"商品剩余量为"<<CPri.getrestnum()<<"，请适当减少需求：";
				 cin>>num; 
	        }
	        totalnow=num*CPri.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
            userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
            userptr[curuser].set_shopcart(6,userptr[curuser].getshopcart(6)+num);
	        CPri.set_rstnum(CPri.getrestnum()-num);
	        cout<<"已将"<<num<<"本C++Primer加入购物车！"<<endl;
	     		   
        }
     }
	 else  if(choice==7)
     {
     	if(EffectC.getrestnum()==0)
     	   cout<<"商品已下架，请选择其他！"<<endl;
        else
        {
        	while(EffectC.getrestnum()<num)
        	{
	        	 cout<<"商品剩余量为"<<EffectC.getrestnum()<<"，请适当减少需求：";
				 cin>>num; 
	        }
	        totalnow=num*EffectC.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
            userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
            userptr[curuser].set_shopcart(7,userptr[curuser].getshopcart(7)+num);
	        EffectC.set_rstnum(EffectC.getrestnum()-num);
	        cout<<"已将"<< num<<"本Effective C++加入购物车！"<<endl;
	      		   
        }
     } 
     else  if(choice==8)
     {
     	if(HeadFJ.getrestnum()==0)
     	   cout<<"商品已下架，请选择其他！"<<endl;
        else
        {
        	while(HeadFJ.getrestnum()<num)
        	{
	        	 cout<<"商品剩余量为"<<HeadFJ.getrestnum()<<"，请适当减少需求：";
				 cin>>num; 
	        }
	        totalnow=num*HeadFJ.getPrice();
            //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()+totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
            userptr[curuser].set_shopcart(8,userptr[curuser].getshopcart(8)+num);
	        HeadFJ.set_rstnum(HeadFJ.getrestnum()-num);
	        cout<<"已将"<< num<<"本HeadFirstJava加入购物车！"<<endl;
	    		   
        }
     }
	 else
	 {
 		cout<<"输入内容错误，请按输入键返回上一级菜单查看商品信息！"<<endl;
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
	
     cout<<"请输入想要删除的商品ID："; 
     cin>>choice;
     cout<<"请输入删除数量：";
	 cin>>num; 
     
     if(choice==0)
     {
     	if(userptr[curuser].getshopcart(0)==0)
     	   cout<<"未将苹果加入购物车，请选择其他！"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(0)<num)
        	{
	        	 cout<<"购物车中该商品共有"<<userptr[curuser].getshopcart(0)<<"件，请输入正确数字：";
				 cin>>num; 
	        }
	        totalnow=num*app.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(0,userptr[curuser].getshopcart(0)-num);
	        app.set_rstnum(app.getrestnum()+num);
	        cout<<"已将"<< num<<"斤苹果从购物车中删除！"<<endl;
	       			   
        }
     }
     else  if(choice==1)
     {
     	if(userptr[curuser].getshopcart(1)==0)
     	   cout<<"未将面包加入购物车，请选择其他！"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(1)<num)
        	{
	        	 cout<<"购物车中该商品共有"<<userptr[curuser].getshopcart(1)<<"件，请输入正确数字：";
				 cin>>num; 
	        }
	        totalnow=num*bre.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(1,userptr[curuser].getshopcart(1)-num);
	        bre.set_rstnum(bre.getrestnum()+num);
	        cout<<"已将"<< num<<"个面包从购物车中删除！"<<endl;
	       			   
        }
     }
     else  if(choice==2)
     {
     	if(userptr[curuser].getshopcart(2)==0)
     	   cout<<"未将奶茶加入购物车，请选择其他！"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(2)<num)
        	{
	        	 cout<<"购物车中该商品共有"<<userptr[curuser].getshopcart(2)<<"件，请输入正确数字：";
				 cin>>num; 
	        }
	        totalnow=num*milkt.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(2,userptr[curuser].getshopcart(2)-num);
	        milkt.set_rstnum(milkt.getrestnum()+num);
	        cout<<"已将"<< num<<"杯奶茶从购物车中删除！"<<endl;
	       			   
        }
     }
	 else  if(choice==3)
     {
     	if(userptr[curuser].getshopcart(3)==0)
     	   cout<<"未将T恤加入购物车，请选择其他！"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(3)<num)
        	{
	        	 cout<<"购物车中该商品共有"<<userptr[curuser].getshopcart(3)<<"件，请输入正确数字：";
				 cin>>num; 
	        }
	        totalnow=num*shi.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(3,userptr[curuser].getshopcart(3)-num);
	        shi.set_rstnum(shi.getrestnum()+num);
	        cout<<"已将"<< num<<"件T恤从购物车中删除！"<<endl;
	       			   
        }
     }
	 else  if(choice==4)
     {
     	if(userptr[curuser].getshopcart(4)==0)
     	   cout<<"未将裙子加入购物车，请选择其他！"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(4)<num)
        	{
	        	 cout<<"购物车中该商品共有"<<userptr[curuser].getshopcart(4)<<"件，请输入正确数字：";
				 cin>>num; 
	        }
	        totalnow=num*ski.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(4,userptr[curuser].getshopcart(4)-num);
	        ski.set_rstnum(ski.getrestnum()+num);
	        cout<<"已将"<< num<<"条裙子从购物车中删除！"<<endl;
	       			   
        }
     }
	 else  if(choice==5)
     {
     	if(userptr[curuser].getshopcart(5)==0)
     	   cout<<"未将长裤加入购物车，请选择其他！"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(5)<num)
        	{
	        	 cout<<"购物车中该商品共有"<<userptr[curuser].getshopcart(5)<<"件，请输入正确数字：";
				 cin>>num; 
	        }
	        totalnow=num*pan.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(5,userptr[curuser].getshopcart(5)-num);
	        pan.set_rstnum(pan.getrestnum()+num);
	        cout<<"已将"<< num<<"条长裤从购物车中删除！"<<endl;
	       			   
        }
     }
	 else  if(choice==6)
     {
     	if(userptr[curuser].getshopcart(6)==0)
     	   cout<<"未将C++Primer加入购物车，请选择其他！"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(6)<num)
        	{
	        	 cout<<"购物车中该商品共有"<<userptr[curuser].getshopcart(6)<<"件，请输入正确数字：";
				 cin>>num; 
	        }
	        totalnow=num*CPri.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(6,userptr[curuser].getshopcart(6)-num);
	        CPri.set_rstnum(CPri.getrestnum()+num);
	        cout<<"已将"<< num<<"本C++Primer从购物车中删除！"<<endl;
	       			   
        }
     }
	 else  if(choice==7)
     {
     	if(userptr[curuser].getshopcart(7)==0)
     	   cout<<"未将EffectiveC++加入购物车，请选择其他！"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(7)<num)
        	{
	        	 cout<<"购物车中该商品共有"<<userptr[curuser].getshopcart(7)<<"件，请输入正确数字：";
				 cin>>num; 
	        }
	        totalnow=num*EffectC.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(7,userptr[curuser].getshopcart(7)-num);
	        EffectC.set_rstnum(EffectC.getrestnum()+num);
	        cout<<"已将"<< num<<"本Effective C++从购物车中删除！"<<endl;
	       			   
        }
     }
     else if(choice==8)
     {
     	if(userptr[curuser].getshopcart(8)==0)
     	   cout<<"未将HeadFirstJava加入购物车，请选择其他！"<<endl;
        else
        {
        	while(userptr[curuser].getshopcart(8)<num)
        	{
	        	 cout<<"购物车中该商品共有"<<userptr[curuser].getshopcart(8)<<"件，请输入正确数字：";
				 cin>>num; 
	        }
	        totalnow=num*HeadFJ.getPrice();
	        //cout<<totalnow<<endl;
	        totalmoney=userptr[curuser].gettotal()-totalnow;
	        userptr[curuser].set_total(totalmoney);
	        //cout<<userptr[curuser].gettotal()<<endl;
	        userptr[curuser].set_shopcart(8,userptr[curuser].getshopcart(8)-num);
	        HeadFJ.set_rstnum(HeadFJ.getrestnum()+num);
	        cout<<"已将"<< num<<"本HeadFirstJava从购物车中删除！"<<endl;
	       			   
        }
     }
	 else
	 {
 		cout<<"输入内容错误，请按输入键返回上一级菜单查看商品信息！"<<endl;
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
	
	cout<<"订单提交成功！共需付￥"<<last<<"!"<<endl;
	userptr[curuser].set_total(last);
	if(last!=0)
	{
		cout<<"请选择支付方式： 1.网上支付   2.货到付款"<<endl;
	    cin>>choice;
	    while((choice!=1)&&(choice!=2))
	   {
		    cout<<"输入错误，请重新输入！"<<endl;
		    cin>>choice;
	   }
	   if(choice==1)
	        payingonline();
       else
            cout<<"您的商品即将发出，请期待！"<<endl;
	 }
	 else
	 {
 		cout<<"请选择商品到购物车！"<<endl;
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
    cout<<"绑定银行卡数："<<cardnum<<endl;
  if(userptr[curuser].getcardnum()==0)
  {
    	cout<<"无银行卡绑定，按输入键返回上级菜单！"<<endl;
  }
  else
  {
	for(j=0;j<userptr[curuser].getcardnum();j++)
	{
	    cout<<"银行账号"<<j+1<<": "<<userptr[curuser].getcardaccount(j)<<endl;
	}
    if(cardnum==1)
        cardaccount=userptr[curuser].getcardaccount(0);
    else
    {
    	cout<<"请输入所选的银行卡序号："<<endl;
    	cin>>choice;
    	cardaccount=userptr[curuser].getcardaccount(choice-1);
    }
    cout<<cardaccount;
    memset(buff,0,sizeof(buff));   //将buffer清空
	int i;
	for(i=0;i<cardaccount.length();i++)    //发送银行账户 
        buff[i]=cardaccount[i];
    buff[i]='\0';
    printf("send a message:");  
    send(sc,buff,1024,0);
    cout<<buff;
    printf("\n");
    

    memset(buff,0,sizeof(buff));   //将buffer清空
    printf("recieve a message:");  //收到输入密码的提示 
    recv(sc,buff,1024,0);
    cout<<buff<<endl;
    if(buff=="该用户不存在，支付失败！")
    {
    	return;
    } 
    
    memset(buff,0,sizeof(buff));   //将buffer清空
    printf("send a message: ");
	cin>>key;  
   // fgets(key, 1024, stdin);   //发送密码 
    send(sc,key,10,0);
    printf("\n");
    
    memset(buff,0,sizeof(buff));   //将buffer清空
    printf("recieve a message:");  //收到输入金额提示 
    recv(sc,buff,1024,0);
    cout<<buff<<endl;
    if(buff=="密码错误，支付失败！")
    {
    	return;
    } 
    
    memset(buff,0,sizeof(buff));   //将buffer清空
    printf("send a message: ");  
    total=userptr[curuser].gettotal();  //发送支付金额 
    sprintf(buff, "%5.2f",total);
    send(sc,buff,1024,0);
    cout<<total;
    printf("\n");
   
    memset(buff,0,sizeof(buff));   //将buffer清空
    printf("recieve a message:");  //收到返回信息 
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



