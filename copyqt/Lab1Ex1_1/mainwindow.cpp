#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0,0,800, 600, this);
    ui->graphicsView->setScene(scene);


    animatic= new QTimer(this);
    connect(animatic,SIGNAL(timeout()),scene,SLOT(advance()));
    animatic->start(1000/60);
    QGraphicsRectItem *border = new QGraphicsRectItem(0,0,800,600);
    scene->addItem(border);


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    int pos=scene->sceneRect().width();




    Baloon *bal= new Baloon(pos);


    scene->addItem(bal);







}
