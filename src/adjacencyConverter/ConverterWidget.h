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
    
private slots:
    void on_convertToText_clicked();
    void on_convertToTable_clicked();
    void on_tableSizeChanged_valueChanged(int);
    
private:
    void setupUi();
    void resizeTable();
    
    void fillTable(std::vector<std::vector<std::string> > tableString);
    void readTable(std::vector<std::vector<std::string> >& result);
    
    Ui::AdjacencyConverter *ui_;
    size_t nElements_;
};
#endif /* defined(__AdjacencyConverter__CoverterWidget__) */
