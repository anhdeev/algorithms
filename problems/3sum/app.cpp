#include "../common/base.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> cache;
        vector< vector<int> > result;
        
        sort(nums.begin(), nums.end());
        for(auto &num: nums) {
            if(cache.count(num)==0) cache[num] = 0;
            cache[num] += 1;
            cout << num << "=" << cache[num] << endl;
        }

        int lastj = 100001, lasti=100001;
        for(int i=0;i<nums.size();++i) {
            if(nums[i]==lasti) continue;
            else lasti=nums[i];

            for(int j=i+1;j<nums.size();++j) {
                int sum2 = -(nums[i] +nums[j]);
                vector<int> v = {nums[i], nums[j], sum2};
                if(nums[j]==lastj) continue;
                else lastj=nums[j];


                if(sum2 == nums[j]) {
                    if(cache[sum2] < 1) continue;
                    else if(nums[i]!=nums[j] && cache[sum2] > 1) result.push_back(v);
                    else if(nums[i]==nums[j] && cache[sum2]>2) result.push_back(v);
                    else continue;
                } else if (sum2 < nums[j]) {
                    continue;
                } else if(cache[sum2] > 0) {
                    result.push_back(v);
                }
            }
        }
        
        return result; 
    }
};

int main() {
    Solution solution;
    
    vector<int> nums = {0,0};
    vector< vector <int> > result = solution.threeSum(nums);

    for(auto v:result) {
        for(auto item: v) {
            cout << item << ",";
        }
        cout << endl;
    }
    return 0;
}
