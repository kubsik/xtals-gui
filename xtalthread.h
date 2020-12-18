#ifndef XTALTHREAD_H
#define XTALTHREAD_H
#include <QtCore>


class xtalThread :public QThread
{
public:
    xtalThread();
    QString pathToXTAL = "xtals";
    QStringList argToRunXTAL;
    void run();
    void setArg(QStringList argToRunXTAL);
};

#endif // XTALTHREAD_H
