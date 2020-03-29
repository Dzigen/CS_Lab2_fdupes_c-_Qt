/**
 *file_size_hash.cpp - Реализация функции file_size_hash.Описание функции находится в dir_iterator_size_hash_insert.h.
 *
 * Copyright (c) 2020, Menshikov Mikhail 
 */
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>                           
#include <cerrno>

#include"dir_iterator_size_hash_insert.h"

using namespace std;

void file_size_hash(string name, long *size, long *hash)
{
	/*переменная для хранения считанного символа из файла */
	char c;

	/*открываем файл */
	ifstream file;
	file.open(name.c_str());

	/*проверка на наличие ошибок при открытии файла */
	if (!file.is_open())
	{
        	fprintf(stderr, "error with open file %s: %s \n", name.c_str(),strerror(errno));
        	exit(EXIT_FAILURE);
	}

	/*вычисляем размер(в байтах) и хэш файла */
	bool flag=true;
	while (flag)
	{
		file.get(c);
		if(file.good()){	
			(*size) += 1;
			/*суммирум коды символов, записанные в файле*/
			(*hash) += c;
		}else if(file.eof()){
			flag=false;
			continue;
		}else if(file.fail()){
			fprintf(stderr, "file %s is corrupted : %s \n", name.c_str(),strerror(errno));
			file.close();
        		exit(EXIT_FAILURE);
		}
    	}


	file.close();
}
