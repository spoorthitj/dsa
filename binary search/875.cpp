class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1;

        int r = *max_element(piles.begin(), piles.end());

        int ans = r;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            long long hours = 0;

            // Calculate hours needed at speed = mid
            for (int pile : piles) {

                hours += (pile + mid - 1) / mid;
            }

            if (hours <= h) {
                // This speed works
                ans = mid;

                // Try finding a smaller speed
                r = mid - 1;
            }
            else {
                // Too slow, need a faster speed
                l = mid + 1;
            }
        }

        return ans;
    }
};