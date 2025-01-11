#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string ch;
    cin >> ch;

    // Precomputing frequencies using hashing
    int hashArr[26] = {0}; 
    for (int i = 0; i < n; i++) {
        hashArr[ch[i] - 'a']++;
    }

    int q;
    cin >> q; 
    while (q--) {
        char character;
        cout << "Enter the character: ";
        cin >> character;

        // Output the frequency of the character
        cout << hashArr[character - 'a'] << endl;
    }

    return 0;
}