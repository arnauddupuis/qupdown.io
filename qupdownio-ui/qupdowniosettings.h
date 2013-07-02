#ifndef QUPDOWNIOSETTINGS_H
#define QUPDOWNIOSETTINGS_H

#include <QWidget>
#include <QSettings>

namespace Ui {
class QupdownioSettings;
}

class QupdownioSettings : public QWidget
{
	Q_OBJECT
	
public:
	explicit QupdownioSettings(QWidget *parent = 0);
	~QupdownioSettings();

private slots:
	void on_apiKeyLineEdit_textChanged ( const QString & text );
	void on_apiUrlLineEdit_textChanged ( const QString & text );
	void on_defaultPeriodComboBox_currentIndexChanged ( const QString & text );
	void on_defaultPublishingComboBox_currentIndexChanged ( const QString & text );
	
private:
	Ui::QupdownioSettings *ui;
	QSettings *m_settings;
};

#endif // QUPDOWNIOSETTINGS_H
