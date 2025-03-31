#include <string>
#include <stdlib.h>
#include <iostream>

namespace strutil {
    std::string toUpper(const std::string&str) {
        const int offset = 'a' - 'A'; // 32
        std::string out;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] >= 'a'&&str[i] <= 'z') {
                out += (str[i] - offset);
            }else{out+=str[i];}
        }
        return out;
    }


    std::string rand(size_t length) {
        std::string out;
        for (size_t i = 0; i < length; i++) {
            char c = 97 + rand() % ('z' - 'a' + 1);
            out += c;
        }
        return out;
    }


    int longestWordLength(const std::string&str) {
        int max = 0;
        int current = 0;
        for (int i = 0; i < str.length; i++) {
            if (str[i] == 32) {
                if(current > max) {
                    max = current;
                    current = 0;
                }
            }else{current++;}
        }
    }
}

int main() {
    std::string random_str = strutil::rand(10);
    std::cout << random_str;
}