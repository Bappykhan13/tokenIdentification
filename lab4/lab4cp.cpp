#include <iostream>
#include <fstream>
#include <regex>
#include <unordered_set>

using namespace std;

int main() {
    ifstream inputFile("com4.cpp");

    if (!inputFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string fileContents((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());

   
    
    regex functionRegex(R"(\b(?:int|void|double|float|char)\s+(\w+)\s*\([^)]*\)\s*\{)");

    smatch match;
    unordered_set<string> functionSet;

    
    
    auto words_begin = sregex_iterator(fileContents.begin(), fileContents.end(), functionRegex);
    auto words_end = sregex_iterator();

    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;
        string functionName = match[1];
 if (functionName != "main") {
            functionSet.insert(functionName);
        }    }

    inputFile.close();

   
    
    cout << "Unique User-Defined Functions:" << endl;
    for (const string& functionName : functionSet) {
        cout << functionName << endl;
    }

    
    
    cout << "Total number of unique user-defined functions: " << functionSet.size() << endl;

    return 0;
}
