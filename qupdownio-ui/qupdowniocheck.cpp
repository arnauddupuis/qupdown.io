#include "qupdowniocheck.h"
#include "ui_qupdowniocheck.h"

QupdownioCheck::QupdownioCheck(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::QupdownioCheck)
{	
	ui->setupUi(this);
}

QupdownioCheck::~QupdownioCheck()
{
	delete ui;
}
