#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

//must compile in c++20
//  g++ -std=c++20 hw_5.cpp

namespace fs = std::filesystem;
//sets folder to look into
std::string dir = "stuFolder/";
//vector of files we want to have
std::vector<std::string> reqFiles = {"test.txt", "hello.cpp"};


void printErr(std::string error) {
    std::cout << "\nERROR:\n" << "\t" << error  << "\n" << std::endl;
}

//prints out a vector and a precurrser message
void print(std::string preCur, auto items) {
    std::cout << preCur << "\n";
    for(auto item : items)
        std::cout << item << "\n";
}

void checkFiles(std::vector<std::string> r) {
    /*currently only checking for present files
        will need to:
            check for extra files
            know which files are missing
    */
    std::vector<std::string> present;
    std::vector<std::string> missing;
    std::vector<std::string> extra;
    for(auto file : r) {
        if(fs::exists(dir + file)) {
            present.push_back(file);
        }
    }
    print("Present files:", present);
}


int main() {
    std::cout << "\tChecking for files....\n";
    
    checkFiles(reqFiles);

    std::cout << "\tDone!" << std::endl;
    return 0;
}
