#include <stdio.h>
#include <string.h>
#include "adder.h"
#include "data_struct.h"

int addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("DB가 가득 찼습니다.\n");
        return 0;
    }
    Book nb;
    nb.bookID = nextID++;
    
    char buffer[128];

    printf("책 이름: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(nb.title, buffer, MAX_TITLE-1);

    printf("저자: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(nb.author, buffer, MAX_AUTHOR-1);

    printf("출판사: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(nb.publisher, buffer, MAX_PUBLISHER-1);

    printf("출판년도: ");
    scanf("%d%*c", &nb.year);

    printf("장르: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(nb.genre, buffer, MAX_GENRE-1);

    bookDB[bookCount++] = nb;
    printf("등록 완료: ID=%d | %s | %s | %s | %d | %s\n",
           nb.bookID, nb.title, nb.author,
           nb.publisher, nb.year, nb.genre);
    return 1;
}
