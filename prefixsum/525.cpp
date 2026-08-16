int sum = 0;
int max_len = 0;

unordered_map<int,int> map;
map[0] = -1;

for(int i = 0; i < nums.size(); i++) {

    if(nums[i] == 0)
        sum--;
    else
        sum++;

    if(map.find(sum) != map.end()) {
        int len = i - map[sum];
        max_len = max(max_len, len);
    }
    else {
        map[sum] = i;
    }
}