#include <cstdio>
#include <cstdint>
#include <cmath>

int main()
{
    bool array[1000000 / 2];
    for (int i = 0; i < 1000000 / 2; i++)
        array[i] = true;
    for (int i = 0; i < 1000000 / 2; i++)
    {
        if (array[i] == true)
        {
            for (int j = 0; (3 * (i + 1) + (2 * i + 3) * j) < 1000000 / 2; j++)
            {
                array[(3 * (i + 1) + (2 * i + 3) * j)] = false;
            }
        }
    }
    uint64_t n = 0, result;
    scanf("%lu", &n);
    result = n;
    if (n % 2 == 0)
    {
        result = result - result / 2;
        while (n % 2 == 0)
            n /= 2;
    }
    for (uint64_t i = 0; i < 1000000 / 2; i++)
    {
        if (array[i] == false)
            continue;
        if (n % (2 * i + 3) == 0)
        {
            result = result - result / (2 * i + 3);
            while (n % (2 * i + 3) == 0)
            {
                n /= (2 * i + 3);
            }
        }
    }
    if (n != 1)
        result = result - result / n;
    printf("%lu\n", result);
}