#inclue "../common/base.h"

class Solution {
public:
    int findNextGreater(int i, vector< pair<int,int> > &range) {
        
    }

    void nextPermutation(vector<int>& nums) {
        vector< pair<int,int> > range;
        int nextGreater = 0;

        for(int i=nums.length()-1; i>=0; --i) {
            int cur = nums[i];
            // find next greater of current number in the past
            // if yes, swap then return result
            // if no, swap to the last number + update Range
        }
    }
};

int main() {
    Solution solution;
    
    vector<int> nums = {1,3,2};
    solution.nextPermutation(nums);
    
    for(auto n: nums) cout << n << " ";
    return 0;
}
