#include <cstdint>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>

int main() {

    std::ifstream file("input");
    if (!file) {
        throw std::runtime_error("Can't read input");
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();

    std::string contents = buffer.str();
    const char *raw = contents.c_str();

    int64_t sum = 0;
    for (int i = 0; i < contents.size() - 1; i++) {
        if (raw[i] == '(') {
            sum++;
        } else {
            sum--;
        }
    }

    std::cout << "sum: " << sum << std::endl;
}
