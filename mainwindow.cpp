#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mydialog.h"
#include <QFileDialog>
#include <QPainter>

#define BOREDER 20

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rowDataList.clear(); // Clear the list
    dotWidget = new DotWidget(this);
    dotWidget->setGeometry(BOREDER, BOREDER, width() - BOREDER, height() - BOREDER); // Set the size to cover the whole main window
    dotWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionMy_Dialog_triggered()
{
    MyDialog* dialog = new MyDialog(this);
    dialog->setInitialData(color, rowDataList);
    if (dialog->exec() == QDialog::Accepted)
    {
        color = dialog->color;
        rowDataList = dialog->tableModelData();
        drawDots(rowDataList);
    }
}

void MainWindow::on_actionClose_triggered()
{
    this->close();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files *.txt; (*.txt) ;; All Files (*.*)");
    // Save rowDataList to the file
}

void MainWindow::drawDots(QList<QList<double>> dots)
{
    if (dotWidget) {
        dotWidget->setColor(color);
        dotWidget->setDots(dots);
    }
}


