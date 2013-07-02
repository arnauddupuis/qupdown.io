#include "qupdowniosettings.h"
#include "ui_qupdowniosettings.h"

QupdownioSettings::QupdownioSettings(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::QupdownioSettings),
	m_settings( new QSettings )
{
	ui->setupUi(this);
	ui->apiKeyLineEdit->setText( m_settings->value("apiKey").toString() );
	ui->apiUrlLineEdit->setText( m_settings->value("apiUrl").toString() );
}

QupdownioSettings::~QupdownioSettings()
{
	delete ui;
}

void QupdownioSettings::on_apiKeyLineEdit_textChanged(const QString &text){
	m_settings->setValue("apiKey",text);
}

void QupdownioSettings::on_apiUrlLineEdit_textChanged(const QString &text){
	m_settings->setValue("apiUrl",text);
}

void QupdownioSettings::on_defaultPeriodComboBox_currentIndexChanged(const QString &text){
	m_settings->setValue("defaultPeriod",text);
}

void QupdownioSettings::on_defaultPublishingComboBox_currentIndexChanged(const QString &text){
	m_settings->setValue("defaultPublishing",text);
}
