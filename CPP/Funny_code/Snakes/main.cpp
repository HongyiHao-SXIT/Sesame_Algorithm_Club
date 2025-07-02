#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

const int width = 20;
const int height = 20;

vector<pair<int, int>> snake;

void InitSnake() {
    snake.clear();
    snake.push_back({10, 10}); 
    snake.push_back({9, 10});
    snake.push_back({8, 10});
}

void Draw() {
    system("cls");

    for (int y = 0; y <= height; y++) {
        for (int x = 0; x <= width; x++) {
            if (x == 0 || x == width || y == 0 || y == height) {
                cout << "#";
            } else {
                bool isSnake = false;
                for (int i = 0; i < snake.size(); i++) {
                    if (snake[i].first == x && snake[i].second == y) {
                        if (i == 0) cout << "O";
                        else cout << "o";
                        isSnake = true;
                        break;
                    }
                }
                if (!isSnake) cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    InitSnake();
    while (true) {
        Draw();
        Sleep(200);
    }
    return 0;
}
