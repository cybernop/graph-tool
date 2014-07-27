//
//  CoverterWidget.cpp
//  Project
//
//  Created by Alexander Schulze on 27.07.14.
//
//

#include <iostream>

#include "CoverterWidget.h"
#include "ui_AdjacencyConverter.h"


ConverterWidget::ConverterWidget(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::AdjacencyConverter)
{
    setupUi();
}

ConverterWidget::~ConverterWidget()
{
    delete ui;
}

// QT slots
void ConverterWidget::on_convertToText_clicked()
{
    // TODO
    std::cout << "clicked convert to text" << std::endl;
}

void ConverterWidget::on_convertToTable_clicked()
{
    // TODO
    std::cout << "clicked convert to table" << std::endl;
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem("1"));
}

void ConverterWidget::setupUi()
{
    ui->setupUi(this);
    
    connect(ui->pushButtonConvertTable, SIGNAL(clicked()), this, SLOT(on_convertToTable_clicked()));
    connect(ui->pushButtonConvertText, SIGNAL(clicked()), this, SLOT(on_convertToText_clicked()));
}