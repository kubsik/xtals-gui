#ifndef XTALTHREAD_H
#define XTALTHREAD_H
#include <QtCore>


class xtalThread :public QThread
{
    Q_OBJECT
public:
    xtalThread();
    void run();
    void setArg(QStringList argToRunXTAL);
//    ~xtalThread();
private:
    QString pathToXTAL = "xtals";
    QStringList argToRunXTAL;
    QString singleLine;
    bool killThreadFlag = false;
signals:
    QString newLineSignal(QString singleLine);
    int endSignal(int);
public slots:
    void stopThreadSlot(bool stopFlag);
};


#endif // XTALTHREAD_H
