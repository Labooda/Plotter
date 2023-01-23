#ifndef COMMONDESIGNES_H
#define COMMONDESIGNES_H

#include <QObject>
#include <QPushButton>

class CommonDesignes : public QObject
{
    Q_OBJECT
public:
    explicit CommonDesignes(QObject *parent = nullptr);

    static QPushButton *designedButton(const QString &text);

signals:

};

#endif // COMMONDESIGNES_H
