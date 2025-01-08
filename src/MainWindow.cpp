#include "MainWindow.h"

#include <QLabel>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Set up UI or custom initialization
    setWindowTitle("My Qt Application");
    QLabel* lblTest = new QLabel("This is a test to test things");

    QWidget* centralWidget = new QWidget(this);
    QHBoxLayout* layout = new QHBoxLayout(centralWidget);
    layout->addWidget(lblTest);

    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() 
{
}