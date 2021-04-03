#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QGraphicsScene>
#include <QListWidget>
#include <QMainWindow>
#include "student.h"
#include "list.h"
#include "list.cpp"
#include"node.h"

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
    void on_clearList_clicked();

   // void on_initList_clicked();

    void on_viewList_clicked();

    void on_viewResult_clicked();

    void on_pushButton_5_clicked();

    void on_addStudent_clicked();

    void on_delStudent_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QListWidget *viewList, *resList;
    List<Student>* startlist;
};
#endif // MAINWINDOW_H
