#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include<QPainter>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>

#include "view.h"
#include "triangle.h"
#include "pentagon.h"
#include "hexagon.h"
#include "figure.h"
#include "rectangle.h"
#include "ellipse.h"




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

      void adding(Figure *item);

      void advance();
      void on_creation_clicked();
      void on_pushButton_clicked();
      void on_pushButton_2_clicked();
      void on_pushButton_3_clicked();
      void on_pushButton_4_clicked();
      void on_pushButton_5_clicked();
      void on_pushButton_6_clicked();
      void on_pushButton_7_clicked();
      void on_pushButton_8_clicked();
      void on_pushButton_9_clicked();
      void on_pushButton_10_clicked();
      void on_pushButton_12_clicked();
      void on_pushButton_11_clicked();
      void on_pushButton_13_clicked();
      void on_pushButton_14_clicked();

      void on_pushButton_15_clicked();

      void on_pushButton_16_clicked();

private:
    Ui::MainWindow *ui;
     QGraphicsScene *scene;
     view *view;
     QPainter *painter;
     QTimer *animatic;
     Figure *selected_object=nullptr;

     Rectangle *rec;
     Triangle *tria;
     Pentagon *penta;
     Hexagon *hex;
     Ellipse *ell;

     QPointF pos_of_obj,geomcentre;
     QMessageBox *mess;

     int Rot=0, moveX=0, moveY=0, speedx=0, speedy=0;
     bool fig=0, firstmoving=0;
     float mainscale=1.0;
     int createX=1000, createY=500, crASide=200, crBside=200, crTr=200;
     int newAside=0, newBside=0, newTrside=0;
     float perimetr, area;
     // QWidget interface
};


#endif // MAINWINDOW_H
