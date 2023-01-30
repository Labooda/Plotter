#ifndef EQUATIONHANDLER_H
#define EQUATIONHANDLER_H

#include "parseequation.h"
#include "discretefunction.h"
#include "funcparams.h"

#include <QObject>

class EquationHandler : public QObject
{
    Q_OBJECT
public:
    explicit EquationHandler(QObject *parent = nullptr);

private:
    ParseEquation* _parser = nullptr;
    DiscreteFunction* _discretor = nullptr;

signals:
    void dotsToPlotter(QMap<double, double> *dots);
    void updateParams(FuncParams *params);

public slots:
    void updateParamsHandle(FuncParams *params);

private slots:
    void getDotsFromDiscretor(QMap<double, double> *dots);
};

#endif // EQUATIONHANDLER_H
