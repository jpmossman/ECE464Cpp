#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include "trimming.h"

int parse_file(std::string file_name) {
    // Open file
    std::ifstream f;
    std::string line;
    f.open(file_name);

    // Parse file
    while (std::getline(f,line)) {
        // Cut out comments and trim whitespace
        line = line.substr(0,line.find('#'));
        trim(line);
        // If line is empty, continue
        if (line.length() == 0) continue;
        // Check for different
        std::cout << line << std::endl;
    }

    // Close file
    f.close();
    return 0;
}

int main() {
    parse_file("c17.bench");
}
