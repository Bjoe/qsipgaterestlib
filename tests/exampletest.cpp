
#include <QtTest>

#include "testconfig.h"
#include "database/databaseutil.h"

#include "testcoverageobject.h"

class ExampleTest : public qttestutil::TestCoverageObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void testExample();
};

void ExampleTest::initTestCase()
{
    qttestutil::database::DatabaseUtil database(DATABASEDRIVER);
    database.open(DATABASE);
    database.read(SQLTESTFILE);
}

void ExampleTest::testExample()
{
    QVERIFY(true);
}

QTEST_MAIN(ExampleTest)
#include "moc_exampletest.cpp"
