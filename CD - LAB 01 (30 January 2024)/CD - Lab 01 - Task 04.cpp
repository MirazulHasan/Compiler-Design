#include <iostream>
using namespace std;

int main()
{
    int i, n, fact = 1;

    cout<<"Enter any positive number: ";
    cin>>n;
    cout<<"\n";

    for(i=1; i<=n; i++)
    {
        fact = fact*i;
    }
    cout<<"Factorial of " <<n<<" is: "<<fact<<endl;

    return 0;
}
