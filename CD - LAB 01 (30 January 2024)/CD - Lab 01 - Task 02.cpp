#include <iostream>
using namespace std;

int main()
{
    int i, n;

    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    cout<<"\n";

    for(i = 0; i < n; ++i)
    {
        cout<<"Enter number "<<i + 1<<" : ";
        cin>>arr[i];
    }

    for(i = 1;i < n; ++i)
    {
        if(arr[0] < arr[i])
        {
            arr[0] = arr[i];
        }
    }

    cout<<"\n";
    cout<< "Largest number = " << arr[0];

    for(i = 1;i < n; ++i)
    {
        if(arr[0] > arr[i])
        {
            arr[0] = arr[i];
        }
    }

    cout<<"\n";
    cout<< "Smallest number = " << arr[0]<<endl;

    return 0;
}
