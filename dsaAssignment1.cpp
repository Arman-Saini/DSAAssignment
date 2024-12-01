#include <iostream>
#include <unordered_map>
using namespace std;

int mostFrequentElement(int arr[], int n) {
    unordered_map<int, int> freqMap;
    for (int i = 0; i < n; i++) {
        freqMap[arr[i]]++;
    }

    int maxFreq = 0, mostFreqElement = -1;
    for (const auto& pair : freqMap) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            mostFreqElement = pair.first;
        }
    }
    return mostFreqElement;
}

int main() {
    int arr[] = {1, 3, 2, 2, 4, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Most frequent element: " << mostFrequentElement(arr, n) << endl;
    return 0;
}