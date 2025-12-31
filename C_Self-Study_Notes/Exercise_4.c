#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double num1, num2, result;
    char op;
    char cont = 'y';

    while (cont == 'y' || cont == 'Y') {
        // 清空畫面 (Windows 用 cls, Linux/macOS 用 clear)
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        // 顯示計算機介面
        printf("==== Console 計算機 ====\n");
        printf("+---+---+---+---+\n");
        printf("| 7 | 8 | 9 | / |\n");
        printf("+---+---+---+---+\n");
        printf("| 4 | 5 | 6 | * |\n");
        printf("+---+---+---+---+\n");
        printf("| 1 | 2 | 3 | - |\n");
        printf("+---+---+---+---+\n");
        printf("| 0 | . | = | + |\n");
        printf("+---+---+---+---+\n");

        // 讀入運算式
        printf("請輸入運算式（例如 3 + 4）: ");
        scanf("%lf %c %lf", &num1, &op, &num2);

        // 計算
        switch(op) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/':
                if(num2 != 0) result = num1 / num2;
                else {
                    printf("錯誤: 除數不能為 0\n");
                    printf("按 Enter 鍵繼續...");
                    getchar(); getchar(); // 暫停等待使用者
                    continue;
                }
                break;
            default:
                printf("無效運算符號\n");
                printf("按 Enter 鍵繼續...");
                getchar(); getchar(); // 暫停等待使用者
                continue;
        }

        printf("結果: %.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);

        // 詢問是否繼續
        printf("是否繼續計算? (y/n): ");
        scanf(" %c", &cont);
    }

    printf("已退出計算機。\n");
    return 0;
}
