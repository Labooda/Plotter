#ifndef PARSEEQUATION_H
#define PARSEEQUATION_H

#include <QObject>

class ParseEquation : public QObject
{
    Q_OBJECT
public:
    explicit ParseEquation(QObject *parent = nullptr);

private:
    int stringToEquationParser(QString equation);

signals:

public slots:
    void setEquationString(const QString equation);

};

#endif // PARSEEQUATION_H
