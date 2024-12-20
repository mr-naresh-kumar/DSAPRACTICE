#include <iostream>
#include <vector>
#include <deque>
#include <climits> // For INT_MAX

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq; // Stores indices in monotonically increasing order of cumulativeSum
        vector<long long> cumulativeSum(n, 0);

        int result = INT_MAX; // To find the minimum size subarray whose sum >= k
        int j = 0;

        while (j < n) {
            if (j == 0) {
                cumulativeSum[j] = nums[j];
            } else {
                cumulativeSum[j] = cumulativeSum[j - 1] + nums[j];
            }

            if (cumulativeSum[j] >= k) {
                result = min(result, j + 1);
            }

            // Shrink the window if needed
            while (!deq.empty() && cumulativeSum[j] - cumulativeSum[deq.front()] >= k) {
                result = min(result, j - deq.front());
                deq.pop_front();
            }

            // Maintain the deque to ensure cumulativeSum[deq.back()] is always increasing
            while (!deq.empty() && cumulativeSum[j] <= cumulativeSum[deq.back()]) {
                deq.pop_back();
            }

            deq.push_back(j);
            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {2, -1, 2};
    int k1 = 3;
    cout << "Shortest subarray length: " << sol.shortestSubarray(nums1, k1) << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 11;
    cout << "Shortest subarray length: " << sol.shortestSubarray(nums2, k2) << endl;

    // Test case 3
    vector<int> nums3 = {-1, -2, -3, 4, 5, 6};
    int k3 = 7;
    cout << "Shortest subarray length: " << sol.shortestSubarray(nums3, k3) << endl;

    // Test case 4
    vector<int> nums4 = {1, 1, 1, 1, 1};
    int k4 = 10;
    cout << "Shortest subarray length: " << sol.shortestSubarray(nums4, k4) << endl;

    return 0;
}
