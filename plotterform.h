#ifndef PLOTTERFORM_H
#define PLOTTERFORM_H

#include "funcparams.h"

#include <QFrame>
#include "plotterform.h"

#include <QPainter>
#include <QPair>
#include <QMouseEvent>

class PlotterForm : public QFrame
{
    Q_OBJECT
public:
    explicit PlotterForm(FuncParams *params, QWidget *parent = nullptr);
    void getBorders(double leftBord, double rightBord);

private:
    FuncParams *_params = nullptr;
    QPainter* _painter = nullptr;
    QMap<double, double> *_dots = nullptr;
    QPoint _dragStartPosition;
    QFont _font;
    double _dx = 0;
    double _dy = 0;
    double _xAxeZero = 0;
    double _yAxeZero = 0;
    double _scale = 100;

    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

    void drawAxes(QPainter &painter);

    double setXtoZero(double x);
    double setYtoZero(double y);
    void setBorders();

public slots:
    void setDots(QMap<double, double> *dots);

signals:
    void sendBorders(double leftBord, double rightBord);
    void plotterMoved(double leftBord, double rightBord);
    void updateParams(FuncParams *params);
};

#endif // PLOTTERFORM_H
