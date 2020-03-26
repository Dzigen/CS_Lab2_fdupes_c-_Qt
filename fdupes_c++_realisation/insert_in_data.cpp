#include <map>
#include <list>
#include <string>

#include "dir_iterator_size_hash_insert.h"

using namespace std;

void insert_in_data(string name, long size, long hash, map < int,map < int, list < string > > >*data_base_files)
{

    /*дополнительные структуры для добавления в data_base_files */
    map < int, list < string > >hash_lvl;
    list < string > path_lvl;

    /*итератор для поиска существующего каталога с файлами такого же размера(в байтах) */
    map < int, map < int, list < string > > >::iterator it =data_base_files->find(size);

    /*проверка на существование раздела с файлами такого же размера */
    if (it != data_base_files->end()) {

        /*итератор для поиска существующего раздела c файлами одинакового хэша */
        map < int, list < string > >::iterator iti = it->second.find(hash);

        /*проверка на существования раздела с файлами с таким же хэшем */
        if (iti != it->second.end()) {

            /**
	      *Записываем путь файла в существующий раздел для данного размера и
	      *существующий раздел для данного хэша файла
	      */
            iti->second.push_back(name);


        } else {

            /**
	      *Создаём новый раздел для данного хэша и 
	      *записываем его в существующий раздел для данного размера(в байтах).
	      *Записываем путь файла в созданный раздел для файлов с данным хэшем
	      */
            path_lvl.push_back(name);
            it->second.insert(pair < int,
            list < string > >(hash, path_lvl));
        }

    } else {

        /**
          *Создаём новый раздел для данного размера(в байтах) и
	  * в нём создаём новый раздел для данного хэша куда записываем путь данного файла
          */
        path_lvl.push_back(name);
        hash_lvl.insert(pair < int, list < string > >(hash, path_lvl));
        data_base_files->insert(pair < int, map < int,list < string > > >(size, hash_lvl));

    }

}
