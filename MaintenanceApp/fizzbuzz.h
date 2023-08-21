#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

#include "qqmlintegration.h"
#include <QObject>

class fizzbuzz : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QList<QString> list READ list WRITE setList NOTIFY listChanged)
	QML_ELEMENT
public:
	explicit fizzbuzz(QObject *parent = nullptr);
	QList<QString> list();
	Q_INVOKABLE QList<QString> generateList(const int iLimit);
	void setList(const QList<QString> &iLimit);
signals:
	void listChanged();

private:
	QList<QString> m_listOfFizzBuzzElements;
//	QList<QString> generateList(int iLimit = 0);


};

#endif // FIZZBUZZ_H
