#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#define MAX_BOOKS     100
#define MAX_TITLE     100
#define MAX_AUTHOR     50
#define MAX_PUBLISHER  50
#define MAX_GENRE      30

typedef struct {
    int bookID;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char publisher[MAX_PUBLISHER];
    int year;
    char genre[MAX_GENRE];
} Book;

/* 전역 변수 선언 */
extern Book bookDB[MAX_BOOKS];
extern int bookCount;
extern int nextID;

#endif // DATA_STRUCT_H
