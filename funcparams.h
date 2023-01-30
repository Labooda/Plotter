#ifndef FUNCPARAMS_H
#define FUNCPARAMS_H

#include "baseoperation.h"

#include <QString>

class FuncParams
{
public:
    FuncParams();
    ~FuncParams();
private:
    QString _strFunc;
    double  _scale = 100;
    double  _leftBord = -5;
    double  _rightBord = 5;
    double  _topBord = 500;
    double  _bottomBord = -500;
    bool    _solved = false;
    BaseOperation *_solution = nullptr;
public:
    void setSolved(bool solved);
    void setSolution(BaseOperation *solution);
    void setStrFunc(QString newStrFunc);
    void setScale(double newScale);
    void setLeftBord(double newLeftBord);
    void setRightBord(double newRightBord);
    void setTopBord(double newTopBord);
    void setBottomBord(double newBottomBord);

    bool getSolved();
    BaseOperation *getSolution();
    QString getStrFunc();
    double getScale();
    double getLeftBord();
    double getRightBord();
    double getTopBord();
    double getBottomBord();
};

#endif // FUNCPARAMS_H
