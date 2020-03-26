#include <iostream>
#include<cstdlib>
#include<cstdio>

#include <map>
#include <list>
#include <string>

#include "dir_iterator_size_hash_insert.h"

using namespace std;

int main(int argc, char *argv[])
{
	/*Проверка на указание директории */
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s directory\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/**
	  *Инициализируем хранилище 
	  *размеров , хэшей и имён файлов заданного каталога и его подкаталогов
	  */
	map < int, map < int, list < string > > >data_base_files;

	/**  
	  *Инициализируем хранилище дубликатов файлов  заданного каталога и его подкаталогов
	  */
	map < int, list < string > >duplicats;


	/**
	  *Двигаемся по файлам заданного каталога
	  *и заносим их размер ,хэш и имя в базу двнных data_base_files
	  */
	dir_iterator(argv[1], &data_base_files);

	/**
	  *Посимвольно сравниваем файлы, отсортированные по размеру и хэшу
	  */
	comparing_files(&data_base_files, &duplicats);

	/**
	  *Выводим информацию о дубликатах в консоль и взаимодействуем с пользователем
	  */
	user_interface(&duplicats);

    return 0;
}
