#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "libqupdownio.h"
#include <QGraphicsDropShadowEffect>

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
    void on_addCheckPushButton_clicked();
    void on_updateCheckPushButton_clicked();
    void on_deleteCheckPushButton_clicked();
    void on_checksFinished(QList<LibQupdownio::Check*> p_list);
    void on_downtimesFinished(QList<LibQupdownio::CheckError*> p_list);

private:
    Ui::MainWindow *ui;
    Qupdownio *m_qupdownio;
    QGraphicsDropShadowEffect *m_shadow;

};

#endif // MAINWINDOW_H
