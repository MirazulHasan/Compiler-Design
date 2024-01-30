#include <iostream>
using namespace std;

int main()
{
    int n, i;

    cout<<"Enter the size of the array: ";
    cin>>n;

    float arr[n], sum=0.0, avg;
    cout<<"\n";

    for(i = 0; i < n; ++i)
    {
        cout<<"Enter Number "<<i + 1<<" : ";
        cin>>arr[i];
        sum += arr[i];
    }

    avg = sum / n;

    cout<<"\n";
    cout<<"Average of above "<<n<<" numbers = "<<avg<<endl;

    return 0;
}
