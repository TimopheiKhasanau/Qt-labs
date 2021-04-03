#include "student.h"

Student::Student()
{

}

Student::Student(int number, QString name, QString groupCode, float avScore, int monPerMemb)
{
    this->number = number;
    this->name = name;
    this->groupCode = groupCode;
    this->avScore = avScore;
    this->monPerMemb = monPerMemb;
}

int Student::getNumb()
{
    return number;
}

QString Student::getName()
{
    return name;
}

QString Student::getGrCode()
{
    return groupCode;
}

float Student::getScore()
{
    return avScore;
}

int Student::getMoney()
{
    return monPerMemb;
}

void Student::setNumb(int numb)
{
    number =numb;
}

void Student::setName(QString nam)
{
    name = nam;
}

void Student::setGrCode(QString code)
{
    groupCode = code;
}

void Student::setScore(float score)
{
    avScore = score;
}

void Student::setMoney(int money)
{
    monPerMemb = money;
}

