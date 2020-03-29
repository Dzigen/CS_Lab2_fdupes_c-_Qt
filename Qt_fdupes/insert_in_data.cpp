/**
 *insert_in_data.cpp - Реализация функции insert_in_data.Описание функции находится в dir_iterator_size_hash_insert.h.
 *
 * Copyright (c) 2020, Menshikov Mikhail 
 */
#include <QMap>
#include <QList>
#include <QString>

#include "dir_iterator_size_hash_insert.h"

using namespace std;

void insert_in_data(QString name, long size, long hash, QMap < long,QMap < long, QList < QString > > >*data_base_files)
{

    /*дополнительные структуры для добавления в data_base_files */
    QMap < long, QList < QString > >hash_lvl;
    QList < QString > path_lvl;

    /*итератор для поиска существующего каталога с файлами такого же размера(в байтах) */
    QMap < long, QMap < long, QList < QString > > >::iterator it =data_base_files->find(size);

    /*проверка на существование раздела с файлами такого же размера */
    if (it != data_base_files->end()) {

        /*итератор для поиска существующего раздела c файлами одинакового хэша */
        QMap < long, QList < QString > >::iterator iti = it.value().find(hash);

        /*проверка на существования раздела с файлами с таким же хэшем */
        if (iti != it.value().end()) {

            /**
	      *Записываем путь файла в существующий раздел для данного размера и
	      *существующий раздел для данного хэша файла
	      */
            iti.value().push_back(name);



        } else {

            /**
             *Создаём новый раздел для данного хэша и
             *записываем его в существующий раздел для данного размера(в байтах).
             *Записываем путь файла в созданный раздел для файлов с данным хэшем
             */
            path_lvl.push_back(name);
            it.value().insert(hash, path_lvl);
        }

    } else {

        /**
          *Создаём новый раздел для данного размера(в байтах) и
          *в нём создаём новый раздел для данного хэша куда записываем путь данного файла
          */
        path_lvl.push_back(name);
        hash_lvl.insert(hash, path_lvl);
        data_base_files->insert(size, hash_lvl);

    }

}
