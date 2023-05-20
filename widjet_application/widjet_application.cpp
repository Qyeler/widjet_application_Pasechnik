#include "widjet_application.h"
#include <iostream>
#include <filesystem>
#include <bitset>
#include <QFileInfo>
#include <QStringList>
#include <QDir>

std::string getFileAttributes(const std::filesystem::directory_entry& entry);

widjet_application::widjet_application(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void widjet_application::Click_to_info() {

    QString path = ui.enter->text();
    std::filesystem::path pathToCheck(path.toStdString());
    QDir directory(path);

    if (!directory.exists()) {
        ui.output->setText(QString::fromLocal8Bit("Error Path"));
        return;
    }

    QStringList fileInfos;
    QStringList fileList = directory.entryList(QDir::Files | QDir::NoDotAndDotDot);

    for (const QString& fileName : fileList) {
        QFileInfo fileInfo(directory, fileName);
        QString fileInfoStr = fileInfo.baseName() + "\t" +
            fileInfo.completeSuffix() + "\t" +
            fileInfo.lastModified().toString("dd.MM.yyyy") + "\t";

        if (fileInfo.isReadable()) {
            fileInfoStr += "R";
        }
        if (fileInfo.isSymLink()) {
            fileInfoStr += "S";
        }
        if (fileInfo.isHidden()) {
            fileInfoStr += "H";
        }
        if (fileInfo.isDir()) {
            fileInfoStr += "D";
        }
        if (!fileInfo.isWritable()) {
            fileInfoStr += "W";
        }

        fileInfos.append(fileInfoStr);
    }
    QString out;
    for (auto i : fileInfos) {
        out += i;
        out += '\n';
    }
    ui.output->setText(out);

}

void widjet_application::Click_to_description() {
    QString path = ui.enter->text();
    std::filesystem::path pathToCheck(path.toStdString());
    QDir directory(path);

    if (!directory.exists()) {
        ui.output->setText(QString::fromLocal8Bit("Error Path"));
        return;
    }

    QStringList fileInfos;
    QStringList fileList = directory.entryList(QDir::Files | QDir::NoDotAndDotDot);

    for (const QString& fileName : fileList) {
        QFileInfo fileInfo(directory, fileName);
        if (fileInfo.completeSuffix() == "c") {
            QString fileInfoStr = fileInfo.baseName() + ".c\t";
            QFile file(fileInfo.filePath());
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                QString line1 = in.readLine();
                QString line2 = in.readLine();
                fileInfoStr += line1 + "\n" + line2;
                file.close();
            }
            fileInfos.append(fileInfoStr);
        }
    }
    QString out;
    for (auto i : fileInfos) {
        out += i;
        out += ' ';
    }
    ui.disc->setText("file name + discription:");
    ui.output->setText(out);
}
widjet_application::~widjet_application()
{}