#include "fun_file.h"

//Dynamic_Chain


Dynamic_Chain::Dynamic_Chain()          //构造函数
{
    Head_Pointer = new Card();          //建立卡的头指针
    Pointer_Link = Head_Pointer;        //尾指针
    Head_Pointer->Next_Card(NULL);
}
void Dynamic_Chain::Add_TeacherCard(const string un,int cnt)  //向链表里添加教师卡
{
    TeacherCard * p = new TeacherCard(un,cnt);
    Pointer_Link->Next_Card(p);
    Pointer_Link = p;
    p->Next_Card(NULL);
    Pointer_Link->Show_information();//显示信息

}
void Dynamic_Chain::Add_StudentCard(const string un,const double ds,int cnt)//向链表里添加学生卡
{
    StudentCard * p = new StudentCard(un,ds,cnt);
    Pointer_Link->Next_Card(p);
    Pointer_Link = p;
    p->Next_Card(NULL);
    Pointer_Link->Show_information();//显示信息

}
void Dynamic_Chain::Add_LimitCard(const string un,const double ds,int cnt)//向链表里添加限制卡
{
    LimitCard * p = new LimitCard(un,ds,cnt);
    Pointer_Link->Next_Card(p);
    Pointer_Link = p;
    p->Next_Card(NULL);
    Pointer_Link->Show_information();//显示信息
}
int Dynamic_Chain::Get_on(const string cardnumber) //提供上车接口
{
    Card * p = Search_Card(cardnumber); //搜索卡 返回指针
    if(p == NULL)return 0;              //如果未搜索到 返回0
    else
    {
        p->Get_on();
        return 1;
    }
}
Card * Dynamic_Chain::Search_Card(const string cardnumber)      //提供搜索卡的接口
{
    Card * p = Head_Pointer->Return_Next_Card();
    while(p != NULL)        //判断是否为最后一个对象
    {
        string a = p->Return_cardnumber();
        string b = p->Return_username();
        if((a == cardnumber)||(b == cardnumber))break;
        else
        {
            p = p->Return_Next_Card();
        }
    }
    return p;

}
void Dynamic_Chain::Delete_Card(const string cardnumber)        //删除卡
{
    Card * p = Head_Pointer->Return_Next_Card();
    Card * q = Head_Pointer;
    Card * d = p->Return_Next_Card();
    while(d != NULL)
    {
        string a = p->Return_cardnumber();
        if(a == cardnumber)
        {
            p = p->Return_Next_Card();
            q->Next_Card(p);

        }
        else
        {
            q = p;
            p = p->Return_Next_Card();
        }
        d = p->Return_Next_Card();
    }
}

//非成员函数


int pow10(int i)                //十的幂数
{
    int n = 0,sum = 1;
    for(;n<i;n++)sum*=10;
    return sum;
}
string To_string(int i)         //将int转化为string 如 1 转化为 "00001"
{
    int weishu = 0;
    int cnt = 0;
    int i2 = i;
    while(i2)
    {
        i2 /=10;
        weishu++;
    }
    char* String = new char[weishu+1];
    for(;cnt < weishu;cnt++)
    {
        if(cnt == (weishu-1)){String[cnt] = (i%10)+48;break;}
        int p = pow10(weishu-1-cnt);
        String[cnt] = (i/p)+48;
        i %= p;

    }
    String[weishu] = '\0';
    string a = "0";
    for(i2 = 4;i2>weishu;i2--)a += "0";    //保证整齐 位宽为5
    a += String;
    delete[] String;
    return a;

}
string To_string_r(int i)         //将int转化为string 如 1 转化为 "1"
{
    int weishu = 0;
    int cnt = 0;
    int i2 = i;
    while(i2)
    {
        i2 /=10;
        weishu++;
    }
    char* String = new char[weishu+1];
    for(;cnt < weishu;cnt++)
    {
        if(cnt == (weishu-1)){String[cnt] = (i%10)+48;break;}
        int p = pow10(weishu-1-cnt);
        String[cnt] = (i/p)+48;
        i %= p;

    }
    String[weishu] = '\0';
    string a;
    a = String;
    delete[] String;
    return a;

}
int To_int(string p)                    //将const char * 转化为int 如 "10" 转化为 10
{
    char * q = (char*)p.data();
    int sum = 0;
    int i = 0;
    int n = 0;
    while(q[i]!='\0')
    {n++;i++;}
    for(int i = 0;i<n;i++)sum += (q[i]-48) * pow10(n-i-1);
    return sum;
}

void remind()
{
    cout << "--(T)教师卡:免费乘车。"<<endl;
    cout << "--(S)学生卡:每次乘车两元。"<<endl;
    cout << "--(L)限制卡:前二十次免费，超过二十次每次两元。"<<endl;
    cout << "--输入括号里的字母，选择你想办理的卡。";
}



/*
Class Chain_Car
*/



Chain_Car::Chain_Car(Dynamic_Chain & Dynamic)           //车的链表的构造函数
{
    Head_Pointer = new Car_Information();
    Pointer_Link = Head_Pointer;
    this->Dynamic = Dynamic;                //输入卡的链表
}
void Chain_Car::Add_Car(string DriverName,string TimeTable,int CN,int MCN,string Model)                 //加入一辆新车
{
    Car_Information* p = new Car_Information(DriverName,TimeTable,CN,MCN,Model);
    Pointer_Link->Set_Next_Car(p);
    cout << "新车建立成功" << endl;
    Pointer_Link = Pointer_Link->Return_Next_Car();
    Pointer_Link->Show();

}
void Chain_Car::Add_Passenger(string lp,string un)
{
    Car_Information * p = Search_Car(lp);
    if(p != NULL)//判断是否检测到车的指针
    {
        if(!(p->Is_Over_Carry()))            //判断是否超载
        {
            Passenger_Pointer = Dynamic.Search_Card(un);
            if(Passenger_Pointer == NULL)cout << "您输入的信息不存在!!!" << endl;
            else if(Passenger_Pointer->Return_Is_On())cout << "抱歉，这张卡已上车!!!" <<endl;
            else
            {
            p->Increase_Carry_Number();
            Card * q = new Card();
            Card * pq = p->Return_Passenger_Pointer();//尾指针
            pq->Next_Card(q);                           //将新建的卡连接到尾指针
            p->Set_Passenger_Pointer(pq->Return_Next_Card());//将尾指针更新
            pq = pq->Return_Next_Card();
            pq->Set_Include_Card(Passenger_Pointer);
            Passenger_Pointer->Get_on();
            pq->Next_Card(NULL);
            cout << "上车成功!!!"<<endl;

            p->Show();

            }
        }
        else cout << "抱歉，车已经满了!!!"<<endl;
    }
    else cout << "抱歉 没有您要查找的车号!!!"<<endl;

}
Car_Information * Chain_Car::Search_Car(string License_Plate)       //搜索车牌号 返回指针
{
    Car_Information * head = Head_Pointer;
    Car_Information *p = head->Return_Next_Car();
    while(p != NULL)
    {
        string lp = p->Return_License_Plate();
        if(lp == License_Plate)return p;
        else p = p->Return_Next_Car();
    }
    return p; //查到车号 返回车的指针，没查到 返回NULL
}
void Chain_Car::Show_Car_Information()      //显示车的信息
{
    Pointer_Link->Show();
}
void Chain_Car::Delete_Card(const string cardnumber,Car_Information * b)        //删除卡
{
    Card * q = b->Return_Passenger_Information();
    Card * p = q->Return_Next_Card();
    while(p != NULL)
    {
        Card * t = p->Return_Include_Card();
        string a = t->Return_cardnumber();
        cout << "卡号: " <<a<<endl;
        if(a == cardnumber)
        {
            Card * m = p;
            p = p->Return_Next_Card();
            delete m;                           //释放删除的卡所分配的储存空间
            q->Next_Card(p);
            cout <<"删除成功!!!" << endl;
            break;
        }
        else
        {
            q = p;
            p = p->Return_Next_Card();
        }
    }

}


/*
File_Control
*/

void File_Control::Card_Write(string cardnumber,string cardtype,string username,string balance,string cnt)//向文件里下入卡的信息
{
    ofstream fout("Card.txt",ios_base::out|ios_base::app);
    fout << endl;
    fout.width(18);
    fout <<cardnumber;
    fout.width(17);
    fout<<cardtype;
    fout.width(16);
    fout <<username;
    fout.width(15);
    fout<<balance;
    fout.width(11);
    fout <<cnt;
    fout.close();
}
void File_Control::Card_Read(int n,string &cardnumber,string &cardtype,string &username,string &balance,string &cnt)//从文件里读取卡的信息
{
    ifstream fin_("Card.txt");
    fin_.ignore(255,'\n');
    while(n--)fin_.ignore(255,'\n');
    while(fin_ >>cardnumber>>cardtype>>username>>balance>>cnt)
    {

            /*cout << "cardnumber: " << cardnumber <<endl;
            cout << "cardtype: " << cardtype << endl;
            cout << "username: " << username << endl;
            cout << "balance: " << balance << endl;
            cout << "cnt: " << cnt << endl;*/
    }
    fin_.close();
}
int File_Control::Search_Card(string cn)        //搜索卡的信息 返回卡的行数
{
    string cardnumber,cardtype,username;
    int i = 0;
    ifstream fin_("Card.txt");
    fin_.ignore(255,'\n').ignore(255,'\n');
    while(fin_>>cardnumber>>cardtype>>username)
    {
        i++;
        if((cardnumber == cn)||(username == cn)) //判断姓名与卡号是否有一个相同
        {fin_.close();return i;}
    }
    fin_.close();
    return 0;
}
/*void File_Control::Rewrite_Card(string cn,string balance,string cnt)
{
    int i = Search_Card(cn);
    string cardnumber,cardtype,username,balance,cnt;
    fstream finout("Card.txt":,ios_base::in|ios_base::out|ios_base::app);
    finout.seekg(0);
    finout.ignore(255,'\n');
    while(i--)
    finout.ignore(255,'\n');
    finout >>cardnumber>>cardtype>>username>>balance>>cnt;

}*/
void File_Control::Car_Write(string licenseplate,string model,string carrynumber,string maxcarrynumber,string drivername,string timetable)//向车的文件里写入车的信息
{
    ofstream fout("Car.txt",ios_base::out|ios_base::app);
    fout << endl;
    fout.width(20);
    fout <<licenseplate;
    fout.width(13);
    fout<<model;
    fout.width(20);
    fout <<maxcarrynumber;
    fout.width(20);
    fout<<drivername;
    fout.width(20);
    fout <<timetable;
    fout.width(20);
    fout << carrynumber <<"/" << maxcarrynumber;
    fout.close();
}
void File_Control::Car_Read(int n,string &licenseplate,string &model,string &maxcarrynumber,string &drivername,string &timetable)//从文件里读取车的信息
{
    ifstream fin_("Car.txt");
    fin_.ignore(255,'\n');
    while(n--)fin_.ignore(255,'\n');
    while(fin_ >>licenseplate>>model>>maxcarrynumber>>drivername>>timetable)
    {

            /*cout << "licenseplate: " << licenseplate <<endl;
            cout << "model: " << model << endl;
            cout << "maxcarrynumber: " << maxcarrynumber << endl;
            cout << "drivername: " << drivername << endl;
            cout << "timetable: " << timetable << endl;*/
    }
    fin_.close();
}
int File_Control::Search_Car(string lp)//查找车返回指针
{
    string licenseplate;
    int i = 0;
    ifstream fin_("Car.txt");
    fin_.ignore(255,'\n').ignore(255,'\n');
    while(fin_>>licenseplate)//从文件里读取需查找的车的行数
    {
        i++;
        if(licenseplate == lp)
        {fin_.close();return i;}
    }
    fin_.close();
    return 0;
}
void File_Control::Write_Card_File(Dynamic_Chain & dc)//更新Card.txt文件
{
    ofstream fout("Card.txt",ios_base::out);
    fout << "		18		 17		 16	  	15	   11	必须按顺序填写" << endl;
    fout << "--------cardnumber---------cardtype--------username--------balance--------cnt";
    fout.close();
    Card * p = dc.Head_Pointer->Return_Next_Card();
    while(p != NULL)
    {
        if((p->Return_cardtype()) == "TeacherCard")Card_Write(p->cardnumber,p->Return_cardtype(),p->username,"NULL",To_string_r(p->cnt));
        else Card_Write(p->cardnumber,p->Return_cardtype(),p->username,To_string_r(p->Return_Deposits()),To_string_r(p->cnt));
        Card * t = p;
        p = p->Return_Next_Card();
        delete t;
    }
    cout << "卡的文件生成成功!!!" << endl;
}
void File_Control::Write_Car_File(Chain_Car & cc)//更新Car.txt文件
{
    ofstream fout("Car.txt",ios_base::out);
    fout << "必须按顺序填写    20	       13		   20		       20		   20                     20" << endl;
    fout << "--------licenseplate--------model------maxcarrynumber----------drivername-----------timetable";
    fout.close();
    Car_Information * p = cc.Head_Pointer->Return_Next_Car();
    while(p != NULL)
    {

        Car_Write(p->License_Plate,p->Model,To_string_r(p->Carry_Number),To_string_r(p->Max_Carry_Number),p->Driver_Name,p->Time_Table);//将车的信息写到文件中
        Card * c = p->Return_Passenger_Information();
        while(!(c == NULL))//释放该车的卡的链表
        {
            Card * t = c;
            c = c->Return_Next_Card();
            delete t;
        }
        Car_Information * t = p;
        p = p->Next_Car;
        delete t;
    }
    cout << "车的文件生成成功!!!"<< endl;
}
void File_Control::Init_Card(Dynamic_Chain & Dynamic)           //初始化
{
    string CardNumber,UserName,CardClass;
    string Cnt,Balance;

    ifstream fin("Card.txt");

    fin.ignore(255,'\n').ignore(255,'\n');

    while(fin >>CardNumber>>CardClass>>UserName>>Balance>>Cnt)
    {
        //cout <<CardNumber << endl << CardClass << endl << UserName <<endl << Balance << endl <<Cnt <<endl; //从文件读取卡的信息 在卡的链表里创建新成员
        if(CardClass == "StudentCard")Dynamic.Add_StudentCard(UserName,To_int(Balance),To_int(Cnt));
        else if(CardClass == "TeacherCard")Dynamic.Add_TeacherCard(UserName,To_int(Cnt));
        else Dynamic.Add_LimitCard(UserName,To_int(Balance),To_int(Cnt));
    }

    fin.close();
}
void File_Control::Init_Car(Chain_Car & cc)
{
    ifstream fin2("Car.txt");
    string licenseplate;
    string model, maxcarrynumber,drivername;
    string timetable;
    fin2.ignore(255,'\n').ignore(255,'\n');
    while(fin2 >>licenseplate>>model>>maxcarrynumber>>drivername>>timetable )
    {
        fin2.ignore(255,'\n');
        // <<licenseplate << endl << model << endl << maxcarrynumber <<endl << drivername << endl <<timetable <<endl; //从文件读取卡的信息 在卡的链表里创建新成员
        cc.Add_Car(drivername,timetable,0,To_int(maxcarrynumber),model);
    }
    fin2.close();
}
