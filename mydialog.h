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
    explicit MyDialog(QWidget *parent = nullptr);
    ~MyDialog();

private:
    QStandardItemModel *tableModel;
    Ui::MyDialog *ui;
};

#endif // MYDIALOG_H
