#include <qapplication.h>
#include "ui_mainwindow.h"
#include "das_mainwindow.h"

das_mainwindow *das_MainWindow;

int main(int argc, char *argv[])
{
	QApplication prg(argc, argv);
	das_MainWindow = new das_mainwindow(NULL);
	das_MainWindow->show();
	return prg.exec();
}

