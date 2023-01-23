#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainform.h"

#include <QMainWindow>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MainForm* _mainForm = nullptr;
    QLayout* _layout = nullptr;
};
#endif // MAINWINDOW_H
