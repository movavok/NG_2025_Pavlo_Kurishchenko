#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char vowels[5] = {'a', 'e', 'u', 'o', 'i'};
    int vowCount = 0, nonCount = 0;

    cout << "Enter your sentence (to calculate the ratio of vowels and non-vowels): ";
    string line;
    getline(cin, line);

    while (line.length() == 0){
        cout << "The line is empty. Enter something: ";
        getline(cin, line);
    }
    int lineLen = line.length();

    for (int lineSymNumber = 0; lineSymNumber < lineLen; lineSymNumber++){
        bool found = false;
        for (int vowSymNumber = 0; vowSymNumber < 5; vowSymNumber++){
            if (tolower(line[lineSymNumber]) == vowels[vowSymNumber]){
                vowCount++;
                found = true;
                break;
            }
        }
        if (!found) nonCount++; // we count all the unspoken symbols (even spaces, commas, etc. As was said in the task)
    }

    double vowPercent = vowCount * 100.0 / lineLen;
    double nonPercent = nonCount * 100.0 / lineLen;

    cout << "The ratio of vowel symbols to all non-vowels is " << vowCount << ":" << nonCount << "\n";
    cout << fixed << setprecision(2) << "What percentage of the text is occupied by vowels:     " << vowPercent << "%\n";
    cout << fixed << setprecision(2) << "                                        by non-vowels: " << nonPercent << "%\n";

    return 0;
}
