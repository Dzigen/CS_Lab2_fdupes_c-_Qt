#include <QMap>
#include <QList>
#include <QString>
#include <QDir>
#include <QTextStream>

#include "dir_iterator_size_hash_insert.h"

using namespace std;

void dir_iterator(QString name, QMap < long, QMap < long,QList < QString > > >*data_base_files)
{
    /*инициализация потока вывода данных в консоль*/
    QTextStream out(stdout);

    /*переменная для хранения размера(в байтах) найденного файла */
    long size;
    /*переменная для хранения хэша найденного  файла */
    long hash;

    /*инициализируем заданный каталог для проверки на дубликаты файлов*/
    QDir dir(name);

    /*проверяем существование заданного каталога*/
    if(!dir.exists()){
       out<<"have no directory:"<< name <<endl;
        _Exit(EXIT_FAILURE);
    }

    /* Выполняем рекурсивный обход дерева каталогов */
    foreach(QFileInfo object , dir.entryInfoList()){

        if(object.isDir()){

            if(object.fileName()!="." && object.fileName()!="..")

                /*спускаемся в подкаталог*/
                dir_iterator(object.filePath(),data_base_files);

        }else if(object.isFile()){

            /*обнуляем переменные */
            size = 0;
            hash = 0;

            /*вычисляем размер  и хэш данного файла */
            file_size_hash(object.filePath(), &size, &hash);
            /*вносим информацию о размере и хэше файла в базу данных */
            insert_in_data(object.filePath(), size, hash, data_base_files);

        }
    }
}
