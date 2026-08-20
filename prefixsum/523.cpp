class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
     unordered_map<int,int>map;
     int sum=0;
     map[0]=-1;
     for(int i=0;i<nums.size();i++){
        sum=sum+nums[i];
        int rem=sum%k;
if (map.find(rem) != map.end() && i-map[rem]>=2 ){
return true;
}
if (map.find(rem) == map.end()) {
    map[rem] = i;
}   
    }
    return false;}
};