#include "plotterform.h"

#include <QPointF>

PlotterForm::PlotterForm(FuncParams *params, QWidget *parent)
    : QFrame{parent},
      _params(params)
{
    this->setStyleSheet("border: 3px solid black;");
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
    painter.setPen(QPen(Qt::black, 2));
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
    }

    painter.drawPolyline(points, length);

    delete[] points;

    painter.setPen(QPen(Qt::red, 2));

    for (auto [key, value] : _dots->asKeyValueRange())
    {
        painter.drawPoint(setXtoZero(key), setYtoZero(value));
    }
}

void PlotterForm::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        _dragStartPosition = event->pos();
    }
}

void PlotterForm::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
    {
        return;
    }

    QPoint currentPos = event->pos();
    _dx = currentPos.x() - _dragStartPosition.x();
    _dy = currentPos.y() - _dragStartPosition.y();

    double left = (-this->width() / 2 - _xAxeZero - _dx)/ _scale;
    double right = (this->width() / 2 - _xAxeZero - _dx)/ _scale;

    _params->setLeftBord(left);
    _params->setRightBord(right);
    emit updateParams(_params);
    update();
    qDebug() << "move::ended" << left << right;
}

void PlotterForm::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton)
    {
        return;
    }

    _xAxeZero += _dx;
    _yAxeZero += _dy;
    _dx = 0;
    _dy = 0;
}

void PlotterForm::wheelEvent(QWheelEvent *event)
{
    int wheelStep = event->angleDelta().y();

    if (wheelStep >= 120)
    {
        _scale *= 2;
    }
    else if (wheelStep <= 120)
    {
        _scale /= 2;
    }

    double left = (-this->width() / 2 - _xAxeZero - _dx)/ _scale;
    double right = (this->width() / 2 - _xAxeZero - _dx)/ _scale;

    _params->setLeftBord(left);
    _params->setRightBord(right);
    emit updateParams(_params);
    update();
}

void PlotterForm::drawAxes(QPainter &painter)
{
    double x = this->width() / 2 + _xAxeZero + _dx;
    double y = this->height() / 2 + _yAxeZero + _dy;
    painter.save();
    painter.setPen(QPen(Qt::green, 1));

    double gridCol = _scale/*this->width() / 10*/;
    double gridRow = _scale/*this->height() / 10*/;
    double startGridX = (int)x % (int)gridCol;
    double startGridY = (int)y % (int)gridRow;

    while (startGridX <= this->width() || startGridY <= this->height())
    {
        painter.drawLine(startGridX, 0, startGridX, this->height());
        painter.drawLine(0, startGridY, this->width(), startGridY);
        startGridX += gridCol;
        startGridY += gridRow;
    }
    painter.restore();
    painter.drawLine(x, 0, x, this->height());
    painter.drawLine(0, y, this->width(), y);
}

double PlotterForm::setXtoZero(double x)
{
    return this->width() / 2 + _xAxeZero + _dx + x * _scale;
}

double PlotterForm::setYtoZero(double y)
{
    return this->height() / 2 + _yAxeZero + _dy - y * _scale;
}

void PlotterForm::getBorders(double leftBord, double rightBord)
{
    emit sendBorders(leftBord, rightBord);
}

