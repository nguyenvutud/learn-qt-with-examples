//
// Created by Vu Nguyen on July 7, 2022.
//
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#ifndef READ_WRITE_JSON_HPP
#define READ_WRITE_JSON_HPP
class ReadWriteJson{
public:
    void readJson();
    void writeJson();
};

#endif // READ_WRITE_JSON_HPP
