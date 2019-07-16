#include "networktest.h"

networktest::networktest(QObject *parent) : QObject(parent)
{

}

QString networktest::getNames()
{
    QNetworkConfigurationManager manager;
    QList<QNetworkConfiguration> localAllConfigurations = manager.allConfigurations();
    QString result = " ";
    Q_FOREACH(QNetworkConfiguration conf, localAllConfigurations){
         QString localIdentifier = conf.identifier();
         QString localName = conf.name();
         result = result % " | " % localName % " - " % conf.bearerTypeName();
         QNetworkConfiguration::Type localType = conf.type();

    }

    return result;
}
