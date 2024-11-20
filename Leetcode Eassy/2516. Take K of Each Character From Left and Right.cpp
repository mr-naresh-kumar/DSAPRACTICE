#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int takeCharacters(string& s, int k) {
        const int n = s.size();
        int freq[3] = {0}; // Frequency array for 'a', 'b', 'c'
        
        // Calculate the initial frequency of characters
        for (char c : s)
            freq[c - 'a']++;
        
        // If any character's frequency is less than k, return -1
        if (any_of(freq, freq + 3, [k](int f) { return f < k; }))
            return -1;

        int ans = n; // Initialize the answer to the length of the string

        // Sliding window approach
        for (int l = 0, r = 0; r < n; r++) {
            int x = s[r] - 'a';
            freq[x]--; // Decrease frequency of the current character
            
            // Shrink the window from the left while it is invalid
            while (l <= r && any_of(freq, freq + 3, [k](int f) { return f < k; })) {
                freq[s[l] - 'a']++;
                l++;
            }
            
            // Update the minimum length of substring to be removed
            ans = min(ans, n - (r - l + 1));
        }

        return ans;
    }
};

// Initialize I/O optimizations
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main() {
    string s;
    int k;
    
    // Input the string and value of k
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the value of k: ";
    cin >> k;

    // Call the function and print the result
    int result = Solution::takeCharacters(s, k);
    cout << "Minimum length of substring to be removed: " << result << endl;

    return 0;
}

