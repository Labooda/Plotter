#ifndef PLOTTERFORM_H
#define PLOTTERFORM_H

#include <QWidget>
#include <QPainter>

class PlotterForm : public QWidget
{
    Q_OBJECT
public:
    explicit PlotterForm(QWidget *parent = nullptr);

    void setDots(QMap<double, double> *dots);

private:
    QPainter* _painter = nullptr;
    void paintEvent(QPaintEvent *event) override;
    void drawAxes(QPainter &painter);
    QMap<double, double> *_dots = nullptr;

    double setXtoZero(double x);
    double setYtoZero(double y);

signals:

};

#endif // PLOTTERFORM_H
