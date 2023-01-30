#include "mainform.h"

#include <QDebug>

MainForm::MainForm(QWidget *parent)
    : QWidget{parent}
{
    _layout = new QHBoxLayout();
     this->setLayout(_layout);

    _inputForm = new InputFunctionForm();
    _plotterForm = new PlotterForm();

    setBorders(-_plotterForm->width() / 2, _plotterForm->width() / 2);

    _layout->addWidget(_inputForm, 1);
    _layout->addWidget(_plotterForm, 1);

    connect(_inputForm, &InputFunctionForm::stringToValidCheck, this, &MainForm::stringToHandler);
    connect(this, &MainForm::dotsToPlotter, _plotterForm, &PlotterForm::setDots);
    connect(_plotterForm, &PlotterForm::sendBorders, this, &MainForm::setBorders);
    connect(_plotterForm, &PlotterForm::plotterMoved, this, &MainForm::plotterMovedHandler);
}

void MainForm::setBorders(double leftBord, double rightBord)
{
    _leftBord = leftBord;
    _rightBord = rightBord;
}

void MainForm::stringToHandler(const QString &equation)
{
    emit stringFromInput(equation, _leftBord, _rightBord);
}

void MainForm::dotsFromHandler(QMap<double, double> *dots)
{
    emit dotsToPlotter(dots);
}

void MainForm::plotterMovedHandler(double leftBord, double rightBord)
{
    emit plotterMoved(leftBord, rightBord);
}
