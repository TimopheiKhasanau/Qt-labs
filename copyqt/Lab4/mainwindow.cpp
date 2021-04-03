#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString letters, symbols;
     QString abra = ui->textEdit->toPlainText();
     for(int i = 0; i< abra.length(); i++)
     {
         if(abra[i] == '+')
         {
             symbols+=abra[i];
             continue;
         }
         else  if(abra[i] == '*')
         {
             symbols+=abra[i];
              continue;
         }
         else if(abra[i] == '/')
         {
             symbols+=abra[i];
              continue;
         }
         else
         {
              letters+=abra[i];
         }






     }

     ui->label->setText(letters);
     ui->label_2->setText(symbols);
}
