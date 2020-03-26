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

    /*переменные для хранения строк,получаемых из данных файлов*/
    QString str_f;
    QString str_s;

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


                    /*сравниваем файлы построчно*/
                    while(!file_f.atEnd() && !file_s.atEnd()){

                        /*записываем строки,полученные из файлов*/
                        str_f=file_f.readLine();
                        str_s=file_s.readLine();

                        /*проверка на их равенство и запись количества совпавших символов*/
                        if(str_f==str_s){
                            size+=str_f.size();
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
