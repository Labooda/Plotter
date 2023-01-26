#ifndef PARSEEQUATION_H
#define PARSEEQUATION_H

#include "baseoperation.h"

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
    void stringSuccesfullyParsed();

public slots:
    void setEquationString(const QString equation);

};

#endif // PARSEEQUATION_H
