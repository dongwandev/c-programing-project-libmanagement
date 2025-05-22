#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#define MAX_BOOKS     100 // 책 최대 저장 개수 100개
#define MAX_TITLE     100 // 최대 책 이름 길이 제한 100
#define MAX_AUTHOR     50 // 최대 책 저자 이름 길이 제한 50
#define MAX_PUBLISHER  50 // 최대 책 출판사 이름 제한 50
#define MAX_GENRE      30 //최대 책 장르 이름 제한 30

typedef struct {
    int bookID;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char publisher[MAX_PUBLISHER];
    int year;
    char genre[MAX_GENRE];
} Book;

extern Book bookDB[MAX_BOOKS];
extern int bookCount;
extern int nextID;

#endif
