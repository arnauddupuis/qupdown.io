#ifndef QUPDOWNIOCHECK_H
#define QUPDOWNIOCHECK_H

#include <QtGui/QWidget>

namespace Ui {
class QupdownioCheck;
}

class QupdownioCheck : public QWidget
{
	Q_OBJECT
	
public:
	explicit QupdownioCheck(QWidget *parent = 0);
	~QupdownioCheck();
	
private:
	Ui::QupdownioCheck *ui;
	const QString m_statusOkCss = "color: rgb(91, 167, 0); cursor: default; display: block; float: right; font-family: Ubuntu, 'Helvetica Neue', helvetica, arial, sans-serif; font-size: 14px; font-style: normal; font-variant: normal; font-weight: bold; height: 14px; line-height: 14px; list-style-image: none; list-style-position: outside; list-style-type: none; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; margin-top: 12.960000038146973px; overflow-x: hidden; overflow-y: hidden; padding-bottom: 0px; padding-left: 0px; padding-right: 0px; padding-top: 0px;text-align: right;text-overflow: ellipsis;vertical-align: baseline;white-space: nowrap;";
	const QString m_statusUnkownCss = "color: rgb(153, 153, 153); cursor: default; display: block; float: right; font-family: Ubuntu, 'Helvetica Neue', helvetica, arial, sans-serif; font-size: 14px; font-style: normal; font-variant: normal; font-weight: bold; height: 14px; line-height: 14px; list-style-image: none; list-style-position: outside; list-style-type: none; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; margin-top: 12.960000038146973px; overflow-x: hidden; overflow-y: hidden; padding-bottom: 0px; padding-left: 0px; padding-right: 0px; padding-top: 0px; text-align: right; text-overflow: ellipsis; vertical-align: baseline; white-space: nowrap;";
	const QString m_statusDownCss = "color:rgb(221, 68, 0); cursor: default; display: block; float: right; font-family: Ubuntu, 'Helvetica Neue', helvetica, arial, sans-serif; font-size: 14px; font-style: normal; font-variant: normal; font-weight: bold; height: 14px; line-height: 14px; list-style-image: none; list-style-position: outside; list-style-type: none; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; margin-top: 12.960000038146973px; overflow-x: hidden; overflow-y: hidden; padding-bottom: 0px; padding-left: 0px; padding-right: 0px; padding-top: 0px; text-align: right; text-overflow: ellipsis; vertical-align: baseline; white-space: nowrap;";
	const QString m_backgroundDown = "background-color: rgba(221, 68, 0, 0.0980392);";
	const QString m_backgroundUp = "";
};

#endif // QUPDOWNIOCHECK_H
