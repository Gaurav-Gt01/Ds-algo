#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find element in sorted array
    // arr: input array
    // k: element to be searched
    bool searchInSorted(vector<int>& arr, int k) {

        int n = arr.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == k) {
                cnt++;
            }
        }
        if (cnt == 0) return false;
        else return true;
    }
};

int main() {
    Solution solution;
    vector<int> arr;
    int n, k;

    // Input size of array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    // Input the element to be searched
    cout << "Enter the element to search: ";
    cin >> k;

    // Call the function and display the result
    bool result = solution.searchInSorted(arr, k);
    if (result) {
        cout << "Element found in the array." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
