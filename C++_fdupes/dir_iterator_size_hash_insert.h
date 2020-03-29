#include <map>
#include <list>
#include <string>

using namespace std;

/**
 * Обращение ко всем файлам в указанном каталоге и его подгаталогах.
 * 
 * @param name имя каталога для рекрсивного обхода его файлов
 * @param data_base_files структура данных ,куда будут заноситься рызмеры,хэши и имена файлов
 * @return none
 */
void dir_iterator( string name , map< int,map< int,list<string> > > *data_base_files );


/**
 * Вычисление размера файла(в байтах) и его хэша.
 * 
 *Способ вычисления хэша:складываются все коды символов в файле.
 *
 * @param size переменная для хранения размера файла
 * @param hash переменная для хранения хэша файла
 * @param name имя файла
 * @return none
 */
void file_size_hash(string name,long *size,long *hash);


/**
 * Сортировка файлов по их хэшу и размеру и занесение в структуру данных data_base_files.
 * 
 * @param name имя файла
 * @param size размер файла(в байтах)
 * @param hash значение хэша данного файла
 * @param data_base_files структура данных ,куда будут заноситься рызмер,хэш и имя файла
 * @return none
 */
void insert_in_data(string name,long size,long hash,map< int,map< int,list<string> > > *data_base_files);


/**
 * Побайтого сравниваем файлов  с одинаковым размером и хэшем.
 * 
 * @param  duplicats структура данных,куда будут заносться дубликаты файлов 
 * @param data_base_files структура данных  размеров ,хэшей и имён файлов 
 * @return none
 */
void comparing_files(map< int,map< int,list<string> > > *data_base_files,map< int,list<string> >* duplicats);



/**
 *Добавление одинаковых файлов в структуру данных дубликатов.
 * 
 * @param  duplicats структура данных,куда будут заносться дубликаты файлов в заданном каталоге
 * @param ptr_f путь к первому дибликату
 * @param ptr_s путь ко второму дубликату
 * @return none
 */
void insert_in_duplicats(map< int,list<string> >* duplicats,string ptr_f,string ptr_s);


/**
 *Вывод информации о дубликатах в консоль и взаимодействие с пользователем.
 * 
 * @param  duplicats структура данных,хранящая дубликаты файлов заданного каталога
 * @return none
 */
void user_interface(map< int,list<string> >* duplicats);









