#include <cstdio>
#include <algorithm> 
int gcd(int a, int b) {
    int tmp = 0;
    if (a < b) {
        std::swap(a, b);
    }
    while (a % b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return b;
} 

int lcm(int a, int b) {
    int g = gcd(a, b);
    return (a / g) * (b / g) * g;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n%d\n", gcd(a, b), lcm(a, b));
}