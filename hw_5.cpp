#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>

//must compile in c++20
//  g++ -std=c++20 hw_5.cpp

namespace fs = std::filesystem;
//sets folder to look into
std::string dir;

//vector of files we want to have
std::vector<std::string> reqFiles = {"test.txt", "hello.cpp"};


void printErr(std::string error) {
    std::cout << "\nERROR:\n" << "\t" << error  << "\n" << std::endl;
}

//prints out a vector and a precurrser message
void print(std::string preCur, auto items) {
    std::cout << preCur << "\n";
    for(auto item : items)
        std::cout << "  " << item << "\n";
}

void checkFiles(std::vector<std::string> r) {
    std::vector<std::string> present, missing, extra, junk;
    for(auto const& dir_entry: fs::directory_iterator{dir}){
        std::string item = dir_entry.path().string();
        item = item.erase(0, dir.size());
        if(std::find(r.begin(), r.end(), item) != r.end()) {
            present.push_back(item);
        }
        else {
            extra.push_back(item);
        }

    }
    for(const auto &file : r) {
        fs::exists(dir + file) ? junk.push_back(file) : missing.push_back(file);
    }
    print("Present files:", present);
    print("Missing files:", missing);
    print("Extra files:", extra); 
}


int main() {
    std::cout << "Enter Directory: ";
    
    std::cin >> dir;
    dir = dir + "/";
    
    std::cout << "\tChecking for files....\n";

    fs::exists(dir) ? checkFiles(reqFiles) : printErr(dir + " DOES NOT EXIST!");
    

    std::cout << "\tDone!" << std::endl;
    return 0;
}
