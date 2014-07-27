//
//  main.cpp
//  AdjacencyConverter
//
//  Created by Alexander Schulze on 27.07.14.
//
//

#include "CoverterWidget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConverterWidget w;
    w.show();
    
    return a.exec();
}