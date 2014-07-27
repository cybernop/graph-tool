//
//  CoverterWidget.cpp
//  Project
//
//  Created by Alexander Schulze on 27.07.14.
//
//

#include <assert.h>

#include <iostream>
#include <string>
#include <QString>

#include "ConverterWidget.h"
#include "ui_AdjacencyConverter.h"
#include <adjacency.h>


ConverterWidget::ConverterWidget(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::AdjacencyConverter),
    nElements_(0)
{
    setupUi();
}

ConverterWidget::~ConverterWidget()
{
    delete ui_;
}

// QT slots
void ConverterWidget::on_convertToText_clicked()
{
    // TODO
    std::cout << "clicked convert to text" << std::endl;
}

void ConverterWidget::on_convertToTable_clicked()
{
    std::vector<std::vector<std::string> > input;
    Adjacency::splitIntoLines(input, ui_->plainTextEdit->toPlainText().toStdString());
    nElements_ = input.size();
    
    resizeTable();
    fillTable(input);
}

void ConverterWidget::setupUi()
{
    ui_->setupUi(this);
    
    connect(ui_->pushButtonConvertTable, SIGNAL(clicked()), this, SLOT(on_convertToTable_clicked()));
    connect(ui_->pushButtonConvertText, SIGNAL(clicked()), this, SLOT(on_convertToText_clicked()));
}

void ConverterWidget::resizeTable()
{
    ui_->tableWidget->setRowCount(nElements_);
    ui_->tableWidget->setColumnCount(nElements_);
}

void ConverterWidget::fillTable(const std::vector<std::vector<std::string> > tableVectors)
{
    assert(tableVectors.size() == nElements_);
    
    size_t row = 0;
    
    for (const std::vector<std::string>& rowVector : tableVectors)
    {
        assert(rowVector.size() == nElements_);
        
        size_t col = 0;
        
        for (const std::string& entry : rowVector)
        {
            ui_->tableWidget->setItem(row, col++, new QTableWidgetItem(QString::fromStdString(entry)));
        }
        row++;
    }
}
