#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mydialog.h"
#include <QFileDialog>
#include <QPainter>
#include <QSvgGenerator>

#define BORDER 20
#define SVG_FILE "result.svg"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rowDataList.clear(); // Clear the list
    dotWidget = new DotWidget(this);
    dotWidget->setGeometry(BORDER, BORDER, width() - BORDER * 2, height() - BORDER * 2);
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
    // Ask the user for a file name and location
    QString fileName = QFileDialog::getSaveFileName(this, "Save As", "", "HTML File (*.html);;All Files (*)");

    if (fileName.isEmpty()) {
        return; // The user canceled the dialog
    }

    QFileInfo fileInfo(fileName);
    QString htmlFileName = fileInfo.path() + "/" + fileInfo.baseName() + ".html";
    QString svgFilename = fileInfo.path() + "/" + SVG_FILE;

    // Save the SVG image
    saveSvgImage(svgFilename);

    // Save the HTML file
    saveHtmlFile(htmlFileName);
}

void MainWindow::saveSvgImage(const QString &fileName)
{
    if (dotWidget) {
        QSvgGenerator generator;
        generator.setFileName(fileName);
        generator.setSize(QSize(dotWidget->width(), dotWidget->height()));
        generator.setViewBox(QRect(0, 0, dotWidget->width(), dotWidget->height()));

        QPainter painter(&generator);
        dotWidget->render(&painter);
    }
}

void MainWindow::saveHtmlFile(const QString &fileName)
{

    QFile htmlFile(fileName);
    if (htmlFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&htmlFile);
        out << "<html>\n";
        out << "<body>\n";
        out << "<center>\n";
        out << "<H1>Результат малювання</H1>\n";
        out << "<img src=\"" << SVG_FILE << "\" border=0>\n";
        out << "</center>\n";
        out << "</body>\n";
        out << "</html>\n";
        htmlFile.close();
    }
}

void MainWindow::drawDots(QList<QList<double>> dots)
{
    if (dotWidget) {
        dotWidget->setColor(color);
        dotWidget->setDots(dots);
    }
}


