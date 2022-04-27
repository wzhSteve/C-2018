#include "fun_file.h"

//Dynamic_Chain


Dynamic_Chain::Dynamic_Chain()          //���캯��
{
    Head_Pointer = new Card();          //��������ͷָ��
    Pointer_Link = Head_Pointer;        //βָ��
    Head_Pointer->Next_Card(NULL);
}
void Dynamic_Chain::Add_TeacherCard(const string un,int cnt)  //����������ӽ�ʦ��
{
    TeacherCard * p = new TeacherCard(un,cnt);
    Pointer_Link->Next_Card(p);
    Pointer_Link = p;
    p->Next_Card(NULL);
    Pointer_Link->Show_information();//��ʾ��Ϣ

}
void Dynamic_Chain::Add_StudentCard(const string un,const double ds,int cnt)//�����������ѧ����
{
    StudentCard * p = new StudentCard(un,ds,cnt);
    Pointer_Link->Next_Card(p);
    Pointer_Link = p;
    p->Next_Card(NULL);
    Pointer_Link->Show_information();//��ʾ��Ϣ

}
void Dynamic_Chain::Add_LimitCard(const string un,const double ds,int cnt)//��������������ƿ�
{
    LimitCard * p = new LimitCard(un,ds,cnt);
    Pointer_Link->Next_Card(p);
    Pointer_Link = p;
    p->Next_Card(NULL);
    Pointer_Link->Show_information();//��ʾ��Ϣ
}
int Dynamic_Chain::Get_on(const string cardnumber) //�ṩ�ϳ��ӿ�
{
    Card * p = Search_Card(cardnumber); //������ ����ָ��
    if(p == NULL)return 0;              //���δ������ ����0
    else
    {
        p->Get_on();
        return 1;
    }
}
Card * Dynamic_Chain::Search_Card(const string cardnumber)      //�ṩ�������Ľӿ�
{
    Card * p = Head_Pointer->Return_Next_Card();
    while(p != NULL)        //�ж��Ƿ�Ϊ���һ������
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
void Dynamic_Chain::Delete_Card(const string cardnumber)        //ɾ����
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

//�ǳ�Ա����


int pow10(int i)                //ʮ������
{
    int n = 0,sum = 1;
    for(;n<i;n++)sum*=10;
    return sum;
}
string To_string(int i)         //��intת��Ϊstring �� 1 ת��Ϊ "00001"
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
    for(i2 = 4;i2>weishu;i2--)a += "0";    //��֤���� λ��Ϊ5
    a += String;
    delete[] String;
    return a;

}
string To_string_r(int i)         //��intת��Ϊstring �� 1 ת��Ϊ "1"
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
int To_int(string p)                    //��const char * ת��Ϊint �� "10" ת��Ϊ 10
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
    cout << "--(T)��ʦ��:��ѳ˳���"<<endl;
    cout << "--(S)ѧ����:ÿ�γ˳���Ԫ��"<<endl;
    cout << "--(L)���ƿ�:ǰ��ʮ����ѣ�������ʮ��ÿ����Ԫ��"<<endl;
    cout << "--�������������ĸ��ѡ���������Ŀ���";
}



/*
Class Chain_Car
*/



Chain_Car::Chain_Car(Dynamic_Chain & Dynamic)           //��������Ĺ��캯��
{
    Head_Pointer = new Car_Information();
    Pointer_Link = Head_Pointer;
    this->Dynamic = Dynamic;                //���뿨������
}
void Chain_Car::Add_Car(string DriverName,string TimeTable,int CN,int MCN,string Model)                 //����һ���³�
{
    Car_Information* p = new Car_Information(DriverName,TimeTable,CN,MCN,Model);
    Pointer_Link->Set_Next_Car(p);
    cout << "�³������ɹ�" << endl;
    Pointer_Link = Pointer_Link->Return_Next_Car();
    Pointer_Link->Show();

}
void Chain_Car::Add_Passenger(string lp,string un)
{
    Car_Information * p = Search_Car(lp);
    if(p != NULL)//�ж��Ƿ��⵽����ָ��
    {
        if(!(p->Is_Over_Carry()))            //�ж��Ƿ���
        {
            Passenger_Pointer = Dynamic.Search_Card(un);
            if(Passenger_Pointer == NULL)cout << "���������Ϣ������!!!" << endl;
            else if(Passenger_Pointer->Return_Is_On())cout << "��Ǹ�����ſ����ϳ�!!!" <<endl;
            else
            {
            p->Increase_Carry_Number();
            Card * q = new Card();
            Card * pq = p->Return_Passenger_Pointer();//βָ��
            pq->Next_Card(q);                           //���½��Ŀ����ӵ�βָ��
            p->Set_Passenger_Pointer(pq->Return_Next_Card());//��βָ�����
            pq = pq->Return_Next_Card();
            pq->Set_Include_Card(Passenger_Pointer);
            Passenger_Pointer->Get_on();
            pq->Next_Card(NULL);
            cout << "�ϳ��ɹ�!!!"<<endl;

            p->Show();

            }
        }
        else cout << "��Ǹ�����Ѿ�����!!!"<<endl;
    }
    else cout << "��Ǹ û����Ҫ���ҵĳ���!!!"<<endl;

}
Car_Information * Chain_Car::Search_Car(string License_Plate)       //�������ƺ� ����ָ��
{
    Car_Information * head = Head_Pointer;
    Car_Information *p = head->Return_Next_Car();
    while(p != NULL)
    {
        string lp = p->Return_License_Plate();
        if(lp == License_Plate)return p;
        else p = p->Return_Next_Car();
    }
    return p; //�鵽���� ���س���ָ�룬û�鵽 ����NULL
}
void Chain_Car::Show_Car_Information()      //��ʾ������Ϣ
{
    Pointer_Link->Show();
}
void Chain_Car::Delete_Card(const string cardnumber,Car_Information * b)        //ɾ����
{
    Card * q = b->Return_Passenger_Information();
    Card * p = q->Return_Next_Card();
    while(p != NULL)
    {
        Card * t = p->Return_Include_Card();
        string a = t->Return_cardnumber();
        cout << "����: " <<a<<endl;
        if(a == cardnumber)
        {
            Card * m = p;
            p = p->Return_Next_Card();
            delete m;                           //�ͷ�ɾ���Ŀ�������Ĵ���ռ�
            q->Next_Card(p);
            cout <<"ɾ���ɹ�!!!" << endl;
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

void File_Control::Card_Write(string cardnumber,string cardtype,string username,string balance,string cnt)//���ļ������뿨����Ϣ
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
void File_Control::Card_Read(int n,string &cardnumber,string &cardtype,string &username,string &balance,string &cnt)//���ļ����ȡ������Ϣ
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
int File_Control::Search_Card(string cn)        //����������Ϣ ���ؿ�������
{
    string cardnumber,cardtype,username;
    int i = 0;
    ifstream fin_("Card.txt");
    fin_.ignore(255,'\n').ignore(255,'\n');
    while(fin_>>cardnumber>>cardtype>>username)
    {
        i++;
        if((cardnumber == cn)||(username == cn)) //�ж������뿨���Ƿ���һ����ͬ
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
void File_Control::Car_Write(string licenseplate,string model,string carrynumber,string maxcarrynumber,string drivername,string timetable)//�򳵵��ļ���д�복����Ϣ
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
void File_Control::Car_Read(int n,string &licenseplate,string &model,string &maxcarrynumber,string &drivername,string &timetable)//���ļ����ȡ������Ϣ
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
int File_Control::Search_Car(string lp)//���ҳ�����ָ��
{
    string licenseplate;
    int i = 0;
    ifstream fin_("Car.txt");
    fin_.ignore(255,'\n').ignore(255,'\n');
    while(fin_>>licenseplate)//���ļ����ȡ����ҵĳ�������
    {
        i++;
        if(licenseplate == lp)
        {fin_.close();return i;}
    }
    fin_.close();
    return 0;
}
void File_Control::Write_Card_File(Dynamic_Chain & dc)//����Card.txt�ļ�
{
    ofstream fout("Card.txt",ios_base::out);
    fout << "		18		 17		 16	  	15	   11	���밴˳����д" << endl;
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
    cout << "�����ļ����ɳɹ�!!!" << endl;
}
void File_Control::Write_Car_File(Chain_Car & cc)//����Car.txt�ļ�
{
    ofstream fout("Car.txt",ios_base::out);
    fout << "���밴˳����д    20	       13		   20		       20		   20                     20" << endl;
    fout << "--------licenseplate--------model------maxcarrynumber----------drivername-----------timetable";
    fout.close();
    Car_Information * p = cc.Head_Pointer->Return_Next_Car();
    while(p != NULL)
    {

        Car_Write(p->License_Plate,p->Model,To_string_r(p->Carry_Number),To_string_r(p->Max_Carry_Number),p->Driver_Name,p->Time_Table);//��������Ϣд���ļ���
        Card * c = p->Return_Passenger_Information();
        while(!(c == NULL))//�ͷŸó��Ŀ�������
        {
            Card * t = c;
            c = c->Return_Next_Card();
            delete t;
        }
        Car_Information * t = p;
        p = p->Next_Car;
        delete t;
    }
    cout << "�����ļ����ɳɹ�!!!"<< endl;
}
void File_Control::Init_Card(Dynamic_Chain & Dynamic)           //��ʼ��
{
    string CardNumber,UserName,CardClass;
    string Cnt,Balance;

    ifstream fin("Card.txt");

    fin.ignore(255,'\n').ignore(255,'\n');

    while(fin >>CardNumber>>CardClass>>UserName>>Balance>>Cnt)
    {
        //cout <<CardNumber << endl << CardClass << endl << UserName <<endl << Balance << endl <<Cnt <<endl; //���ļ���ȡ������Ϣ �ڿ��������ﴴ���³�Ա
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
        // <<licenseplate << endl << model << endl << maxcarrynumber <<endl << drivername << endl <<timetable <<endl; //���ļ���ȡ������Ϣ �ڿ��������ﴴ���³�Ա
        cc.Add_Car(drivername,timetable,0,To_int(maxcarrynumber),model);
    }
    fin2.close();
}
