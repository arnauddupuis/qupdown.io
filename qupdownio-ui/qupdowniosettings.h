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
	
private:
	Ui::QupdownioSettings *ui;
	QSettings *m_settings;
};

#endif // QUPDOWNIOSETTINGS_H
