#include <iostream>
#include <string>

using namespace std;

bool isValidVariableName(const string& name)
{
    if (!(name[0] >= 'a' && name[0] <= 'z') && !(name[0] >= 'A' && name[0] <= 'Z') && name[0] != '_')
    {
        cout<<"\n";
        cout<<"- The name is not a valid variable name."<<endl;
        cout<<"\n";
        cout<<"- Variable name must start with a letter or underscore."<<endl;

        return false;
    }

    for (char c : name)
    {
        if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_'))
        {
            cout<<"\n";
            cout<<"- The name is not a valid variable name."<<endl;
            cout<<"\n";
            cout<<"- Special character in variable name: '"<<c<<"'"<<endl;

            return false;
        }
    }

    if (name == "int" || name == "char" || name == "double" || name == "float" || name == "if" ||
        name == "else" || name == "while" || name == "for" || name == "return" || name == "class" ||
        name == "do" || name == "new" || name == "switch" || name == "long" || name == "operator" ||
        name == "template" || name == "break")
    {
        cout<<"\n";
        cout<<"- The name is not a valid variable name."<<endl;
        cout<<"\n";
        cout<<"- The name '"<<name<<"' is a reserved keyword."<<endl;

        return false;
    }

    return true;
}

int main()
{
    string input;
    cout<<"Enter a variable name: ";
    getline(cin, input);

    if(isValidVariableName(input))
    {
        cout<<"\n";
        cout<<"- The name '"<<input<<"' is a valid variable name."<<endl;
    }
    return 0;
}
