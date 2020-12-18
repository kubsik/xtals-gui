#include "xtalthread.h"
#include "toolbox.h"
#include "configurationdialog.h"
#include <QtCore>
#include <QDebug>

xtalThread::xtalThread()
{

}

void xtalThread::run()
{
    qDebug() << "DEBUG: start XTAL thread";
    QProcess XTALS;
    XTALS.setProcessChannelMode(QProcess::MergedChannels);
    XTALS.start(pathToXTAL, argToRunXTAL);
    while (XTALS.waitForReadyRead()) {
        qDebug() << XTALS.readAll();
    }
    XTALS.waitForFinished();
}

void xtalThread::setArg(QStringList arg)
{
    qDebug() << "DEBUG: set args for XTAL thread";
    argToRunXTAL = arg;
}
