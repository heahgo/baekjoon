#include <cstdio>

int main() {
    //odd number array (ex: 3, 5, 7, 9, ...)
    bool array[10000];
    for (int i = 0; i < 10000; i++) array[i] = true;
    for (int i = 0; i < 10000; i++) {
        if (array[i] == true) {
            for (int j = 0; (3*(i+1)+(2*i+3)*j) < 10000; j++) {
                array[(3*(i+1)+(2*i+3)*j)] = false;
            }
        }
    }
    int n = 1, r = 0, tmp = 0;
    scanf("%d", &r);
    for(int j = 0; j < r; j++) {
        scanf("%d", &n);
        if (n == 4) {
            printf("2 2\n");
            continue;
        }
        if ((n / 2) % 2 == 0) tmp = n / 2 - 1;
        else tmp = n / 2;
        while(tmp >= 3) {
            if (array[(tmp - 3) / 2] == true && array[(n - tmp - 3) / 2] == true) {
                if (tmp < n - tmp) 
                    printf("%d %d\n", tmp, n - tmp);
                else    
                    printf("%d %d\n", n - tmp, tmp);
                break;
            }
            tmp -= 2;
        }
    }
}          