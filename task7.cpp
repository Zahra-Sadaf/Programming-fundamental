#include <iostream>
#include <cmath>
using namespace std;


double calculateHeight(double distance, double angle) {
    
    double rad = angle * (3.14159 / 180);

    
    double height = distance * tan(rad);

    return height;
}

int main() {
    double distance, angle;

    cin >> distance >> angle;

    cout << calculateHeight(distance, angle);

    return 0;
}