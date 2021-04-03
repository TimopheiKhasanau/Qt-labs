#ifndef LIST_H
#define LIST_H
#include <QString>
#include <QFile>
#include <QTextStream>
#include "candidate.h"


class List
{

   Candidate** lal, **final;
   Candidate* cop;
    QString fileName = "";
    QFile *file;
        int size, delcoef=0;

    QTextStream *fileStream;
public:
    List();
    Candidate* send(int number);
    void setFileName(QString name);
    void initialize();
    void push( Candidate* element);
    void edit(int numb, QString fullName, QString sex, int age, int height, int weight, int minAge, int maxAge, int minH, int maxH, int minW, int maxW);
    void pop(int number);
    QList<Candidate*> result(int numb);
    QList<Candidate*> findCand(QStringList keyWords);
    Candidate** transport();
    void FileNameForList(QString name);
    int getSize();

    Candidate* operator[](int pos);
};

#endif // LISCandidate_H
