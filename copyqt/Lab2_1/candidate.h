#ifndef CANDIDATE_H
#define CANDIDATE_H
#include <QString>

class Candidate
{
    QString fullName = "Petr Efimovich";
    QString sex = "m";
    int age = 25, height = 179, weight = 75,
    minAge= 18, maxAge = 28, minH =150, maxH=190,
    minW = 40, maxW = 80;
    int numb=0;

public:
    Candidate();
    Candidate(int numb, QString fullName, QString sex, int age, int height, int weight,
              int minAge, int maxAge, int minH, int maxH, int minW, int maxW);
    void setCand(int numb, QString fullName, QString sex, int age, int height, int weight,
                 int minAge, int maxAge, int minH, int maxH, int minW, int maxW);
    void setNumb(int num);
    void setName(QString newName);
    void setSex(QString choice);
    void setAge(int newAge);
    void setHeight(int newHeight);
    void setWeight(int newWeight);
    void setMinAge(int newMinAge);
    void setMaxAge(int newMaxAge);
    void setMinHeight(int newMinHeight);
    void setMaxHeight(int newMaxHeight);
    void setMinWeight(int newMinWeight);
    void setMaxWeight(int newMaxWeight);

    int getNumb();
    QString getName();
    QString getSex();
    int getHeight();
    int getWeight();
    int getAge();
    int getMinAge();
    int getMaxAge();
    int getMinHeight();
    int getMaxHeight();
    int getMinWeight();
    int getMaxWeight();





};

#endif // CANDIDATE_H
