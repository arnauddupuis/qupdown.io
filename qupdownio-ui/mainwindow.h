#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "libqupdownio.h"
#include <QGraphicsDropShadowEffect>
#include "qupdowniosettings.h"

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
	void on_settingsPushButton_clicked();
	void on_checksFinished(QList<LibQupdownio::Check*> p_list);
	void on_downtimesFinished(QList<LibQupdownio::CheckError*> p_list);
	void on_updateFinished(LibQupdownio::Check* p_check);
	void on_deleteFinished(bool status, QString message);
	void on_addCheckFinished(LibQupdownio::Check*);

private:
	Ui::MainWindow *ui;
	Qupdownio *m_qupdownio;
	QGraphicsDropShadowEffect *m_shadow;
	QupdownioSettings *m_settings;
};

#endif // MAINWINDOW_H
