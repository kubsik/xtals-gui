#ifndef XTALTHREAD_H
#define XTALTHREAD_H
#include <QtCore>


class xtalThread :public QThread
{
public:
    xtalThread();
    void run();
    void setArg(QStringList argToRunXTAL);
private:
    QString pathToXTAL = "xtals";
    QStringList argToRunXTAL;
};

#endif // XTALTHREAD_H
