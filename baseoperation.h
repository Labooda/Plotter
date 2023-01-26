#ifndef BASEOPERATION_H
#define BASEOPERATION_H

#include <QObject>

class BaseOperation
{
public:
    BaseOperation(QPair<QString, QString> *operand);

    BaseOperation(BaseOperation *firstOp,
                  QString oprtr,
                  BaseOperation *secondOp);


    double computeResult(double x = 0);
private:
    int _currentFlag = -1;
    QPair<QString, QString> *_singleOp = nullptr;

    BaseOperation *_firstOp = nullptr;
    QString _oprtr = "";
    BaseOperation *_secondOp = nullptr;

    enum OpFlag {SingleOperand, Operation};
};

#endif // BASEOPERATION_H
