
#include "Car_information.h"

int Car_Information::Car_Number = -1;            //初始化车的数量为-1
void Car_Information::Show(void)                //显示车的所有信息
{
    cout << "License_Plate: " << License_Plate << endl;
    cout << "Driver_Name: " << Driver_Name << endl;
    cout << "Model: " << Model << endl;
    cout << "Carry_Number: " << Carry_Number << endl;
    cout << "Max_Carry_Number: " << Max_Carry_Number<< endl;
    cout << "Time_Table: " << Time_Table << endl;
}
Car_Information::Car_Information(int CN,int MCN)    //传入参数 进行构造
{
    Car_Number++;
    if(Car_Number>=0)
    {
    Carry_Number = CN;
    Max_Carry_Number = MCN;
    License_Plate = "XD" + To_string(Car_Number);          //将车的数量转化为车的编号
    Next_Car = NULL;                                //车的链表的下一辆车赋值为NULL
    Passenger_Information = new Card();             //建立该车上卡的链表头指针
    Passenger_Information->Next_Card(NULL);         //车上卡的下一张卡赋值为NULL
    Passenger_Information->Set_Include_Card(NULL);  //车上的卡连接卡的总链表的接口赋值为NULL
    Passenger_Pointer = Passenger_Information; //车上卡的指针指向头指针

    }

}
Car_Information::Car_Information(string DriverName,string TimeTable,int CN,int MCN,string Model)
{
    Car_Number++;
    if(Car_Number>=0)
    {
        Driver_Name = DriverName;
        Carry_Number = CN;
        Max_Carry_Number = MCN;
        this->Model = Model;
        Time_Table = TimeTable;
        License_Plate = "XD" + To_string(Car_Number);          //将车的数量转化为车的编号
        Next_Car = NULL;                                //车的链表的下一辆车赋值为NULL
        Passenger_Information = new Card();             //建立该车上卡的链表头指针
        Passenger_Information->Next_Card(NULL);         //车上卡的下一张卡赋值为NULL
        Passenger_Information->Set_Include_Card(NULL);  //车上的卡连接卡的总链表的接口赋值为NULL
        Passenger_Pointer = Passenger_Information; //车上卡的指针指向头指针

    }

}
