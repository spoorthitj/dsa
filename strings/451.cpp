class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>map;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }
        vector<pair<char,int>>v(map.begin(),map.end());
sort(v.begin(), v.end(), [](auto a, auto b) {
    return a.second > b.second;
});
string k="";
for (auto p : v) {
    for (int i = 0; i < p.second; i++) {
        k += p.first;
    }
}
  return k;  }
};