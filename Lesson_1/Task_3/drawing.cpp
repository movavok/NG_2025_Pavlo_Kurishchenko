#include <iostream>

using namespace std;

void first_figure(int);
void second_figure(int);

int main()
{
    int size = 0;

    cout << "Enter size of the first figure(working only with 10 :/): ";
    cin >> size;
    first_figure(size);

    cout << "\n\n-------------------\n\n";

    cout << "Enter size of the second figure (a whole odd number): ";
    cin >> size;
    second_figure(size);
}

void first_figure(int size){

    int right_border = size;
    int left_border = -1;
    char str[size];
    bool turn = true;
    char symbol;

    for (int row = 0; size > row; row++){
        if (turn == true){
            turn = !turn;
            symbol = '*';
            left_border++;
        } else {
            turn = !turn;
            symbol = ' ';
            if (left_border >= 1) left_border++;
        }

        if (size / 2 == left_border) break;

        for (int element = left_border; element < right_border; element++) str[element] = symbol;
        for (int element = 0; element < size; element++) cout << str[element];
        //cout << left_border << "/" << right_border;
        if (size / 2 == right_border) break;
        cout << "\n";
        right_border--;
    }
    cout << "\n";
    for (int row = 0; size > row; row++){
        if (turn == false){
            turn = !turn;
            symbol = '*';
            left_border--;
        } else {
            turn = !turn;
            symbol = ' ';
        }

        if (size / 2 - 2 == row){ // finish
            for (int element = 1; element < size; element++) str[element] = '*';
            for (int element = 0; element < size; element++) cout << str[element];
            break;
        }

        right_border++;

        for (int element = left_border; element < right_border; element++) str[element] = symbol;
        for (int element = 0; element < size; element++) cout << str[element];
        //cout << left_border << "/" << right_border;
        cout << "\n";
    }
}

void second_figure(int size){

    int stars_count = 1;
    int spaces_count = size / 2;

    for (int row = 0; size > row; row++){ // Drawing a top part and middle line of the romb
        for (int spaces = 0; spaces < spaces_count; spaces++) cout << " ";
        for (int stars = 0; stars < stars_count; stars++) cout << "*";
        cout << "\n";

        if (spaces_count < 1){
            stars_count -= 2;
            spaces_count++;
            break;
        }
        stars_count += 2;
        spaces_count--;
    }

    for (int row = 0; size > row; row++){ // Drawing a bottom part of the romb
        for (int spaces = 0; spaces < spaces_count; spaces++) cout << " ";
        for (int stars = 0; stars < stars_count; stars++) cout << "*";
        cout << "\n";
        stars_count -= 2;
        spaces_count++;
        if (stars_count < 1){
            break;
        }
    }
}
