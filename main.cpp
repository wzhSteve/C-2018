#include <iostream>
#include "Class_file.h"
#include "fun_file.h"
#include "Car_information.h"
// 卡号"XD201800001"   五位
int main(void)
{

    Dynamic_Chain A;        //控制卡的链表的A
    Chain_Car B(A);         //控制车的链表的B
    File_Control C;         //控制文件的C
    C.Init_Card(A);         //为文件实例C传入卡链表
    C.Init_Car(B);          //为文件实例C传入车链表

    string enter;           //输入变量enter

    cout << "-----------欢迎来到一卡通乘车系统-----------"<< endl;
    cout << "-----------                      -----------"<<endl;
    cout <<"--------请问有什么能为您服务的。--"<<endl;
    cout << "--------请您开始建立新卡!!!" <<endl;
    while(1)
    {
            string f;
            cout<<"--------请问你要办理哪种卡: "<<endl;        //选择创建卡
                    remind();
                    string str;
                    cin >>str;
                    if((str == "T")||(str ==  "t"))
                    {
                        cout <<"--------请输入你的姓名: ";
                        string name;
                        cin>>name;
                        A.Add_TeacherCard(name);                //向卡的链表中加入新成员
                        cout <<"--------建立成功!--"<<endl;
                    }
                    else if((str == "S")||(str == "s"))
                    {
                        cout <<"--------请输入你的姓名: ";
                        string name;
                        cin>>name;
                        cout <<"--------请输入你的金额: ";
                        double deposits;
                        cin>>deposits;
                        A.Add_StudentCard(name,deposits);       //向卡的链表中加入新成员
                        cout <<"--------建立成功!--"<<endl;
                    }
                    else if((str == "L")||(str == "l"))
                    {
                        cout <<"--------请输入你的姓名: ";
                        string name;
                        cin>>name;
                        cout <<"--------请输入你的金额: ";
                        double deposits;
                        cin>>deposits;
                        A.Add_LimitCard(name,deposits);         //向卡的链表中加入新成员
                        cout << "--------建立成功!--------"<<endl;
                    }
                    else
                    {
                        while(1)
                        {
                            cout << "--------抱歉，您输入的字母不对，请问您要继续办理新卡么？y or n"<<endl;
                            cin >>f;
                            if((f == "N")||(f == "n"))break;
                            else if((f == "Y")||(f == "y"))
                            {
                                break;
                            }
                            else cout << "--------请输入正确选项，谢谢!--------";
                        }
                    }
            while(1)
            {
                cout <<"--------请问您是否已经建立足够的新卡想开始创建车辆? y or n "<<endl;
                cin >> enter;
                if((enter == "y")||(enter == "Y"))break;
                else if ((enter == "N")||(enter == "n"))break;
                else cout << "--------抱歉，您输入的字母不对"<<endl;

            }
            if((enter == "Y")||(enter == "y"))break;
    }
    cout << "--------您好,接下来开始建立车辆!!!"<< endl;
    while(1)
    {
            int max_carry_number;
            string DriverName;
            string TimeTable;
            char time;
            string Model;
            cout << "--------请输入司机姓名: ";
            cin >> DriverName;

            cout << "--------A:5:30--18:30"<<endl<<"--------B:6:00--19:00"<<endl<<"-------C:6:30--19:30"<<endl;
            cout << "--------请选择时刻表 a or b or c: ";
            cin >> time;
           switch(time)                                 //选择时刻表
            {
            case 'A':
            case 'a': {TimeTable = "5:30--18:30";break;}
            case 'b':
            case 'B': {TimeTable = "6:00--19:00";break;}
            case 'c':
            case 'C': {TimeTable = "6:30--19:30";break;}
            default: {TimeTable = "7:30--20:30";break;}
            }

            cout << "--------请输入车的型号: ";
            cin >> Model;
            cout << "--------请输入车的最大承载人数: ";
            cin >> max_carry_number;
            B.Add_Car(DriverName,TimeTable,0,max_carry_number,Model);//向车的链表中加入新成员
            while(1)
            {
                cout << "--------请问您是否觉得已经建立了足够多的车辆,准备开始乘车? y or n"<< endl;
                cin >> enter;
                if((enter == "y")||(enter == "Y"))break;
                else if((enter == "N")||(enter == "n"))break;
                else cout << "--------抱歉,您输入的字母不对"<<endl;
            }
            if((enter == "y")||(enter == "Y"))break;
    }
    cout << "--------您好,接下来开始乘车!!!" << endl;
    while(1)
    {
            string Car_number;
            string usn;
            cout << "--------乘客你好，请问你要乘坐哪一辆车:   ";
            cin.clear();
            cin >>Car_number;
            cin.clear();
            cout << endl << "--------请问 你的名字是:   ";
            cin >> usn;
            cout << "--------名字: " <<usn;
            cin.clear();
            B.Add_Passenger(Car_number,usn);            //向该车的卡的链表中加入新成员
            while(1)
            {
                cout << "--------请问您是否要结束上车,开始下车? y or n " << endl;
                cin >> enter;
                if((enter == "y")||(enter == "Y"))break;
                else if((enter == "N")||(enter == "n"))break;
                else cout << "--------抱歉,您输入的字母不对"<<endl;
            }
            if((enter == "y")||(enter == "Y"))break;
    }
    while(1)
    {
        string licenseplate;
        cout << "--------请任意输入一个车牌号: ";
        cin >> licenseplate;
        Car_Information * p = B.Search_Car(licenseplate);       //检索车
        if(p != NULL)//判断是否检测到车的指针
        {
            int num = p->Return_Carry_Number();
            if(num)
            {
                int rn = rand()%(num+1);        //生成随机数量乘客下车

                if(rn)
                {
                    cout << "有" << rn << "个乘客下车。" <<endl;
                    while(rn--)
                    {
                        int a;
                        a = 1+rand()%num;       //选择随机的乘客下车
                        Card * q = p->Return_Passenger_Information();
                        for(;a > 0;a--)
                        {
                            q = q->Return_Next_Card();
                        }
                        Card * c = q->Return_Include_Card();
                        string cardn = c->Return_cardnumber();
                        cout << "名字" << cardn << endl;
                        cout << c->Return_username() << "下车!!!" <<endl;
                        p->Get_Down_Car();          //调用下车函数
                        p->Show();
                        B.Delete_Card(cardn,p);
                        num--;
                    }
                }
                else cout << "--------没有乘客下车。"<< endl;
            }
            else cout << "--------该车上目前没有乘客。" << endl;

        }
        else cout << "--------抱歉 没有您要查找的车号!!!"<<endl;
        while(1)
        {
            cout << "--------请问您要结束程序么? y or n: ";
            cin >> enter;
            if((enter == "y")||(enter == "Y"))break;
            else if((enter == "n")||(enter == "N"))break;
            else cout << "--------请输入正确字母!!!"<<endl;
        }
        if((enter == "y")||(enter == "Y"))break;
    }
    C.Write_Car_File(B);//更新Car.txt
    C.Write_Card_File(A);//更新card.txt
    cout << "--------感谢使用本系统,欢迎再次使用!!!" << endl;
    cout << "--------再见。" << endl;
    return 0;
}
