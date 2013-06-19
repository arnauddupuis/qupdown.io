#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_qupdownio = new Qupdownio(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checksPushButton_clicked(){
	ui->statusLabel->setText("API Key: "+ui->apiKeyLineEdit->text());
	m_qupdownio->setApiKey(ui->apiKeyLineEdit->text());
	m_qupdownio->checks();
}
