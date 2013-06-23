#include "checkerror.h"

namespace LibQupdownio {
    CheckError::CheckError(QObject *parent) :
        QObject(parent),m_endedAt(),m_error(),m_startedAt()
    {
            m_duration = 0;

    }

    // Setters (slots)
    void CheckError::setDuration(const qint64 & p_duration) {
        m_duration=p_duration;
        emit(durationChanged(m_duration));
    }

    void CheckError::setEndedAt(const QDateTime & p_endedAt) {
        m_endedAt=p_endedAt;
        emit(endedAtChanged(m_endedAt));
    }

    void CheckError::setError(const QString & p_error) {
        m_error=p_error;
        emit(errorChanged(m_error));
    }

    void CheckError::setStartedAt(const QDateTime & p_startedAt) {
        m_startedAt=p_startedAt;
        emit(startedAtChanged(m_startedAt));
    }



    // Getters
    qint64 CheckError::duration() {
        return m_duration;
    }

    QDateTime CheckError::endedAt() {
        return m_endedAt;
    }

    QString CheckError::error() {
        return m_error;
    }

    QDateTime CheckError::startedAt() {
        return m_startedAt;
    }

}
