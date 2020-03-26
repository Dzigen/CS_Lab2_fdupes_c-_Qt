#include <QMap>
#include <QList>
#include <QString>

#include "dir_iterator_size_hash_insert.h"

using namespace std;

void insert_in_duplicats(QMap< long,QList<QString> >* duplicats,QString ptr_f,QString ptr_s){
	
	/*вхождение данных строк в структуру данных duplicats*/
	bool flag_f=false;
	bool flag_s=false;

	/*дополгительная структура для дальнейшего добавления в  duplicats*/
    QList<QString> listing;
	
	/*номер нового раздела*/
	int number;

	/*обходим  структуру дубликатов и проверяем на вхождение данные пути файлов*/
    for(QMap<long,QList<QString> >::iterator it=duplicats->begin(); it!=duplicats->end();it++){
        for(QList<QString>::iterator ut=it.value().begin(); ut!=it.value().end();ut++){
					
			if(ptr_f==*ut)
				flag_f=true;
				
			if(ptr_s==*ut)
				flag_s=true;
		}
		
		/*если какой-то путь из пары уже в структуре,то в его раздел  добавляется другой путь пары*/
		if(flag_f==true &&  flag_s==false)
            it.value().push_back(ptr_s);
		else if(flag_f==false &&  flag_s==true)
            it.value().push_back(ptr_f);
	}
	/*если пара путей файлов не входит в структуру,то создаём новый раздел и добавляем в него эту пару */
	if(flag_f==false &&  flag_s==false){

			listing.push_back(ptr_f);
			listing.push_back(ptr_s);
			
			/*номер нового раздела*/
			number=duplicats->size();
			number++;

            duplicats->insert(number,listing);
	}

}
