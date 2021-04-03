#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startlist = new List<Student>();

    viewList = ui->vlist;
    resList = ui->rList;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_clearList_clicked()
{
    viewList->clear();
    QListWidgetItem *poten = new QListWidgetItem();
    poten->setText("ID\tName\tGroupCode\t AverageScore\tSufficiency");
    poten->setData(Qt::UserRole, 0);
    poten->setForeground(Qt::white);
    poten->setBackground(QBrush(Qt::darkCyan));
    ui->vlist->addItem(poten);
}

//void MainWindow::on_initList_clicked()
//{
//    QString stream = ui->initNumb->toPlainText();
//    int numb = stream.toInt();

//    for(int i = 0; i< numb; i++)
//    {

//    }
//}

void MainWindow::on_viewList_clicked()
{
    ui->clearList->click();

    Node<Student> *proto = startlist->transportHead();
    Student pam = proto->data;
    for(int i = 0; i < startlist->getSize(); i++)
    {
        QListWidgetItem *poten = new QListWidgetItem();
        QString Text = "";

        Text.append(QString::number(pam.getNumb()));
        Text.append("\t");
        Text.append(pam.getName());
        Text.append("\t ");
        Text.append(pam.getGrCode());
        Text.append("\t   ");
        Text.append(QString::number(pam.getScore()));
        Text.append("\t   ");
        Text.append(QString::number(pam.getMoney()));
        Text.append("$ ");
        Text.append("\t   ");

        poten->setText(Text);
        poten->setData(Qt::UserRole, pam.getNumb());
        ui->vlist->addItem(poten);
        if(proto->pNext!= nullptr)
        {
            proto = proto->pNext;
            pam = proto->data;
        }

    }
}

void MainWindow::on_viewResult_clicked()
{

}

void MainWindow::on_pushButton_5_clicked()
{
    resList->clear();
    QListWidgetItem *poten = new QListWidgetItem();
    poten->setText("ID\tName\tGroupCode\t AverageScore\tSufficiency");
    poten->setData(Qt::UserRole, 0);
    poten->setForeground(Qt::white);
    poten->setBackground(QBrush(Qt::darkCyan));
    ui->vlist->addItem(poten);
}

void MainWindow::on_addStudent_clicked()
{
    QString name = ui->textEdit_2->toPlainText();
    QString groupCode = ui->textEdit_3->toPlainText();
    QString score = ui->textEdit_4->toPlainText() ;
    QString smoney = ui->textEdit_5->toPlainText();

    Node<Student>* proto= startlist->transportHead();


    int number, maxNumb;
    int money = smoney.toInt();
    float avScore = score.toFloat();


    if(startlist->getSize() == 0)
    {
        maxNumb = 0;
    }
    else
    {
        Student pam =  proto->data;
        while(proto->pNext != nullptr)
        {
            proto=proto->pNext;
        }
        pam =  proto->data;
        maxNumb = startlist->getSize();
    }

    number = maxNumb +1;
    Student nova(number, name, groupCode, avScore, money);
    startlist->pushBack(nova);
}

void MainWindow::on_delStudent_clicked()
{
    if(viewList->selectedItems().count())
    {
         int numb = viewList->selectedItems()[0]->data(Qt::UserRole).toInt();

        if(!numb)
        {
            return;
        }

        startlist->removeAt(numb);
        ui->viewList->click();
    }
}
