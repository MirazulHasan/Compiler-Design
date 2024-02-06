#include <iostream>
#include <string>

using namespace std;

bool slc(string line)
{
    return line.find("//") == 0;
}

bool mcs(string line)
{
    return line.find("/*") == 0;
}

bool mce(string line)
{
    return line.find("*/") == (line.length() - 2);
}

bool cl(string line)
{
    return slc(line) || mcs(line) && mce(line);
}

int main()
{
    cout<<"Enter A Line: ";
    string in;
    getline(cin, in);

    if (cl(in))
    {
        cout<<"\n";
        cout<<"The given input is a comment line."<<endl;
    }

    else
    {
        cout<<"\n";
        cout<<"The given input is not a comment line."<<endl;
    }

    return 0;
}

