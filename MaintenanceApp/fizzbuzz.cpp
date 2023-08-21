#include "fizzbuzz.h"

fizzbuzz::fizzbuzz(QObject *parent)
	: QObject{parent}
{

}

QList<QString> fizzbuzz::list() {
	return m_listOfFizzBuzzElements;
}

QList<QString> fizzbuzz::generateList(const int iLimit)
{
	QList<QString> listOfValues;
	for (int i = 1; i <= iLimit; i++) {
		QString strIndexString = "";
		if ((i % 3) == 0) {
			strIndexString += "fizz";
		}
		if ((i % 5) == 0) {
			strIndexString += "buzz";
		}
		if (strIndexString == "") {
			strIndexString = QString::number(i);
		}
		listOfValues.append(strIndexString);

	}
	return listOfValues;
}

void fizzbuzz::setList(const QList<QString> &list)
{
	m_listOfFizzBuzzElements = list;
	emit listChanged();
}
