#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long result = 0;
        long long currentWindowSum = 0;
        unordered_set<int> st;

        int i = 0; 
        int j = 0;

        while (j < n) {
            // Check if nums[j] is already present in the current window
            while (st.count(nums[j])) {
                currentWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            currentWindowSum += nums[j];
            st.insert(nums[j]);

            // If the window size matches k, update result
            if (j - i + 1 == k) {
                result = max(result, currentWindowSum);
                currentWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return result;
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 3;

    Solution solution;
    long long result = solution.maximumSubarraySum(nums, k);

    cout << "Maximum Subarray Sum with distinct elements of size " << k << ": " << result << endl;

    return 0;
}
