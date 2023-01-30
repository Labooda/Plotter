#ifndef MAINFORM_H
#define MAINFORM_H

#include "inputfunctionform.h"
#include "plotterform.h"
#include "funcparams.h"

#include <QWidget>
#include <QHBoxLayout>

class MainForm : public QWidget
{
    Q_OBJECT
public:
    explicit MainForm(QWidget *parent = nullptr);

private:
    FuncParams *_params = nullptr;
    InputFunctionForm *_inputForm = nullptr;
    PlotterForm *_plotterForm = nullptr;
    QHBoxLayout *_layout = nullptr;
    double _leftBord = 0;
    double _rightBord = 0;

private slots:
    void updateParamsHandle(FuncParams *params);

public slots:
    void dotsFromHandler(QMap<double, double> *dots);

signals:
    void dotsToPlotter(QMap<double, double> *dots);
    void updateParams(FuncParams *params);
};

#endif // MAINFORM_H
