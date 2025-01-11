#include <iostream>

using namespace std;

int Maxx(int a, int b) {
    if (a >= b) return a;
    else return b;
}

int arrayMod(int arr[], int n) {
    arr[0] = arr[0] + 100; // Modify the first element
    return arr[n-1]; // Return the last element of the array
}

int main() {
    int c = Maxx(190, 220);
    cout << "Max value: " << c << endl;

    int n = 6;
    int aray[] = {2, 4, 5, 6, 7, 8}; // Initialize the array

    int b = arrayMod(aray, n); // Pass array to the function

    cout << "Modified first element: " << aray[0] << endl; // Display modified first element
    cout << "Last element returned: " << b << endl; // Display last element

    return 0;
}
