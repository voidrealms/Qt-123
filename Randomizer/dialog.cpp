#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

int Dialog::getNumber(int &baseNumber)
{
    int high = 100;
    int low = 1;
    int random = qrand() % ((high +1) - low) + low;

    qDebug() << "Randomizing " << baseNumber << " = " << random;
    baseNumber = random;

    return 0;
}

void Dialog::on_pushButton_clicked()
{
    QList<int> list;

    //Add 0 to 99
    for(int i = 0; i < 100; i++)
    {
        list.append(i);
    }

    qDebug() << "Started!";

    //Block until all have completed
    QtConcurrent::blockingMap(list,&Dialog::getNumber);

    qDebug() << "Finished!";

    ui->listWidget->clear();

    //update the ui
    for(int i = 0; i < list.count(); i++)
    {
        ui->listWidget->addItem(QString::number(i) + " = " + QString::number(list.at(i)));
    }

}
