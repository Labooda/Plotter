#include "mainwindow.h"
#include "constants.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _handler = new EquationHandler();
    _mainForm = new MainForm();

    connect(_mainForm, &MainForm::updateParams, _handler, &EquationHandler::updateParams);
    connect(_handler, &EquationHandler::dotsToPlotter, _mainForm, &MainForm::dotsFromHandler);

    this->setCentralWidget(_mainForm);
    this->resize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
}

MainWindow::~MainWindow()
{
}
