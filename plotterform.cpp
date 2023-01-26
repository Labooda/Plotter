#include "plotterform.h"

#include <QPointF>

PlotterForm::PlotterForm(QWidget *parent)
    : QWidget{parent}
{

}

void PlotterForm::setDots(QMap<double, double> *dots)
{
    if (_dots != nullptr)
    {
        _dots->clear();
    }
    _dots = dots;
    update();
}

void PlotterForm::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(Qt::black);
    this->drawAxes(painter);

    if (_dots == nullptr)
    {
        return;
    }

    int length = _dots->size();
    QPointF* points = new QPointF[length] {QPointF(0, 0)};
    QMap<double, double>::Iterator i;
    int j = 0;
    for (i = _dots->begin(); i != _dots->end(); i++, j++)
    {
        points[j].setX(setXtoZero(i.key()));
        points[j].setY(setYtoZero(i.value()));
    }

    painter.drawPolyline(points, length);
    delete[] points;

    painter.setPen(Qt::red);

    for (auto [key, value] : _dots->asKeyValueRange())
    {
        painter.drawPoint(setXtoZero(key), setYtoZero(value));
    }
}

void PlotterForm::drawAxes(QPainter &painter)
{
    qDebug() << this->width() << " " << this->height();
    painter.drawLine(this->width() / 2, 0, this->width() / 2, this->height());
    painter.drawLine(0, this->height() / 2, this->width(), this->height() / 2);
}

double PlotterForm::setXtoZero(double x)
{
    return this->width() / 2 + x;
}

double PlotterForm::setYtoZero(double y)
{
    return this->height() / 2 - y;
}
