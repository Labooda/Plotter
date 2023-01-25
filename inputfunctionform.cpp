#include "inputfunctionform.h"
#include "commondesignes.h"

#include <QPushButton>

InputFunctionForm::InputFunctionForm(QWidget *parent)
    : QWidget{parent}
{
    setupMainWidget();
}

void InputFunctionForm::setupNumbersWidget()
{
    QPushButton* oneBtn   = CommonDesignes::designedButton("1");
    QPushButton* twoBtn   = CommonDesignes::designedButton("2");
    QPushButton* threeBtn = CommonDesignes::designedButton("3");
    QPushButton* fourBtn  = CommonDesignes::designedButton("4");
    QPushButton* fiveBtn  = CommonDesignes::designedButton("5");
    QPushButton* sixBtn   = CommonDesignes::designedButton("6");
    QPushButton* sevenBtn = CommonDesignes::designedButton("7");
    QPushButton* eightBtn = CommonDesignes::designedButton("8");
    QPushButton* nineBtn  = CommonDesignes::designedButton("9");
    QPushButton* zeroBtn  = CommonDesignes::designedButton("0");

    _numbers->addWidget(oneBtn,   1, 1);
    _numbers->addWidget(twoBtn,   1, 2);
    _numbers->addWidget(threeBtn, 1, 3);
    _numbers->addWidget(fourBtn,  2, 1);
    _numbers->addWidget(fiveBtn,  2, 2);
    _numbers->addWidget(sixBtn,   2, 3);
    _numbers->addWidget(sevenBtn, 3, 1);
    _numbers->addWidget(eightBtn, 3, 2);
    _numbers->addWidget(nineBtn,  3, 3);
    _numbers->addWidget(zeroBtn,  4, 2);

    QPushButton* leftBtn  = CommonDesignes::designedButton("left");
    QPushButton* rightBtn = CommonDesignes::designedButton("right");

    _numbers->addWidget(leftBtn, 4, 1);
    _numbers->addWidget(rightBtn, 4, 3);

    connect(oneBtn, QPushButton::pressed, this, [&](){this->setNumber("1");});
    connect(twoBtn, QPushButton::pressed, this, [&](){this->setNumber("2");});
    connect(threeBtn, QPushButton::pressed, this, [&](){this->setNumber("3");});
    connect(fourBtn, QPushButton::pressed, this, [&](){this->setNumber("4");});
    connect(fiveBtn, QPushButton::pressed, this, [&](){this->setNumber("5");});
    connect(sixBtn, QPushButton::pressed, this, [&](){this->setNumber("6");});
    connect(sevenBtn, QPushButton::pressed, this, [&](){this->setNumber("7");});
    connect(eightBtn, QPushButton::pressed, this, [&](){this->setNumber("8");});
    connect(nineBtn, QPushButton::pressed, this, [&](){this->setNumber("9");});
    connect(zeroBtn, QPushButton::pressed, this, [&](){this->setNumber("0");});
}

void InputFunctionForm::setupOperandsWidget()
{
    QPushButton* plusBtn  = CommonDesignes::designedButton("+");
    QPushButton* minusBtn = CommonDesignes::designedButton("-");
    QPushButton* multBtn  = CommonDesignes::designedButton("*");
    QPushButton* divBtn   = CommonDesignes::designedButton("/");

    _operands->addWidget(plusBtn,  1, 1);
    _operands->addWidget(minusBtn, 2, 1);
    _operands->addWidget(multBtn,  3, 1);
    _operands->addWidget(divBtn,   4, 1);

    connect(plusBtn, QPushButton::pressed, this, [&](){this->setOperand("+");});
    connect(minusBtn, QPushButton::pressed, this, [&](){this->setOperand("-");});
    connect(multBtn, QPushButton::pressed, this, [&](){this->setOperand("*");});
    connect(divBtn, QPushButton::pressed, this, [&](){this->setOperand("/");});
}

void InputFunctionForm::setupInputForm()
{
    _inputForm->setFocus();
    qDebug() << _inputForm->cursorPosition();
}

void InputFunctionForm::setupMainWidget()
{
    _layout = new QGridLayout();
    _numbers  = new QGridLayout();
    _operands = new QGridLayout();
    _inputForm = new QLineEdit();

    setupNumbersWidget();
    setupOperandsWidget();
    setupInputForm();

    _layout->addWidget(_inputForm, 1, 1, 1, 2);
    _layout->addLayout(_numbers, 2, 1);
    _layout->addLayout(_operands, 2, 2);

    this->setLayout(_layout);
}

void InputFunctionForm::setNumber(const QString &number)
{
    _inputForm->insert(number);
}

void InputFunctionForm::setOperand(const QString &operand)
{
    if (!_inputForm->cursorPosition())
    {
        return;
    }

    _inputForm->insert(" " + operand + " ");
}
