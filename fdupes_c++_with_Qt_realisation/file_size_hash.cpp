#include<QFile>
#include<QString>
#include <QTextStream>

#include"dir_iterator_size_hash_insert.h"

using namespace std;

void file_size_hash(QString name, long *size, long *hash)
{
    /*инициализация потока вывода данных в консоль*/
    QTextStream out(stdout);

    /*переменные для хранения счтанного символа из файла */
    char c;


    /*инициализируем файл*/
    QFile file(name);
    /*проверка на наличие ошибок при открытии файла*/
    if(!file.open(QIODevice::ReadOnly)){
        out<<"can not open file "<<name<<": "<<file.errorString()<<endl;
        _Exit(EXIT_FAILURE);
    }



    /*вычисляем размер(в байтах) и хэш файла */
    while (!file.atEnd()) {

        file.getChar(&c);
        if( file.error()){
            out<<"error with reading  "<<name<<": "<<file.errorString()<<endl;
            file.close();
            _Exit(EXIT_FAILURE);
        }

        (*size) += 1;
        (*hash) +=c;

    }

    file.close();

}
