#include <iostream>
#include <string>
using namespace std;
void search(string& pat, string& txt) {
    int M = pat.size();
    int N = txt.size();
    bool flag = true;
    // A loop to slide pat[] one by one
    for (int i = 0; i <= N - M; i++) {
        int j;

        // For current index i, check for pattern match
        for (j = 0; j < M; j++) {
            if (txt[i + j] != pat[j]) {
                break;
            }
        }

        // If pattern matches at index i
        if (j == M) {
            cout << "Pattern found at index " << i << endl;
            flag = false;
        }
    }
    if(flag){
        cout<<"Pattern not found";
    }
}

// Driver's Code
int main() {
    string pat,txt;
    cin>> txt>>pat;
    search(pat, txt);
}
