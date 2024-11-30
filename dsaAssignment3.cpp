#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void intersection(vector<int>& a1, vector<int>& a2) {
    unordered_map<int, bool> ht;
    for (int i : a2) {
        ht[i] = true;
    }
    cout << "Elements present in a1 but not in a2: ";
    bool found = false;
    for (int i : a1) {
        if (ht.find(i) == ht.end()) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "None";
    }
    cout << endl;
}

int main() {
    vector<int> a1 = {1, 2, 3, 4, 5, 6};
    vector<int> a2 = {1, 3, 5, 7, 9};
    intersection(a1, a2);
    return 0;
}
