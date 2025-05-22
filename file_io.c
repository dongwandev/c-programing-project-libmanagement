#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_io.h"
#include "data_struct.h"

int loadBooks(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fp = fopen(filename, "w");
        if (!fp) return -1;
        fclose(fp);
        fp = fopen(filename, "r");
        if (!fp) return -1;
    }

    char line[512];
    while (fgets(line, sizeof(line), fp) && bookCount < MAX_BOOKS) {
        /* 개행 제거 */
        line[strcspn(line, "\r\n")] = '\0';

        /* CSV 토큰화 */
        char *token = strtok(line, ",");
        if (!token) continue;
        bookDB[bookCount].bookID = atoi(token);

        token = strtok(NULL, ",");
        if (token) {
            strncpy(bookDB[bookCount].title, token, MAX_TITLE-1);
            bookDB[bookCount].title[MAX_TITLE-1] = '\0';
        }

        token = strtok(NULL, ",");
        if (token) {
            strncpy(bookDB[bookCount].author, token, MAX_AUTHOR-1);
            bookDB[bookCount].author[MAX_AUTHOR-1] = '\0';
        }

        token = strtok(NULL, ",");
        if (token) {
            strncpy(bookDB[bookCount].publisher, token, MAX_PUBLISHER-1);
            bookDB[bookCount].publisher[MAX_PUBLISHER-1] = '\0';
        }

        token = strtok(NULL, ",");
        if (token) {
            bookDB[bookCount].year = atoi(token);
        }

        token = strtok(NULL, ",");
        if (token) {
            strncpy(bookDB[bookCount].genre, token, MAX_GENRE-1);
            bookDB[bookCount].genre[MAX_GENRE-1] = '\0';
        }

        bookCount++;
    }
    fclose(fp);
    return 0;
}

void saveBooks(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) return;
    for (int i = 0; i < bookCount; ++i) {
        Book *b = &bookDB[i];
        fprintf(fp, "%d,%s,%s,%s,%d,%s\n",
                b->bookID, b->title, b->author,
                b->publisher, b->year, b->genre);
    }
    fclose(fp);
}
