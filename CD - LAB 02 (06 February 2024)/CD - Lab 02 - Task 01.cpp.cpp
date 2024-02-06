#include <iostream>
#include <string>

using namespace std;

bool nc(string in)
{
    for(char ch : in)
    {
        if (ch < '0' || ch > '9')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string uInput;

    cout<<"Enter A Value: ";
    cin>>uInput;

    if (nc(uInput))
    {
        cout<<"\n";
        cout<<"The Value Is A Numeric Constant."<<endl;
    }

    else
    {
        cout<<"\n";
        cout<<"The Value Is Not A Numeric Constant."<<endl;
    }

    return 0;
}
