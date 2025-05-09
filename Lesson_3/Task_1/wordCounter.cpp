#include <iostream>

using namespace std;

int main()
{
    cout << "Enter your line (to count the number of words in it): ";
    string line;
    getline(cin, line);

    int lineLen = line.length();
    int wordCount = 0;
    bool isWord = false;

    for (int symNumber = 0; symNumber < lineLen; symNumber++){
        if ((line[symNumber] >= 'A' && line[symNumber] <= 'Z') || (line[symNumber] >= 'a' && line[symNumber] <= 'z')){
            if (!isWord){
                isWord = true;
                wordCount++;
            }
        }
        else isWord = false;
    }
    cout << "The number of words per line is " << wordCount;

    return 0;
}

