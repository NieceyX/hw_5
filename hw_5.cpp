#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
std::string req = "reqFile.txt";

void printErr(std::string error) {
    std::cout << "\nERROR:\n" << "\t" << error  << "\n" << std::endl;
}

void checkFiles() {
    //will check files against the set
}

int main() {
    std::cout << "Hello!\n";
    
    if(fs::exists(req)) {
        std::cout << "Required file exists" << std::endl;
    }
    else
        printErr("Missing file containing required files: " + req);

    return 0;
}
