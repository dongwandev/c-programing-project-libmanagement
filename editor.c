#include <stdio.h>
#include <string.h>
#include "editor.h"

void editBook(Book *b) {
    int choice;
    char buffer[128];

    printf("1.책 이름 2.저자 3.출판사 4.출판년도 5.장르 6.취소 > ");
    scanf("%d%*c", &choice);

    switch (choice) {
    case 1:
        printf("새 책 이름: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(b->title, buffer, MAX_TITLE-1);
        b->title[MAX_TITLE-1] = '\0';
        break;
    case 2:
        printf("새 저자: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(b->author, buffer, MAX_AUTHOR-1);
        b->author[MAX_AUTHOR-1] = '\0';
        break;
    case 3:
        printf("새 출판사: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(b->publisher, buffer, MAX_PUBLISHER-1);
        b->publisher[MAX_PUBLISHER-1] = '\0';
        break;
    case 4:
        printf("새 출판년도: ");
        scanf("%d%*c", &b->year);
        break;
    case 5:
        printf("새 장르: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(b->genre, buffer, MAX_GENRE-1);
        b->genre[MAX_GENRE-1] = '\0';
        break;
    default:
        return;
    }

    printf("수정 완료: ID=%d | %s | %s | %s | %d | %s\n",
           b->bookID, b->title, b->author,
           b->publisher, b->year, b->genre);
}
