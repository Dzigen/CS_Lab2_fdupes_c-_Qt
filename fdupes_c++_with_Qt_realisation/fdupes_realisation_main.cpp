#include <QTextStream>
#include <QMap>
#include <QList>
#include <QString>

#include "dir_iterator_size_hash_insert.h"

using namespace std;

int main(int argc, char *argv[])
{
    /*инициализация потока вывода данных в консоль*/
    QTextStream out(stdout);

    /*Проверка на указание директории */
    if (argc < 2) {
        out<< "Usage: "<<argv[0]<<" directory"<<endl;
        _Exit(EXIT_FAILURE);
    }


    /**
     *  Инициализируем хранилище 
     *  размеров , хэшей и имён файлов заданного каталога и его подкаталогов
     */
    QMap < long, QMap < long, QList < QString > > >data_base_files;

     /**
      *  Инициализируем хранилище дубликатов файлов  заданного каталога и его подкаталогов
      */
    QMap < long, QList < QString > >duplicats;



    /**
     *  Двигаемся по файлам заданного каталога
     *  и заносим их размер ,хэш и имя в базу двнных data_base_files
     */
    dir_iterator(argv[1], &data_base_files);

    /**
     *	Посимвольно сравниваем файлы, отсортированные по размеру и хэшу
     */
    comparing_files(&data_base_files, &duplicats);

    /**
     * Выводим информацию о дубликатах в консоль и взаимодействуем с пользователем
     */
    user_interface(&duplicats);


    return 0;
}
