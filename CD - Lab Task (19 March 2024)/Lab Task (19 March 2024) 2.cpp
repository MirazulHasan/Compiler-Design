#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool isReservedKeyword(const string& name)
{
    static const vector<string> keywords =
    {
        "int", "char", "double", "float", "if", "else", "while",
        "for", "return", "class", "do", "new", "switch", "long",
        "operator", "template", "break", "string"
    };
    return find(keywords.begin(), keywords.end(), name) != keywords.end();
}

bool isValidVariableName(const string& name) {
    if (!(isalpha(name[0]) || name[0] == '_')) {
        return false; // Variable name must start with a letter or underscore.
    }

    for (char c : name) {
        if (!(isalnum(c) || c == '_')) {
            return false; // Special character in variable name.
        }
    }

    return !isReservedKeyword(name);
}

int main() {
    string input;
    cout << "Enter a variable name: ";
    getline(cin, input);

    // Writing input to a file
    ofstream outputFile("variableName.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return 1;
    }
    outputFile << input;
    outputFile.close();

    // Reading input from the file
    ifstream inputFile("variableName.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file for reading." << endl;
        return 1;
    }
    string storedName;
    getline(inputFile, storedName);
    inputFile.close();

    // Validating stored name
    if (isValidVariableName(storedName)) {
        cout << "The name '" << storedName << "' is a valid variable name." << endl;
    } else {
        cout << "The name '" << storedName << "' is not a valid variable name." << endl;
    }

    return 0;
}
