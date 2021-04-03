#ifndef STUDENT_H
#define STUDENT_H
#include<QString>

class Student
{
    int number;
    QString name, groupCode;
    float avScore;
    int monPerMemb;
public:
    Student();
    Student( int number, QString name, QString groupCode, float avScore,  int monPerMemb);

    int getNumb();
    QString getName();
    QString getGrCode();
    float getScore();
    int getMoney();

    void setNumb(int numb);
    void setName(QString nam);
    void setGrCode( QString code);
    void setScore( float score);
    void setMoney(int money);


};

#endif // STUDENT_H
