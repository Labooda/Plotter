#ifndef DISCRETEFUNCTION_H
#define DISCRETEFUNCTION_H

#include "baseoperation.h"
#include "funcparams.h"

#include <QObject>
#include <QMap>

class DiscreteFunction : public QObject
{
    Q_OBJECT
public:
    explicit DiscreteFunction(QObject *parent = nullptr);

private:
    double _leftBord = -320;
    double _rightBord = 320;
    double _topBord = 500;
    double _bottomBord = -500;
    BaseOperation *_baseOp = nullptr;

    void cleanDots(QMap<double, double> *dots);

public slots:
    void arrayOfDots(BaseOperation *baseOp = nullptr);
    void updateParams(FuncParams *params);

signals:
    void dotsCompleted(QMap<double, double> *dots);
};

#endif // DISCRETEFUNCTION_H
