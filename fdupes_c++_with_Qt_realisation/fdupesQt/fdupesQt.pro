QT += core
QT -= gui

TARGET = fdupesQt
CONFIG += console
CONFIG -= app_bundle
CONFIG+=-std=c++11


TEMPLATE = app

SOURCES += \
    ../comparing_files.cpp \
    ../dir_iterator.cpp \
    ../fdupes_realisation_main.cpp \
    ../file_size_hash.cpp \
    ../insert_in_data.cpp \
    ../insert_in_duplicats.cpp \
    ../user_interface.cpp

HEADERS += \
    ../dir_iterator_size_hash_insert.h

