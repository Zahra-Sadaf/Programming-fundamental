#include <iostream>
using namespace std;

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}


bool isStrong(int num) {
    int temp = num;
    int sum = 0;

    while (temp > 0) {
        int digit = temp % 10;
        sum += factorial(digit);
        temp /= 10;
    }

    return (sum == num);
}

int main() {
    int num;
    cin >> num;

    if (isStrong(num)) {
        cout << "Strong Number";
    } else {
        cout << "Not a Strong Number";
    }

    return 0;
}