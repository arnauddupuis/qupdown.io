#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_qupdownio = new Qupdownio(this);
    connect(m_qupdownio,SIGNAL(checksFinished(QList<LibQupdownio::Check*>)),this,SLOT(on_checksFinished(QList<LibQupdownio::Check*>)));
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
