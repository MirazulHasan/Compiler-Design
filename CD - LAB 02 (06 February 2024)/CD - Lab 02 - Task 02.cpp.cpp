#include <iostream>
#include <string>

using namespace std;

bool op(char ch)
{
    return(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='=');
}

int main()
{
    cout<<"Enter A String: ";
    string st;
    getline(cin, st);

    cout<<"\n";
    cout<<"Operators in the input:"<<endl;
    cout<<"\n";

    for(char ch : st)
    {
        if(op(ch))
        {
            cout<<"Operator: "<<ch<<endl;
            cout<<"\n";
        }
    }

    return 0;
}

