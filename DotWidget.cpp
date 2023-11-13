#include "DotWidget.h"
#include <QPainter>
#include <QPen>

DotWidget::DotWidget(QWidget *parent) : QWidget(parent) {
    this->color = Qt::black;
}

void DotWidget::setDots(const QList<QList<double>>& dots)
{
    this->dots = dots;
    update(); // Trigger a repaint
}

void DotWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    for (const QList<double>& dot : dots)
    {
        double x = dot[0];
        double y = dot[1];
        double size = dot[2];

        // Calculate the rectangle where the ellipse will be drawn
        QRectF rect(x - size / 2, y - size / 2, size, size);

        // Set the color for the ellipse
        painter.setBrush(QBrush(color));
        painter.setPen(Qt::NoPen); // No outline

        // Draw the ellipse at the specified position
        painter.drawEllipse(rect);
    }
}

void DotWidget::setColor(QColor& color)
{
    this->color = color;
}
