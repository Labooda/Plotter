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
    qDebug() << "setDots:Called";
}

void PlotterForm::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1));
    this->drawAxes(painter);
    painter.setPen(QPen(Qt::cyan, 3));

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
        //qDebug() << "QPoints: " << points[j].x() - this->width() / 2 << " " << this->height() / 2 - points[j].y();
    }

    painter.drawPolyline(points, length);

    delete[] points;

    painter.setPen(QPen(Qt::red, 1));

    for (auto [key, value] : _dots->asKeyValueRange())
    {
        painter.drawPoint(setXtoZero(key), setYtoZero(value));
    }

    //qDebug() << "paintEvent:Called";
}

void PlotterForm::drawAxes(QPainter &painter)
{
    //qDebug() << this->width() << " " << this->height();
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
