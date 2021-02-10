#ifndef TOOLBOX_H
#define TOOLBOX_H

#include "configurationdialog.h"
#include "xtalthread.h"
#include <QFrame>
#include <QProcess>
#include <QToolBox>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QFileDialog>
#include <QTextEdit>

class ToolBox : public QFrame
{
    Q_OBJECT

public:
    explicit ToolBox(QWidget *parent = 0);
    QString pathToXTAL = "xtals";
    QString pathToConfiguration;
    ~ToolBox();
//    xtalThread *xtalInstance;
    int theIterator = 0;

public slots:
    void setPathToConfiguration(QString pathToConfiguration);
    void loadConfigFromFile();
    void createConfigFile();
    void verifyXTALSversion();
    void runXTALS();
    void onNewLine(QString);
    void onEnd(int);
    void stopXTALS();
signals:
    bool stopThreadSignal(bool);
private:
    QToolBox *toolBox;
    QProcess *XTALS;
    QStringList argToRunXTALversion;
    QStringList newArgToRunXTAL;
    QWidget *configurationWidget;
    QWidget *optionsWidget;
    QWidget *processWidget;
    QVBoxLayout *configurationLayout;
    QVBoxLayout *processLayout;
    QVBoxLayout *optionsLayout;
    QFrame *optionsFrame;
    QPushButton *createConfig;
    QPushButton *loadConfig;
    QLineEdit *configPathLine;
    QPushButton *runProcessing;
    QPushButton *stopProcessing;
    QTextEdit *terminalText;
    QCheckBox *exportChBox;
    QCheckBox *signalChBox;
    QCheckBox *integrateChBox;
    QCheckBox *geometryChBox;
    QCheckBox *dumpChBox;
    QProgressBar *progressBar;
    ConfigurationDialog *confDialog;
};
#endif // TOOLBOX_H
