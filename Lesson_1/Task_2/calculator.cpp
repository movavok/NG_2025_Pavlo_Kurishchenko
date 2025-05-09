#include <iostream>

using namespace std;

void calculate(double a, double b, char oper, double result){ cout << "Your result is: " << a << oper << b << " = " << result << endl;}

int main()
{
    double first_num = 0;
    double second_num = 0;
    char operation;

    cout << "Thats a simple calculator!\n"
            "Enter 2 whole numbers and an operation between them (like 2 + 3, use spaces to separate numbers and operation)\n"
            "'+'  - plus\n"
            "'-'  - minus\n"
            "'*'  - multiplication\n"
            "'/'  - division\n"
            "'^'  - power->(first number to second number power)\n"
            "'v2' - square root->(enter only your number and symbol of this operation)\n\n";

    while (true){
        cout << ">> ";
        cin >> first_num >> operation >> second_num;

        if (operation == 'v'){ // square root
            if (second_num != 2) cerr << "Incorrect symbol ,_," << endl;
            else calculate(first_num, 2, operation, pow(first_num, 0.5));
        }
        else if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '^') { // other operations
            double result = 0;
            switch (operation){
            case '+': result = first_num + second_num; break;
            case '-': result = first_num - second_num; break;
            case '*': result = first_num * second_num; break;
            case '/': result = first_num / second_num; break;
            case '^': result = pow(first_num, second_num); break;
            }
            calculate(first_num, second_num, operation, result);
        }
        else cerr << "You entered non-exist operation or number ,_," << endl;
    }
    return 0;
}
