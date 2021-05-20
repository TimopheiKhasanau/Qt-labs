#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    base = new MyHashTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushToTreeWidget(Node<QString> *node, QTreeWidgetItem *item = nullptr, int  index = 0)
{
    QString str;
     QTreeWidgetItem *newItem, *dopItem;
    if(item == nullptr) {
        newItem = new QTreeWidgetItem(ui->treeWidget);
        str.append(QString::number(index));
        index++;
        str.append(":");
        newItem->setText(0,str);
        str = "";
        ui->treeWidget->addTopLevelItem(newItem);
    }
        if(node != nullptr) {

            if(item == nullptr) {
                dopItem = new QTreeWidgetItem();
                dopItem->setText(0, QString::number(node->key));
                dopItem->setText(1, node->data);
                newItem->addChild(dopItem);
            }
            else {
                dopItem = new QTreeWidgetItem();
                dopItem->setText(0, QString::number(node->key));
                dopItem->setText(1, node->data);
                item->addChild(dopItem);
            }
            pushToTreeWidget(node->pNext, dopItem, index);
        }
}

void MainWindow::initialization()
{
    base->add(13,"Khasanau Timophei");
     base->add(15,"Redkov Maksim");
      base->add(7,"Lihodievski Aleksei");
       base->add(5,"Zhaburonok Victor");
        base->add(2,"Dmitri Pekutko");
         base->add(6,"Dostoevski Fedor");
          base->add(9,"Putin Vladimir");
           base->add(7,"Levi Akkerman");
            base->add(8,"Dazai Osamu");
             base->add(12,"Shcundich Aleksei");
              base->add(10,"Armin Alert");
               base->add(11,"Asahi Azumana");
                base->add(15,"Jack Spearow");
                 base->add(19,"Robert Pattinson");
                  base->add(25,"Hit Ledger");
                   base->add(23,"Ilon Mask");
                    base->add(36,"Shrek");
                     base->add(32,"Ricardo Milos");
                      base->add(73,"Danila Bereznov");
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->treeWidget->clear();
    for(int i =0; i < 11; i++)
    {
            pushToTreeWidget(base->table[i].transportHead(), nullptr, i);
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    QString name = ui->textEdit_2->toPlainText(), strkey = ui->textEdit_3->toPlainText();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    for(int i =0; i< strkey.length(); i++)
    {
            if( strkey[i] != '0'  && strkey[i] != '1' && strkey[i] != '2' && strkey[i] != '3'
                    && strkey[i] != '4' && strkey[i] != '5' && strkey[i] != '6' && strkey[i] != '7'
                    && strkey[i] != '8' && strkey[i] != '9')
            {
                return;
            }
    }
    int key = strkey.toInt();
    if( name != "")
    {
        base->add(key, name);
        ui->pushButton_12->click();
    }
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->pushButton_15->hide();
    initialization();
    ui->pushButton_12->click();
}

void MainWindow::on_pushButton_14_clicked()
{
    less = new MyHashTable();
    int key = (ui->textEdit_5->toPlainText()).toInt();
    less = base->lessThanKey(key);
    ui->treeWidget->clear();
    for(int i = 0; i < 11; i++)
    {
            pushToTreeWidget(less->table[i].transportHead(), nullptr, i);
    }
    less->~MyHashTable();
}

void MainWindow::on_pushButton_13_clicked()
{
    more = new MyHashTable();
    int key = (ui->textEdit_5->toPlainText()).toInt();
    more = base->moreThanKey(key);
    ui->treeWidget->clear();
    for(int i = 0; i < 11; i++)
    {
            pushToTreeWidget(more->table[i].transportHead(), nullptr, i);
    }
    more->~MyHashTable();
}

void MainWindow::on_pushButton_11_clicked()
{
    QString param;
    int key = (ui->textEdit_5->toPlainText()).toInt();
    ui->textEdit_5->clear();
    Node<QString> *proto = base->find(key);
    if(proto != nullptr)
    {
        param.append(QString::number(proto->key));
        param.append(": ");
        param.append(proto->data);
        ui->textEdit->setText(param);
    }
    else
    {
        ui->textEdit->setText("NO_DATA");
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    int key = (ui->textEdit_5->toPlainText()).toInt();
    ui->textEdit_5->clear();
    base->deleting(key);
    ui->pushButton_12->click();
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->pushButton_15->show();
    for(int i = 0; i < 11; i++)
    {
        base->table[i].clearList();
    }
    ui->pushButton_12->click();
}
