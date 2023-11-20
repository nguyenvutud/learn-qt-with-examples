#include <QtTest>
#include <QtWidgets>


// add necessary includes here

class replaying_event : public QObject
{
    Q_OBJECT

public:
    replaying_event();
    ~replaying_event();

private slots:
    void testGui_data();
    void testGui();

};

replaying_event::replaying_event()
{

}

replaying_event::~replaying_event()
{

}

void replaying_event::testGui_data()
{
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<QString>("expected");

    QTestEventList list1;
    list1.addKeyClick('a');
    QTest::newRow("char") << list1 << "a";

    QTestEventList list2;
    list2.addKeyClick('a');
    list2.addKeyClick(Qt::Key_Backspace);
    QTest::newRow("there+back-again") << list2 << "";


}

void replaying_event::testGui()
{
    QFETCH(QTestEventList, events);
    QFETCH(QString, expected);

    QLineEdit lineEdit;

    events.simulate(&lineEdit);

    QCOMPARE(lineEdit.text(), expected);
}

QTEST_MAIN(replaying_event)

#include "tst_replaying_event.moc"
