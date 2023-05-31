#include <cstdio>
#include <cstdint>

int main()
{
    int64_t n, a;
    scanf("%ld%ld", &n, &a);
    int64_t q, s0 = 1, s1 = 0, t0 = 0, t1 = 1, r0 = a, r1 = n, tmp;
    while (r1)
    {
        q = r0 / r1;
        tmp = r1;
        r1 = r0 - r1 * q;
        r0 = tmp;
        tmp = s1;
        s1 = s0 - s1 * q;
        s0 = tmp;
        tmp = t1;
        t1 = t0 - t1 * q;
        t0 = tmp;
    }
    if (s0 < 0) s0 += n;
    if (r0 != 1)
        printf("%ld -1\n", (n - a) % n);
    else
        printf("%ld %ld\n", (n - a) % n, s0);
}