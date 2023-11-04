#include "mydialog.h"
#include "ui_mydialog.h"
#include <QColorDialog>

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
    tableModel = new QStandardItemModel(this);
    ui->tableView->setModel(tableModel);
    tableModel->setHorizontalHeaderItem(0, new QStandardItem("X"));
    tableModel->setHorizontalHeaderItem(1, new QStandardItem("Y"));
    tableModel->setHorizontalHeaderItem(2, new QStandardItem("Size"));
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_addColor_clicked()
{
    color = QColorDialog::getColor( Qt::black, this );
    if(!color.isValid( ) )
    {
        color = Qt::black;
    }
}

