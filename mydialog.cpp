#include "mydialog.h"
#include "ui_mydialog.h"
#include <QColorDialog>
#include <QComboBox>

MyDialog::MyDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyDialog)
{
    ui->setupUi(this);
    tableModel = new QStandardItemModel(this);
    tableModel->setHorizontalHeaderItem(0, new QStandardItem("X"));
    tableModel->setHorizontalHeaderItem(1, new QStandardItem("Y"));
    tableModel->setHorizontalHeaderItem(2, new QStandardItem("Size"));
    ui->tableView->setModel(tableModel);
    color = Qt::black;
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_addColor_clicked()
{
    color = QColorDialog::getColor(color, this);
    if (!color.isValid())
    {
        color = Qt::black;
    }
}

void MyDialog::on_addRow_clicked()
{
    // Add a new row to the table
    int rowCount = tableModel->rowCount();
    tableModel->insertRow(rowCount);

    // Set default size value in the "Size" column (e.g., 4)
    tableModel->setItem(rowCount, 2, new QStandardItem("4"));
}

void MyDialog::setInitialData(const QColor& initialColor, const QList<QList<double>>& initialData)
{
    color = initialColor;
    tableModel->clear();
    tableModel->setHorizontalHeaderItem(0, new QStandardItem("X"));
    tableModel->setHorizontalHeaderItem(1, new QStandardItem("Y"));
    tableModel->setHorizontalHeaderItem(2, new QStandardItem("Size"));

    for (const QList<double>& rowData : initialData)
    {
        QStandardItem* xItem = new QStandardItem(QString::number(rowData[0]));
        QStandardItem* yItem = new QStandardItem(QString::number(rowData[1]));
        QStandardItem* sizeItem = new QStandardItem(QString::number(rowData[2]));

        QList<QStandardItem*> rowItems = { xItem, yItem, sizeItem };
        tableModel->appendRow(rowItems);
    }
}

QList<QList<double>> MyDialog::tableModelData()
{
    QList<QList<double>> data;
    for (int row = 0; row < tableModel->rowCount(); ++row)
    {
        QList<double> rowData;
        for (int col = 0; col < tableModel->columnCount(); ++col)
        {
            rowData.append(tableModel->item(row, col)->text().toDouble());
        }
        data.append(rowData);
    }
    return data;
}
