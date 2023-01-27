#include "baseoperation.h"

#include <QDebug>

BaseOperation::BaseOperation(QPair<QString, QString> *operand)
{
    _currentFlag = SingleOperand;
    _singleOp = operand;
}

BaseOperation::BaseOperation(BaseOperation *firstOp, QString oprtr, BaseOperation *secondOp)
{
    _currentFlag = Operation;
    _firstOp = firstOp;
    _oprtr = oprtr;
    _secondOp = secondOp;
}

double BaseOperation::computeResult(double x)
{
    if (_currentFlag == SingleOperand)
    {
        if (_singleOp->first == "number")
        {
            return _singleOp->second.toDouble();
        }
        if (_singleOp->first == "variable")
        {
            return x;
        }
    }

    if (_currentFlag == Operation)
    {
        double firstRes = _firstOp->computeResult(x);
        double secondRes = _secondOp->computeResult(x);

        if (_oprtr == "+")
        {
            return firstRes + secondRes;
        }
        if (_oprtr == "-")
        {
            return firstRes - secondRes;
        }
        if (_oprtr == "*")
        {
            return firstRes * secondRes;
        }
        if (_oprtr == "/")
        {
            return secondRes != 0 ? firstRes / secondRes : INT_MAX;
        }
    }

    return 0;
}
