#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isValidVariableName(const string& name)
{
    if (!(name[0] >= 'a' && name[0] <= 'z') && !(name[0] >= 'A' && name[0] <= 'Z') && name[0] != '_')
    {
        cout << "- False" << endl;
        cout << "- Variable name must start with a letter or underscore." << endl;
        return false;
    }

    for (char c : name)
    {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_'))
        {
            cout << "- False" << endl;
            cout << "- Special character in variable name: '" << c << "'" << endl;
            return false;
        }
    }

    if (name == "main" ||name == "int" || name == "char" || name == "double" || name == "float" ||
        name == "else" || name == "while" || name == "for" || name == "return" || name == "class" ||
        name == "do" || name == "new" || name == "switch" || name == "long" || name == "operator" ||
        name == "template" || name == "break" || name == "string" || name == "if")
    {
        cout << "- False" << endl;
        cout << "- The name '" << name << "' is a reserved keyword." << endl;
        return false;
    }

    return true;
}

int main()
{
    string input;
    cout << "Enter a variable name: ";
    getline(cin, input);

    ofstream outputFile("variableName.txt");

    if (outputFile.is_open())
    {
        outputFile << input;
        outputFile.close();
    }

    else
    {
        return 1;
    }

    ifstream inputFile("variableName.txt");

    if (inputFile.is_open())
    {
        string storedName;
        getline(inputFile, storedName);
        inputFile.close();

        if (isValidVariableName(storedName))
        {
            cout << "- True" << endl;
            cout << "- The name '" << storedName << "' is a valid variable name." << endl;
        }
        else
        {

        }
    }

    else
    {
        return 1;
    }

    return 0;
}
