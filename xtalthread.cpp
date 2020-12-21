#include "xtalthread.h"
#include "toolbox.h"
#include "configurationdialog.h"
#include <QtCore>
#include <QDebug>

xtalThread::xtalThread()
{

}

//xtalThread::~xtalThread()
//{

//}

void xtalThread::run()
{
    QMutex mutex;
    qDebug() << "DEBUG: start XTAL thread";
    QProcess XTALS;
    XTALS.setProcessChannelMode(QProcess::MergedChannels);
    XTALS.start(pathToXTAL, argToRunXTAL);
    while (XTALS.waitForReadyRead()) {
        singleLine = XTALS.readLine();
        mutex.lock();
        emit newLineSignal(singleLine);
        mutex.unlock();
        qDebug() << singleLine;
        msleep(10);
        if (killThreadFlag) {
          XTALS.kill();
          killThreadFlag = false;
          newLineSignal("SIGKILL send to xtal thread");
          return;
        }
    }
    XTALS.waitForFinished();
    qDebug() << "DEBUG: emit endSignal";
    mutex.lock();
    emit endSignal(100);
    mutex.unlock();
}

void xtalThread::setArg(QStringList arg)
{
    qDebug() << "DEBUG: set args for XTAL thread";
    argToRunXTAL = arg;
}

void xtalThread::stopThreadSlot(bool stopFlag)
{
    qDebug() << "DEBUG: stopThread SLOT";
    killThreadFlag = stopFlag;
}
