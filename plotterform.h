#ifndef PLOTTERFORM_H
#define PLOTTERFORM_H

#include <QFrame>
#include <QPainter>
#include <QPair>
#include <QMouseEvent>

class PlotterForm : public QFrame
{
    Q_OBJECT
public:
    explicit PlotterForm(QWidget *parent = nullptr);
    void getBorders(double leftBord, double rightBord);

private:
    QPainter* _painter = nullptr;
    QMap<double, double> *_dots = nullptr;
    QPoint _dragStartPosition;
    double _dx = 0;
    double _dy = 0;
    double _xAxeZero = 0;
    double _yAxeZero = 0;

    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void drawAxes(QPainter &painter);

    double setXtoZero(double x);
    double setYtoZero(double y);

public slots:
    void setDots(QMap<double, double> *dots);

signals:
    void sendBorders(double leftBord, double rightBord);
    void plotterMoved(double leftBord, double rightBord);
};

#endif // PLOTTERFORM_H
