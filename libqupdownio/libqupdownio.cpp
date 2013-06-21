#include "libqupdownio.h"
#include <QDebug>


Qupdownio::Qupdownio(QObject *parent, const QString &p_apiKey) : QObject(parent),m_apiKey(p_apiKey),m_baseUrl("https://beta.updown.io/api")
{
	m_parser = new QJson::Parser();
	m_networkManager = new QNetworkAccessManager(this);
	connect(m_networkManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(requestFinished(QNetworkReply*)));
}

Qupdownio::~Qupdownio(){
	delete m_networkManager;
	delete m_parser;
}

QVariantMap Qupdownio::replyToJson(QNetworkReply *p_reply){
	QString json = p_reply->readAll();
    qDebug() << "Qupdownio::replyToJson : raw JSON = " << json << "\n\n";
	bool ok = false;
    QVariant result = m_parser->parse(json.toUtf8(), &ok);
    qDebug() << "Qupdownio::replyToJson : result=" << result << "\n\n";
    foreach (QVariant v, result.toList()){
        QVariantMap m = v.toMap();
        qDebug() << "Qupdownio::replyToJson : m = " << m << "\n\n";
    }

	if(ok){
		qDebug() << "Qupdownio::replyToJson : parsing successful";
        return result.toMap();
	}
	else{
		qDebug() << "Qupdownio::replyToJson : error while parsing : " << m_parser->errorString();
		return QVariantMap();
	}
}

void Qupdownio::setProxy(const QNetworkProxy &p_proxy){
	m_networkManager->setProxy(p_proxy);
}

void Qupdownio::setApiKey(const QString &p_apiKey){
	m_apiKey = p_apiKey;
}

const QString& Qupdownio::apiKey(){
	return m_apiKey;
}

void Qupdownio::checks(){
	m_networkManager->get( QNetworkRequest( QUrl( m_baseUrl+"/checks?api-key="+m_apiKey ) ) );
}

void Qupdownio::downtimes(const QString &p_token, const int &p_page){
	m_networkManager->get( QNetworkRequest( QUrl( m_baseUrl+"checks/"+p_token+"/downtimes?api-key="+m_apiKey+"&page="+p_page ) ) );
}

void Qupdownio::addCheck(const QString &p_url, const int &p_period, const bool &p_published){
	QByteArray ba;
	ba.append( "url="+p_url );
	ba.append( "period="+p_period );
	ba.append( "published="+p_published );
	m_networkManager->post( QNetworkRequest( QUrl( m_baseUrl+"checks?api-key="+m_apiKey ) ), ba );
}

void Qupdownio::updateCheck(const QString &p_token, const QString &p_url, const int &p_period, const bool &p_published){
    QByteArray ba;
    ba.append( "url="+p_url );
    ba.append( "period="+p_period );
    ba.append( "published="+p_published );
    m_networkManager->put( QNetworkRequest( QUrl( m_baseUrl+"checks/"+p_token+"?api-key="+m_apiKey ) ), ba );
}

void Qupdownio::deleteCheck(const QString &p_token){
    m_networkManager->deleteResource( QNetworkRequest( QUrl( m_baseUrl+"checks/"+p_token+"?api-key="+m_apiKey) ) );
}

void Qupdownio::requestFinished(QNetworkReply *p_reply){
	QString json = p_reply->readAll();
	QNetworkRequest request = p_reply->request();
	qDebug() << "Qupdownio::requestFinished : URL path = " << request.url().path();
	qDebug() << "Qupdownio::requestFinished : raw JSON = " << json << "\n\n";
	bool ok = false;
	QVariant result = m_parser->parse(json.toUtf8(), &ok);
	qDebug() << "Qupdownio::requestFinished : result=" << result << "\n\n";
	if(!result.isNull()){
		if( request.url().path() == "/api/checks" ){
			QList<LibQupdownio::Check*> checksList;
			foreach (QVariant v, result.toList()){
			    QVariantMap map = v.toMap();
			    LibQupdownio::Check *check = new LibQupdownio::Check(this);
//			    qDebug() << "Qupdownio::requestFinished : m = " << map << "\n\n";
			    // m =  QMap(("down", QVariant(bool, false) ) ( "down_since" ,  QVariant(, ) ) ( "enabled" ,  QVariant(bool, true) ) ( "error" ,  QVariant(, ) ) ( "last_check_at" ,  QVariant(QString, "2013-06-21 04:36:14 UTC") ) ( "next_check_at" ,  QVariant(QString, "2013-06-21 04:36:44 UTC") ) ( "period" ,  QVariant(qulonglong, 30) ) ( "published" ,  QVariant(bool, false) ) ( "token" ,  QVariant(QString, "63y4") ) ( "uptime" ,  QVariant(double, 99.997) ) ( "url" ,  QVariant(QString, "http://www.genymobile.com") ) )
			    check->setToken( map.value("token").toString() );
			    check->setDown( map.value("down").toBool() );
			    check->setDownSince( map.value("down_since").toDateTime() );
			    check->setEnabled( map.value("enabled").toBool() );
			    check->setError( map.value("error").toString() );
			    check->setLastCheckAt( map.value("last_check_at").toDateTime() );
//			    qDebug() << "Qupdownio::requestFinished : check->lastCheckAt() = " << check->lastCheckAt().toString("yyyy-MM-dd hh::mm::ss") << "\n\n";
			    check->setNextCheckAt( map.value("next_check_at").toDateTime() );
			    check->setPeriod( map.value("period").toInt() );
			    check->setPublished( map.value("published").toBool() );
			    check->setUptime( map.value("uptime").toDouble() );
			    check->setUrl( map.value("url").toUrl() );
			    checksList.append(check);
			}
			emit( checksFinished( checksList ) );
		}
	}
}

