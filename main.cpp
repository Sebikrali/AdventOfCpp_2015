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
    bool first = true;
    int first_index = 0;
    for (int i = 0; i < contents.size() - 1; i++) {
        if (raw[i] == '(') {
            sum++;
        } else {
            sum--;
            if (first && sum == -1) {
                first_index = i + 1;
                first = false;
            }
        }
    }

    std::cout << "first_index: " << first_index << std::endl;
}
