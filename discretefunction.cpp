#include "discretefunction.h"

#include <QDebug>

DiscreteFunction::DiscreteFunction(QObject *parent)
    : QObject{parent}
{
}

void DiscreteFunction::arrayOfDots(BaseOperation *baseOp)
{
    QMap<double, double> *dots = new QMap<double, double>();

    for (double i = _leftBord; i < _rightBord; i += (_rightBord - _leftBord) / 100)
    {
        dots->insert(i, _baseOp->computeResult(i));
    }

    emit dotsCompleted(dots);
}

void DiscreteFunction::updateParams(FuncParams *params)
{
    _baseOp = params->getSolution();
    _leftBord = params->getLeftBord();
    _rightBord = params->getRightBord();
    qDebug() << "DiscreteFunction::updateParams::ended" << _leftBord << _rightBord;

    arrayOfDots();
}
