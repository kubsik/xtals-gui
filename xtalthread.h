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
signals:
    QString newLineSignal(QString singleLine);
};

#endif // XTALTHREAD_H
