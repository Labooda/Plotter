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

    QMap<int, int> *getDots();
    void arrayOfDots(BaseOperation *baseOp);
    BaseOperation *_baseOp = nullptr;

    QMap<int, int> *_dots = nullptr;

private:


signals:
    void dotsCompleted();
};

#endif // DISCRETEFUNCTION_H
