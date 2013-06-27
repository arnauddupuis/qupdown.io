#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_qupdownio = new Qupdownio(this);
    connect(m_qupdownio,SIGNAL(checksFinished(QList<LibQupdownio::Check*>)),this,SLOT(on_checksFinished(QList<LibQupdownio::Check*>)));
    connect(m_qupdownio,SIGNAL(downtimesFinished(QList<LibQupdownio::CheckError*>)),this,SLOT(on_downtimesFinished(QList<LibQupdownio::CheckError*>)));
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

void MainWindow::on_addCheckPushButton_clicked(){
	m_qupdownio->setApiKey(ui->apiKeyLineEdit->text());
	m_qupdownio->addCheck(ui->hostLineEdit->text(),30,false);
}
