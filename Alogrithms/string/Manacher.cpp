#include <iostream>
#include<vector>
using namespace std;
// Function to find the longest palindromic substring
string longestPalindrome(string txt) {
    // Transform the input string by inserting '#' between each character
    string transformed = "#";
    for (char c : txt) {
        transformed += c;
        transformed += "#";
    }

    int n = transformed.size();
    vector<int> p(n, 0);  // Array to store the radius of palindromes
    int maxLen = 0;       // Maximum length (radius) of palindrome found
    int center = 0;       // Center of the longest palindrome found
    for (int i = 1; i < n - 1; i++) {
        int a = i - 1;    // Left index for expansion
        int b = i + 1;    // Right index for expansion

        // Expand around the center i while the characters match
        while (a >= 0 && b < n && transformed[a] == transformed[b]) {
            a--;
            b++;
            p[i]++;  // Increase the palindrome radius for center i
        }
        if (p[i] > maxLen) {
            maxLen = p[i];
            center = i;
        }
    }
    // Calculate the starting index of the longest palindrome in the original string
    int startIndex = (center - maxLen) / 2;

    return txt.substr(startIndex, maxLen);
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    // Find and output the longest palindromic substring
    cout << "Longest Palindromic Substring of \"" << str << "\" is: " 
         << longestPalindrome(str) << endl;

    return 0;
}
