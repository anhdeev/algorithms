#include "../common/base.h"

class Solution {
public:
    bool isValidSudoku(vector< vector<char> >& board) {
        map< int, array<int, 3> > marked = {};
        
        for(int i=0; i< 9; ++i)
            for(int j=0; j< 9; ++j) {
                char num = board[i][j];
                if(num == '.') continue;
                
                if(marked.count(num) > 0) {
                    // Check overlap
                    bool overlap = false;
                    overlap =
                        ((marked[num][0] & (1<<i)) != 0) ||
                        ((marked[num][1] & (1<<j)) != 0) ||
                        ((marked[num][2] & (1 << ((i/3 * 3) + j/3))) != 0);
                    if(overlap)  {
                        cout << marked[num][0] << ":" << marked[num][1] << ":" << marked[num][2] << endl;
                        cout << "i,j=" << i <<"," << j << endl;
                        return false;
                    }
                } else {
                    marked[num] = {0,0,0};
                }
                

                // Mark as existed
                marked[num][0] |= (1<<i);
                marked[num][1] |= (1<<j);
                marked[num][2] |= (1 << ((i/3 * 3) + j/3));
            }
        
        return true;
    }
};

int main() {
    Solution solution;
    vector< vector<char> > board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    const bool rst = solution.isValidSudoku(board);
    cout << "Result: " << rst << endl;
    return 0;
}


