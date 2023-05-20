#include "widjet_application.h"
#include <iostream>
#include <filesystem>
#include <bitset>
#include <QFileInfo>
#include <QStringList>
#include <QDir>

widjet_application::widjet_application(QWidget* parent) : QMainWindow(parent) {
    ui.setupUi(this);
}

void widjet_application::Click_to_info() {

    QString path = ui.enter->text();  // Получаем путь из пользовательского ввода
    QDir directory(path);  // Создаем объект QDir для работы с папкой
    if (!directory.exists()) {
        ui.output->setText(QString::fromLocal8Bit("Error path"));  // Выводим сообщение об ошибке, если папка не существует
        return;
    }

    QStringList fileInfos;  // Создаем список для хранения информации о файлах
    QStringList fileList = directory.entryList(QDir::Files | QDir::NoDotAndDotDot);  // Получаем список файлов в папке
    for (const QString& fileName : fileList) {
        QFileInfo fileInfo(directory, fileName);  // Создаем объект QFileInfo для каждого файла

        QString fileInfoStr = fileInfo.baseName() + "\t" +  // Получаем название файла без расширения
            fileInfo.completeSuffix() + "\t" +  // Получаем расширение файла
            fileInfo.lastModified().toString("dd.MM.yyyy") + "\t";  // Получаем дату последнего изменения файла

        if (fileInfo.isReadable()) {
            fileInfoStr += "R";  // Если файл читаемый, добавляем "R"
        }
        if (fileInfo.isSymLink()) {
            fileInfoStr += "S";  // Если файл является символической ссылкой, добавляем "S"
        }
        if (fileInfo.isHidden()) {
            fileInfoStr += "H";  // Если файл скрытый, добавляем "H"
        }
        if (fileInfo.isDir()) {
            fileInfoStr += "D";  // Если файл является папкой, добавляем "D"
        }
        if (!fileInfo.isWritable()) {
            fileInfoStr += "W";  // Если файл только для чтения, добавляем "W"
        }

        fileInfos.append(fileInfoStr);  // Добавляем строку с информацией о файле в список
    }
    QString out;
    for (auto i : fileInfos) {
        out += i;
        out += '\n';
    }
    ui.output->setText(out);  // Выводим информацию о файлах в виджет

}

void widjet_application::Click_to_description() {
    QString path = ui.enter->text();  // Получаем путь из пользовательского ввода
    QDir directory(path);  // Создаем объект QDir для работы с папкой
    if (!directory.exists()) {
        ui.output->setText(QString::fromLocal8Bit("Error path"));  // Выводим сообщение об ошибке, если папка не существует
        return;
    }

    QStringList fileList = directory.entryList(QDir::Files | QDir::NoDotAndDotDot);  // Получаем список файлов в папке
    for (const QString& fileName : fileList) {
        QFileInfo
            fileInfo(directory, fileName);  // Создаем объект QFileInfo для каждого файла

        if (fileInfo.suffix().toLower() == "jpg") {  // Проверяем, является ли расширение файла "jpg"
            if (fileInfo.size() > (1024 * 1024)) {  // Проверяем, превышает ли размер файла 1 мегабайт (1 мегабайт = 1024 * 1024 байт)
                QString newFileName = fileInfo.completeBaseName() + "&." + fileInfo.suffix();  // Создаем новое имя файла, добавляя "&" в конец
                QString newPath = directory.absoluteFilePath(newFileName);  // Получаем полный путь к новому файлу
                std::filesystem::rename(fileInfo.absoluteFilePath().toStdString(), newPath.toStdString());  // Переименовываем файл с помощью std::filesystem
                QFile::rename(fileInfo.absoluteFilePath(), newPath);  // Переименовываем файл с помощью QFile
            }
        }
    }
}

widjet_application::~widjet_application() {}
