#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mydialog.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionMy_Dialog_triggered()
{
    MyDialog* dialog = new MyDialog(this);
    dialog->exec();
}


void MainWindow::on_actionClose_triggered()
{
    this->close();
}


void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "",
        "Text Files *.txt; (*.txt) ;; All Files (*.*)" );
}

