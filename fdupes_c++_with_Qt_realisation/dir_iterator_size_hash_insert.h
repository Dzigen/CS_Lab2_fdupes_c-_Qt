#include <QMap>
#include <QList>
#include <QString>

using namespace std;

/**
 * Обращение ко всем файлам в указанном каталоге и его подгаталогах.
 * 
 * @param name имя каталога для рекрсивного обхода его файлов
 * @param data_base_files структура данных ,куда будут заноситься рызмеры,хэши и имена файлов
 * @return none
 */
void dir_iterator( QString name , QMap< long,QMap< long,QList<QString> > > *data_base_files );


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
void file_size_hash(QString name,long *size,long *hash);


/**
 * Сортировка файлов по их хэшу и размеру и занесение в структуру данных data_base_files.
 * 
 * @param name имя файла
 * @param size размер файла(в байтах)
 * @param hash значение хэша данного файла
 * @param data_base_files структура данных ,куда будут заноситься рызмеры,хэши и имена файлов
 * @return none
 */
void insert_in_data(QString name,long size,long hash,QMap< long,QMap< long,QList<QString> > > *data_base_files);


/**
 * Побайтого сравнение файлов с одинаковым размером и хэшем.
 * 
 * @param  duplicats структура данных,куда будут заносться дубликаты файлов
 * @param data_base_files структура данных  размеров ,хэшей и имён файлов
 * @return none
 */
void comparing_files(QMap< long,QMap< long,QList<QString> > > *data_base_files,QMap< long,QList<QString> >* duplicats);



/**
 *Добавление одинаковых файлов в структуру данных дубликатов.
 * 
 * @param  duplicats структура данных,куда будут заносться дубликаты файлов в заданном каталоге
 * @param ptr_f путь к первому дибликату
 * @param ptr_s путь ко второму дубликату
 * @return none
 */
void insert_in_duplicats(QMap< long,QList<QString> >* duplicats,QString ptr_f,QString ptr_s);


/**
 *Вывод информации о дубликатах в консоль и взаимодействие с пользователем.
 * 
 * @param  duplicats структура данных,хранящая дубликаты файлов в заданном каталоге
 * @return none
 */
void user_interface(QMap< long,QList<QString> >* duplicats);









