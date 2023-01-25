#include "mainform.h"

MainForm::MainForm(QWidget *parent)
    : QWidget{parent}
{
    _layout = new QHBoxLayout();
     this->setLayout(_layout);

    _inputForm = new InputFunctionForm();
    _plotterForm = new PlotterForm();

    _layout->addWidget(_inputForm, 1);
    _layout->addWidget(_plotterForm, 1);

    connect(_inputForm, &InputFunctionForm::stringToValidCheck, this, MainForm::sendStringToValidation);
}

void MainForm::sendStringToValidation(const QString &equation)
{
    qDebug() << equation;
}
