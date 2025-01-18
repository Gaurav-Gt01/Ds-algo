/*
/ The Solution class with mergeSort and merge methods
class Solution {
  public:
    vector<int> temp;

    void mergeSort(vector<int> &arr, int l, int h) {
        // Base case
        if (l >= h) return;

        int mid = l + (h - l) / 2; // Correct midpoint calculation
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);

        // Merging:
        merge(arr, l, mid, h);
    }

    void merge(vector<int> &arr, int low, int mid, int high) {
        temp.clear(); // Clear temp before using it
        
        int left = low;
        int right = mid + 1;

        // Merge the two sorted parts
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.emplace_back(arr[left]);
                left++;
            } else {
                temp.emplace_back(arr[right]);
                right++;
            }
        }

        // When the right array is exhausted
        while (left <= mid) {
            temp.emplace_back(arr[left]);
            left++;
        }

        // When the left array is exhausted
        while (right <= high) {
            temp.emplace_back(arr[right]);
            right++;
        }

        // Copy the merged elements back to the original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
};
*/