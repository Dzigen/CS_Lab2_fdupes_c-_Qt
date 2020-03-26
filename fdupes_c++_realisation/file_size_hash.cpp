#include<fstream>
#include<string>
#include<cstdlib>
#include<cstdio>

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
        	fprintf(stderr, "error with open file: %s \n", name.c_str());
        	exit(EXIT_FAILURE);
	}

	/*вычисляем размер(в байтах) и хэш файла */
	while (file.get(c))
	{
		(*size) += 1;

		/*суммирум коды символов, записанные в файле*/
		(*hash) += c;
    	}

	file.close();
}
