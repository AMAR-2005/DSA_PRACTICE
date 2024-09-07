// You are using GCC
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int catchThieves(string arr, int k) {
    int n = arr.length();
    queue<int> police, thieves;
    int max_catches = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 'P') {
            police.push(i);
        } else if (arr[i] == 'T') {
            thieves.push(i);
        }

        while (!police.empty() && !thieves.empty()) {
            int p = police.front();
            int t = thieves.front();

            if (abs(p - t) <= k) {
                max_catches++;
                police.pop();
                thieves.pop();
            } 
        }
    }
    return max_catches;
}

int main() {
    string arr;
    int k;
    cin >> arr >> k;
    cout << catchThieves(arr, k) << endl;
}