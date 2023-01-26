#include "discretefunction.h"

DiscreteFunction::DiscreteFunction(QObject *parent)
    : QObject{parent}
{
}

QMap<double, double> *DiscreteFunction::getDots()
{
    return _dots;
}

void DiscreteFunction::arrayOfDots(BaseOperation *baseOp)
{
    _dots = new QMap<double, double>();
    _baseOp = baseOp;
    for (double i = 0; i < 100; i++)
    {
        _dots->insert(i, _baseOp->computeResult(i));
    }

    emit dotsCompleted();
}
