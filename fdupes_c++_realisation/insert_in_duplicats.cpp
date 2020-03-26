#include<list>
#include<string>
#include<map>

#include "dir_iterator_size_hash_insert.h"

using namespace std;

void insert_in_duplicats(map< int,list<string> >* duplicats,string ptr_f,string ptr_s){
	
	/*вхождение данных строк в структуру данных duplicats*/
	bool flag_f=false;
	bool flag_s=false;

	/*дополгительная структура для дальнейшего добавления в  duplicats*/
	list<string> listing;
	
	/*номер нового раздела*/
	int number;

	/*обходим  структуру дубликатов и проверяем на вхождение данные пути файлов*/
	for(map<int,list<string> >::iterator it=duplicats->begin(); it!=duplicats->end();it++){
		for(list<string>::iterator ut=it->second.begin(); ut!=it->second.end();ut++){
					
			if(ptr_f==*ut)
				flag_f=true;
				
			if(ptr_s==*ut)
				flag_s=true;
		}
		
		/*если какой-то путь из пары уже в структуре,то в его раздел  добавляется другой путь пары*/
		if(flag_f==true &&  flag_s==false)
			it->second.push_back(ptr_s);
		else if(flag_f==false &&  flag_s==true)
			it->second.push_back(ptr_f);
	}
	/*если пара путей файлов не входит в структуру,то создаём новый раздел и добавляем в него эту пару */
	if(flag_f==false &&  flag_s==false){

			listing.push_back(ptr_f);
			listing.push_back(ptr_s);
			
			/*номер нового раздела*/
			number=duplicats->size();
			number++;

			duplicats->insert(pair<int,list<string> >(number,listing));
	}

}