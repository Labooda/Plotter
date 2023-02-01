#include "plotterform.h"

#include <QPointF>
#include <QFontMetrics>

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
    painter.fillRect(0, 0, this->width(), this->height(), Qt::white);

    painter.setPen(QPen(Qt::cyan, 3));

    if (_dots == nullptr)
    {
        painter.setPen(QPen(Qt::black, 2));
        drawAxes(painter);
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

    painter.setPen(QPen(Qt::black, 3));
    drawAxes(painter);
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

    setBorders();
    emit updateParams(_params);
    update();
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

    if (wheelStep > 0 && ((_scale * 2) < std::numeric_limits<double>::max()))
    {
        _scale *= 2;
        _xAxeZero = 2 * _xAxeZero - (event->position().x() - this->width() / 2);
        _yAxeZero = 2 * _yAxeZero - (event->position().y() - this->height() / 2);
    }

    if (wheelStep < 0 && ((_scale / 2) > 1))
    {
        _scale /= 2;
        _xAxeZero = _xAxeZero / 2 + 0.5 * (event->position().x() - this->width() / 2);
        _yAxeZero = _yAxeZero / 2 + 0.5 * (event->position().y() - this->height() / 2);
    }

    setBorders();
    emit updateParams(_params);
    update();
}

void PlotterForm::drawAxes(QPainter &painter)
{
    QFont font("Consolas", 10, 100, true);
    QFontMetrics fm(font);
    painter.setFont(font);
    int pixelsW;
    int pixelsH;
    QString number;

    double x = this->width() / 2 + _xAxeZero + _dx;
    double y = this->height() / 2 + _yAxeZero + _dy;

    painter.setPen(QPen(Qt::green, 1));

    double gridCol = 100;
    double gridRow = 100;
    double startGridX = (int)x % (int)gridCol - gridCol;
    double startGridY = (int)y % (int)gridRow - gridRow;

    while (startGridX <= this->width() || startGridY <= this->height())
    {
        if (abs(startGridX - x) <= 1)
        {
            painter.setPen(QPen(Qt::black, 2));
            painter.drawLine(x, 0, x, this->height());
            painter.setPen(QPen(Qt::green, 1));
        }
        else
        {
            painter.drawLine(startGridX, 0, startGridX, this->height());
        }


        number = QString::number(-(x - startGridX) / _scale);
        pixelsW = fm.horizontalAdvance(number);
        pixelsH = fm.height();
        double rectY = (y < 0 ? 5 : y > this->height() - pixelsH - 5 ? this->height() - pixelsH - 5 : y + 5);
        QRect rX(startGridX + 5, rectY, pixelsW, pixelsH);
        painter.fillRect(rX, Qt::white);
        painter.drawText(rX, Qt::AlignCenter, number);

        startGridX += gridCol;

        if (abs(startGridY - y) <= 1)
        {
            painter.setPen(QPen(Qt::black, 2));
            painter.drawLine(0, y, this->width(), y);
            painter.setPen(QPen(Qt::green, 1));
        }
        else
        {
            painter.drawLine(0, startGridY, this->width(), startGridY);
        }


        number = QString::number((y - startGridY) / _scale);
        pixelsW = fm.horizontalAdvance(number);
        pixelsH = fm.height();
        double rectX = (x < 0 ? 5 : x > this->width() - pixelsW - 5 ? this->width() - pixelsW - 5 : x + 5);
        QRect rY(rectX, startGridY + 5, pixelsW, pixelsH);
        painter.fillRect(rY, Qt::white);
        painter.drawText(rY, Qt::AlignCenter, number);

        startGridY += gridRow;
    }
}

double PlotterForm::setXtoZero(double x)
{
    return this->width() / 2 + _xAxeZero + _dx + x * _scale;
}

double PlotterForm::setYtoZero(double y)
{
    return this->height() / 2 + _yAxeZero + _dy - y * _scale;
}

void PlotterForm::setBorders()
{
    double left = (-this->width() / 2 - _xAxeZero - _dx)/ _scale;
    double right = (this->width() / 2 - _xAxeZero - _dx)/ _scale;
    double top = (this->height() / 2 + _yAxeZero + _dy)/ _scale;
    double bottom = (-this->height() / 2 + _yAxeZero + _dy)/ _scale;

    _params->setLeftBord(left);
    _params->setRightBord(right);
    _params->setTopBord(top);
    _params->setBottomBord(bottom);
}

void PlotterForm::getBorders(double leftBord, double rightBord)
{
    emit sendBorders(leftBord, rightBord);
}

