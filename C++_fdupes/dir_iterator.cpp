/**
 *dir_iterator.cpp - Реализация функции dir_iterator.Описание функции находится в dir_iterator_size_hash_insert.h.
 *
 * Copyright (c) 2020, Menshikov Mikhail 
 */
#include <map>
#include <list>
#include <string>

#include <experimental/filesystem>

using namespace std;
namespace fs = experimental::filesystem;

#include "dir_iterator_size_hash_insert.h"

void dir_iterator(string name, map < int, map < int,list < string > > >*data_base_files)
{
	/*переменная для хранения размера(в байтах) найденного файла*/
	long size;
	/*переменная для хранения хэша найденного  файла*/
	long hash;

	/*проверка на существование введённой директории*/
	if(!fs::exists(name)){
		fprintf(stderr,"directore  %s  is not exist\n",name.c_str());
		exit(EXIT_FAILURE);
	}

	/*Выполняем рекурсивный обход дерева каталогов*/
	for (auto & p:fs::recursive_directory_iterator(name))
        	if (fs::is_regular_file(fs::status(p))) {

            		/*обнуляем переменные */
            		size = 0;
            		hash = 0;

            		/*вычисляем размер  и хэш данного файла*/
            		file_size_hash(p.path().string(), &size, &hash);

            		/*вносим информацию о размере и хэше файла в базу данных*/
            		insert_in_data(p.path().string(), size, hash, data_base_files);
        }
}
