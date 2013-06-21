#include "check.h"

namespace LibQupdownio {
	Check::Check(QObject *parent) :
	    QObject(parent),m_downSince(),m_error(),m_lastCheckAt(),m_nextCheckAt(),m_token(),m_url()
	{
		m_period = 0;
		m_uptime = 0;

	}

	// Setters (slots)
	void Check::setDown(const bool & p_down) {
		m_down=p_down;
		emit(downChanged(m_down));
	}

	void Check::setDownSince(const QDateTime & p_downSince) {
		m_downSince=p_downSince;
		emit(downSinceChanged(m_downSince));
	}

	void Check::setEnabled(const bool & p_enabled) {
		m_enabled=p_enabled;
		emit(enabledChanged(m_enabled));
	}

	void Check::setError(const QString & p_error) {
		m_error=p_error;
		emit(errorChanged(m_error));
	}

	void Check::setLastCheckAt(const QDateTime & p_lastCheckAt) {
		m_lastCheckAt=p_lastCheckAt;
		emit(lastCheckAtChanged(m_lastCheckAt));
	}

	void Check::setNextCheckAt(const QDateTime & p_nextCheckAt) {
		m_nextCheckAt=p_nextCheckAt;
		emit(nextCheckAtChanged(m_nextCheckAt));
	}

	void Check::setPeriod(const int & p_period) {
		m_period=p_period;
		emit(periodChanged(m_period));
	}

	void Check::setPublished(const bool & p_published) {
		m_published=p_published;
		emit(publishedChanged(m_published));
	}

	void Check::setToken(const QString & p_token) {
		m_token=p_token;
		emit(tokenChanged(m_token));
	}

	void Check::setUptime(const qint64 & p_uptime) {
		m_uptime=p_uptime;
		emit(uptimeChanged(m_uptime));
	}

	void Check::setUrl(const QUrl & p_url) {
		m_url=p_url;
		emit(urlChanged(m_url));
	}



	// Getters
	bool Check::down() {
		return m_down;
	}

	QDateTime Check::downSince() {
		return m_downSince;
	}

	bool Check::enabled() {
		return m_enabled;
	}

	QString Check::error() {
		return m_error;
	}

	QDateTime Check::lastCheckAt() {
		return m_lastCheckAt;
	}

	QDateTime Check::nextCheckAt() {
		return m_nextCheckAt;
	}

	int Check::period() {
		return m_period;
	}

	bool Check::published() {
		return m_published;
	}

	QString Check::token() {
		return m_token;
	}

	qint64 Check::uptime() {
		return m_uptime;
	}

	QUrl Check::url() {
		return m_url;
	}



} // eof
