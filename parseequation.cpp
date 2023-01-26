#include "parseequation.h"

#include <QRegularExpression>

ParseEquation::ParseEquation(QObject *parent)
    : QObject{parent}
{

}

BaseOperation *ParseEquation::stringToEquationParser(QString equation)
{
    int lastOpPos = equation.lastIndexOf(QRegularExpression("[+-]"));

    if (lastOpPos == -1)
    {
        lastOpPos = equation.lastIndexOf(QRegularExpression("[*/]"));
    }

    if (lastOpPos == -1)
    {
        if (equation == "x")
        {
            return new BaseOperation(new QPair<QString, QString>("variable", equation));
        }
        else
        {
            return new BaseOperation(new QPair<QString, QString>("number", equation));
        }
    }

    QString leftOperand = equation.sliced(0, lastOpPos);
    QString oprtr = equation[lastOpPos];
    QString rightOperand = equation.sliced(lastOpPos + 1);

    return new BaseOperation(stringToEquationParser(leftOperand), oprtr, stringToEquationParser(rightOperand));
}

void ParseEquation::setEquationString(QString equation)
{
    BaseOperation* bo = stringToEquationParser(equation.remove(' '));
    double result = bo->computeResult(10.0);

    qDebug() << result;
}
