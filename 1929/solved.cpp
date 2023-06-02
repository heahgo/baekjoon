#include <cstdio>
#include <iostream>
#include <cstdint>

int main() {
    uint32_t m, n;
    scanf("%u%u", &m, &n);

    if (n == 1 && m == 1) return 0;

    uint32_t sieve[500000];
    std::fill_n(sieve, 500000, true);
    for (int i = 0; i < 500000; i++) {  
        if (sieve[i] == false) continue; 
        for (int j = 1; i + (2*i+3) * j < 500000; j++) {
            sieve[i + (2*i+3) * j ] = false;
        }
    }
    if (m == 1)  m ++;
    if (m <= 2 && n >= 2) printf("2\n");
    if (m % 2 == 0) m++;

    for (; m <= n; m+=2) {
        if (sieve[(m - 3) / 2] == true) printf("%u\n", m);
    }
}