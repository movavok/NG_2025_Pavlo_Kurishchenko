#include <iostream>

using namespace std;

int enterNumbers(int numbers[]){
    int maxNumber = 0;
    for (int index = 0; index < 5; index++) {
        cout << "Enter number " << index + 1 << ": ";
        cin >> numbers[index];
        if (numbers[index] < 0){
            cout << "(Enter an integer greater than or equal to zero)\n";
            index--;
            continue;
        } else if (maxNumber < numbers[index]) maxNumber = numbers[index];
    }
    return maxNumber;
}

void drawStars(int maxNumber, int numbers[]){
    for (int row = 0; row < maxNumber; row++){
        for (int colm = 0; colm < 5; colm++){
            if (numbers[colm] - row > 0) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
}

int main() {
    cout << "(Enter 5 integers >= 0 so that I can draw stars the number of which corresponds to the given numbers)\n";
    int numbers[5];

    drawStars(enterNumbers(numbers), numbers);

    return 0;
}

