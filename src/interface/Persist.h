#pragma once
#ifndef INCLUDED_PERSIST_H
#define INCLUDED_PERSIST_H
#include <QDataStream>
#include <QGraphicsItem>
#include <QFileDialog>

class Persist : public QDataStream
{
//public:
//   Persist(QFile file) : QDataStream(&file) {}
//
//   QDataStream& operator<< (QGraphicsItem& item);
};

#endif
