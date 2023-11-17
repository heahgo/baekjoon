#include <iostream>
#include <cstdint>
#include <string>

using std::cout, std::cin, std::endl;
using std::string;

uint32_t GenLcsTable(string str1, string str2) {
    uint32_t row = str1.length();
    uint32_t col = str2.length();

    uint32_t* table = new uint32_t[(row+1)*(col+1)];
    for (uint32_t i = 0; i <= col; i++)
        table[i] = 0;

    for (uint32_t i = 0; i <= row; i++) 
        table[i*(col+1)] = 0;
    
    for (uint32_t i = 1 ; i <= row; i++) {
        for (uint32_t j = 1; j <= col; j++) {
            if (str1[i-1] == str2[j-1]) {
                table[j+i*(col+1)] = table[(j-1)+(i-1)*(col+1)] + 1;
            }
            else if (str1[i-1] != str2[j-1]) {
                if (table[j+(i-1)*(col+1)] > table[(j-1)+i*(col+1)]) {
                    table[j+i*(col+1)] = table[j+(i-1)*(col+1)];
                }
                else {
                    table[j+i*(col+1)] = table[(j-1)+i*(col+1)];
                }
            }
        }
    }
    return table[(row+1)*(col+1)-1];
}

int main() {

    string str1, str2;
    cin >> str1;
    cin >> str2;
    uint32_t lcs = GenLcsTable(str1, str2);
    cout << lcs;
}