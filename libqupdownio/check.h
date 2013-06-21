#ifndef CHECK_H
#define CHECK_H

#include <QObject>
#include <QDateTime>
#include <QUrl>

namespace LibQupdownio {

	class Check : public QObject
	{
		Q_OBJECT
		Q_PROPERTY(bool down READ down WRITE setDown)
		Q_PROPERTY(QDateTime downSince READ downSince WRITE setDownSince)
		Q_PROPERTY(bool enabled READ enabled WRITE setEnabled)
		Q_PROPERTY(QString error READ error WRITE setError)
		Q_PROPERTY(QDateTime lastCheckAt READ lastCheckAt WRITE setLastCheckAt)
		Q_PROPERTY(QDateTime nextCheckAt READ nextCheckAt WRITE setNextCheckAt)
		Q_PROPERTY(int period READ period WRITE setPeriod)
		Q_PROPERTY(bool published READ published WRITE setPublished)
		Q_PROPERTY(QString token READ token WRITE setToken)
		Q_PROPERTY(qint64 uptime READ uptime WRITE setUptime)
		Q_PROPERTY(QUrl url READ url WRITE setUrl)


	public:
		/*!
		Constructs a new Check object.
		*/
		explicit Check(QObject *parent = 0);

	    // Getters

		/*!
		If true the check failed.
		\return m_down as a bool
		*/
		bool down() ;


		/*!
		Get the date since when the url is down.
		\return m_downSince as a QDateTime
		*/
		QDateTime downSince() ;


		/*!
		If true the check is enabled otherwise disabled.
		\return m_enabled as a bool
		*/
		bool enabled() ;


		/*!
		Get the error string of a check.
		\return m_error as a QString
		*/
		QString error() ;


		/*!
		Get the date of the last check.
		\return m_lastCheckAt as a QDateTime
		*/
		QDateTime lastCheckAt() ;


		/*!
		Get the date of the next check.
		\return m_nextCheckAt as a QDateTime
		*/
		QDateTime nextCheckAt() ;


		/*!
		Get the period between 2 checks.
		\return m_period as a int
		*/
		int period() ;


		/*!
		If true the check is publicly available to everyone, if false the check is private.
		\return m_published as a bool
		*/
		bool published() ;


		/*!
		Get the token of the check.
		\return m_token as a QString
		*/
		QString token() ;


		/*!
		Get the uptime of the check.
		\return m_uptime as a qint64
		*/
		qint64 uptime() ;


		/*!
		Get the url of the check.
		\return m_url as a QUrl
		*/
		QUrl url() ;



	private:
	    // Member variables
		bool m_down;
		QDateTime m_downSince;
		bool m_enabled;
		QString m_error;
		QDateTime m_lastCheckAt;
		QDateTime m_nextCheckAt;
		int m_period;
		bool m_published;
		QString m_token;
		qint64 m_uptime;
		QUrl m_url;


	signals:
		void downChanged(const bool & p_down);
		void downSinceChanged(const QDateTime & p_downSince);
		void enabledChanged(const bool & p_enabled);
		void errorChanged(const QString & p_error);
		void lastCheckAtChanged(const QDateTime & p_lastCheckAt);
		void nextCheckAtChanged(const QDateTime & p_nextCheckAt);
		void periodChanged(const int & p_period);
		void publishedChanged(const bool & p_published);
		void tokenChanged(const QString & p_token);
		void uptimeChanged(const qint64 & p_uptime);
		void urlChanged(const QUrl & p_url);


	public slots:

		/*!
		If true the check failed.
		*/
		void setDown(const bool & p_down) ;


		/*!
		Set the date since when the url is down.
		*/
		void setDownSince(const QDateTime & p_downSince) ;


		/*!
		If true the check is enabled otherwise disabled.
		*/
		void setEnabled(const bool & p_enabled) ;


		/*!
		Set the error string of a check.
		*/
		void setError(const QString & p_error) ;


		/*!
		Set the date of the last check.
		*/
		void setLastCheckAt(const QDateTime & p_lastCheckAt) ;


		/*!
		Set the date of the next check.
		*/
		void setNextCheckAt(const QDateTime & p_nextCheckAt) ;


		/*!
		Set the period between 2 checks.
		*/
		void setPeriod(const int & p_period) ;


		/*!
		If true the check is publicly available to everyone, if false the check is private.
		*/
		void setPublished(const bool & p_published) ;


		/*!
		Set the token of the check.
		*/
		void setToken(const QString & p_token) ;


		/*!
		Set the uptime of the check.
		*/
		void setUptime(const qint64 & p_uptime) ;


		/*!
		Set the url of the check.
		*/
		void setUrl(const QUrl & p_url) ;




	};

}

#endif // CHECK_H
