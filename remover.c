#include <stdio.h>
#include "remover.h"
#include "data_struct.h"

int deleteBook(int idx) {
    printf("정말 삭제하시겠습니까? (Y/N) > ");
    char c = getchar(); getchar();
    if (c == 'Y' || c == 'y') {
        for (int j = idx; j < bookCount - 1; ++j) {
            bookDB[j] = bookDB[j + 1];
        }
        bookCount--;
        printf("삭제 완료.\n");
        return 1;
    }
    printf("삭제 취소.\n");
    return 0;
}
