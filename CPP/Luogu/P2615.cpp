#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> magic_square(N, vector<int>(N, 0));

    int row = 0, col = N / 2;
    magic_square[row][col] = 1;

    for (int num = 2; num <= N * N; ++num) {
        int new_row, new_col;

        if (row == 0 && col != N - 1) {
            new_row = N - 1;
            new_col = col + 1;
        }

        else if (col == N - 1 && row != 0) {
            new_row = row - 1;
            new_col = 0;
        }

        else if (row == 0 && col == N - 1) {
            new_row = row + 1;
            new_col = col;
        }

        else {
            new_row = row - 1;
            new_col = col + 1;

            if (new_row >= 0 && new_col < N && magic_square[new_row][new_col] == 0) {
            }

            else {
                new_row = row + 1;
                new_col = col;
            }
        }


        row = new_row;
        col = new_col;

        magic_square[row][col] = num;
    }


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << magic_square[i][j];
            if (j < N - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}