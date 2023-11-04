#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    QStandardItemModel *tableModel;
    QColor color;
    explicit MyDialog(QWidget *parent = nullptr);
    ~MyDialog();

private slots:
    void on_addColor_clicked();

private:
    Ui::MyDialog *ui;
};

#endif // MYDIALOG_H
