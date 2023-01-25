#ifndef MAINFORM_H
#define MAINFORM_H

#include "inputfunctionform.h"
#include "plotterform.h"

#include <QWidget>
#include <QHBoxLayout>

class MainForm : public QWidget
{
    Q_OBJECT
public:
    explicit MainForm(QWidget *parent = nullptr);

private:
    InputFunctionForm *_inputForm = nullptr;
    PlotterForm *_plotterForm = nullptr;
    QHBoxLayout *_layout = nullptr;

signals:

private slots:
    void sendStringToValidation(const QString& equation);

};

#endif // MAINFORM_H