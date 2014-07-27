//
//  CoverterWidget.cpp
//  Project
//
//  Created by Alexander Schulze on 27.07.14.
//
//

#include "CoverterWidget.h"
#include "ui_AdjacencyConverter.h"

ConverterWidget::ConverterWidget(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::AdjacencyConverter)
{
    
    ui->setupUi(this);
}

ConverterWidget::~ConverterWidget()
{
    delete ui;
}