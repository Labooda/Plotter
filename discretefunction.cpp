#include "discretefunction.h"

#include <QDebug>

DiscreteFunction::DiscreteFunction(QObject *parent)
    : QObject{parent}
{
}

void DiscreteFunction::arrayOfDots(BaseOperation *baseOp)
{
    if (baseOp != nullptr)
    {
        _baseOp = baseOp;
    }

    if (_baseOp == nullptr)
    {
        return;
    }

    QMap<double, double> *dots = new QMap<double, double>();

    for (double i = _leftBord; i < _rightBord; i++)
    {
        dots->insert(i, _baseOp->computeResult(i));
    }

    emit dotsCompleted(dots);
}

void DiscreteFunction::setBrdrs(double leftBord, double rightBord)
{
    _leftBord = leftBord;
    _rightBord = rightBord;

    arrayOfDots();
}
