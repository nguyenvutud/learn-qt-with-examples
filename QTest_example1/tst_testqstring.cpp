#include <QtTest>
#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>

// add necessary includes here

class testQString : public QObject
{
    Q_OBJECT

public:
    testQString();
    ~testQString();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

testQString::testQString()
{

}

testQString::~testQString()
{

}

void testQString::initTestCase()
{

}

void testQString::cleanupTestCase()
{

}

void testQString::test_case1()
{
    QString str = "hello";
    QCOMPARE(str.toUpper(), "HELLO");
}

QTEST_MAIN(testQString)

#include "tst_testqstring.moc"
