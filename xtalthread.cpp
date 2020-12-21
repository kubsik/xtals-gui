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
    qDebug() << "DEBUG: start XTAL thread";
    QProcess XTALS;
    XTALS.setProcessChannelMode(QProcess::MergedChannels);
    XTALS.start(pathToXTAL, argToRunXTAL);
    while (XTALS.waitForReadyRead()) {
        singleLine = XTALS.readLine();
        emit newLineSignal(singleLine);
        qDebug() << "DEBUG: " << singleLine;
    }
    XTALS.waitForFinished();
}

void xtalThread::setArg(QStringList arg)
{
    qDebug() << "DEBUG: set args for XTAL thread";
    argToRunXTAL = arg;
}
