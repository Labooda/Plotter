#include "mainwindow.h"
#include "constants.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _mainForm = new MainForm();
    this->setCentralWidget(_mainForm);

    this->resize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
}

MainWindow::~MainWindow()
{
}
