#include <stdio.h>
#include "remover.h"
#include "data_struct.h"

int deleteBook(int idx) {
    char c;
    while (1) {
        printf("정말 삭제하시겠습니까? (Y/N) > ");
        c = getchar();
        // 입력 버퍼에 남아있는 나머지 문자를 버립니다.
        char dummy;
        while ((dummy = getchar()) != '\n' && dummy != EOF);

        if (c == 'Y' || c == 'y') {
            // 삭제 로직 (기존과 동일)
            for (int j = idx; j < bookCount - 1; ++j) {
                bookDB[j] = bookDB[j + 1];
            }
            bookCount--;
            printf("삭제 완료.\n");
            return 1;
        }
        else if (c == 'N' || c == 'n') {
            printf("삭제 취소.\n");
            return 0;
        }
        else {
            // Y/N 외의 입력 처리
            printf("잘못된 입력입니다. 다시 선택해주세요.\n");
        }
    }
}

