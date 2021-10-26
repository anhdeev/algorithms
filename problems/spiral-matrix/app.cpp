#include "../common/base.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int size_n = matrix.size();
        int size_m = matrix[0].size();
        int depth = min(size_n,size_m)/2;

        vector< pair<int,int> > conners ={{size_n-1,0}, {size_n-1, size_m-1}, {0,size_m-1}, {0,0}};
        for(int z=0; z<depth; ++z) {
            bool horizon=true;

            for(int j=0; j<4; ++j) {
                pair<int, int> con = conners[conners.size()-1-j];
                int r = con.first==0? z: con.first-z;
                int c = con.second==0? z: con.second-z;

                if(con.first==0 && con.second==0) {
                    for(int i=z; i<size_m-1-z;++i) {
                        result.push_back(matrix[r][i]);
                    }
                } else if(con.first==0 && con.second!=0) {
                    for(int i=z; i<size_n-1-z;++i) {
                        result.push_back(matrix[i][c]);
                    }
                } else if(con.first!=0 && con.second!=0) {
                    for(int i=size_m-1-z; i>z;--i) {
                        result.push_back(matrix[r][i]);
                    }
                } else {
                    for(int i=size_n-1-z; i>z;--i) {
                        result.push_back(matrix[i][c]);
                    }
                }
            }
        }
        
        if(size_m%2 && size_m==size_n) result.push_back(matrix[depth][depth]);
        else if(size_m>size_n&& size_m*size_n > result.size()) {
            for(int i=depth; i < size_m-depth; ++i) {
                result.push_back(matrix[depth][i]);
            }
        } else if(size_m < size_n && size_m*size_n > result.size()) {
            for(int i=depth; i < size_n-depth; ++i) {
                result.push_back(matrix[i][depth]);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    
    //vector< vector<int> > nums = {{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}, {13,14,15}};
    vector< vector<int> > nums = {{0,1},{2,3},{4,5}};
    vector<int> rst = solution.spiralOrder(nums);

    for(auto v: rst) {
        cout << v << " ";
    }
    return 0;
}
