#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// List of C++ keywords for reference
vector<string> keywords = {"auto", "break", "case", "cout", "const", "continue", "default", "do", "else", "enum", "extern", "for", "goto", "if", "register", "return", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "volatile", "while"};

// List of preprocessor directives
vector<string> preprocessorDirectives = {"#include", "#define", "#ifdef", "#endif", "#pragma"};

// List of commonly used data types
vector<string> dataTypes = {"int", "char", "float", "double", "bool", "void", "long", "short"};

bool isKeyword(const string &word) {
    return find(keywords.begin(), keywords.end(), word) != keywords.end();
}

bool isPreprocessorDirective(const string &word) {
    return find(preprocessorDirectives.begin(), preprocessorDirectives.end(), word) != preprocessorDirectives.end();
}

bool isDataType(const string &word) {
    return find(dataTypes.begin(), dataTypes.end(), word) != dataTypes.end();
}

bool isPunctuation(char ch) {
    return ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}';
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>' || ch == '%';
}

bool isLibraryFunction(const string &word) {
    return word == "iostream" || word == "ifstream" || word == "ofstream" || word == "vector" || word == "algorithm";
}

bool isUsingNamespaceStd(const string &line) {
    return line.find("using namespace std;") != string::npos;
}

bool isFunction(const string &word) {
    return word == "main";
}

bool isVariable(const string &word) {
    return word == "x" || word == "y" || word == "z";
}

int main() {
    ifstream file("lex_input.txt");
    if (!file.is_open()) {
        cout << "Error opening file\n";
        return 1;
    }

    string line;
    bool usingNamespaceStdFound = false; // Flag to indicate if using namespace std is found
    while (getline(file, line)) {
        if (isUsingNamespaceStd(line)) {
            cout << line << " to avoid std:: prefix\n";
            usingNamespaceStdFound = true;
        } else {
            string buffer;
            bool isMainFound = false;
            bool inString = false; // Flag to indicate if currently parsing a string
            bool inNumber = false; // Flag to indicate if currently parsing a number
            for (char ch : line) {
                if (ch == '"' && !inString) {
                    inString = true;
                    buffer += ch;
                } else if (ch == '"' && inString) {
                    inString = false;
                    buffer += ch;
                    cout << buffer << " is an output statement\n";
                    buffer.clear();
                } else if (inString) {
                    buffer += ch;
                } else if (isdigit(ch) && !inNumber) {
                    inNumber = true;
                    buffer += ch;
                } else if (isdigit(ch) && inNumber) {
                    buffer += ch;
                } else if (!isdigit(ch) && inNumber) {
                    cout << buffer << " is a constant\n";
                    buffer.clear();
                    inNumber = false;
                    buffer += ch;
                } else if (ch == ' ' || ch == '\t') {
                    // Check if buffer contains a keyword, preprocessor directive, data type, library function, function name, or variable
                    if (!buffer.empty()) {
                        if (isKeyword(buffer)) {
                            cout << buffer << " is a reserved keyword\n";
                        } else if (isPreprocessorDirective(buffer)) {
                            cout << buffer << " is a preprocessor directive\n";
                        } else if (isDataType(buffer)) {
                            cout << buffer << " is a data type\n";
                        } else if (isLibraryFunction(buffer)) {
                            cout << buffer << " is a library function\n";
                        } else if (isFunction(buffer)) {
                            cout << buffer << "() is a function name\n";
                            isMainFound = true;
                        } else if (isVariable(buffer)) {
                            cout << buffer << " is a variable\n";
                        }
                        buffer.clear();
                    }
                } else if (isPunctuation(ch)) {
                    cout << ch << " is a punctuation\n";
                } else if (isOperator(ch)) {
                    cout << ch << " is an operator\n";
                } else {
                    buffer += ch;
                }
            }
            // Check buffer at the end of the line
            if (!buffer.empty()) {
                if (isKeyword(buffer)) {
                    cout << buffer << " is a keyword\n";
                } else if (isPreprocessorDirective(buffer)) {
                    cout << buffer << " is a preprocessor directive\n";
                } else if (isDataType(buffer)) {
                    cout << buffer << " is a data type\n";
                } else if (isLibraryFunction(buffer)) {
                    cout << buffer << " is a library function\n";
                } else if (isFunction(buffer)) {
                    cout << buffer << "() is a function name\n";
                    isMainFound = true;
                } else if (isVariable(buffer)) {
                    cout << buffer << " is a variable\n";
                } else if (inNumber) {
                    cout << buffer << " is a constant\n";
                } else {
                    cout << buffer << " is an punctuation\n";
                }
            }
        }
    }

    file.close();
    return 0;
}
