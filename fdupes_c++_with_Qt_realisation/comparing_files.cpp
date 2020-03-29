/**
 *comparing_files.cpp - Реализация функции comparing_files.Описание функции находится в dir_iterator_size_hash_insert.h.
 *
 * Copyright (c) 2020, Menshikov Mikhail 
 */
#include <QMap>
#include <QList>
#include <QString>
#include <QFile>
#include <QTextStream>

#include "dir_iterator_size_hash_insert.h"

using namespace std;

void comparing_files(QMap< long,QMap< long,QList<QString> > > *data_base_files,QMap< long,QList<QString> >* duplicats){

    /*инициализация потока вывода данных в консоль*/
    QTextStream out(stdout);

	/*переменная для хранения количества совпавших подряд символов у сравниваемых файлов*/
    long size;

    /*переменные для хранения символов,получаемых из данных файлов*/
    char chr_f;
    char chr_s;

	/*спускаем к структурам(list<string>),хранящим пути файлов c одинаковым размером(в байтах) м хэшем*/
    for(QMap<long,QMap<long,QList<QString> > >::iterator it=data_base_files->begin(); it!=data_base_files->end();it++)
        for(QMap<long,QList<QString> >::iterator ut=it.value().begin(); ut!=it.value().end();ut++)
            for(QList<QString>::iterator ptr_f=ut.value().begin(); ptr_f!=ut.value().end();ptr_f++){
				
				/*ставим итератор на элемент перед ptr_s для сравнения всёх комбинаций пар файлов*/
                QList<QString>::iterator ptr_s=ptr_f;
				ptr_s++;

                for(;ptr_s!=ut.value().end();ptr_s++){
					
					/*обнуляем переменную*/		
					size=0;


                    /*инициализируем файл*/
                    QFile file_f(*ptr_f);
					/*проверка на наличие ошибок при открытии файла*/
                    if(!file_f.open(QIODevice::ReadOnly)){
                        out<<"can not open file: "<<*ptr_f<<endl;
                        _Exit(EXIT_FAILURE);
                    }

                    /*инициализируем файл*/
                    QFile file_s(*ptr_s);
					/*проверка на наличие ошибок при открытии файла*/
                    if(!file_s.open(QIODevice::ReadOnly)){
                        out<<"can not open file: "<<*ptr_s<<endl;
                        _Exit(EXIT_FAILURE);
                    }


                    /*сравниваем файлы посимвольно*/
                    while(!file_f.atEnd() && !file_s.atEnd()){

                        /*записываем символы,полученные из файлов*/
                        file_f.getChar(&chr_f);

                        if( file_f.error()){
                            out<<"error with reading  "<<*ptr_f<<": "<<file_f.errorString()<<endl;
                            file_f.close();
                            file_s.close();
                            _Exit(EXIT_FAILURE);
                        }

                        file_s.getChar(&chr_s);

                        if( file_s.error()){
                            out<<"error with reading  "<<*ptr_s<<": "<<file_s.errorString()<<endl;
                            file_f.close();
                            file_s.close();
                            _Exit(EXIT_FAILURE);
                        }

                        /*проверка на их равенство и запись количества совпавших символов*/
                        if(chr_f==chr_s){
                            size++;
							continue;
						}

						break;
					}

					file_s.close();
					file_f.close();
					
					/*если файлы посимвольно совпадают,вносим в базу данных дубликатов*/
                    if(size==it.key())
						insert_in_duplicats(duplicats,*ptr_f,*ptr_s);
				}
			}	
}
