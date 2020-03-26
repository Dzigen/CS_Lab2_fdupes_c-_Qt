#include<map>
#include<list>
#include<string>
#include<iostream>
#include<experimental/filesystem>

#include<cstdlib>

#include"dir_iterator_size_hash_insert.h"

namespace fs = experimental::filesystem;
using namespace std;

void user_interface(map < int, list < string > >*duplicats)
{
	/*строка ,хранящая набранную команду*/
    	string command;
	
	/*номер каталога с дубликатами*/
    	int num_pos;

    	bool flag;

	/*проверка на наличие каталогов с  файлами-дубликатами в структуре dublicats*/
	if(duplicats->size()==0)
		cout << endl<<"There are no duplicates in this directory and its subdirectories"<< endl<< endl;
	 
	/*обходим струтуру дубликатов файлов*/
	for (map < int, list < string > >::iterator iti = duplicats->begin(); iti != duplicats->end(); iti++)
	{
		cout << endl;
		num_pos = 0;

		for (list < string >::iterator uti = iti->second.begin(); uti != iti->second.end(); uti++)
		{
			num_pos++;
			cout << "[" << num_pos << "]" << ": " << *uti << endl;
		}

		flag = false;

		/*Пользователь вводит команду.Проверка на ввод существующей*/
		while (!flag)
		{
			cout << endl<< "Set " << iti->first << " of " << duplicats->size() << ", preserve files [1 - " << iti->second.size() << ", all]: ";
			cin >> command;
			cout << endl;

			if (command == "all"){
				flag = true;
			}else if (atoi(command.c_str()) >= 1 && atoi(command.c_str()) <= iti->second.size()){
				flag = true;
			}else{
				cout << "Wrong command.Try again." << endl;
			}
		}

		num_pos = 0;

		/*Выполнение команды.Вывод информации об исполненной команде*/
       		for (list < string >::iterator uti = iti->second.begin(); uti != iti->second.end(); uti++)
		{
			if(command == "all") {
				cout << "[+]" << ": " << *uti << endl;
			}else{
				num_pos++;
				if(num_pos == atoi(command.c_str())){
					cout << "[+]" << ": " << *uti << endl;
                    			continue;
                		}

               			fs::remove(*uti);
                		cout << "[-]" << ": " << *uti << endl;
			}
      		}

        	cout << endl<< "=========" << endl;
	}
}
