#include "equationhandler.h"

EquationHandler::EquationHandler(QObject *parent)
    : QObject{parent}
{
    _parser = new ParseEquation();
    _discretor = new DiscreteFunction();

    connect(this, &EquationHandler::updateParams, _parser, &ParseEquation::solveStrFunc);
    connect(_parser, &ParseEquation::updateParams, _discretor, &DiscreteFunction::updateParams);
    connect(_discretor, &DiscreteFunction::dotsCompleted, this, &EquationHandler::getDotsFromDiscretor);
}

void EquationHandler::updateParamsHandle(FuncParams *params)
{
    emit updateParams(params);
}

void EquationHandler::getDotsFromDiscretor(QMap<double, double> *dots)
{
    emit dotsToPlotter(dots);
}
