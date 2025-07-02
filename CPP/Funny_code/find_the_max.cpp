#include <iostream>
#include <cmath>

using namespace std;

void find_max(int arr[]);

int main() 
{
    int num[10];

    for (int i = 0; i < 10; i++) 
    {
        cin >> num[i];
    }

    find_max(num);

    return 0;
}

void find_max(int arr[]) 
{
    int max = arr[0], position = 1;

    for (int i = 1; i < 10; i++) 
    {
        if (max < arr[i]) 
        {
            max = arr[i];
            position = i + 1;
        }
    }

    for (int i = 0; i < 10; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "The largest number is: " << max << endl
         << "The position of this number is: " << position << endl;
}