#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QStandardItem>
#include "DotWidget.h"

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
    void on_actionMy_Dialog_triggered();
    void on_actionClose_triggered();
    void on_actionSave_As_triggered();

private:
    Ui::MainWindow *ui;
    QColor color;
    DotWidget *dotWidget; // Add this member variable
    QList<QList<double>> rowDataList;
    void drawDots(QList<QList<double>> dots);
};
#endif // MAINWINDOW_H
