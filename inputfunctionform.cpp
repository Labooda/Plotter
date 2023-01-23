#include "inputfunctionform.h"
#include "commondesignes.h"

#include <QPushButton>

InputFunctionForm::InputFunctionForm(QWidget *parent)
    : QWidget{parent}
{
    _layout = new QGridLayout();
    QHBoxLayout* inputLayout = new QHBoxLayout();
    QGridLayout* numbers  = new QGridLayout();
    QGridLayout* operands = new QGridLayout();

    //_layout->setAlignment(Qt::AlignCenter);
    numbers->setAlignment(Qt::AlignCenter & Qt::AlignRight);
    operands->setAlignment(Qt::AlignCenter & Qt::AlignLeft);

    numbers->setHorizontalSpacing(5);
    numbers->setVerticalSpacing(5);
    operands->setHorizontalSpacing(5);
    operands->setVerticalSpacing(5);

    qDebug() << numbers->verticalSpacing();

    this->setLayout(_layout);
    _layout->addLayout(inputLayout, 1, 1, 1, 2);
    _layout->addLayout(numbers, 2, 1);
    _layout->addLayout(operands, 2, 2);

    _inputForm = new QLineEdit();

    inputLayout->addWidget(_inputForm);

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

    numbers->addWidget(oneBtn,   1, 1);
    numbers->addWidget(twoBtn,   1, 2);
    numbers->addWidget(threeBtn, 1, 3);
    numbers->addWidget(fourBtn,  2, 1);
    numbers->addWidget(fiveBtn,  2, 2);
    numbers->addWidget(sixBtn,   2, 3);
    numbers->addWidget(sevenBtn, 3, 1);
    numbers->addWidget(eightBtn, 3, 2);
    numbers->addWidget(nineBtn,  3, 3);
    numbers->addWidget(zeroBtn,  4, 2);

    QPushButton* leftBtn  = CommonDesignes::designedButton("left");
    QPushButton* rightBtn = CommonDesignes::designedButton("right");

    numbers->addWidget(leftBtn, 4, 1);
    numbers->addWidget(rightBtn, 4, 3);

    QPushButton* plusBtn  = CommonDesignes::designedButton("+");
    QPushButton* minusBtn = CommonDesignes::designedButton("-");
    QPushButton* multBtn  = CommonDesignes::designedButton("*");
    QPushButton* divBtn   = CommonDesignes::designedButton("/");

    operands->addWidget(plusBtn,  1, 1);
    operands->addWidget(minusBtn, 2, 1);
    operands->addWidget(multBtn,  3, 1);
    operands->addWidget(divBtn,   4, 1);

    connect(plusBtn, QPushButton::pressed, this, [&](){this->setOperand("+");});
    connect(minusBtn, QPushButton::pressed, this, [&](){this->setOperand("-");});
    connect(multBtn, QPushButton::pressed, this, [&](){this->setOperand("*");});
    connect(divBtn, QPushButton::pressed, this, [&](){this->setOperand("/");});

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

void InputFunctionForm::setNumber(const QString &number)
{
    const QString& temp = _inputForm->text();
    _inputForm->setText(temp + number);
}

void InputFunctionForm::setOperand(const QString &operand)
{
    const QString& temp = _inputForm->text();
    _inputForm->setText(temp + operand);
}
