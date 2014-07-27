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
#include <QMessageBox>

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
    std::vector<std::vector<std::string> > tableContentVectors;
    readTable(tableContentVectors);
    std::string tableString = Adjacency::vectorsToString(tableContentVectors);
    
    ui_->plainTextEdit->clear();
    ui_->plainTextEdit->insertPlainText(QString::fromStdString(tableString));
}

void ConverterWidget::on_convertToTable_clicked()
{
    std::vector<std::vector<std::string> > input;
    Adjacency::splitIntoLines(input, ui_->plainTextEdit->toPlainText().toStdString());
    nElements_ = input.size();
    
    ui_->spinBoxNumberElements->setValue(nElements_);
    
    fillTable(input);
}

void ConverterWidget::on_tableSizeChanged_valueChanged(int value)
{
    nElements_ = value;
    resizeTable();
}

void ConverterWidget::setupUi()
{
    ui_->setupUi(this);
    
    connect(ui_->pushButtonConvertTable, SIGNAL(clicked()), this, SLOT(on_convertToTable_clicked()));
    connect(ui_->pushButtonConvertText, SIGNAL(clicked()), this, SLOT(on_convertToText_clicked()));
    connect(ui_->spinBoxNumberElements, SIGNAL(valueChanged(int)), this, SLOT(on_tableSizeChanged_valueChanged(int)));
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
        if (!rowVector.size() == nElements_)
        {
            QMessageBox::warning(this, tr("Dimension Error"), tr("Dimensions for rows and columns must match"));
            return;
        }
        
        size_t col = 0;
        
        for (const std::string& entry : rowVector)
        {
            ui_->tableWidget->setItem(row, col++, new QTableWidgetItem(QString::fromStdString(entry)));
        }
        row++;
    }
}

void ConverterWidget::readTable(std::vector<std::vector<std::string> >& result)
{
    assert(ui_->tableWidget->rowCount() == nElements_ && ui_->tableWidget->columnCount() == nElements_);
    
    result.resize(nElements_);
    
    for (size_t row = 0; row < nElements_; row++)
    {
        std::vector<std::string>* currentRow = &result[row];
        currentRow->resize(nElements_);
        
        for (size_t col = 0; col < nElements_; col++)
        {
            if (ui_->tableWidget->item(row, col) == NULL)
            {
                return;
            }
            
            currentRow->at(col) = ui_->tableWidget->item(row, col)->text().toStdString();
        }
    }
}
