#ifndef EQUATIONHANDLER_H
#define EQUATIONHANDLER_H

#include "parseequation.h"
#include "discretefunction.h"

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
    void sendToParser(const QString& equation);
    void dotsToPlotter(QMap<double, double> *dots);
    void sendBordersToDisc(double leftBord, double rightBord);
    void plotterMoved(double leftBord, double rightBord);

public slots:
    void getStringFromInput(const QString &equation, double leftBord, double rightBord);
    void plotterMovedHandler(double leftBord, double rightBord);

private slots:
    void getDotsFromDiscretor(QMap<double, double> *dots);
};

#endif // EQUATIONHANDLER_H
