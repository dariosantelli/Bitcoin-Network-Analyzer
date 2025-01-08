#include <iostream>
#include <QApplication>
#include "MainWindow.h"

int main(int argc, char* argv[])
{
    std::cout << "TESTING TESTING 123" << std::endl;
    std::cout << "argc: " << argc << std::endl;
    std::cout << "argv: " << argv << std::endl;

    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}