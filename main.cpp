#include <iostream>
#include "Class_file.h"
#include "fun_file.h"
#include "Car_information.h"
// ����"XD201800001"   ��λ
int main(void)
{

    Dynamic_Chain A;        //���ƿ��������A
    Chain_Car B(A);         //���Ƴ��������B
    File_Control C;         //�����ļ���C
    C.Init_Card(A);         //Ϊ�ļ�ʵ��C���뿨����
    C.Init_Car(B);          //Ϊ�ļ�ʵ��C���복����

    string enter;           //�������enter

    cout << "-----------��ӭ����һ��ͨ�˳�ϵͳ-----------"<< endl;
    cout << "-----------                      -----------"<<endl;
    cout <<"--------������ʲô��Ϊ������ġ�--"<<endl;
    cout << "--------������ʼ�����¿�!!!" <<endl;
    while(1)
    {
            string f;
            cout<<"--------������Ҫ�������ֿ�: "<<endl;        //ѡ�񴴽���
                    remind();
                    string str;
                    cin >>str;
                    if((str == "T")||(str ==  "t"))
                    {
                        cout <<"--------�������������: ";
                        string name;
                        cin>>name;
                        A.Add_TeacherCard(name);                //�򿨵������м����³�Ա
                        cout <<"--------�����ɹ�!--"<<endl;
                    }
                    else if((str == "S")||(str == "s"))
                    {
                        cout <<"--------�������������: ";
                        string name;
                        cin>>name;
                        cout <<"--------��������Ľ��: ";
                        double deposits;
                        cin>>deposits;
                        A.Add_StudentCard(name,deposits);       //�򿨵������м����³�Ա
                        cout <<"--------�����ɹ�!--"<<endl;
                    }
                    else if((str == "L")||(str == "l"))
                    {
                        cout <<"--------�������������: ";
                        string name;
                        cin>>name;
                        cout <<"--------��������Ľ��: ";
                        double deposits;
                        cin>>deposits;
                        A.Add_LimitCard(name,deposits);         //�򿨵������м����³�Ա
                        cout << "--------�����ɹ�!--------"<<endl;
                    }
                    else
                    {
                        while(1)
                        {
                            cout << "--------��Ǹ�����������ĸ���ԣ�������Ҫ���������¿�ô��y or n"<<endl;
                            cin >>f;
                            if((f == "N")||(f == "n"))break;
                            else if((f == "Y")||(f == "y"))
                            {
                                break;
                            }
                            else cout << "--------��������ȷѡ�лл!--------";
                        }
                    }
            while(1)
            {
                cout <<"--------�������Ƿ��Ѿ������㹻���¿��뿪ʼ��������? y or n "<<endl;
                cin >> enter;
                if((enter == "y")||(enter == "Y"))break;
                else if ((enter == "N")||(enter == "n"))break;
                else cout << "--------��Ǹ�����������ĸ����"<<endl;

            }
            if((enter == "Y")||(enter == "y"))break;
    }
    cout << "--------����,��������ʼ��������!!!"<< endl;
    while(1)
    {
            int max_carry_number;
            string DriverName;
            string TimeTable;
            char time;
            string Model;
            cout << "--------������˾������: ";
            cin >> DriverName;

            cout << "--------A:5:30--18:30"<<endl<<"--------B:6:00--19:00"<<endl<<"-------C:6:30--19:30"<<endl;
            cout << "--------��ѡ��ʱ�̱� a or b or c: ";
            cin >> time;
           switch(time)                                 //ѡ��ʱ�̱�
            {
            case 'A':
            case 'a': {TimeTable = "5:30--18:30";break;}
            case 'b':
            case 'B': {TimeTable = "6:00--19:00";break;}
            case 'c':
            case 'C': {TimeTable = "6:30--19:30";break;}
            default: {TimeTable = "7:30--20:30";break;}
            }

            cout << "--------�����복���ͺ�: ";
            cin >> Model;
            cout << "--------�����복������������: ";
            cin >> max_carry_number;
            B.Add_Car(DriverName,TimeTable,0,max_carry_number,Model);//�򳵵������м����³�Ա
            while(1)
            {
                cout << "--------�������Ƿ�����Ѿ��������㹻��ĳ���,׼����ʼ�˳�? y or n"<< endl;
                cin >> enter;
                if((enter == "y")||(enter == "Y"))break;
                else if((enter == "N")||(enter == "n"))break;
                else cout << "--------��Ǹ,���������ĸ����"<<endl;
            }
            if((enter == "y")||(enter == "Y"))break;
    }
    cout << "--------����,��������ʼ�˳�!!!" << endl;
    while(1)
    {
            string Car_number;
            string usn;
            cout << "--------�˿���ã�������Ҫ������һ����:   ";
            cin.clear();
            cin >>Car_number;
            cin.clear();
            cout << endl << "--------���� ���������:   ";
            cin >> usn;
            cout << "--------����: " <<usn;
            cin.clear();
            B.Add_Passenger(Car_number,usn);            //��ó��Ŀ��������м����³�Ա
            while(1)
            {
                cout << "--------�������Ƿ�Ҫ�����ϳ�,��ʼ�³�? y or n " << endl;
                cin >> enter;
                if((enter == "y")||(enter == "Y"))break;
                else if((enter == "N")||(enter == "n"))break;
                else cout << "--------��Ǹ,���������ĸ����"<<endl;
            }
            if((enter == "y")||(enter == "Y"))break;
    }
    while(1)
    {
        string licenseplate;
        cout << "--------����������һ�����ƺ�: ";
        cin >> licenseplate;
        Car_Information * p = B.Search_Car(licenseplate);       //������
        if(p != NULL)//�ж��Ƿ��⵽����ָ��
        {
            int num = p->Return_Carry_Number();
            if(num)
            {
                int rn = rand()%(num+1);        //������������˿��³�

                if(rn)
                {
                    cout << "��" << rn << "���˿��³���" <<endl;
                    while(rn--)
                    {
                        int a;
                        a = 1+rand()%num;       //ѡ������ĳ˿��³�
                        Card * q = p->Return_Passenger_Information();
                        for(;a > 0;a--)
                        {
                            q = q->Return_Next_Card();
                        }
                        Card * c = q->Return_Include_Card();
                        string cardn = c->Return_cardnumber();
                        cout << "����" << cardn << endl;
                        cout << c->Return_username() << "�³�!!!" <<endl;
                        p->Get_Down_Car();          //�����³�����
                        p->Show();
                        B.Delete_Card(cardn,p);
                        num--;
                    }
                }
                else cout << "--------û�г˿��³���"<< endl;
            }
            else cout << "--------�ó���Ŀǰû�г˿͡�" << endl;

        }
        else cout << "--------��Ǹ û����Ҫ���ҵĳ���!!!"<<endl;
        while(1)
        {
            cout << "--------������Ҫ��������ô? y or n: ";
            cin >> enter;
            if((enter == "y")||(enter == "Y"))break;
            else if((enter == "n")||(enter == "N"))break;
            else cout << "--------��������ȷ��ĸ!!!"<<endl;
        }
        if((enter == "y")||(enter == "Y"))break;
    }
    C.Write_Car_File(B);//����Car.txt
    C.Write_Card_File(A);//����card.txt
    cout << "--------��лʹ�ñ�ϵͳ,��ӭ�ٴ�ʹ��!!!" << endl;
    cout << "--------�ټ���" << endl;
    return 0;
}
