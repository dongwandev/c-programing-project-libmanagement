#include <stdio.h>
#include <string.h>
#include "menu_control.h"
#include "file_io.h"
#include "search.h"
#include "editor.h"
#include "remover.h"
#include "adder.h"

void runMenuLoop(const char *filename) {
    loadBooks(filename);

    while (1) {
        int sel;
        printf("\n=== 메인 메뉴 ===\n");
        printf("1. 책 정보 검색\n2. 신규 책 등록\n3. 프로그램 종료\n> ");
        scanf("%d%*c", &sel);

        if (sel == 1) {
            char kw[64];
            int res[100];

            printf("검색어: ");
            fgets(kw, sizeof(kw), stdin);
            kw[strcspn(kw, "\n")] = '\0';

            int cnt = searchBooks(kw, res, 100);
            if (cnt == 0) {
                printf("잘못된 검색어입니다.\n");
            } else {
                printf("[%d]건 검색되었습니다.\n", cnt);
                for (int i = 0; i < cnt; ++i) {
                    Book *b = &bookDB[res[i]];
                    printf("ID=%d | %s | %s | %s | %d | %s\n",
                           b->bookID, b->title, b->author,
                           b->publisher, b->year, b->genre);
                }
                printf("수정/삭제할 ID (취소: 0)> ");
                int id; scanf("%d%*c", &id);
                if (id > 0) {
                    int idx = -1;
                    for (int i = 0; i < bookCount; ++i)
                        if (bookDB[i].bookID == id) { idx = i; break; }
                    if (idx >= 0) {
                        printf("1. 수정 2. 삭제 3. 취소 > ");
                        int m; scanf("%d%*c", &m);
                        if (m == 1) editBook(&bookDB[idx]);
                        else if (m == 2) deleteBook(idx);
                    } else {
                        printf("해당 ID가 존재하지 않습니다.\n");
                    }
                }
            }
        }
        else if (sel == 2) {
            addBook();
        }
        else if (sel == 3) {
            saveBooks(filename);
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("잘못된 선택입니다.\n");
        }
    }
}
