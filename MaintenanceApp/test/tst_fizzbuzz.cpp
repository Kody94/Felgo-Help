#include <QObject>
#include <QTest>
#include <QDebug>
#include "../fizzbuzz.h"

class TestFizzbuzz: public QObject
{
	Q_OBJECT
public:
	explicit TestFizzbuzz(QObject *parent = nullptr);
private slots:
	void testFizzBuzz();
};

TestFizzbuzz::TestFizzbuzz(QObject *parent) : QObject{parent}
{

}

void TestFizzbuzz::testFizzBuzz()
{
	// Invoke fizzbuzz::generateList() with an integer parameter
	// The function should return a QList of numbers up to the parameter
	// Each number in the QList that is divisible by 3 should be replaced by the string "fizz"
	// Each number in the QList that is divisible by 5 should be replaced by the string "buzz"
	// Each number in the QList that is divisible by both 3 and 5 should be replaced by the string "fizzbuzz"
	// Each number in the returned QList should be a QString
	//	generateList(15);
	//	>> ["1", "2", "fizz", "4", "buzz", "fizz", "7", "8", "fizz", "buzz", "11", "fizz", "13", "14", "fizzbuzz"]
	fizzbuzz myFizzbuzz;
	int iLimit = 15;
	QList<QString> listOfExpectedValues({"1", "2", "fizz", "4", "buzz", "fizz", "7", "8", "fizz", "buzz", "11", "fizz", "13", "14", "fizzbuzz"});
	QList<QString> listOfValuesToTest = myFizzbuzz.generateList(iLimit);
	QCOMPARE(listOfValuesToTest, listOfExpectedValues);
}

QTEST_MAIN(TestFizzbuzz)
#include "tst_fizzbuzz.moc"
