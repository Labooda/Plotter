#include "parseequation.h"

#include <QRegularExpression>

ParseEquation::ParseEquation(QObject *parent)
    : QObject{parent}
{

}

int ParseEquation::stringToEquationParser(QString equation)
{
    int lastPlusMinusPos = equation.lastIndexOf(QRegularExpression("[+-]"));

    QString leftOperand = equation.sliced(0, lastPlusMinusPos);
    QString oprtr = equation[lastPlusMinusPos];
    QString rightOperand = equation.sliced(lastPlusMinusPos + 1);

    int leftResult;
    int rightResult;

    if (leftOperand.contains("+") || leftOperand.contains("-"))
    {
        leftResult = stringToEquationParser(leftOperand);
    }
    else
    {
        leftResult = leftOperand.toInt();
    }

    if (rightOperand.contains("+") || rightOperand.contains("-"))
    {
        rightResult = stringToEquationParser(rightOperand);
    }
    else
    {
        rightResult = rightOperand.toInt();
    }

    if (oprtr == "-")
    {
        return leftResult - rightResult;
    }

    if (oprtr == "+")
    {
        return leftResult + rightResult;
    }

    return 0;
}

void ParseEquation::setEquationString(QString equation)
{
    qDebug() << stringToEquationParser(equation.remove(' '));
}
