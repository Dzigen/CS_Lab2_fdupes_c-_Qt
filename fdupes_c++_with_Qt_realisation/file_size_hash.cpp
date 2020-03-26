#include<QFile>
#include<QString>
#include <QTextStream>

#include"dir_iterator_size_hash_insert.h"

using namespace std;

void file_size_hash(QString name, long *size, long *hash)
{
    /*инициализация потока вывода данных в консоль*/
    QTextStream out(stdout);

    /*переменная для хранения считанной строки из файла */
    QString s;


    /*инициализируем файл*/
    QFile file(name);
    /*проверка на наличие ошибок при открытии файла*/
    if(!file.open(QIODevice::ReadOnly)){
        out<<"can not open file: "<<name<<endl;
        _Exit(EXIT_FAILURE);
    }



    /*вычисляем размер(в байтах) и хэш файла */
    while (!file.atEnd()) {

        /*суммируем размер строки(в юайтах), считанной из файла*/
        s=file.readLine();
        (*size) += s.size();

        /*суммирум коды символов, записанных в считанной строке из файла*/
        for(  int i=0; i<s.size(); i++)
             (*hash) += s[i].unicode();

    }

    file.close();

}
