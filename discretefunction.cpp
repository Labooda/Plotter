#include "discretefunction.h"

#include <QDebug>

DiscreteFunction::DiscreteFunction(QObject *parent)
    : QObject{parent}
{
}

void DiscreteFunction::cleanDots(QMap<double, double> *dots)
{

}

void DiscreteFunction::arrayOfDots(BaseOperation *baseOp)
{
    QMap<double, double> *dots = new QMap<double, double>();
    double step = (_rightBord - _leftBord) / 100;

    for (double i = _leftBord; i < _rightBord; i += step)
    {
        dots->insert(i, _baseOp->computeResult(i));
    }

    //cleanDots(dots);

    emit dotsCompleted(dots);
}

void DiscreteFunction::updateParams(FuncParams *params)
{
    _baseOp = params->getSolution();
    _leftBord = params->getLeftBord();
    _rightBord = params->getRightBord();
    _topBord = params->getTopBord();
    _bottomBord = params->getBottomBord();

    arrayOfDots();
}
