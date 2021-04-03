#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view=ui->view;
    scene = new QGraphicsScene(0,0,1600, 1200, this);
    view->setScene(scene);

    animatic = new QTimer(this);
    animatic->start(1000/60);
    connect(animatic,SIGNAL(timeout()),this, SLOT(advance()));
    painter= new QPainter;

    mess = new QMessageBox;


}

MainWindow::~MainWindow()
{
    delete scene;
    delete selected_object;
    delete ui;
}


void MainWindow::advance()
{
    Figure *selected_object = view->getSelFig();
    int rotation=0;
    double scale=1.0;
    speedx=0, speedy=0;

    if(fig==1)
    {
        rotation = selected_object->rotation();

        scale=selected_object->scale();
        selected_object->setTransformOriginPoint(moveX,moveY);
    }

    if(Rot>rotation)
    {
        selected_object->setRotation(rotation+1);
    }
    else if(Rot<rotation)
    {
         selected_object->setRotation(rotation-1);
    }

    if( mainscale > scale+0.009 )
    {
        selected_object->setScale(scale+0.009);
    }
    else if( mainscale < scale-0.009 )
    {
         selected_object->setScale(scale-0.009);
    }

//    if( moveX - pos_of_obj.x()>0 )
//    {
//        speedx=1;

//    }
//    else if( moveX - pos_of_obj.x()<0 )
//    {
//         speedx=-1;

//    }

//    if( moveY > pos_of_obj.y() )
//    {
//        speedy=1;

//    }
//    else if( moveY < pos_of_obj.y() )
//    {
//         speedy=-1;

//    }


//    if(fig==1)
//    {
//      QPoint position = view->mapFromParent(selected_object->getCenter());
//      pos_of_obj=position;
//      selected_object->moveBy(speedx,speedy);



//    }

}

void MainWindow::on_pushButton_clicked()
{
   rec = new Rectangle(-crASide/2,-crBside/2,crASide,crBside);
   rec->setPos(1000,500);

   adding(rec);
   selected_object=rec;
}

void MainWindow::on_pushButton_7_clicked()
{
    tria=new Triangle(-crTr/2,-crTr/2,crTr);
    tria->setPos(1000,500);

    adding(tria);
    selected_object=tria;

}

void MainWindow::on_pushButton_11_clicked()
{
    penta=new Pentagon(-crTr/2,-crTr/2,crTr);
    penta->setPos(1000,500);

    adding(penta);
    selected_object=penta;
}

void MainWindow::on_pushButton_13_clicked()
{
    hex =new Hexagon(-crTr/2,-crTr/2,crTr);
    hex->setPos(1000,500);

    adding(hex);
    selected_object=hex;
}

void MainWindow::on_pushButton_9_clicked()
{
    ell= new Ellipse(-crASide/2,-crBside/2,crASide,crBside);
    ell->setPos(1000,500);

    adding(ell);
    selected_object=ell;
}



void MainWindow::on_pushButton_2_clicked()
{
    Rot = ui->spinBox->value();
}


void MainWindow::on_pushButton_3_clicked()
{
    exit(0);
}

void MainWindow::adding(Figure *item)
{
    fig=1;
    mainscale=1.0;
    moveX=0;
    moveY=0;
    Rot=0;
    scene->addItem(item);
    view->addFigure(item);
}

void MainWindow::on_pushButton_4_clicked()
{
    selected_object->setPos(ui->xspinbox->value()+150,ui->yspinbox->value()+200);

    ui->xspinbox->setValue(0);
    ui->yspinbox->setValue(0);
}

void MainWindow::on_pushButton_5_clicked()
{
    mainscale=ui->doubleSpinBox->value();
    ui->doubleSpinBox->setValue(1);
}

void MainWindow::on_pushButton_6_clicked()
{
    newAside=ui->recchA->value();
    newBside=ui->recchB->value();

    rec->setAside(newAside);
    rec->setBside(newBside);

    ui->recchA->setValue(100);
    ui->recchB->setValue(100);
}

void MainWindow::on_pushButton_8_clicked()
{
    perimetr=mainscale*(selected_object->perimetr());
    area=mainscale*(selected_object->square());

    mess->setStyleSheet("QLabel{min-width: 700px;}");
    mess->information(this, "Perimetr: ", QString::number(perimetr));
    mess->information(this, "Area: ", QString::number(area));
}

void MainWindow::on_creation_clicked()
{
    createX=ui->xspinbox->value();
    createY=ui->yspinbox->value();

    crASide=ui->changeA->value();
    crBside=ui->changeB->value();

    crTr=ui->recSide->value();
}

void MainWindow::on_pushButton_10_clicked()
{
    newAside=ui->ellchA->value();
    newBside=ui->ellchB->value();

    ell->setAdiam(newAside);
    ell->setBdiam(newBside);

    ui->ellchA->setValue(100);
    ui->ellchB->setValue(100);
}

void MainWindow::on_pushButton_12_clicked()
{
    moveX=ui->spinBox_2->value();
    moveY=ui->spinBox_2->value();
}


void MainWindow::on_pushButton_14_clicked()
{
    newTrside=ui->trchA->value();

    tria->setAcat(newTrside);

    ui->trchA->setValue(100);

}

void MainWindow::on_pushButton_15_clicked()
{
    newTrside=ui->trchA->value();

    hex->setAcat(newTrside);

    ui->trchA->setValue(100);
}

void MainWindow::on_pushButton_16_clicked()
{
    newTrside=ui->trchA->value();

    penta->setAcat(newTrside);

    ui->trchA->setValue(100);
}
