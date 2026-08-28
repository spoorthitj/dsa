class Solution {
public:

    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {

    int conse = 0;
    int count = 0;

    for (int i = 0; i < bloomDay.size(); i++) {

        if (bloomDay[i] <= day) {
            conse++;
        }
        else {
            conse = 0;
        }

        if (conse == k) {
            count++;
            conse = 0;  // flowers used for one bouquet
        }

        if (count == m) {
            return true;
        }
    }

    return false;
}

    int minDays(vector<int>& bloomDay, int m, int k) {

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};