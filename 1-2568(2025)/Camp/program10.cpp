#include <iostream>
using namespace std;

int main() {
    float temperature;
    cin >> temperature;
    if(temperature > 37.5){
        cout << "Fever";
    }
    else {
        cout << "Normal";
    }
}