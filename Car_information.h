#ifndef CAR_INFORMATION_H
#define CAR_INFORMATION_H

#include <iostream>
#include <string>
#include "Class_file.h"
#include "fun_file.h"
using std::string;
class Card;
class File_Control;


class Car_Information //������Ϣ��
{
    friend File_Control;
private:
    static int Car_Number;
    string License_Plate;               //���� ���
    string Model;                       //�ͺ�
    int Carry_Number;                   //��������
    int Max_Carry_Number;              //����������
    string Driver_Name;
    string Time_Table;

    Car_Information * Next_Car;

    Card * Passenger_Information; //�൱��Card��ͷָ��
    Card * Passenger_Pointer;       //βָ��
public:

    Car_Information(int CN = 0,int MCN = 40);
    Car_Information(string DriverName,string TimeTable,int CN = 0,int MCN = 40,string Model = "IMB");
    virtual ~Car_Information(){};

    string Return_Driver_Name(void){return Driver_Name;}
    string Return_Time_Tabel(void){return Time_Table;}

    void Set_Carry_Number(int Carry_Number){this->Carry_Number = Carry_Number;}//�Գ��������Ľӿ�
    int Return_Carry_Number(void){return Carry_Number;}
    int Increase_Carry_Number(void){return ++Carry_Number;}
    int Is_Over_Carry(void){return Carry_Number >= Max_Carry_Number;}

    void Set_Max_Carry_Number(int Max_Carry_Number){this->Max_Carry_Number = Max_Carry_Number;}
    int Return_Max_Carry_Number(void){return Max_Carry_Number;}
    string Return_License_Plate(void){return License_Plate;}

    string Return_Model(void){return Model;}
    void Get_Down_Car(void){Carry_Number--;}
    void Show(void);

    Card * Return_Passenger_Information(void){return Passenger_Information;}//�Գ��Ͽ���ͷָ��Ľӿ�
    void Set_Passenger_Information(Card*p){Passenger_Information = p;}

    Card * Return_Passenger_Pointer(void){return Passenger_Pointer;}//�Գ��Ͽ���βָ��Ľӿ�
    void Set_Passenger_Pointer(Card*p){Passenger_Pointer = p;}

    Car_Information * Return_Next_Car(void){return Next_Car;}//����һ�����Ľӿ�
    void Set_Next_Car(Car_Information* p){Next_Car = p;}

};


#endif // CAR_INFORMATION_H
