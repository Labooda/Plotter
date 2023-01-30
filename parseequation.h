#ifndef PARSEEQUATION_H
#define PARSEEQUATION_H

#include "baseoperation.h"
#include "funcparams.h"

#include <QObject>

class ParseEquation : public QObject
{
    Q_OBJECT
public:
    explicit ParseEquation(QObject *parent = nullptr);

    BaseOperation* getParsedFunc();

private:
    BaseOperation *stringToEquationParser(QString equation);
    BaseOperation* _parsedFunc = nullptr;

signals:
    void updateParams(FuncParams *params);

public slots:
    void solveStrFunc(FuncParams *params);

};

#endif // PARSEEQUATION_H
