#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool check(vector<int>& arr, int x) {
    unordered_map<int, bool> ht;
    for (int i : arr) {
        int y = x - i;
        if (ht.find(y) != ht.end()) {
            return true;
        }
        ht[i] = true;
    }
    return false;
}

int main() {
    vector<int> a = {1, 4, 3, 5, 2};
    int x = 6;
    if (check(a, x)) {
        cout << "Yes, there exists a pair";
    } else {
        cout << "No, there is no pair";
    }
    return 0;
}
