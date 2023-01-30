#include "equationhandler.h"

EquationHandler::EquationHandler(QObject *parent)
    : QObject{parent}
{
    _parser = new ParseEquation();
    _discretor = new DiscreteFunction();

    connect(this, &EquationHandler::sendToParser, _parser, &ParseEquation::setEquationString);
    connect(_parser, &ParseEquation::stringSuccesfullyParsed, _discretor, &DiscreteFunction::arrayOfDots);
    connect(_discretor, &DiscreteFunction::dotsCompleted, this, &EquationHandler::getDotsFromDiscretor);
    connect(this, &EquationHandler::sendBordersToDisc, _discretor, &DiscreteFunction::setBrdrs);
    connect(this, &EquationHandler::plotterMoved, _discretor, &DiscreteFunction::setBrdrs);
}

void EquationHandler::getStringFromInput(const QString &equation, double leftBord, double rightBord)
{
    emit sendBordersToDisc(leftBord, rightBord);
    emit sendToParser(equation);
}

void EquationHandler::getDotsFromDiscretor(QMap<double, double> *dots)
{
    emit dotsToPlotter(dots);
}

void EquationHandler::plotterMovedHandler(double leftBord, double rightBord)
{
    emit plotterMoved(leftBord, rightBord);
}
