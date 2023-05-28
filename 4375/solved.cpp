#include <cstdio>
#include <cstdint>

int main()
{
    uint32_t n = 0, digit = 1, result = 1, tmp = 0;
    while (scanf("%d", &n) != EOF)
    {
        tmp = 10 % n;
        digit = 1;
        result = 1;
        while (result % n != 0)
        {
            result += tmp;
            tmp = (tmp * 10) % n;
            digit++;
        }
        printf("%u\n", digit);
    }
}
