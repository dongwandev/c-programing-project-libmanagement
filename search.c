#include <stdio.h>    // snprintf 선언
#include <string.h>   // strstr 선언
#include "search.h"
#include "data_struct.h"

int searchBooks(const char *keyword, int results[], int maxResults) {
    int count = 0;
    for (int i = 0; i < bookCount && count < maxResults; ++i) {
        Book *b = &bookDB[i];

        // 연도를 문자열로 변환
        char yearStr[16];
        snprintf(yearStr, sizeof(yearStr), "%d", b->year);

        // 각 필드를 부분 문자열 검색
        if (strstr(b->title, keyword) ||
            strstr(b->author, keyword) ||
            strstr(b->publisher, keyword) ||
            strstr(b->genre, keyword) ||
            strstr(yearStr,   keyword)) 
        {
            results[count++] = i;
        }
    }
    return count;
}
