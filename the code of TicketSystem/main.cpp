#include "GUILogin.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    a.setWindowIcon(QIcon("test.ico"));
	GUILogin w;
	w.show();
	return a.exec();
}
