#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <vector>

std::vector<uint32_t> eratosthenes_sieve(uint32_t n) {
    std::vector <uint32_t>list;
    std::vector<uint32_t>::iterator iter;
    for(uint32_t i = n; i > 2; i--) {
        list.push_back(i);
    }
   for(uint32_t i = 2; i < n; i++) {
        for (iter = list.begin(); iter != list.end(); iter++) {
            if (*iter % i == 0 && *iter != i) list.erase(iter);
        }
    }
    return list;
}
void goldbach(uint32_t n) {
    std::vector<uint32_t> list;
    list = eratosthenes_sieve(n);
    for (uint32_t i = 0; i < list.size(); i++) {
        for (uint32_t j =0; j < list.size(); j++) {
            if (list[i] + list[j] == n) {
                if (list[i] < list[j]) printf("%u = %u + %u\n", n, list[i], list[j]);
                else printf("%u = %u + %u\n", n, list[j], list[i]);
                return;
            }
        }
    }
    printf("Goldbach's conjecture is wrong.\n");
}
int main() {
    uint32_t n = 0;
    while(1) {
        if (scanf("%u", &n) == EOF ) return 0;
        goldbach(n);
    }
}