/**
 * This file is part of EasyLogging++ samples
 * Demonstration of multithreaded application in C++ (Qt)
 *
 * Compile this program using Qt
 *    qmake qt-sample.pro && make
 *
 * Revision: 1.1
 * @author mkhan3189
 */

#include "mythread.h"
#include "easylogging++.h"

_INITIALIZE_EASYLOGGINGPP

int main(int argc, char* argv[]) {
    _START_EASYLOGGINGPP(argc, argv)

    bool runThreads = true;

    if (runThreads) {
        for (int i = 1; i <= 1; ++i) {
            MyThread t(i);
            t.start();
            t.wait();
        }
    }

    QVector<QString> stringList;
    stringList.push_back (QString("Test"));
    stringList.push_back (QString("Test 2"));
    LINFO << stringList;

    QPair<QString, int> qpair_;
    qpair_.first = "test";
    qpair_.second = 2;
    LINFO << qpair_;

    QMap<QString, int> qmap_;
    qmap_.insert ("john", 100);
    qmap_.insert ("michael", 101);
    LINFO << qmap_;

    QMultiMap<QString, int> qmmap_;
    qmmap_.insert ("john", 100);
    qmmap_.insert ("michael", 101);
    LINFO << qmmap_;

    QSet<QString> qset_;
    qset_.insert ("test");
    qset_.insert ("second");
    LINFO << qset_;

    QVector<QString*> ptrList;
    ptrList.push_back (new QString("Test"));
    LINFO << ptrList;
    qDeleteAll(ptrList);

    QHash<QString, QString> qhash_;
    qhash_.insert ("john", "101fa");
    qhash_.insert ("michael", "102mf");
    LINFO << qhash_;

    QLinkedList<QString> qllist_;
    qllist_.push_back ("test");
    qllist_.push_back ("test 2");
    LINFO << qllist_ ;

    QStack<QString> qstack_;
    qstack_.push ("100");
    qstack_.push ("200");
    qstack_.push ("100");
    LINFO << "Printing qstack " << qstack_;

    return 0;

}