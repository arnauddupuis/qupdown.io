#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "libqupdownio.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
	void on_checksPushButton_clicked();
    void on_downtimesPushButton_clicked();
    void on_checksFinished(QList<LibQupdownio::Check*> p_list);
    void on_downtimesFinished(QList<LibQupdownio::CheckError*> p_list);

private:
    Ui::MainWindow *ui;
    Qupdownio *m_qupdownio;
};

#endif // MAINWINDOW_H
