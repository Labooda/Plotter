#include "mainform.h"

#include <QDebug>

MainForm::MainForm(QWidget *parent)
    : QWidget{parent}
{
    _parser = new ParseEquation();
    _discreter = new DiscreteFunction();

    _layout = new QHBoxLayout();
     this->setLayout(_layout);

    _inputForm = new InputFunctionForm();
    _plotterForm = new PlotterForm();

    _layout->addWidget(_inputForm, 1);
    _layout->addWidget(_plotterForm, 1);

    connect(_inputForm, &InputFunctionForm::stringToValidCheck, _parser, &ParseEquation::setEquationString);

    connect(_parser, &ParseEquation::stringSuccesfullyParsed, this, [this]()
    {
        BaseOperation* temp = this->_parser->getParsedFunc();
        this->_discreter->arrayOfDots(temp);
    });

    connect(_discreter, &DiscreteFunction::dotsCompleted, this, [this]()
    {
        this->_dots = this->_discreter->getDots();

        for (auto [key, value] : _dots->asKeyValueRange())
        {
            qDebug() << key << " " << value;
        }

        this->_plotterForm->setDots(this->_dots);
    });
}
