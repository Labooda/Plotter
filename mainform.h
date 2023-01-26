#ifndef MAINFORM_H
#define MAINFORM_H

#include "inputfunctionform.h"
#include "plotterform.h"
#include "parseequation.h"
#include "discretefunction.h"

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
    ParseEquation* _parser = nullptr;
    DiscreteFunction* _discreter = nullptr;

    QMap<double, double>* _dots;

};

#endif // MAINFORM_H
