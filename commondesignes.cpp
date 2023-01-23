#include "commondesignes.h"

CommonDesignes::CommonDesignes(QObject *parent)
    : QObject{parent}
{

}

QPushButton *CommonDesignes::designedButton(const QString &text)
{
    QPushButton *btn = new QPushButton(text);
    btn->setStyleSheet("color: black;"
                       "background-color: grey;"
                       "border-style: none;"
                       "border-width: 0px;"
                       "border-radius: 2px;"
                       "font-size: 20px;"
                       "font-family: Consolas;");
    btn->setMaximumSize(50, 50);
    btn->setMinimumSize(50, 50);

    return btn;
}
