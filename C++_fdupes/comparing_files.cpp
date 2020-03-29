/**
 *comparing_files.cpp - Реализация функции comparing_files.Описание функции находится в dir_iterator_size_hash_insert.h.
 *
 * Copyright (c) 2020, Menshikov Mikhail 
 */
#include <map>
#include <list>
#include <string>
#include <fstream>
#include <iostream>      
#include <cstring>                     
#include <cerrno>

#include<cstdlib>
#include<cstdio>

#include "dir_iterator_size_hash_insert.h"

using namespace std;

void comparing_files(map< int,map< int,list<string> > > *data_base_files,map< int,list<string> >* duplicats)
{
	/*переменная для хранения количества совпавших подряд символов у сравниваемых файлов*/
	int size;

	/*переменные для хранения символов,получаемых из данных файлов*/
	char chr_f;
	char chr_s;

	/*спускаем к структурам(list<string>),хранящим пути файлов c одинаковым размером(в байтах) м хэшем*/
	for(map<int,map<int,list<string> > >::iterator it=data_base_files->begin(); it!=data_base_files->end();it++)
		for(map<int,list<string> >::iterator ut=it->second.begin(); ut!=it->second.end();ut++)
			for(list<string>::iterator ptr_f=ut->second.begin(); ptr_f!=ut->second.end();ptr_f++)
			{	
				/*ставим итератор на элемент перед ptr_s для сравнения всёх комбинаций пар файлов*/
				list<string>::iterator ptr_s=ptr_f;
				ptr_s++;

				for(ptr_s;ptr_s!=ut->second.end();ptr_s++)
				{
					/*обнуляем переменную*/		
					size=0;

					/*открываем файл*/
 					ifstream file_f;
					file_f.open(ptr_f->c_str());	

					/*проверка на наличие ошибок при открытии файла*/
					if(!file_f.is_open())
					{
						fprintf(stderr, "error with open file %s: %s \n", ptr_f->c_str(),strerror(errno));
        					exit(EXIT_FAILURE);
					}			

					/*открываем файл*/
 					ifstream file_s;
					file_s.open(ptr_s->c_str());	

					/*проверка на наличие ошибок при открытии файла*/
					if(!file_s.is_open())
					{
						fprintf(stderr, "error with open file %s: %s \n", ptr_s->c_str(),strerror(errno));
        					exit(EXIT_FAILURE);
					}		
					

					/*сравниваем файлы посимвольно*/
					bool flag =true;
					while(flag)
					{
						file_f.get(chr_f);
						file_s.get(chr_s);

						/*проверка на корректное считывание*/
						if(file_f.good()||file_s.good()){
							if(chr_f==chr_s){
								size+=1;
								continue;
							}
							break;
						}else if(file_f.eof()||file_s.eof()){
							flag=false;
							continue;					
						}else if( file_f.fail() ){
							fprintf(stderr, " file  %s  is corrupted : %s \n", ptr_f->c_str(),strerror(errno));
							file_s.close();
							file_f.close();
        						exit(EXIT_FAILURE);
						}else if( file_f.fail() ){
							fprintf(stderr, " file  %s  is corrupted : %s \n", ptr_f->c_str(),strerror(errno));
							file_s.close();
							file_f.close();
        						exit(EXIT_FAILURE);
						}

					}
						

					file_s.close();
					file_f.close();
					
					/*если файлы посимвольно совпадают,вносим в базу данных дубликатов*/
					if(size==it->first)
						insert_in_duplicats(duplicats,*ptr_f,*ptr_s);
				}
			}	
}