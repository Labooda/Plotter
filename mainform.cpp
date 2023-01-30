#include "mainform.h"

#include <QDebug>

MainForm::MainForm(QWidget *parent)
    : QWidget{parent}
{
    _params = new FuncParams();
    _layout = new QHBoxLayout();
     this->setLayout(_layout);

    _inputForm = new InputFunctionForm(_params);
    _plotterForm = new PlotterForm(_params);

    _layout->addWidget(_inputForm, 1);
    _layout->addWidget(_plotterForm, 1);

    connect(_inputForm, &InputFunctionForm::updateParams, this, &MainForm::updateParamsHandle);
    connect(this, &MainForm::dotsToPlotter, _plotterForm, &PlotterForm::setDots);
    connect(_plotterForm, &PlotterForm::updateParams, this, &MainForm::updateParamsHandle);
}

void MainForm::updateParamsHandle(FuncParams *params)
{
    emit updateParams(params);
}

void MainForm::dotsFromHandler(QMap<double, double> *dots)
{
    emit dotsToPlotter(dots);
}
