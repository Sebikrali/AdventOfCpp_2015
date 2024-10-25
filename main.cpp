#include <fstream>
#include <ostream>
#include <sstream>

int main() {
    std::ifstream file("input");
    if (!file) {
        throw std::runtime_error("Can't read input");
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();

    std::string contents = buffer.str();
}
