#ifndef DOTWIDGET_H
#define DOTWIDGET_H

#include <QWidget>
#include <QList>
#include <QList>
#include <QList>
#include <QList>
#include <QList>

class DotWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DotWidget(QWidget *parent = nullptr);

    void setDots(const QList<QList<double>>& dots);
    void setColor(QColor& color);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QList<QList<double>> dots;
    QColor color;
};

#endif // DOTWIDGET_H
