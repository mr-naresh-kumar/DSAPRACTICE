#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        
        // If k == 0, all elements in the result array are 0
        if (k == 0) {
            return result;
        }

        int i = -1, j = -1;
        if (k > 0) {
            i = 1;      // Start index for window sum
            j = k;      // End index for window sum
        } else {
            i = n - abs(k); // Start from the left end for negative k
            j = n - 1;      // Wrap around for the end
        }

        int windowSum = 0;

        // Initialize window sum
        for (int pointer = i; pointer <= j; pointer++) {
            windowSum += code[pointer % n];
        }

        // Calculate result array
        for (int index = 0; index < n; index++) {
            result[index] = windowSum;

            // Slide the window
            windowSum -= code[i % n];      // Remove the outgoing element
            i++;
            windowSum += code[(j + 1) % n]; // Add the incoming element
            j++;
        }

        return result;
    }
};

int main() {
    // Example input
    vector<int> code = {5, 7, 1, 4};
    int k = 3;

    // Create Solution object
    Solution solution;
    vector<int> result = solution.decrypt(code, k);

    // Print result
    cout << "Decrypted code: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
