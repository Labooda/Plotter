#include "funcparams.h"

FuncParams::FuncParams()
{

}

FuncParams::~FuncParams()
{

}

void FuncParams::setSolved(bool solved)
{
    _solved = solved;
}

void FuncParams::setSolution(BaseOperation *solution)
{
    _solution = solution;
}

void FuncParams::setStrFunc(QString newStrFunc)
{
    _strFunc = newStrFunc;
}

void FuncParams::setScale(double newScale)
{
    _scale = newScale;
}

void FuncParams::setLeftBord(double newLeftBord)
{
    _leftBord = newLeftBord;
}

void FuncParams::setRightBord(double newRightBord)
{
    _rightBord = newRightBord;
}

void FuncParams::setTopBord(double newTopBord)
{
    _topBord = newTopBord;
}

void FuncParams::setBottomBord(double newBottomBord)
{
    _bottomBord = newBottomBord;
}

bool FuncParams::getSolved()
{
    return _solved;
}

BaseOperation *FuncParams::getSolution()
{
    return _solution;
}

QString FuncParams::getStrFunc()
{
    return _strFunc;
}

double FuncParams::getScale()
{
    return _scale;
}

double FuncParams::getLeftBord()
{
    return _leftBord;
}

double FuncParams::getRightBord()
{
    return _rightBord;
}

double FuncParams::getTopBord()
{
    return _topBord;
}

double FuncParams::getBottomBord()
{
    return _bottomBord;
}
