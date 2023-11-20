//
// Created by Vu Nguyen on July 7, 2022.
//
#include "read_write_json.h"
#include <QDebug>
#include <QDir>

void ReadWriteJson::readJson()
{
    QString val;
    QFile file;
    //QDir::homePath() + "filename.json" //in case you want to get home dir
    file.setFileName("json/test.json");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "File open error";
    }
    else {
        qDebug() << "File is open";
    }
    //Clear the original content in the file
    //file.resize(0);

    val = file.readAll();
    file.close();
    qDebug() << val;
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = doc.object();
    QJsonValue value = sett2.value(QString("appName"));
    qDebug() << value;

    QJsonObject item = value.toObject();
    qDebug() << QObject::tr("QJsonObject of description:") << item;

    //in case of string value get value and convert into string
    qWarning() << QObject::tr("QJsonObject[appName] of description: ") << item["description"];
    QJsonValue subobj = item["description"];
    qWarning() << subobj.toString();

    //in case of array, get array and convert into string
    qWarning() << QObject::tr("QJsonObject[appName] of value: ") << item["imp"];
    QJsonArray jarray = item["imp"].toArray();
    for(int i=0; i < jarray.size(); i++)
    {
        qWarning() << jarray[i].toString();
    }

}

void ReadWriteJson::writeJson()
{
    QFile file(QDir::homePath() + "/1.json");
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "Can't open file!";
    }
    else
    {
        qDebug() << "File is open!";
    }
    //Clear the original content in the file
    file.resize(0);

    //Add value using QJsonArray and write to a json file
    QJsonArray jsonArray;

    for(int i = 0; i < 10; i++)
    {
        QJsonObject jsonObj;
        jsonObj.insert("Date", "19.07.2017");
        jsonObj.insert("Band", "5");
        QJsonObject jsonLat;
        jsonLat.insert("Lat", "2132.3232");
        jsonLat.insert("Lon", "34234.3232");
        jsonLat.insert("Sender", "ACD234");

        QJsonObject jsonLatRec;
        jsonLatRec.insert("Lat", "342432.43242");
        jsonLatRec.insert("Lon", "342432.43242");
        jsonLatRec.insert("Receiver", "DEF324");

        jsonObj.insert("Sender", jsonLat);
        jsonObj.insert("Receiver", jsonLatRec);
        jsonArray.append(jsonObj);

    }
    QJsonObject jsonObject;
    jsonObject.insert("number", jsonArray.size());
    jsonArray.append(jsonObject);

    QJsonDocument jsonDoc;
    jsonDoc.setArray(jsonArray);
    file.write(jsonDoc.toJson());
    file.close();
    qDebug() << "Write to file";
}
