
#include "Car_information.h"

int Car_Information::Car_Number = -1;            //��ʼ����������Ϊ-1
void Car_Information::Show(void)                //��ʾ����������Ϣ
{
    cout << "License_Plate: " << License_Plate << endl;
    cout << "Driver_Name: " << Driver_Name << endl;
    cout << "Model: " << Model << endl;
    cout << "Carry_Number: " << Carry_Number << endl;
    cout << "Max_Carry_Number: " << Max_Carry_Number<< endl;
    cout << "Time_Table: " << Time_Table << endl;
}
Car_Information::Car_Information(int CN,int MCN)    //������� ���й���
{
    Car_Number++;
    if(Car_Number>=0)
    {
    Carry_Number = CN;
    Max_Carry_Number = MCN;
    License_Plate = "XD" + To_string(Car_Number);          //����������ת��Ϊ���ı��
    Next_Car = NULL;                                //�����������һ������ֵΪNULL
    Passenger_Information = new Card();             //�����ó��Ͽ�������ͷָ��
    Passenger_Information->Next_Card(NULL);         //���Ͽ�����һ�ſ���ֵΪNULL
    Passenger_Information->Set_Include_Card(NULL);  //���ϵĿ����ӿ���������Ľӿڸ�ֵΪNULL
    Passenger_Pointer = Passenger_Information; //���Ͽ���ָ��ָ��ͷָ��

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
        License_Plate = "XD" + To_string(Car_Number);          //����������ת��Ϊ���ı��
        Next_Car = NULL;                                //�����������һ������ֵΪNULL
        Passenger_Information = new Card();             //�����ó��Ͽ�������ͷָ��
        Passenger_Information->Next_Card(NULL);         //���Ͽ�����һ�ſ���ֵΪNULL
        Passenger_Information->Set_Include_Card(NULL);  //���ϵĿ����ӿ���������Ľӿڸ�ֵΪNULL
        Passenger_Pointer = Passenger_Information; //���Ͽ���ָ��ָ��ͷָ��

    }

}
