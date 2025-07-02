#include <iostream>
using namespace std;

void hail(int num) {
    int arr[1000];
    int time = 0;
    arr[time] = num;
    time++;

    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = num * 3 + 1;
        }
        arr[time] = num;
        time++;
    }

    for (int i = 0; i < time; i++) {
        cout << arr[i];
        if (i < time - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    hail(n);
    return 0;
}