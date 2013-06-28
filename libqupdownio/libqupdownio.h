#ifndef LIBQUPDOWNIO_H
#define LIBQUPDOWNIO_H

#include "libqupdownio_global.h"
#include "check.h"
#include "checkerror.h"
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QVariantMap>
#include "qjson/parser.h"
#include <QList>

class LIBQUPDOWNIOSHARED_EXPORT Qupdownio: public QObject
{
    Q_OBJECT
public:
	explicit Qupdownio(QObject *parent = 0, const QString& p_apiKey=QString());
	~Qupdownio();
	void setApiKey(const QString& p_apiKey);
	const QString& apiKey();
public slots:
    /*!
      List all your checks.
      On updown.io it corresponds to :
      GET /api/checks
      \return This method returns nothing but emit the checksFinished(QList<Qupdownio::Check*>) signal
     */
    void checks();
    /*!
      Get all the downtimes of a check.
      On updown.io it corresponds to :
      GET /api/checks/:token/downtimes
      \param p_token The check unique token
      \param p_pages The page to fetch (100 per page)
      \return This method returns nothing but emit the downtimesFinished(const QString& p_token, QList<Qupdownio::Check*>) signal
     */
    void downtimes(const QString& p_token,const int& p_page=1);
    /*!
      Add a new check.
      On updown.io it corresponds to :
      POST /api/checks
      \param p_url The URL you want to monitor
      \param p_period Interval in seconds (30, 60, 120, 300 or 600)
      \param p_published Shall the status page be public (true or false)
      \return This method returns nothing but emit the checkAdded(const QString& p_token, Qupdownio::Check) signal
     */
    void addCheck(const QString& p_url, const int& p_period=60, const bool& p_published=false);
    /*!
      Update a check.
      On updown.io it corresponds to :
      PUT /api/checks/:token
      \param p_token The check unique token
      \param p_url The URL you want to monitor
      \param p_period Interval in seconds (30, 60, 120, 300 or 600)
      \param p_published Shall the status page be public (true or false)
      \return This method returns nothing but emit the checkUpdated(Qupdownio::Check) signal
     */
    void updateCheck(const QString& p_token,const QString& p_url, const int& p_period=60, const bool& p_published=false);
    /*!
      Delete a check.
      On updown.io it corresponds to :
      DELETE /api/checks/:token
      \param p_token The check unique token
      \return This method returns nothing but emit the deleteFinished(const QString& p_token, const bool deleted) signal
     */
    void deleteCheck(const QString& p_token);
    void setProxy(const QNetworkProxy &p_proxy);
signals:
    /*!
     * \brief checksFinished is emitted after a reply to a checks() call is available.
     */
    void checksFinished(QList<LibQupdownio::Check*>);
    /*!
     * \brief downtimesFinished is emitted after a reply to a downtimes() call is available.
     */
    void downtimesFinished(QList<LibQupdownio::CheckError*>);
    /*!
      * \breif deleteCheckFinished is emitted after a reply to a deleteCheck() call is available.
      */
    void deleteCheckFinished(bool status, QString message);
    /*!
     * \brief updateCheckFinished is emitted after a reply to a updateCheck() call is available.
     */
    void updateCheckFinished(LibQupdownio::Check*);
    /*!
     * \brief addCheckFinished is emitted after a reply to a addCheck() call is available.
     */
    void addCheckFinished(LibQupdownio::Check*);
private slots:
	void requestFinished(QNetworkReply*);
protected:
	QVariantMap replyToJson(QNetworkReply*);
private:
    QString m_apiKey;
    QString m_baseUrl;
    QNetworkAccessManager *m_networkManager;
    QJson::Parser *m_parser;

};

#endif // LIBQUPDOWNIO_H
