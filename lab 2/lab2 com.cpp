
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <set>
using namespace std;

int main() {
    ifstream input_file("file.txt");
    if (!input_file.is_open()) {
        cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    string line;
    string code;

    // Read the content of the file into a single string
    while (getline(input_file, line)) {
        code += line + "\n";

    }

    // Define regular expressions for C++ tokens
    regex keyword_regex("\\b(if|int|return|else|while|for)\\b");
    regex identifier_regex("\\b[a-zA-Z_]\\w*\\b");
    regex constant_regex("\\b\\d+\\b");
    regex operator_regex("[\\+\\-\\*\\/=<>]");
    regex punctuation_regex("[;(){}\\[\\],.:\"']");

    set<string> uniqueOperators;
    set<string> uniquePunctuations;
    set<string> uniqueKeywords;
    set<string> uniqueConstants;
    set<string> uniqueIdentifiers;

    // Tokenize the code using regular expressions
    sregex_iterator it(code.begin(), code.end(), keyword_regex);
    sregex_iterator end;
    while (it != end) {
        std::smatch match = *it;
        uniqueKeywords.insert(match.str());
        ++it;
    }

    it = sregex_iterator(code.begin(), code.end(), identifier_regex);
    while (it != end) {
        std::smatch match = *it;
        uniqueIdentifiers.insert(match.str());
        ++it;
    }

    it = sregex_iterator(code.begin(), code.end(), constant_regex);
    while (it != end) {
        std::smatch match = *it;
        uniqueConstants.insert(match.str());
        ++it;
    }

    it = sregex_iterator(code.begin(), code.end(), operator_regex);
    while (it != end) {
        std::smatch match = *it;
        uniqueOperators.insert(match.str());
        ++it;
    }

    it = sregex_iterator(code.begin(), code.end(), punctuation_regex);
    while (it != end) {
        std::smatch match = *it;
        uniquePunctuations.insert(match.str());
        ++it;
    }

    // Display the unique tokens for each category
    cout << "Operators: ";
    for (const string& op : uniqueOperators) {
        cout << op << " ";
    }
    cout << endl;

    cout << "Punctuations: ";
    for (const string& punc : uniquePunctuations) {
        cout << punc << " ";
    }
    cout << endl;

    cout << "Keywords: ";
    for (const std::string& kw : uniqueKeywords) {
        cout << kw << " ";
    }
    cout << endl;

    cout << "Constants: ";
    for (const string& constant : uniqueConstants) {
        cout << constant << " ";
    }
    cout << std::endl;

    cout << "Identifiers: ";
    for (const string& id : uniqueIdentifiers) {
        cout << id << " ";
    }
    cout <<endl;

    input_file.close();

    return 0;
}
