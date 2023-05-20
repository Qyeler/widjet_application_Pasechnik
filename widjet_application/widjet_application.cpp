#include "widjet_application.h"
#include <iostream>
#include <filesystem>
#include <bitset>
#include <QFileInfo>
#include <QStringList>
#include <QDir>

widjet_application::widjet_application(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void widjet_application::Click_to_info() {
    // ˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜˜˜
    QString path = ui.enter->text();//˜˜˜˜˜˜˜˜ ˜˜˜˜
    QDir directory(path);//˜˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜
    if (!directory.exists()) {// ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜˜
        ui.output->setText(QString::fromLocal8Bit("Error Path"));// ˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜˜
        return;
    }

    QStringList fileInfos;//˜˜˜˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜ ˜˜˜˜˜˜
    QStringList fileList = directory.entryList(QDir::Files | QDir::NoDotAndDotDot);
    //˜˜˜˜˜˜˜ ˜˜˜˜ ˜˜˜˜˜˜
    for (const QString& fileName : fileList) {//˜˜˜˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜
        QFileInfo fileInfo(directory, fileName);//˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜ ˜˜˜˜˜
        QString fileInfoStr = fileInfo.baseName() + "\t" +
            fileInfo.completeSuffix() + "\t" +
            fileInfo.lastModified().toString("dd.MM.yyyy") + "\t";//˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜ ˜˜˜˜˜˜˜˜˜˜˜

        if (fileInfo.isReadable()) {
            fileInfoStr += "R";//˜˜˜˜ ˜˜˜˜ ˜˜˜˜˜˜˜˜
        }
        if (fileInfo.isSymLink()) {
            fileInfoStr += "S";//˜˜˜˜ ˜˜˜˜ ˜˜˜˜˜˜˜˜˜
        }
        if (fileInfo.isHidden()) {
            fileInfoStr += "H";//˜˜˜˜ ˜˜˜˜ ˜˜˜˜˜˜˜
        }
        if (fileInfo.isDir()) {
            fileInfoStr += "D";//˜˜˜˜ ˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ 
        }
        if (!fileInfo.isWritable()) {
            fileInfoStr += "W";//˜˜˜˜ ˜ ˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜-˜˜
        }

        fileInfos.append(fileInfoStr);//˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜ ˜˜˜˜˜ ˜ ˜˜˜˜˜
    }
    QString out;//˜˜˜˜˜ ˜˜˜˜˜˜
    for (auto i : fileInfos) {
        out += i;
        out += '\n';//˜˜˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜ ˜ ˜˜˜˜˜˜˜˜˜ ˜ ˜˜˜˜˜
    }
    ui.output->setText(out);//˜˜˜˜˜˜˜ ˜ ˜˜˜˜˜˜ ˜˜˜˜˜


}

void widjet_application::Click_to_description() {
    QString path = ui.enter->text();//˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜
    QDir directory(path);//˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜
    if (!directory.exists()) {// ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜˜
        ui.output->setText(QString::fromLocal8Bit("Error Path"));// ˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜˜
        return;
    }

    QStringList fileList = directory.entryList(QDir::Files | QDir::NoDotAndDotDot);//˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜
    for (const QString& fileName : fileList) {//˜˜˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜
        QFileInfo fileInfo(directory, fileName);

        if (fileInfo.suffix().toLower() == "jpg") {
            if (fileInfo.size() > (1024 * 1024)) {// ˜˜˜˜ ˜˜˜˜˜˜ 1 ˜˜˜˜˜˜˜˜˜
                QString newFileName = fileInfo.completeBaseName() + "&." + fileInfo.suffix();//˜˜˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜
                QString newPath = directory.absoluteFilePath(newFileName);//˜˜˜˜˜˜˜˜˜
                std::filesystem::rename(fileInfo.absoluteFilePath().toStdString(), newPath.toStdString());//˜˜˜˜˜˜
                QFile::rename(fileInfo.absoluteFilePath(), newPath);//˜˜˜˜˜˜˜
            }
        }
    }
}
widjet_application::~widjet_application()
{}