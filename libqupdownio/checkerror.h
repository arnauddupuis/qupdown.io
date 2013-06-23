#ifndef CHECKERROR_H
#define CHECKERROR_H

#include <QObject>
#include <QDateTime>
#include <QString>

namespace LibQupdownio {

    class CheckError : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(qint64 duration READ duration WRITE setDuration)
        Q_PROPERTY(QDateTime endedAt READ endedAt WRITE setEndedAt)
        Q_PROPERTY(QString error READ error WRITE setError)
        Q_PROPERTY(QDateTime startedAt READ startedAt WRITE setStartedAt)


    public:
        /*!
        Constructs a new CheckError object.
        */
        explicit CheckError(QObject *parent = 0);

        // Getters

        /*!
        Get the duration this check was in error.
        \return m_duration as a qint64
        */
        qint64 duration() ;


        /*!
        Get the date and time of the end of the error.
        \return m_endedAt as a QDateTime
        */
        QDateTime endedAt() ;


        /*!
        Get the check error string.
        \return m_error as a QString
        */
        QString error() ;


        /*!
        Get the date and time since when the check is in error.
        \return m_startedAt as a QDateTime
        */
        QDateTime startedAt() ;



    private:
        // Member variables
            qint64 m_duration;
        QDateTime m_endedAt;
        QString m_error;
        QDateTime m_startedAt;


    signals:
            void durationChanged(const qint64 & p_duration);
        void endedAtChanged(const QDateTime & p_endedAt);
        void errorChanged(const QString & p_error);
        void startedAtChanged(const QDateTime & p_startedAt);


    public slots:

        /*!
        Set the duration this check was in error.
        */
        void setDuration(const qint64 & p_duration) ;


        /*!
        Set the date and time of the end of the error.
        */
        void setEndedAt(const QDateTime & p_endedAt) ;


        /*!
        Set the check error string.
        */
        void setError(const QString & p_error) ;


        /*!
        Set the date and time since when the check is in error.
        */
        void setStartedAt(const QDateTime & p_startedAt) ;



    };

}
#endif // CHECKERROR_H
