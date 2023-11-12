#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include <QStyledItemDelegate>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = nullptr);
    ~MyDialog();
    QList<QList<double>> tableModelData();
    void setInitialData(const QColor& color, const QList<QList<double>>& rowDataList);
    QColor color;

private slots:
    void on_addColor_clicked();
    void on_addRow_clicked();

private:
    Ui::MyDialog *ui;
    QStandardItemModel *tableModel;

    // Add a function to create a combo box delegate for the "Size" column
    void createSizeComboBoxDelegate();
};

#endif // MYDIALOG_H
