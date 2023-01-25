#ifndef INPUTFUNCTIONFORM_H
#define INPUTFUNCTIONFORM_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>

class InputFunctionForm : public QWidget
{
    Q_OBJECT
public:
    explicit InputFunctionForm(QWidget *parent = nullptr);

private:
    QGridLayout* _layout = nullptr;
    QLineEdit* _inputForm = nullptr;
    QGridLayout* _numbers  = nullptr;
    QGridLayout* _operands = nullptr;

    void setupMainWidget();
    void setupNumbersWidget();
    void setupOperandsWidget();
    void setupInputForm();

    void setNumber(const QString& number);
    void setOperand(const QString& operand);

signals:
    void stringToValidCheck(const QString& equation);

private slots:
    void getStringFromInput();

};

#endif // INPUTFUNCTIONFORM_H
