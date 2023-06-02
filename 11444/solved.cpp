#include <cstdio>
#include <cstdint>
#include <cstring>
int main()
{
    uint64_t n;
    uint64_t m[2][2] = {{1, 1}, {1, 0}};
    uint64_t result[2][2] = {{1, 0}, {0, 1}};
    uint64_t tmp[2][2] = {{0, 0}, {0, 0}};
    scanf("%lu", &n);
    n -= 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            std::memcpy(&tmp, &result, sizeof(result));
            result[0][0] = ((tmp[0][0] * m[0][0]) + (tmp[0][1] * m[1][0])) % 1000000007;
            result[0][1] = ((tmp[0][0] * m[0][1]) + (tmp[0][1] * m[1][1])) % 1000000007;
            result[1][0] = ((tmp[1][0] * m[0][0]) + (tmp[1][1] * m[1][0])) % 1000000007;
            result[1][1] = ((tmp[1][0] * m[0][1]) + (tmp[1][1] * m[1][1])) % 1000000007;
        }
        std::memcpy(&tmp, &m, sizeof(m));
        m[0][0] = (tmp[0][0] * tmp[0][0] + tmp[0][1] * tmp[1][0]) % 1000000007;
        m[0][1] = (tmp[0][0] * tmp[0][1] + tmp[0][1] * tmp[1][1]) % 1000000007;
        m[1][0] = (tmp[1][0] * tmp[0][0] + tmp[1][1] * tmp[1][0]) % 1000000007;
        m[1][1] = (tmp[1][0] * tmp[0][1] + tmp[1][1] * tmp[1][1]) % 1000000007;
        n /= 2;
    }
    printf("%lu\n", result[0][0]);
}