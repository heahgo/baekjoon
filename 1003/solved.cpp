#include <cstdio>
#include <iostream>
#include <cstdint>

int main()
{
    uint32_t n = 0, T = 0, zero_1, zero_2, one_1, one_2, tmp1, tmp2;

    scanf("%d", &T);
    for (uint32_t i = 0; i < T; i++)
    {
        scanf("%u", &n);
        zero_1 = 0;
        one_1 = 1;
        zero_2 = 1;
        one_2 = 0;
        if (n == 0) {
            printf("%u %u\n", zero_2, one_2);
            continue;
        }
        if (n == 1) {
            printf("%u %u\n", zero_1, one_1);
            continue;
        }
        for (uint32_t i = 2; i <= n; i++)
        {
            tmp1 = one_1;
            one_1 = one_1 + one_2;
            one_2 = tmp1;

            tmp2 = zero_1;
            zero_1 = zero_1 + zero_2;
            zero_2 = tmp2;
        }
        printf("%u %u\n", zero_1, one_1);
    }
}