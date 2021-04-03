#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "list.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include<QStringList>
#include <QListWidget>
#include <QListWidgetItem>
#include "candidate.h"
#include <QFileDialog>
#include <QMessageBox>
#include<function.h>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_clearlist_clicked();

    void on_viewlist_clicked();

    void on_openfile_clicked();

    void on_addcand_clicked();

    void on_editcand_clicked();

    void on_delcand_clicked();

    void on_sortcand_clicked();

    void on_clearlist_2_clicked();

    void on_viewresult_clicked();

 //   void on_pushButton_clicked();



    void on_textEdit_textChanged();

    void on_keyword_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QListWidget *viewList, *resList;
     QList<Candidate*> partners;
    List *listset ;

};
#endif // MAINWINDOW_H
