#include <QtWidgets>
#include "toolbox.h"
#include "configurationdialog.h"

ToolBox::ToolBox(QWidget *parent) : QFrame(parent) {
//    setFixedSize(200,350); //default look better

    confDialog = new ConfigurationDialog(this);

    /* XTALS PROCESS
    * We are running process from "/usr/local/bin/xtals" via terminal.
    * It fails GUI (delete ToolBox instance) if binary of XTALS wasn't found.
    * If version of GUI is not compatibile with binary version of XTAL (1.0)
    * then it also kill that object.
    */

    QString pathToXTAL = "xtals";
    QStringList argToRunXTAL;
    argToRunXTAL << "--version";

    QProcess *XTALS = new QProcess(this);

    XTALS->setProcessChannelMode(QProcess::MergedChannels);
    XTALS->start(pathToXTAL, argToRunXTAL);

    if (!XTALS->waitForFinished()) {
        QMessageBox::information(this, tr("ERROR 1"),
            tr("Couldn't find XTALS in PATH"));
        exit (1);
    }

    QString presentXtalVersion = XTALS->readAll();
    QString expectedXtalVersion = "\nxtals  version: 1.0\n\n";
    if (presentXtalVersion != expectedXtalVersion) {
        QMessageBox::information(this, tr("ERROR 2"),
            tr("XTAL-GUI doesn't support this version of XTAL binary!"));
        exit (2);
    }

    /* PAGE: Set configuration */
    QWidget *configurationWidget = new QWidget;
    createConfig = new QPushButton(tr("&Create file"));
    loadConfig = new QPushButton(tr("&Load file"));
    connect(createConfig, &QPushButton::clicked, this, &ToolBox::createConfigFile);
    connect(loadConfig, &QPushButton::clicked, this, &ToolBox::loadConfigFromFile);
    QLabel *configPathLabel = new QLabel(tr("Chosen configuration file:"));
    configPathLine = new QLineEdit;
    configPathLine->setReadOnly(true);

    QVBoxLayout *configurationLayout = new QVBoxLayout;
    configurationLayout->addWidget(createConfig);
    configurationLayout->addWidget(loadConfig);
    configurationLayout->addWidget(configPathLabel);
    configurationLayout->addWidget(configPathLine);
    configurationWidget->setLayout(configurationLayout);

    /* PAGE: Choose options */
    QWidget *optionsWidget = new QWidget;
    QVBoxLayout *optionsLayout = new QVBoxLayout;
    exportChBox = new QCheckBox;
    exportChBox->setText("--export");
    signalChBox = new QCheckBox;
    signalChBox->setText("--signal");
    integrateChBox = new QCheckBox;
    integrateChBox->setText("--integrate");
    geometryChBox = new QCheckBox;
    geometryChBox->setText("--geometry");
    dumpChBox = new QCheckBox;
    dumpChBox->setText("--dump");
    runProcessing = new QPushButton(tr("&Run"));
    connect(runProcessing, &QPushButton::clicked, this, &ToolBox::runXTALS);
//    optionsFrame = new QFrame;
//    optionsFrame->setFrameShape( QFrame::Box );
//    optionsFrame->setFrameShadow( QFrame::Sunken );
//    optionsFrame->setLineWidth( 3 );
//    optionsFrame->setMidLineWidth( 3 );
//    optionsLayout->addWidget(optionsFrame);
    optionsLayout->addWidget(exportChBox);
    optionsLayout->addWidget(signalChBox);
    optionsLayout->addWidget(integrateChBox);
    optionsLayout->addWidget(geometryChBox);
    optionsLayout->addWidget(dumpChBox);
    optionsLayout->addWidget(runProcessing);
    optionsWidget->setLayout(optionsLayout);

    /* PAGE: Process data */
    QWidget *processWidget = new QWidget;
    QVBoxLayout *processLayout = new QVBoxLayout;
    progressBar = new QProgressBar;
    progressBar->setRange(0,100);
    progressBar->setValue(14);
    stopProcessing = new QPushButton(tr("&Stop"));
    slider = new QSlider;
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setValue(14);
    connect(slider, SIGNAL (valueChanged(int)), progressBar, SLOT (setValue(int)));
    processLayout->addWidget(progressBar);
    processLayout->addWidget(slider);

    processLayout->addWidget(stopProcessing);
    processWidget->setLayout(processLayout);

    /* Organize Widgets in ToolBox */
    toolBox = new QToolBox;
    toolBox->addItem(configurationWidget, "Set configuration");
    toolBox->addItem(optionsWidget, "Choose options");
    toolBox->addItem(processWidget, "Process data");

    toolBox->setItemToolTip(0, "Choose if you want to create or load already existing configuration file");
    toolBox->setItemToolTip(1, "Choose which options you want to perform");
    toolBox->setItemToolTip(2, "Processing...");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(toolBox);
    setLayout(layout);
}

ToolBox::~ToolBox() {
    delete toolBox;
}

void ToolBox::setPathToConfiguration(QString pathToConfiguration)
{
    configPathLine->setText(pathToConfiguration);
}

void ToolBox::loadConfigFromFile()
{
    QString pathToConfiguration = QFileDialog::getOpenFileName(this,
        tr("Open Configuration File"), "",
        tr("input file (*.inp);;configuration file (*.cfg);;All Files (*)"));

    if (pathToConfiguration.isEmpty())
        return;
//    configPathLine->setText(pathToConfiguration);
    ToolBox::setPathToConfiguration(pathToConfiguration);
}

void ToolBox::createConfigFile()
{
    confDialog->show();
}

void ToolBox::runXTALS()
{
    toolBox->setCurrentIndex(2);

    bool isExport = exportChBox->isChecked();
    bool isSignal = signalChBox->isChecked();
    bool isIntegrate = integrateChBox->isChecked();
    bool isGeometry = geometryChBox->isChecked();
    bool isDump = dumpChBox->isChecked();


    if (!isExport && !isSignal && !isIntegrate && !isGeometry && !isDump) {
        QMessageBox::information(this, tr("No argument!"),
            tr("You must choose some option to run XTALS!"));
        return;
    }

    QStringList newArgToRunXTAL;
    newArgToRunXTAL << "--readconf" << configPathLine->text();
    if (isExport) newArgToRunXTAL << "--export";
    if (isSignal) newArgToRunXTAL << "--signal";
    if (isIntegrate) newArgToRunXTAL << "--integrate";
    if (isGeometry) newArgToRunXTAL << "--geometry";
    if (isDump) newArgToRunXTAL << "--dump";

    QString pathToXTAL = "xtals"; //ISSUE 2 why is not global
    QProcess *XTALS = new QProcess(this);
    XTALS->setProcessChannelMode(QProcess::MergedChannels);
    XTALS->start(pathToXTAL, newArgToRunXTAL);

    // wymusza pozostanie na stronie któ©a nie jest potrezbna
    while (XTALS->waitForReadyRead())
        qDebug() << XTALS->readAll();
}
