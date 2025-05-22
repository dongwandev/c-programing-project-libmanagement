#ifndef FILE_IO_H
#define FILE_IO_H

/* loadBooks: filename 에서 CSV 읽어 bookDB[] 채우기.
   반환값 0=정상, -1=오류 */
int  loadBooks(const char *filename);
/* saveBooks: bookDB[] 내용을 filename 에 CSV로 쓰기 */
void saveBooks(const char *filename);

#endif // FILE_IO_H
