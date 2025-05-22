#ifndef SEARCH_H
#define SEARCH_H

/* keyword 로 bookDB[] 전 필드를 부분 검색.
   results[] 에 인덱스 저장, 최대 maxResults 개수까지.
   반환값 = 찾은 개수 */
int searchBooks(const char *keyword, int results[], int maxResults);

#endif // SEARCH_H
