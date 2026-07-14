class Solution {
public:

    int countPartitions(vector<int>& nums, int maxSum) {

        int partitions = 1;
        long long subarraySum = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (subarraySum + nums[i] <= maxSum) {
                subarraySum += nums[i];
            }
            else {
                partitions++;
                subarraySum = nums[i];
            }
        }

        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());
        long long high = 0;

        for (int num : nums) {
            high += num;
        }

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            int partitions = countPartitions(nums, mid);

            if (partitions > k) {
                // Need more allowed sum
                low = mid + 1;
            }
            else {
                // Try a smaller maximum sum
                high = mid - 1;
            }
        }

        return low;
    }
};