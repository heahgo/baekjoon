#include <iostream>
#include <cstdint>

void eratosthenes_sieve(uint32_t n, uint32_t k) {
    uint32_t count = 0;
    bool number_list[1000];
    std::fill_n(number_list, 1000, true);
    for (uint32_t divisor = 2; divisor <= n; divisor++) {
        if (number_list[divisor] == false) continue;
        for (uint32_t idx = 2; idx <= n; idx++) {
            if (idx % divisor == 0 && number_list[idx] != false) {
                number_list[idx] = false; 
                count++;
                if (count == k) {
                    std::cout << idx;
                    return;
                }
            }
        }
    }
}

int main() {
    uint32_t n, k;
    std::cin >> n >> k;
    eratosthenes_sieve(n, k);

}