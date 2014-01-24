#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{

	// main function 
	 
    QApplication a(argc, argv);
	
	// create a object Dialog & show
	
    Dialog w;
    w.show();



    return a.exec();
}

