#include "function.h"
#include "ui_function.h"

Function::Function(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Function)
{
    ui->setupUi(this);
}

Function::~Function()
{
    delete ui;
}

void Function::on_Accept_clicked()
{
    QString name = ui->NameEdit->toPlainText();
    QString sex = ui->SexEdit->toPlainText();
    QString sAge = ui->AgeEdit->toPlainText() ;
    QString sheight = ui->HeightEdit->toPlainText();
    QString sweight = ui->WeightEdit->toPlainText();
    QString sminAge = ui->MinAgeEdit->toPlainText();
    QString smaxAge = ui->MaxAgeEdit->toPlainText();
    QString sminH = ui->MinHEdit->toPlainText();
    QString smaxH = ui->MaxHEdit->toPlainText();
    QString sminW = ui->MinWEdit->toPlainText();
    QString smaxW = ui->MaxWEdit->toPlainText();

    int number;
    int maxNumb;
    int  Age = sAge.toInt();
    int  height = sheight .toInt();
    int  weight =sweight.toInt();
    int  minAge = sminAge.toInt();
    int  maxAge = smaxAge.toInt();
    int  minH = sminH.toInt();
    int  maxH =smaxH .toInt();
    int  minW = sminW.toInt();
    int  maxW = smaxW.toInt();

    if( !name.count() || !sex.count()) return;
    if( name.contains('&') || sex.contains('&')) return;
    if( !Age || !height || !weight) return;
    if( !minAge || !minH || !minW) return;
    if( !maxAge || !maxH || !maxW) return;

    if( editing )
    {
        number = pot_cand->getNumb();
        list ->edit( number, name, sex, Age, height, weight, minAge, maxAge, minH, maxH, minW, maxW);
    }
    else
    {
        maxNumb = list->transport()[list->getSize()-1]->getNumb();
        number =maxNumb +1;
        Candidate* nova = new Candidate(number, name, sex, Age, height, weight, minAge, maxAge, minH, maxH, minW, maxW);
        list->push(nova);
    }
     this->hide();
}

void Function::ListOfObj(List *list, bool editing, Candidate *_cand)
{
       this->list = list;
       this->editing = editing;
       this->pot_cand = _cand;
    if(editing)
    {
         ui->NameEdit->setText(pot_cand->getName());
         ui->SexEdit->setText(pot_cand->getSex());
         ui->AgeEdit->setText(QString::number(pot_cand->getAge()));
         ui->HeightEdit->setText(QString::number(pot_cand->getHeight()));
         ui->WeightEdit->setText(QString::number(pot_cand->getWeight()));
         ui->MinAgeEdit->setText(QString::number(pot_cand->getMinAge()));
         ui->MaxAgeEdit->setText(QString::number(pot_cand->getMaxAge()));
         ui->MinHEdit->setText(QString::number(pot_cand->getMinHeight()));
         ui->MaxHEdit->setText(QString::number(pot_cand->getMaxHeight()));
         ui->MinWEdit->setText(QString::number(pot_cand->getMinWeight()));
         ui->MaxWEdit->setText(QString::number(pot_cand->getMaxWeight()));
    }
}
