//
//  CoverterWidget.cpp
//  Project
//
//  Created by Alexander Schulze on 27.07.14.
//
//

#include <iostream>
#include <string>

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
    ui_->tableWidget->setItem(1, 1, new QTableWidgetItem("1"));
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
