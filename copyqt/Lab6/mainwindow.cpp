#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setVerticalHeaderItem(0,new QTableWidgetItem("Key"));
    ui->tableWidget->setVerticalHeaderItem(1,new QTableWidgetItem("Full Name"));
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget-> setRowCount ( rows );
    ui->tableWidget->setColumnWidth(0, 150);
    ui->tableWidget->verticalHeader()->hide();
        QStringList name_table;
            name_table << "Key" << "Full Name";
            ui->tableWidget->setHorizontalHeaderLabels(name_table);
            ui->treeWidget->setColumnCount(2);
            ui->treeWidget->setHeaderLabels(name_table);



 bam = new MyTree<QString>();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::transfer()
{
    ui->tableWidget->clear();
    rows=11;
   ui->tableWidget->setItem(0,0, new QTableWidgetItem("13"));
   ui->tableWidget->setItem(0,1, new QTableWidgetItem("Khasanov Timophei"));
   ui->tableWidget->setItem(1,0, new QTableWidgetItem("15"));
   ui->tableWidget->setItem(1,1, new QTableWidgetItem("Redkov Maksim" ));
   ui->tableWidget->setItem(2,0, new QTableWidgetItem("7"));
   ui->tableWidget->setItem(2,1, new QTableWidgetItem("Lihodievski Aleksei"));
   ui->tableWidget->setItem(3,0, new QTableWidgetItem("5"));
   ui->tableWidget->setItem(3,1, new QTableWidgetItem("Zhaburonok Victor"));
   ui->tableWidget->setItem(4,0, new QTableWidgetItem("2"));
   ui->tableWidget->setItem(4,1, new QTableWidgetItem("Dmitri Pekutko"));
   ui->tableWidget->setItem(5,0, new QTableWidgetItem("6"));
   ui->tableWidget->setItem(5,1, new QTableWidgetItem("Dostoevski Fedor"));
   ui->tableWidget->setItem(6,0, new QTableWidgetItem("9"));
   ui->tableWidget->setItem(6,1, new QTableWidgetItem("Putin Vladimir"));
   ui->tableWidget->setItem(7,0, new QTableWidgetItem("8"));
   ui->tableWidget->setItem(7,1, new QTableWidgetItem("Dazai Osamu"));
   ui->tableWidget->setItem(8,0, new QTableWidgetItem("11"));
   ui->tableWidget->setItem(8,1, new QTableWidgetItem("No Fantasia"));
   ui->tableWidget->setItem(9,0, new QTableWidgetItem("10"));
   ui->tableWidget->setItem(9,1, new QTableWidgetItem("Miss Margarita"));
   ui->tableWidget->setItem(10,0, new QTableWidgetItem("12"));
   ui->tableWidget->setItem(10,1, new QTableWidgetItem("Shcundich Aleksei"));
   for(int i =0; i< rows; i++)
   {
       for( int j =0; j<2; j++)
       {
           ui->tableWidget->item(i,j)->setTextAlignment(Qt::AlignCenter);
       }
   }
}


void MainWindow::pushToTreeWidget(Node<QString> *node, QTreeWidgetItem *item = nullptr)
{
    if(node != nullptr) {
        QTreeWidgetItem *newItem;
        if(item == nullptr) {
            newItem = new QTreeWidgetItem(ui->treeWidget);
            newItem->setText(0, QString::number(node->key));
            newItem->setText(1, node->data);
            ui->treeWidget->addTopLevelItem(newItem);
        }
        else {
            newItem = new QTreeWidgetItem();
            newItem->setText(0, QString::number(node->key));
            newItem->setText(1, node->data);
            item->addChild(newItem);
        }
        pushToTreeWidget(node->pLeft, newItem);
        pushToTreeWidget(node->pRight, newItem);
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    transfer();
}

void MainWindow::on_pushButton_3_clicked()
{
    int key =0;
    QString name = "";
    if(bam->shareApex() == nullptr )
    {
        for(int i =0; i < rows; i++)
        {
            key = (ui->tableWidget->item(i, 0)->text()).toInt();
            name = ui->tableWidget->item(i, 1)->text();
            bam->add(key, name);
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->treeWidget->clear();
    pushToTreeWidget(bam->shareApex());

}

void MainWindow::on_pushButton_7_clicked()
{
    ui->textEdit->clear();
    QList<Node<QString> *> param;
    QString str;
    if(bam->shareApex() != nullptr)
    {
        param = bam->postTravList();
    }

     int i =0;
    while(i < param.size())
    {
        str.append(QString::number(param[i]->key));
        str.append(": ");
        str.append(param[i]->data);
        ui->textEdit->append(str);
        i++;
        str = "";
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->textEdit->clear();
    QList<Node<QString> *> param;
    QString str;
    if(bam->shareApex() != nullptr)
    {
        param = bam->preTravList();
    }

     int i =0;
    while(i < param.size())
    {
        str.append(QString::number(param[i]->key));
        str.append(": ");
        str.append(param[i]->data);
        ui->textEdit->append(str);
        i++;
        str = "";
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->textEdit->clear();
    QList<Node<QString> *> param;
    QString str;
    if(bam->shareApex() != nullptr)
    {
        param = bam->inTravList();
    }

     int i =0;
    while(i < param.size())
    {
        str.append(QString::number(param[i]->key));
        str.append(": ");
        str.append(param[i]->data);
        ui->textEdit->append(str);
        i++;
        str = "";
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(bam->shareApex()!= nullptr)
    {
        bam->Balancing(nullptr, bam->shareApex());
        ui->pushButton->click();
    }

}

void MainWindow::on_pushButton_10_clicked()
{
    if(bam->shareApex() != nullptr)
    {
        QString prove = "";
       Node<QString> *average = bam->findAverage();
       if(average != nullptr)
       {
           prove.append(QString::number(average->key));
           prove.append(": ");
           prove.append(average->data);
           ui->textEdit->clear();
           ui->textEdit->setText(prove);
       }
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    QString prover= ui->textEdit_5->toPlainText();
    ui->textEdit_5->clear();
    int poc =0;
    for(int i =0; i< prover.length(); i++)
    {
            if( prover[i] != '0'  && prover[i] != '1' && prover[i] != '2' && prover[i] != '3'
                    && prover[i] != '4' && prover[i] != '5' && prover[i] != '6' && prover[i] != '7'
                    && prover[i] != '8' && prover[i] != '9')
            {
                return;
            }
    }
    int key = prover.toInt();
    if(key != 0)
    {
        for(int i=0; i<ui->tableWidget->rowCount(); i++)
        {
            if(ui->tableWidget->item(i,0) != 0 && prover == ui->tableWidget->item(i,0)->text())
            {
                poc = 1;
                ui->tableWidget->removeRow(i);
                rows--;
                ui->tableWidget->setRowCount(rows);
                break;
            }
        }
        if(poc == 0)
        {
            return;
        }
        bam->delSubApex(key);
        ui->pushButton->click();
    }


}

void MainWindow::on_pushButton_11_clicked()
{
    QString prover= ui->textEdit_5->toPlainText(), prove = "";
    ui->textEdit_5->clear();
    for(int i =0; i< prover.length(); i++)
    {
            if(  prover[i] != '0'  && prover[i] != '1' && prover[i] != '2' && prover[i] != '3'
                    && prover[i] != '4' && prover[i] != '5' && prover[i] != '6' && prover[i] != '7'
                    && prover[i] != '8' && prover[i] != '9')
            {
                return;
            }
    }
    int key = prover.toInt();

   Node<QString> *average = bam->findSubApex(key);
   if(average != nullptr)
   {
       prove.append(QString::number(average->key));
       prove.append(": ");
       prove.append(average->data);
       ui->textEdit->clear();
       ui->textEdit->setText(prove);
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
    if(key != 0 && name != "")
    {
        rows++;
        ui->tableWidget->setRowCount(rows);
        ui->tableWidget->setItem(rows-1,0, new QTableWidgetItem(strkey));
        ui->tableWidget->setItem(rows-1,1, new QTableWidgetItem(name));
        ui->tableWidget->item(rows-1,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(rows-1,1)->setTextAlignment(Qt::AlignCenter);
        bam->add(key, name);
        ui->pushButton->click();
    }

}

void MainWindow::on_pushButton_12_clicked()
{
    bam->delSubTree(bam->shareApex());
    ui->textEdit->clear();
    ui->tableWidget->clear();
    ui->treeWidget->clear();
    rows = 0;
}
