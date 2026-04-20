#include <iostream>
using namespace std;


float calculateBalance(float balance, int years) {
    float interestRate;

    
    if (balance < 10000)
        interestRate = 5;
    else if (balance <= 50000)
        interestRate = 7;
    else
        interestRate = 10;

   
    if (years >= 3)
        interestRate += 2;

   
    float interest = (balance * interestRate) / 100;

    
    return balance + interest;
}

int main() {
    float balance;
    int years;

    cin >> balance >> years;

    cout << calculateBalance(balance, years);

    return 0;
}