#include "include/processhandler.h"

void ProcessHandler::startProcess(QString process, QStringList &params) {
    myProcess = new QProcess(this);
    connect(myProcess, SIGNAL(readyReadStandardError()), this, SLOT(readStandardError()));
    myProcess->start(process, params);
    myProcess->waitForFinished(30000000);
}

void ProcessHandler::readStandardError() {
    QByteArray processOutput;
    processOutput = myProcess->readAllStandardError();

    qDebug().noquote() << QString(processOutput);
}