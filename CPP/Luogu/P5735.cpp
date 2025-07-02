#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

constexpr double calculateDistance(double x1, double y1, double x2, double y2) noexcept {
    const double dx = x1 - x2;
    const double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct Point { double x, y; };
    Point p1, p2, p3;
    
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

    const double perimeter = calculateDistance(p1.x, p1.y, p2.x, p2.y)
                          + calculateDistance(p2.x, p2.y, p3.x, p3.y)
                          + calculateDistance(p3.x, p3.y, p1.x, p1.y);

    cout << fixed << setprecision(2) << perimeter << '\n';

    return 0;
}