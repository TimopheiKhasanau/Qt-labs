#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include "myhashtable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void pushToTreeWidget(Node<QString> *node, QTreeWidgetItem *item, int index);
    void initialization();
    ~MainWindow();

private slots:
    void on_pushButton_12_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_16_clicked();

private:
    Ui::MainWindow *ui;
    MyHashTable *base, *less, *more;
};
#endif // MAINWINDOW_H
