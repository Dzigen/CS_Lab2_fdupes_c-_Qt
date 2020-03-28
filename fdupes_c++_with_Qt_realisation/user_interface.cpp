/**
 *user_interface.cpp - Реализация функции user_interface.Описание функции находится в dir_iterator_size_hash_insert.h.
 *
 * Copyright (c) 2020, Menshikov Mikhail 
 */
#include <QMap>
#include <QList>
#include <QString>
#include <QFile>
#include <QTextStream>

#include"dir_iterator_size_hash_insert.h"

using namespace std;

void user_interface(QMap < long, QList < QString > >*duplicats)
{
    /*инициализация потока вывода и ввода данных в консоль*/
    QTextStream out(stdout);
    QTextStream in(stdin);

    QString command;

    long num_pos;

    bool flag;

    /*проверка на наличие каталогов с  файлами-дубликатами в структуре dublicats*/
    if(duplicats->size()==0)
         out << endl<<"There are no duplicates in this directory and its subdirectories"<< endl<< endl;

    /*обходим струтуру дубликатов файлов*/
    for (QMap < long, QList < QString > >::iterator iti = duplicats->begin(); iti != duplicats->end(); iti++) {

        out << endl;
        num_pos = 0;

        for (QList < QString >::iterator uti = iti.value().begin();
             uti != iti.value().end(); uti++) {

            num_pos++;
            out << "[" << num_pos << "]" << ": " << *uti << endl;
        }

        flag = false;

        /*Пользователь вводит команду.Проверка на ввод существующей*/
        while (!flag) {

            out << endl<< "Set " << iti.key() << " of " << duplicats->size() << ", preserve files [1 - " << iti.value().size() << ", all]: ";
            out.flush();
            command=in.readLine();
            out << endl;

            if (command == "all") {
                flag = true;
            } else if (command.toLong() >= 1 && command.toLong() <= static_cast<signed int>(iti.value().size())) {
                flag = true;
            } else {
                out << "Wrong command.Try again." << endl;
            }

        }

        num_pos = 0;

        /*Выполнение команды.Вывод информации об исполненной команде*/
        for (QList < QString >::iterator uti = iti.value().begin(); uti != iti.value().end(); uti++) {

            if (command == "all") {

                out << "[+]" << ": " << *uti << endl;

            }else {

                num_pos++;

                if (num_pos == command.toLong()) {
                    out << "[+]" << ": " << *uti << endl;
                    continue;
                }

                QFile::remove(*uti);
                out << "[-]" << ": " << *uti << endl;

            }

        }

        out << endl<< "=========" << endl;

    }

}
