#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= std::sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

std::vector<int> findPalindromicPrimes(int a, int b) {
    std::vector<int> result;
    for (int num = a; num <= b; ++num) {
        if (isPalindrome(num) && isPrime(num)) {
            result.push_back(num);
        }
    }
    return result;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::vector<int> palindromicPrimes = findPalindromicPrimes(a, b);
    for (int prime : palindromicPrimes) {
        std::cout << prime << std::endl;
    }
    return 0;
}