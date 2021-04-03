#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0,0,1020, 800, this);
    ui->graphicsView->setScene(scene);
    listset = new List();

    viewList = ui->prets;
    resList = ui->result;

    ui->clearlist->click();
    ui->keyword->hide();
    ui->clearlist_2->hide();
    ui->viewresult->hide();
    ui->clearlist->hide();
    ui->viewlist->hide();
    ui->editcand->hide();
    ui->delcand->hide();
    ui->addcand->hide();
    ui->sortcand->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_clearlist_clicked()
{
        viewList->clear();
        QListWidgetItem *poten = new QListWidgetItem();
        poten->setText("ID\tName\t\tSex\t Age\tHeight\tWeight\tMinA\tMaxA\t"
"MinH\tMaxH\tMinW\tMaxW");
        poten->setData(Qt::UserRole, 0);
        poten->setForeground(Qt::white);
        poten->setBackground(QBrush(Qt::darkCyan));
        ui->prets->addItem(poten);
}

void MainWindow::on_viewlist_clicked()
{
    ui->clearlist->click();
    Candidate ** cands = listset->transport();
    for(int i = 0; i < listset->getSize(); i++)
    {
        QListWidgetItem *poten = new QListWidgetItem();
        QString Text = "";

        //ID Full name Sex Age Height Weight P.MinAge P.MaxAge P.MinHeight P.MaxHeight P.MinWeight P.MaxWeight

        Text.append(QString::number(cands[i]->getNumb()));
        Text.append(")\t");
        Text.append(cands[i]->getName());
        Text.append("\t ");
        Text.append("(");
        Text.append(cands[i]->getSex());
         Text.append(")");
        Text.append("\t   ");
        Text.append(QString::number(cands[i]->getAge()));
        Text.append("\t   ");
        Text.append(QString::number(cands[i]->getHeight()));
        Text.append("\t   ");
        Text.append(QString::number(cands[i]->getWeight()));
        Text.append("\t   ");
        Text.append(QString::number(cands[i]->getMinAge()));
        Text.append("\t   ");
        Text.append(QString::number(cands[i]->getMaxAge()));
        Text.append("\t   ");
        Text.append(QString::number(cands[i]->getMinHeight()));
        Text.append("\t   ");
        Text.append(QString::number(cands[i]->getMaxHeight()));
        Text.append("\t   ");
        Text.append(QString::number(cands[i]->getMinWeight()));
        Text.append("\t   ");
        Text.append(QString::number(cands[i]->getMaxWeight()));
        Text.append("\t   ");

        poten->setText(Text);
        poten->setData(Qt::UserRole, cands[i]->getNumb());
        ui->prets->addItem(poten);
    }
}

void MainWindow::on_openfile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Choose txt-type file ", "~");
      if(fileName.count())
      {
           if(!fileName.contains(".txt"))
           {
                       QMessageBox::warning(this, "Wrong file type", "File must have .txt extension.");
                       return;
            }
                listset->FileNameForList(fileName);
                listset->initialize();

               ui->clearlist_2->show();
               ui->keyword->show();
               ui->viewresult->show();
               ui->clearlist-> show();
               ui->viewlist-> show();
               ui->editcand-> show();
               ui->delcand-> show();
               ui->addcand-> show();
               ui->sortcand-> show();

               ui->viewlist-> click();
       }
}

void MainWindow::on_addcand_clicked()
{
    Function* funcWindow = new Function;
    funcWindow->ListOfObj(listset);
    funcWindow->show();
}

void MainWindow::on_editcand_clicked()
{

    if(viewList->selectedItems().count())
    {
        int  numb = viewList->selectedItems()[0]->data(Qt::UserRole).toInt();

        if(!numb)
        {
            return;
        }
        Candidate* _cand = listset->send(numb);
        Function* funcWindow = new Function;
        funcWindow->ListOfObj(listset, true, _cand);
        funcWindow -> show();
    }
}

void MainWindow::on_delcand_clicked()
{
    if(viewList->selectedItems().count())
    {
         int numb = viewList->selectedItems()[0]->data(Qt::UserRole).toInt();

        if(!numb)
        {
            return;
        }

        listset->pop(numb);
        ui->viewlist->click();
    }
}

void MainWindow::on_sortcand_clicked()
{
    if(viewList->selectedItems().count())
    {
         int numb = viewList->selectedItems()[0]->data(Qt::UserRole).toInt();

        if(!numb)
        {
            return;
        }

         partners = listset->result(numb);
        ui->viewresult->click();
    }
}

void MainWindow::on_clearlist_2_clicked()
{
    resList->clear();
    QListWidgetItem *poten = new QListWidgetItem();
    poten->setText("ID\tName\t\tSex\t Age\tHeight\tWeight\tMinA\tMaxA\t"
"MinH\tMaxH\tMinW\tMaxW");
    poten->setData(Qt::UserRole, 0);
    poten->setForeground(Qt::white);
    poten->setBackground(QBrush(Qt::darkCyan));
    ui->result->addItem(poten);
}

void MainWindow::on_viewresult_clicked()
{
    ui->clearlist_2->click();
    for(int i = 0; i < partners.length(); i++)
    {
        QListWidgetItem *poten = new QListWidgetItem();
        QString Text = "";

        //ID Full name Sex Age Height Weight P.MinAge P.MaxAge P.MinHeight P.MaxHeight P.MinWeight P.MaxWeight

        Text.append(QString::number(partners[i]->getNumb()));
        Text.append(")\t");
        Text.append(partners[i]->getName());
        Text.append("\t ");
        Text.append("(");
        Text.append(partners[i]->getSex());
         Text.append(")");
        Text.append("\t   ");
        Text.append(QString::number(partners[i]->getAge()));
        Text.append("\t   ");
        Text.append(QString::number(partners[i]->getHeight()));
        Text.append("\t   ");
        Text.append(QString::number(partners[i]->getWeight()));
        Text.append("\t   ");
        Text.append(QString::number(partners[i]->getMinAge()));
        Text.append("\t   ");
        Text.append(QString::number(partners[i]->getMaxAge()));
        Text.append("\t   ");
        Text.append(QString::number(partners[i]->getMinHeight()));
        Text.append("\t   ");
        Text.append(QString::number(partners[i]->getMaxHeight()));
        Text.append("\t   ");
        Text.append(QString::number(partners[i]->getMinWeight()));
        Text.append("\t   ");
        Text.append(QString::number(partners[i]->getMaxWeight()));
        Text.append("\t   ");

        poten->setText(Text);
        poten->setData(Qt::UserRole, partners[i]->getNumb());
        ui->result->addItem(poten);
    }
}




void MainWindow::on_textEdit_textChanged()
{
    ui->keyword->click();
}

void MainWindow::on_keyword_clicked()
{
      QString keyName= ui->textEdit->toPlainText();
      QStringList nameList;
      QStringList nameListRight;

      if( keyName.count() )
      {
          nameList = keyName.split(' ');
          for(int i = 0; i < nameList.length(); i++)
          {
              if(nameList[i].count())
              {
                  nameListRight.append(nameList[i]);
              }
          }

          QList <Candidate*> findedList = listset->findCand(nameListRight);
          ui->clearlist->click();
          if( !findedList.length() )
          {
              viewList->addItem("\tNo results");
              return;
          }

          for(int i = 0; i < findedList.length(); i++) {
              QListWidgetItem *item = new QListWidgetItem();
              QString Text = "";

              Text.append(QString::number(findedList[i]->getNumb()));
              Text.append(")\t");
              Text.append(findedList[i]->getName());
              Text.append("\t ");
              Text.append("(");
              Text.append(findedList[i]->getSex());
               Text.append(")");
              Text.append("\t   ");
              Text.append(QString::number(findedList[i]->getAge()));
              Text.append("\t   ");
              Text.append(QString::number(findedList[i]->getHeight()));
              Text.append("\t   ");
              Text.append(QString::number(findedList[i]->getWeight()));
              Text.append("\t   ");
              Text.append(QString::number(findedList[i]->getMinAge()));
              Text.append("\t   ");
              Text.append(QString::number(findedList[i]->getMaxAge()));
              Text.append("\t   ");
              Text.append(QString::number(findedList[i]->getMinHeight()));
              Text.append("\t   ");
              Text.append(QString::number(findedList[i]->getMaxHeight()));
              Text.append("\t   ");
              Text.append(QString::number(findedList[i]->getMinWeight()));
              Text.append("\t   ");
              Text.append(QString::number(findedList[i]->getMaxWeight()));
              Text.append("\t   ");

              item->setText(Text);
              item->setData(Qt::UserRole, findedList[i]->getNumb());
              viewList->addItem(item);
              //viewList->addItem(item);
          }
      }
      else {
          ui->viewlist->click();
          //viewList->addItem("\tNo results");
      }
}
