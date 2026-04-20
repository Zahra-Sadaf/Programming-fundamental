#include <iostream>
#include <cmath>
using namespace std;

string projectTimeCalculation(int neededHours, int days, int workers) {
    
    double workingDays = days * 0.9;

   
    double totalHours = workingDays * workers * 10;

   
    int availableHours = floor(totalHours);

    if (availableHours >= neededHours) {
        int left = availableHours - neededHours;
        return "Yes!" + to_string(left) + " hours left.";
    } 
    else {
        int needed = neededHours - availableHours;
        return "Not enough time!" + to_string(needed) + " hours needed.";
    }
}