#include "libqupdownio.h"
#include <QDebug>


Qupdownio::Qupdownio(QObject *parent, const QString &p_apiKey) : QObject(parent),m_apiKey(p_apiKey),m_baseUrl("https://updown.io/api")
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
	//	qDebug() << "Qupdownio::downtimes: URL=" << m_baseUrl+"/checks/"+p_token+"/downtimes?api-key="+m_apiKey+"&page="+QString::number(p_page) ;
	m_networkManager->get( QNetworkRequest( QUrl( m_baseUrl+"/checks/"+p_token+"/downtimes?api-key="+m_apiKey+"&page="+QString::number(p_page) ) ) );
}

void Qupdownio::addCheck(const QString &p_url, const int &p_period, const bool &p_published){
	QByteArray ba;
	QUrl t_url(p_url);
	ba.append( "url="+t_url.toEncoded() );
	ba.append( ";period="+QString::number(p_period) );
	if( p_published )
		ba.append( ";published=true" );
	else
		ba.append( ";published=false" );
	QNetworkRequest t_request( QUrl( m_baseUrl+"/checks?api-key="+m_apiKey ) );
	t_request.setHeader(QNetworkRequest::ContentTypeHeader	,"application/x-www-form-urlencoded");
	m_networkManager->post( t_request, ba );
}

void Qupdownio::updateCheck(const QString &p_token, const QString &p_url, const int &p_period, const bool &p_published){
	QByteArray ba;
	QUrl t_url(p_url);
	ba.append( "url="+t_url.toEncoded() );
	ba.append( ";period="+QString::number(p_period) );
	if( p_published )
		ba.append( ";published=true" );
	else
		ba.append( ";published=false" );
	QNetworkRequest t_request( QUrl( m_baseUrl+"/checks/"+p_token+"?api-key="+m_apiKey ) );
	t_request.setHeader(QNetworkRequest::ContentTypeHeader	,"application/x-www-form-urlencoded");
	m_networkManager->put( t_request, ba );
}

void Qupdownio::deleteCheck(const QString &p_token){
	QNetworkRequest t_request( QUrl( m_baseUrl+"/checks/"+p_token+"?api-key="+m_apiKey ) );
	t_request.setHeader(QNetworkRequest::ContentTypeHeader	,"application/x-www-form-urlencoded");
	m_networkManager->deleteResource( t_request );
}

void Qupdownio::requestFinished(QNetworkReply *p_reply){
	QString json = p_reply->readAll();
	QNetworkRequest request = p_reply->request();
//	qDebug() << "Qupdownio::requestFinished : URL path = " << request.url().path();
//	qDebug() << "Qupdownio::requestFinished : raw JSON = " << json ;
//	qDebug() << "Qupdownio::requestFinished : reply operation = " << p_reply->operation() << "\n\n";
	bool ok = false;
	QVariant result = m_parser->parse(json.toUtf8(), &ok);
	//	qDebug() << "Qupdownio::requestFinished : result=" << result << "\n\n";
	if(ok && !result.isNull()){
		if( p_reply->operation() == QNetworkAccessManager::GetOperation && request.url().path() == "/api/checks" ){
			QList<LibQupdownio::Check*> checksList;
			foreach (QVariant v, result.toList()){
				QVariantMap map = v.toMap();
				LibQupdownio::Check *check = new LibQupdownio::Check(this);
				check->setToken( map.value("token").toString() );
				check->setDown( map.value("down").toBool() );
				check->setDownSince( map.value("down_since").toDateTime() );
				check->setEnabled( map.value("enabled").toBool() );
				check->setError( map.value("error").toString() );
				check->setLastCheckAt( map.value("last_check_at").toDateTime() );
				check->setNextCheckAt( map.value("next_check_at").toDateTime() );
				check->setPeriod( map.value("period").toInt() );
				check->setPublished( map.value("published").toBool() );
				check->setUptime( map.value("uptime").toDouble() );
				check->setUrl( map.value("url").toUrl() );
				checksList.append(check);
			}
			emit( checksFinished( checksList ) );
		}
		else if( request.url().path().endsWith("/downtimes") ){
			QList<LibQupdownio::CheckError*> downtimesList;
			foreach (QVariant v, result.toList()){
				QVariantMap map = v.toMap();
				LibQupdownio::CheckError *checkerror = new LibQupdownio::CheckError(this);
				checkerror->setDuration( map.value("duration").toDouble() );
				checkerror->setError( map.value("error").toString() );
				checkerror->setStartedAt( map.value("started_at").toDateTime() );
				checkerror->setEndedAt( map.value("ended_at").toDateTime() );
				downtimesList.append(checkerror);
			}
			emit( downtimesFinished(downtimesList) );
		}
		else if( p_reply->operation() == QNetworkAccessManager::DeleteOperation ){
			QVariantMap map = result.toMap();
			if(map.contains("deleted") ){
				if(map.value("deleted").toString() == "true"){
					emit( deleteCheckFinished(true, QString("Check successfully deleted.") ) );
				}
				else{
					emit( deleteCheckFinished(false, QString("Error while deleting check.") ) );
				}
			}
			else if( map.contains("error") ){
				emit( deleteCheckFinished(false, map.value("error").toString() ) );
			}
		}
		else if( p_reply->operation() == QNetworkAccessManager::PutOperation || p_reply->operation() == QNetworkAccessManager::PostOperation ){
			QVariantMap map = result.toMap();
			LibQupdownio::Check *check = new LibQupdownio::Check(this);
			check->setToken( map.value("token").toString() );
			check->setDown( map.value("down").toBool() );
			check->setDownSince( map.value("down_since").toDateTime() );
			check->setEnabled( map.value("enabled").toBool() );
			check->setError( map.value("error").toString() );
			check->setLastCheckAt( map.value("last_check_at").toDateTime() );
			check->setNextCheckAt( map.value("next_check_at").toDateTime() );
			check->setPeriod( map.value("period").toInt() );
			check->setPublished( map.value("published").toBool() );
			check->setUptime( map.value("uptime").toDouble() );
			check->setUrl( map.value("url").toUrl() );
			if( p_reply->operation() == QNetworkAccessManager::PutOperation )
				emit( updateCheckFinished(check) );
			else
				emit( addCheckFinished(check) );
		}
	}
}

