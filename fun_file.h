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
string To_string(int i);            //将输入的整数转化为字符串
int pow10(int i);                   //10的i次幂
int To_int(string p);               //将输入的字符串转化为整数
void remind();
class Card;
class TeacherCard;
class StudentCard;
class LimitCard;
class Car_Information;
class File_Control;

 //对Card进行操作的系统类

class Dynamic_Chain
{
    friend File_Control;
private:
    Card * Head_Pointer;            //头指针
    Card * Pointer_Link;            //尾指针
public:
    Dynamic_Chain();
    void Add_TeacherCard(const string un,int cnt = 0);                         //为链表添加教师卡
    void Add_StudentCard(const string un,const double ds = 30,int cnt = 0);    //为链表添加学生卡
    void Add_LimitCard(const string un,const double ds = 30,int cnt = 0);      //为链表添加限制卡
    int Get_on(const string cardnumber);                                       //上车
    Card * Search_Card(const string cardnumber);                  //按卡号查找对应卡 修改数据
    void Delete_Card(const string cardnumber);                    //删除对应卡号的卡
};

//控制车链表的类

class Chain_Car
{
friend File_Control;
private:
    Car_Information * Head_Pointer;//指向车的头指针
    Car_Information * Pointer_Link;//指向最新建立的车
    Card * Head_Passenger;          //指向车上的卡的链表 头指针
    Card * Passenger_Pointer;       //指向最新的车上的卡
    Dynamic_Chain  Dynamic;        //导入卡的链表
public:
    Chain_Car(Dynamic_Chain & Dynamic);         //传入卡的链表
    void Add_Car(string DriverName,string TimeTable,int CN = 0,int MCN = 40,string Model = "IBM");     //增加车
    Car_Information * Search_Car(string License_Plate);//查找车 并返回至向他的指针
    void Add_Passenger(string lp,string un);//增加乘客
    void Show_Car_Information();            //显示车的信息
    void Delete_Card(const string cardnumber,Car_Information * b);                    //删除对应卡号的卡
};


//控制文件的类


class File_Control
{
public:
    void Card_Write(string cardnumber,string cardtype,string username,string balance = "NULL",string cnt = "0");    //在文件尾插入新行
    void Card_Read(int n,string &cardnumber,string &cardtype,string &username,string &balance,string &cnt);   //读取指定行的参数
    int Search_Card(string cn);                                                                                 //找到返回行数 未找到返回0
    //void Rewrite_Card(string cn,string balance,string cnt);
    void Car_Write(string licenseplate,string model,string carrynumber,string maxcarrynumber,string drivername,string timetable);    //在文件尾插入新行
    void Car_Read(int n,string &licenseplate,string &model,string &maxcarrynumber,string &drivername,string &timetable);   //读取指定行的参数
    int Search_Car(string cn);                                                                                      //找到返回行数 未找到返回0

    void Write_Card_File(Dynamic_Chain & dc);           //生成卡的文件并释放指针
    void Write_Car_File(Chain_Car & cc);                //生成车的文件并释放指针
    void Init_Card(Dynamic_Chain & Dynamic);                  //初始化卡的链表
    void Init_Car(Chain_Car & cc);                            //初始化车的链表
};
#endif
