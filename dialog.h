#ifndef DIALOG_H
#define DIALOG_H



#include <QDialog>
#include "QString"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void messageBox(const QString&);


private:
    Ui::Dialog *ui;


//Processing functions at the click of a button
 private slots:
    void btnBlur_click();
    void btnView_click();
    void btnOpen_click();


};

#endif // DIALOG_H
