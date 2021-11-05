#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>

//must compile in c++20
//  g++ -std=c++20 hw_5.cpp

using std::filesystem::exists;

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
    
    if(){
    // FIXME if file exits run for loop else go to else block and add to extra
    	for (const auto &file : r){
	    	exists(file) ? present.push_back(file) : missing.push_back(file);
	    
    	}
    }else{
	    extra.push_back(file);
    }
    

    print("\tPresent files:", present);

    print("\tMissing files:", missing);
    
    print("\tExtra files:", extra);
}


int main() {
    std::cout << "\tChecking for files....\n";
    
    checkFiles(reqFiles);

    std::cout << "\tDone!" << std::endl;
    return 0;
}
