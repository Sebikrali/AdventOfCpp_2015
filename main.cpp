#include <algorithm>
#include <fstream>
#include <sstream>
#include <array>
#include <iostream>

int calc(const std::string& str) {
    std::array<int, 3> sides;
    std::istringstream stream(str);
    std::string token;

    size_t i = 0;
    while (std::getline(stream, token, 'x')) {
        sides[i] = std::atoi(token.c_str());
        i++;
    }

    // For ribbon
    std::sort(sides.begin(), sides.end());
    int res = sides[0] * 2 + sides[1] * 2;
    return res + (sides[0] * sides[1] * sides[2]);
}

int main() {
    std::ifstream file("input");
    if (!file) {
        throw std::runtime_error("Can't read input");
    }

    int res = 0;
    std::string line;
    while (std::getline(file, line)) {
        res += calc(line);
    }

    printf("final_res=%d\n", res);
}

