#include "qupdowniosettings.h"
#include "ui_qupdowniosettings.h"

QupdownioSettings::QupdownioSettings(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::QupdownioSettings),
	m_settings( new QSettings )
{
	ui->setupUi(this);
}

QupdownioSettings::~QupdownioSettings()
{
	delete ui;
}
