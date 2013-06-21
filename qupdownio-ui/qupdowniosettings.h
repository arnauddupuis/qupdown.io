#ifndef QUPDOWNIOSETTINGS_H
#define QUPDOWNIOSETTINGS_H

#include <QWidget>

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
};

#endif // QUPDOWNIOSETTINGS_H
