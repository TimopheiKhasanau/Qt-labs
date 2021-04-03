#include "list.h"

List::List(){}

Candidate *List::send(int number)
{
    for( int i =0; i< size; i++)
    {
        if(lal[i]->getNumb() == number)
        {
            return lal[i];
        }
    }
};

void List::initialize()
{
       file = nullptr;
       fileStream = nullptr;
       lal = nullptr;
       size = 0;
       lal = new Candidate*[size];
       file = new QFile(fileName);
       fileStream = new QTextStream(file);
       if (!file->open(QIODevice::ReadOnly)) {
           qWarning("Cannot open file for reading");
       }
       QStringList fieldsList;
       while (!fileStream->atEnd()) {
           QString line = fileStream->readLine();
           fieldsList = line.split('&');
           Candidate *partn = new Candidate(fieldsList[0].toInt(),fieldsList[1],fieldsList[2],fieldsList[3].toInt(),fieldsList[4].toInt(),fieldsList[5].toInt(),
                   fieldsList[6].toInt(), fieldsList[7].toInt(), fieldsList[8].toInt(), fieldsList[9].toInt(), fieldsList[10].toInt(),fieldsList[11].toInt());
           if(!size) {
               lal[0] = partn;
           }
           else {
               Candidate **copy = new Candidate*[size+1];
               for(int i = 0; i < size; i++) {
                   copy[i] = lal[i];
               }
               copy[size] = partn;
               delete[] lal;
               lal = nullptr;
               lal = new Candidate*[size+1];
               for(int i = 0; i < size+1; i++) {
                   lal[i] = copy[i];
               }
               delete[] copy;
           }
           size++;
       }

       file->close();
}


Candidate* List::operator[](int pos)
{
    return lal[pos];
}


void List::push(Candidate* element)
{
    Candidate **copy = new Candidate*[size+1];
        for(int i = 0; i < size; i++) {
            copy[i] = lal[i];
        }
        copy[size] = element;
        delete[] lal;
        lal = nullptr;
        lal = new Candidate*[size+1];
        for(int i = 0; i < size+1; i++) {
            lal[i] = copy[i];
        }
        delete[] copy;
        size++;
        delcoef++;

        QString sum = "";
        int nom = element->getNumb();
        QString name = element->getName();
        QString pol = element->getSex();
        int mainAge = element->getAge();
        int h = element->getHeight();
        int w = element->getWeight();
        int nAge = element->getMinAge();
        int xAge = element->getMaxAge();
        int minh = element->getMinHeight();
        int maxh = element->getMaxHeight();
        int minw = element->getMinWeight();
        int maxw = element->getMaxWeight();

        sum.append(QString::number(nom));
        sum.append("&");
        sum.append(name);
        sum.append("&");
        sum.append(pol);
        sum.append("&");
        sum.append(QString::number(mainAge));
        sum.append("&");
        sum.append(QString::number(h));
        sum.append("&");
        sum.append(QString::number(w));
        sum.append("&");
        sum.append(QString::number(nAge));
        sum.append("&");
        sum.append(QString::number(xAge));
        sum.append("&");
        sum.append(QString::number(minh));
        sum.append("&");
        sum.append(QString::number(maxh));
        sum.append("&");
        sum.append(QString::number(minw));
        sum.append("&");
        sum.append(QString::number(maxw));
        sum.append("\n");

        if (file->open(QIODevice::WriteOnly | QIODevice::Append)) {
            fileStream->operator <<(sum);
        }
        file->close();
}

void List::edit(int numb, QString fullName, QString sex, int age, int height, int weight, int minAge, int maxAge, int minH, int maxH, int minW, int maxW)
{
       QStringList fileDataList;
       QStringList fieldsList;
        for(int i = 0; i < size; i++)
        {
               if(lal[i]->getNumb() == numb)
               {
                   lal[i]->setCand(numb, fullName, sex,  age,  height,  weight,  minAge,  maxAge,  minH,  maxH,  minW,  maxW);
                   break;
               }
         }

           if(file->open(QIODevice::ReadWrite | QIODevice::Text))
           {
               while(!fileStream->atEnd())
               {
                   QString line = fileStream->readLine();
                   line.append('\n');
                   fileDataList.append(line);
               }
           }
           file->close();



                 for(int i = 0; i < fileDataList.length(); i++)
                 {
                    fieldsList = fileDataList[i].split('&');
                     if(fieldsList[0] == QString::number(numb))
                     {
                         fileDataList[i] = "";
                         fileDataList[i].append(QString::number(numb));
                         fileDataList[i].append('&');
                         fileDataList[i].append(fullName);
                         fileDataList[i].append('&');
                         fileDataList[i].append(sex);
                         fileDataList[i].append('&');
                         fileDataList[i].append(QString::number(age));
                         fileDataList[i].append('&');
                         fileDataList[i].append(QString::number(height));
                         fileDataList[i].append('&');
                         fileDataList[i].append(QString::number(weight));
                         fileDataList[i].append('&');
                         fileDataList[i].append(QString::number(minAge));
                         fileDataList[i].append('&');
                         fileDataList[i].append(QString::number(maxAge));
                         fileDataList[i].append('&');
                         fileDataList[i].append(QString::number(minH));
                         fileDataList[i].append('&');
                         fileDataList[i].append(QString::number(maxH));
                         fileDataList[i].append('&');
                         fileDataList[i].append(QString::number(minW));
                         fileDataList[i].append('&');
                         fileDataList[i].append(QString::number(maxW));
                         fileDataList[i].append('\n');
                     }
                 }


                 if (file->open(QIODevice::WriteOnly))
                 {
                       for(int i = 0; i < fileDataList.length(); i++)
                       {
                           fileStream->operator <<(fileDataList[i]);
                       }
                 }
                       file->close();


}


void List::pop(int number)
{
    QStringList fileDataList;
    QStringList fieldsList;
    Candidate** copy = new Candidate*[size-1];
    bool finded = false;
       for(int i = 0; i < size; i++)
       {
           if(lal[i]->getNumb() == number)
           {
               finded = true;
               continue;
           }

           if(finded)
           {
                 copy[i-1] = lal[i];
           }
           else
           {
               copy[i] = lal[i];
           }

       }
       delete[] lal;
       lal = nullptr;
       lal = new Candidate*[size-1];

       for( int i = 0; i < size-1 ; i++)
       {
               lal[i] = copy[i];
       }
       delete[] copy;
       size--;
        delcoef++;

       if(file->open(QIODevice::ReadWrite | QIODevice::Text))
       {
           while(!fileStream->atEnd())
           {
               QString line = fileStream->readLine();
               line.append('\n');
               fileDataList.append(line);
           }
       }
       file->close();

       int coef;
       for(int i = 0; i < fileDataList.length(); i++)
       {
           fieldsList = fileDataList[i].split('&');
           if(fieldsList[0] == QString::number(number))
           {
               fileDataList.removeAt(i);
               coef = i;
           }
       }

//       for(int i = 0; i < fileDataList.length(); i++)
//       {
//           fieldsList = fileDataList[i].split('&');
//           QString check = fieldsList[0];
//           int coc =check.toInt();
//           if(coc >= coef)
//           {
//               QString proto =  fileDataList[i];
//               int gen =fieldsList[0].toInt() -1;
//               QChar mam = (char)gen;
//               proto[0] = mam;
//                fileDataList[i] = proto;
//           }
//       }

       if (file->open(QIODevice::WriteOnly)) {
           for(int i = 0; i < fileDataList.length(); i++) {
            fileStream->operator <<(fileDataList[i]);
           }
       }
       file->close();
}

QList<Candidate*> List::result( int numb )
{
    int id, age,  height,  weight,  minAge,  maxAge,  minH,  maxH, minW, maxW;
    int pid, page,  pheight,  pweight,  pminAge,  pmaxAge,  pminH,  pmaxH, pminW, pmaxW;
    QString sex, partnSex;
    numb-=1;
    int num = numb;

    if(num>delcoef)
    {
        numb-=delcoef;
    }

    sex = lal[numb]->getSex();
    id = lal[numb]->getNumb();
    age = lal[numb]->getAge();
    height = lal[numb]->getHeight();
    weight = lal[numb]->getWeight();
    minAge = lal[numb]->getMinAge();
    maxAge = lal[numb]->getMaxAge();
    minH = lal[numb]->getMinHeight();
    maxH = lal[numb]->getMaxHeight();
    minW = lal[numb]->getMinWeight();
    maxW = lal[numb]->getMaxWeight();

    QList <Candidate*> crash;
    for(int i =0; i< size; i++)
    {
        partnSex = lal[i]->getSex();
        pid = lal[i]->getNumb();
        page = lal[i]->getAge();
        pheight = lal[i]->getHeight();
        pweight = lal[i]->getWeight();
        pminAge = lal[i]->getMinAge();
        pmaxAge = lal[i]->getMaxAge();
        pminH = lal[i]->getMinHeight();
        pmaxH = lal[i]->getMaxHeight();
        pminW = lal[i]->getMinWeight();
        pmaxW = lal[i]->getMaxWeight();

        if( sex != partnSex && id != pid)
         {
            if( age >= pminAge && age<= pmaxAge && page >= minAge && page<=maxAge )
            {
                if( weight >= pminW && weight <= pmaxW && pweight >= minW && weight <= maxW )
                {
                    if(height >= pminH && height <= pmaxH && pheight >= minH && height <= maxH)
                    {
                          crash.append(lal[i]);
                    }
                }
            }

         }
            // lal[numb]->getWeight()>=lal[i]->getMinWeight() && lal[numb]->getWeight()<=lal[i]->getMaxWeight() )
    }

    for(int i = crash.length()-1; i >= 0; i--)
    {
         for(int j = crash.length()-1; j >= i; j--)
         {
             if(crash[j]->getAge() > crash[i]->getAge())
             {
                 std::swap(crash[i], crash[j]);
             }
         }
     }
    return crash;
}

QList<Candidate *> List::findCand( QStringList keyWords )
{
    QList <Candidate*> resultList;
       for( int i = 0;  i < size;  i++)
       {
           for( int j = 0;  j < keyWords.length();  j++)
           {
               if( lal[i]->getName().contains(keyWords[j]) )
               {
                   if( !resultList.contains(lal[i]) )
                   {
                       resultList.append(lal[i]);
                       break;
                   }
               }
           }
       }
     return resultList;
}

Candidate ** List::transport()
{
    return lal;
}

void List::FileNameForList(QString name)
{
    fileName = name;
}

int List::getSize()
{
    return size;
}

