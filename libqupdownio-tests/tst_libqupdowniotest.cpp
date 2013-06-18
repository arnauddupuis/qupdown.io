#include <QString>
#include <QtTest>

class LibqupdownioTest : public QObject
{
    Q_OBJECT
    
public:
    LibqupdownioTest();
    
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
};

LibqupdownioTest::LibqupdownioTest()
{
}

void LibqupdownioTest::initTestCase()
{
}

void LibqupdownioTest::cleanupTestCase()
{
}

void LibqupdownioTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(LibqupdownioTest)

#include "tst_libqupdowniotest.moc"
