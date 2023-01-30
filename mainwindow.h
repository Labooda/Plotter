#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainform.h"
#include "equationhandler.h"

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MainForm *_mainForm = nullptr;
    EquationHandler *_handler = nullptr;
};
#endif // MAINWINDOW_H
