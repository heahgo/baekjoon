#include <cstdio>

int main() {
    bool array[500000];
    for (int i = 0; i < 500000; i++) array[i] = true;
    for (int i = 0; i < 500000; i++) {
        if (array[i] == true) {
            for (int j = 0; (3*(i+1)+(2*i+3)*j) < 500000; j++) {
                array[(3*(i+1)+(2*i+3)*j)] = false;
            }
        }
    }
    int n = 1, flag = 0;
    while(1) {
        scanf("%d", &n);
        if (n == 0) return 0;
        for (int i = 0; i < 500000; i++) {
            flag = 0;
            if (array[i] == true && array[n / 2 - 3 - i] == true) {
                if (i < n / 2 - 3 - i)
                    printf("%d = %d + %d\n", n, 2 * i + 3, n - 2 * i - 3);
                else
                    printf("%d = %d + %d\n", n, n - 2 * i - 3, 2 * i + 3);
                flag = 1;
                break;
            }
        }if (flag == 0) printf("Goldbach's conjecture is wrong.\n");
    }
}          