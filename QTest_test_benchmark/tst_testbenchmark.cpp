#include <QtTest>
#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>
#include <QtWidgets>

// add necessary includes here

class TestBenchmark : public QObject
{
    Q_OBJECT

public:
    TestBenchmark();
    ~TestBenchmark();

private slots:
    void simple();

    void multiple_data();
    void multiple();
    void series_data();
    void series();
};

TestBenchmark::TestBenchmark()
{

}

TestBenchmark::~TestBenchmark()
{

}

void TestBenchmark::simple()
{
    QString str1 = QLatin1String("This is a test string");
    QString str2 = QLatin1String("This is a test string");

    QCOMPARE(str1.localeAwareCompare(str2), 0);

    QBENCHMARK {
        str1.localeAwareCompare(str2);
    }
}

void TestBenchmark::multiple_data()
{
    QTest::addColumn<bool>("useLocaleCompare");
    QTest::newRow("locale aware compare") << true;
    QTest::newRow("standard compare") << false;
}

void TestBenchmark::multiple()
{
    QFETCH(bool, useLocaleCompare);
    QString str1 = QLatin1String("This is a test string");
    QString str2 = QLatin1String("This is a test string");

    int result;
    if (useLocaleCompare) {
        QBENCHMARK {
            result = str1.localeAwareCompare(str2);
        }
    } else {
        QBENCHMARK {
            result = (str1 == str2);
        }
    }
    Q_UNUSED(result);
}

void TestBenchmark::series_data()
{
    QTest::addColumn<bool>("useLocaleCompare");
    QTest::addColumn<int>("stringSize");

    for (int i = 1; i < 10000; i += 2000) {
        QTest::addRow("locale-aware-compare:%d", i) << true << i;
        QTest::addRow("standard-compare:%d", i) << false << i;
    }
}

void TestBenchmark::series()
{
    QFETCH(bool, useLocaleCompare);
    QFETCH(int, stringSize);

    QString str1 = QString().fill('A', stringSize);
    QString str2 = QString().fill('A', stringSize);
    int result;
    if (useLocaleCompare) {
        QBENCHMARK {
            result = str1.localeAwareCompare(str2);
        }
    } else {
        QBENCHMARK {
            result = (str1 == str2);
        }
    }
    Q_UNUSED(result);
}

QTEST_MAIN(TestBenchmark)

#include "tst_testbenchmark.moc"
