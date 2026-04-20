#include <iostream>
using namespace std;


float calculateSalary(float base, int score, int experience) {
    float bonusPercent;

  
    if (score >= 90)
        bonusPercent = 20;
    else if (score >= 75)
        bonusPercent = 10;
    else
        bonusPercent = 5;

   
    if (experience >= 5)
        bonusPercent += 5;

    
    float bonus = (base * bonusPercent) / 100;

    
    return base + bonus;
}

int main() {
    float baseSalary;
    int score, experience;

    cin >> baseSalary >> score >> experience;

    cout << calculateSalary(baseSalary, score, experience);

    return 0;
}