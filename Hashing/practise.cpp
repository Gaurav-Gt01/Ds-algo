#include <iostream>
#include <vector>
#include <algorithm> // Include for std::max_element

using namespace std;

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    // Find the maximum element
    auto maxElementIterator = max_element(v.begin(), v.end());
    int maxElement = *maxElementIterator; // Dereference iterator to get the value

    cout << maxElement << endl;

    return 0;
}