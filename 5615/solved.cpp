#include <cstdio>
#include <cstdint>
#include <cstring>
#include <bitset>

using namespace std;

uint64_t prime_list[] = {2, 3, 5, 7};

uint64_t mod_exp(uint64_t a, uint64_t n, uint64_t m) {
    uint64_t A = 1, B = a;
    while (n) {
        if (n % 2 == 1) A = A * B % m;
        B = B * B % m;
        n = n / 2;
    }
    return A;
}

bool miller_rabin_primality_test(uint64_t n) {
    uint64_t d = n - 1;
    uint32_t r = 0;
    uint64_t x = 0;
    bitset<1> break_flag = 0;
    while(d % 2 == 0) {
        d /= 2;
        r += 1;
    }
    for (uint64_t i = 0; i < sizeof(prime_list) / sizeof(uint64_t); i++) {
        break_flag.reset();
        x = mod_exp(prime_list[i], d, n);
        if (x == 1 || x == n - 1) continue;
        for (uint64_t j = 0; j < r; j++) {
            x = (x * x) % n;
            if (x == 1) return false;
            if (x == n - 1) {
                break_flag.set();
                break;
            }
        }
        if (break_flag.all() == 1) continue;
        return false;
    }
    return true;
}

bool is_prime(uint64_t n) {
    if (n == 2 || n == 3 || n == 5 || n == 7) return true;
    if (miller_rabin_primality_test(n)) return true;
    return false;
} 

int main() {
    uint64_t n = 0, count = 0, area = 0;
    scanf("%lu", &n);

    for (uint64_t i = 0; i < n; i++) {
        scanf("%lu", &area);
        if (is_prime(2 * area + 1)) count++;
    }
    printf("%lu", count);
 }