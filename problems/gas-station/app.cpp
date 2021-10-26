#include "../common/base.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0, tank=0;
        
        for(int i=0; i < gas.size()*2; ++i) {
            int index = i % gas.size();
            tank += (gas[index] - cost[index]);
            
            if(tank < 0) {
                for(int j=start; j<=i;++j) {
                    index = j % gas.size();
                    tank -= (gas[index] - cost[index]);
                }

                start = i+1;
            } else {
                if(i - start >= gas.size()-1) return start%gas.size();
            }
        }
        
        return -1;
    }
};

int main() {
    Solution solution;
    
    vector<int> gas = {2,3,4};
    vector<int> cost = {3,4,3};
    cout << solution.canCompleteCircuit(gas, cost) << endl;

    return 0;
}
