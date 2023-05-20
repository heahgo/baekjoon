#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <vector>

void eratosthenes_sieve(uint32_t n, uint32_t k) {
    uint32_t count = 0;
    std::vector<uint32_t>::iterator iter;
    std::vector<uint32_t>list;
    for(uint32_t i = 2; i <= n; i++) {
        list.push_back(i);
    }
    // for (iter = list.begin(); iter != list.end(); iter++) {
    //     printf("%u ", *iter); 
    // }
    
    for (uint32_t i = 2; i <= n; i++) {
        iter = list.begin();
        while(iter != list.end()) {
            if (*iter % i == 0) {
                count++;
                if (count == k) {
                    printf("%u", *iter);
                    break;
                }
            }   
        }
    }
    // for(uint32_t i = 2; i < n; i++) {
    //     for (iter = list.begin(); iter != list.end(); iter++) {
    //         if (*iter % i == 0 ) {
    //             // count++;
    //             // if (count == k) {
    //             //     printf("%u", *iter);
    //             //     break;
    //             // }
    //             list.erase(iter);
    //         }
    //     }
    // }
}

int main() {
    uint32_t n, k;
    scanf("%u%u", &n, &k);
    eratosthenes_sieve(n, k);

}