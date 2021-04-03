#ifndef FUNCTION_H
#define FUNCTION_H

#include <QMainWindow>
#include "list.h"
#include"candidate.h"


namespace Ui {
class Function;
}

class Function : public QMainWindow
{
    Q_OBJECT

public:
    explicit Function(QWidget *parent = nullptr);
    ~Function();


void ListOfObj(List *list, bool editing = false, Candidate* _cand = nullptr);
private slots:
    void on_Accept_clicked();

private:
    Ui::Function *ui;
    List *list;
    Candidate *pot_cand = nullptr;
    bool editing = false;
};

#endif // FUNCTION_H
