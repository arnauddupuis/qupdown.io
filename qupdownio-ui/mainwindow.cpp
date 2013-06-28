#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_qupdownio = new Qupdownio(this);
    connect(m_qupdownio,SIGNAL(checksFinished(QList<LibQupdownio::Check*>)),this,SLOT(on_checksFinished(QList<LibQupdownio::Check*>)));
    connect(m_qupdownio,SIGNAL(downtimesFinished(QList<LibQupdownio::CheckError*>)),this,SLOT(on_downtimesFinished(QList<LibQupdownio::CheckError*>)));
    connect( m_qupdownio,SIGNAL(updateCheckFinished(LibQupdownio::Check*)),this,SLOT(on_updateFinished(LibQupdownio::Check*)) );
    connect( m_qupdownio,SIGNAL(deleteCheckFinished(bool,QString)),this,SLOT(on_deleteFinished(bool,QString)) );
    connect( m_qupdownio,SIGNAL(addCheckFinished(LibQupdownio::Check*)),this,SLOT(on_addCheckFinished(LibQupdownio::Check*)) );
    m_shadow = new QGraphicsDropShadowEffect(ui->menuWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checksPushButton_clicked(){
	m_qupdownio->setApiKey(ui->apiKeyLineEdit->text());
	m_qupdownio->checks();
}

void MainWindow::on_downtimesPushButton_clicked(){
    m_qupdownio->downtimes(ui->tokenComboBox->currentText(),1);
}

void MainWindow::on_checksFinished(QList<LibQupdownio::Check *> p_list){
    ui->tokenComboBox->clear();
    foreach( LibQupdownio::Check *check, p_list ){
        ui->tokenComboBox->addItem(check->token());
    }
}

void MainWindow::on_downtimesFinished(QList<LibQupdownio::CheckError *> p_list){
	foreach( LibQupdownio::CheckError *ce, p_list ){
		qDebug() << "Downtime: start: " << ce->startedAt().toString("yyyy-MM-dd@hh:mm:ss") << " duration: " << ce->duration() << " error: " << ce->error() << " end: " << ce->endedAt().toString("yyyy-MM-dd@hh:mm:ss");
	}
}

void MainWindow::on_updateFinished(LibQupdownio::Check *p_check){
	qDebug() << "Check updated with: URL=" << p_check->url() << " period=" << p_check->period() << " published=" << p_check->published() << "token=" << p_check->token();
	QMessageBox msg;
	msg.setText( "Check updated with: URL=" + p_check->url().toString() + " period=" + p_check->period() + " published=" + p_check->published() + "token=" + p_check->token() );
	msg.setIcon(QMessageBox::Information);
	msg.exec();
}

void MainWindow::on_addCheckFinished(LibQupdownio::Check *p_check){
//	qDebug() << "Check added with: URL=" << p_check->url() << " period=" << p_check->period() << " published=" << p_check->published() << "token=" << p_check->token();
	on_checksPushButton_clicked();
	QMessageBox msg;
	msg.setText( "Check added with: URL=" + p_check->url().toString() + " period=" + p_check->period() + " published=" + p_check->published() + "token=" + p_check->token() );
	msg.setIcon(QMessageBox::Information);
	msg.exec();
}

void MainWindow::on_deleteFinished(bool status, QString message){
	QMessageBox msg;
	msg.setText(message);
	if(status){
		msg.setIcon(QMessageBox::Information);
		on_checksPushButton_clicked();
	}
	else{
		msg.setIcon(QMessageBox::Critical);
	}
	msg.exec();
}

void MainWindow::on_addCheckPushButton_clicked(){
	m_qupdownio->setApiKey(ui->apiKeyLineEdit->text());
	m_qupdownio->addCheck(ui->hostLineEdit->text(),30,false);
}

void MainWindow::on_updateCheckPushButton_clicked(){
    m_qupdownio->setApiKey(ui->apiKeyLineEdit->text());
    m_qupdownio->updateCheck(ui->tokenComboBox->currentText(),ui->hostLineEdit->text(),120,false);
}

void MainWindow::on_deleteCheckPushButton_clicked(){
    m_qupdownio->setApiKey(ui->apiKeyLineEdit->text());
    m_qupdownio->deleteCheck(ui->tokenComboBox->currentText());
}

