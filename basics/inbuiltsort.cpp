#include <iostream>
#include <vector>
#include <algorithm> // Include algorithm for sort

using namespace std;

int main() {
    int array[] = {10, 2, 5, 4, 1};
    sort(array, array + 5, greater<int>() );

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) { // Corrected loop condition
        cout << array[i] << " ";
    }

    cout << endl;
    return 0;
}