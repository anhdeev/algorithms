#include "../common/base.h"

class Solution {
public:
    void rotate_one(int &r, int &c, const int size) {
        int tmp = r;
        r = c;
        c = size-1-tmp;
    }
    void rotate(vector<vector<int>>& matrix) {
        pair<int,int> indexer = make_pair(0,0);
        const int size = matrix.size();
        const int depth = size/2;
        
        for(int z=0; z<depth; z++) {
            for(int i=z; i<size-1-z; i++) {
                int r=z,c=i;
                int last = matrix[r][c];
                for(int j=0; j<4; j++) {
                    // rotate
                    rotate_one(r,c, size);
                    cout << r << "," << c << endl;
                    int tmp = matrix[r][c];
                    matrix[r][c] = last;
                    last = tmp;
                }
            }
        }
    }
};

int main() {
    Solution solution;
    
    vector< vector<int> > nums = {{1,2,3}, {4,5,6}, {7,8,9}};
    solution.rotate(nums);

    for(auto v:nums) {
        for(auto item: v) {
            cout << item << ",";
        }
        cout << endl;
    }
    return 0;
}
