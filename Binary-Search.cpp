#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for(int i=0;i<n;i++) 
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());

    cout << "Enter the element to be searched: ";
    int key;
    cin >> key;
    int low = 0, high = n-1;
    
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == key)
        {
            cout << "Element found at index " << mid << endl;
            return 0;
        }
        else if(arr[mid] < key) 
        {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }
    cout << "Element not found" << endl;
    return 0;
}