#ifndef DISCRETEFUNCTION_H
#define DISCRETEFUNCTION_H

#include "baseoperation.h"

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
    BaseOperation *_baseOp = nullptr;

public slots:
    void arrayOfDots(BaseOperation *baseOp = nullptr);
    void setBrdrs(double leftBord, double rightBord);

signals:
    void dotsCompleted(QMap<double, double> *_dots);
};

#endif // DISCRETEFUNCTION_H
