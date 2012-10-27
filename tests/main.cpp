#include "testgraph.hpp"

#include <QTest>

int main(int argc, char *argv[])
{
    TestGraph test1;
    QTest::qExec(&test1, argc, argv);
}
