class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        int prefix = 0;
        int count = 0;

        freq[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];

            int needed = prefix - k;

            if (freq.find(needed) != freq.end()) {
                count += freq[needed];
            }

            freq[prefix]++;
        }

        return count;
    }
};