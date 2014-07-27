//
//  CoverterWidget.h
//  AdjacencyConverter
//
//  Created by Alexander Schulze on 27.07.14.
//
//

#ifndef __AdjacencyConverter__CoverterWidget__
#define __AdjacencyConverter__CoverterWidget__

#include <QMainWindow>

namespace Ui {
    class AdjacencyConverter;
}

class ConverterWidget : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ConverterWidget(QWidget *parent = 0);
    ~ConverterWidget();
    
private:
    Ui::AdjacencyConverter *ui;
};
#endif /* defined(__AdjacencyConverter__CoverterWidget__) */
