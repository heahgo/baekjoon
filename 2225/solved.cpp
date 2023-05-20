#include <cstdio>
#include <cstdint>
// nHr = n-1 H r + n H r-1
// 1 H r =  1
// n H 1 = n
int main()      { 
    uint64_t n, r;
    uint64_t dp[201][201] = {1,};
    scanf("%lu %lu", &r, &n);
    for (uint64_t i = 1; i <= 200; i++) {
        dp[1][i] = 1;
        dp[i][1] = i;
    }
    for (uint64_t i = 2; i <= n; i++) {
        for (uint64_t j = 2; j <= r; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j - 1];
            dp[i][j] %= 1000000000;
        }
    }
    printf("%lu\n", dp[n][r]);
}