#ifndef FUN_FILE_H
#define FUN_FILE_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Class_file.h"
#include "Car_information.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ifstream;
using std::ios_base;
using std::ofstream;

string To_string_r(int i);
string To_string(int i);            //�����������ת��Ϊ�ַ���
int pow10(int i);                   //10��i����
int To_int(string p);               //��������ַ���ת��Ϊ����
void remind();
class Card;
class TeacherCard;
class StudentCard;
class LimitCard;
class Car_Information;
class File_Control;

 //��Card���в�����ϵͳ��

class Dynamic_Chain
{
    friend File_Control;
private:
    Card * Head_Pointer;            //ͷָ��
    Card * Pointer_Link;            //βָ��
public:
    Dynamic_Chain();
    void Add_TeacherCard(const string un,int cnt = 0);                         //Ϊ������ӽ�ʦ��
    void Add_StudentCard(const string un,const double ds = 30,int cnt = 0);    //Ϊ�������ѧ����
    void Add_LimitCard(const string un,const double ds = 30,int cnt = 0);      //Ϊ����������ƿ�
    int Get_on(const string cardnumber);                                       //�ϳ�
    Card * Search_Card(const string cardnumber);                  //�����Ų��Ҷ�Ӧ�� �޸�����
    void Delete_Card(const string cardnumber);                    //ɾ����Ӧ���ŵĿ�
};

//���Ƴ��������

class Chain_Car
{
friend File_Control;
private:
    Car_Information * Head_Pointer;//ָ�򳵵�ͷָ��
    Car_Information * Pointer_Link;//ָ�����½����ĳ�
    Card * Head_Passenger;          //ָ���ϵĿ������� ͷָ��
    Card * Passenger_Pointer;       //ָ�����µĳ��ϵĿ�
    Dynamic_Chain  Dynamic;        //���뿨������
public:
    Chain_Car(Dynamic_Chain & Dynamic);         //���뿨������
    void Add_Car(string DriverName,string TimeTable,int CN = 0,int MCN = 40,string Model = "IBM");     //���ӳ�
    Car_Information * Search_Car(string License_Plate);//���ҳ� ��������������ָ��
    void Add_Passenger(string lp,string un);//���ӳ˿�
    void Show_Car_Information();            //��ʾ������Ϣ
    void Delete_Card(const string cardnumber,Car_Information * b);                    //ɾ����Ӧ���ŵĿ�
};


//�����ļ�����


class File_Control
{
public:
    void Card_Write(string cardnumber,string cardtype,string username,string balance = "NULL",string cnt = "0");    //���ļ�β��������
    void Card_Read(int n,string &cardnumber,string &cardtype,string &username,string &balance,string &cnt);   //��ȡָ���еĲ���
    int Search_Card(string cn);                                                                                 //�ҵ��������� δ�ҵ�����0
    //void Rewrite_Card(string cn,string balance,string cnt);
    void Car_Write(string licenseplate,string model,string carrynumber,string maxcarrynumber,string drivername,string timetable);    //���ļ�β��������
    void Car_Read(int n,string &licenseplate,string &model,string &maxcarrynumber,string &drivername,string &timetable);   //��ȡָ���еĲ���
    int Search_Car(string cn);                                                                                      //�ҵ��������� δ�ҵ�����0

    void Write_Card_File(Dynamic_Chain & dc);           //���ɿ����ļ����ͷ�ָ��
    void Write_Car_File(Chain_Car & cc);                //���ɳ����ļ����ͷ�ָ��
    void Init_Card(Dynamic_Chain & Dynamic);                  //��ʼ����������
    void Init_Car(Chain_Car & cc);                            //��ʼ����������
};
#endif
