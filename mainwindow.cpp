#include "mainwindow.h"
#include "constants.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _handler = new EquationHandler();
    _mainForm = new MainForm();

    connect(_mainForm, &MainForm::stringFromInput, _handler, &EquationHandler::getStringFromInput);
    connect(_handler, &EquationHandler::dotsToPlotter, _mainForm, &MainForm::dotsFromHandler);
    connect(_mainForm, &MainForm::plotterMoved, _handler, EquationHandler::plotterMovedHandler);

    this->setCentralWidget(_mainForm);
    this->resize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
}

MainWindow::~MainWindow()
{
}
