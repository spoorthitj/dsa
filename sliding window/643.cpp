class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
    for(int i=0;i<k;i++){
      sum+=nums[i];
    }
    double max=sum/k;
    int j=0;
    for(int i=k;i<nums.size();i++){
        sum=sum+nums[i]-nums[j];
        double s=sum/k;
        if(s>max){
            max=s;
        }
        j++;
    }
    return max;
    }
};