#ifndef MAINFORM_H
#define MAINFORM_H

#include "inputfunctionform.h"
#include "plotterform.h"

#include <QWidget>
#include <QHBoxLayout>

class MainForm : public QWidget
{
    Q_OBJECT
public:
    explicit MainForm(QWidget *parent = nullptr);

private:
    InputFunctionForm *_inputForm = nullptr;
    PlotterForm *_plotterForm = nullptr;
    QHBoxLayout *_layout = nullptr;
    double _leftBord = 0;
    double _rightBord = 0;

private slots:
    void stringToHandler(const QString &equation);
    void setBorders(double leftBord, double rightBord);

public slots:
    void dotsFromHandler(QMap<double, double> *dots);
    void plotterMovedHandler(double leftBord, double rightBord);

signals:
    void dotsToPlotter(QMap<double, double> *dots);
    void stringFromInput(const QString &equation, double leftBord, double rightBord);
    void plotterMoved(double leftBord, double rightBord);
};

#endif // MAINFORM_H
