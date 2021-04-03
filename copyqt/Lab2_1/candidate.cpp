#include "candidate.h"

Candidate::Candidate()
{

}

void Candidate::setNumb(int num)
{
    numb=num;
}

Candidate::Candidate(int numb, QString fullName, QString sex, int age, int height, int weight, int minAge, int maxAge, int minH, int maxH, int minW, int maxW)
{
    this->numb=numb;
    this->fullName = fullName;
    this->sex = sex;
    this->age = age;
    this->height = height;
    this->weight = weight;
    this->minAge = minAge;
    this->maxAge = maxAge;
    this->minH = minH;
    this->maxH = maxH;
    this->minW = minW;
    this->maxW = maxW;
}

void Candidate::setCand(int numb, QString fullName, QString sex, int age, int height, int weight,
                        int minAge, int maxAge, int minH, int maxH, int minW, int maxW)
{
    this->numb=numb;
    this->fullName = fullName;
    this->sex = sex;
    this->age = age;
    this->height = height;
    this->weight = weight;
    this->minAge = minAge;
    this->maxAge = maxAge;
    this->minH = minH;
    this->maxH = maxH;
    this->minW = minW;
    this->maxW = maxW;
}

void Candidate::setName(QString newName)
{
    fullName = newName;
}

void Candidate::setSex(QString choice)
{
    sex = choice;
}

void Candidate::setAge(int newAge)
{
    age = newAge;
}

void Candidate::setHeight(int newHeight)
{
    height = newHeight;
}

void Candidate::setWeight(int newWeight)
{
    weight = newWeight;
}

void Candidate::setMinAge(int newMinAge)
{
    minAge = newMinAge;
}

void Candidate::setMaxAge(int newMaxAge)
{
    maxAge = newMaxAge;
}

void Candidate::setMinHeight(int newMinHeight)
{
    minH = newMinHeight;
}

void Candidate::setMaxHeight(int newMaxHeight)
{
    maxH = newMaxHeight;
}

void Candidate::setMinWeight(int newMinWeight)
{
    minW = newMinWeight;
}

void Candidate::setMaxWeight(int newMaxWeight)
{
    maxW = newMaxWeight;
}

int Candidate::getNumb()
{
    return numb;
}

QString Candidate::getName()
{
    return fullName;
}

QString Candidate::getSex()
{
    return sex;
}

int Candidate::getHeight()
{
    return height;
}

int Candidate::getWeight()
{
    return weight;
}

int Candidate::getAge()
{
    return age;
}

int Candidate::getMinAge()
{
    return minAge;
}

int Candidate::getMaxAge()
{
    return maxAge;
}

int Candidate::getMinHeight()
{
    return minH;
}

int Candidate::getMaxHeight()
{
    return maxH;
}

int Candidate::getMinWeight()
{
    return minW;
}

int Candidate::getMaxWeight()
{
    return maxW;
}
