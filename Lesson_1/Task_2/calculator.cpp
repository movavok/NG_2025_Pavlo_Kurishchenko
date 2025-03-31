#include <iostream>

using namespace std;

int main()
{
    double first_num = 0;
    double second_num = 0;
    char operation;

    cout << "Thats a simple calculator!\n"
            "Enter 2 whole numbers and an operation between them (like 2 + 3, use spaces to separate numbers and operation)\n"
            "'+' - plus\n"
            "'-' - minus\n"
            "'*' - multiplication\n"
            "'/' - division\n"
            "'^' - power->(first number to second number power)\n"
            "'v' - square root->(enter only one number and symbol of this operation)\n\n"
            ">> ";
    cin >> first_num >> operation >> second_num;

    if (operation == 'v'){
        cout << "Your result is: " << first_num << operation << " = " << pow(first_num, 0.5) << endl;
        if (second_num != 0)
            cout << "You should not enter second number if you choose square root operation, so i did not use that value ,_," << endl;
    }
    else if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '^') {
        switch (operation){
        case '+':
            cout << "Your result is: " << first_num << operation << second_num << " = " << first_num + second_num << endl;
            break;
        case '-':
            cout << "Your result is: " << first_num << operation << second_num << " = " << first_num - second_num << endl;
            break;
        case '*':
            cout << "Your result is: " << first_num << operation << second_num << " = " << first_num * second_num << endl;
            break;
        case '/':
            cout << "Your result is: " << first_num << operation << second_num << " = " << first_num / second_num << endl;
            break;
        case '^':
            cout << "Your result is: " << first_num << operation << second_num << " = " << pow(first_num, second_num) << endl;
            break;
        }
    }
    else{
        cout << "You entered non-exist operation or number ,_," << endl;
    }
    return 0;
}
