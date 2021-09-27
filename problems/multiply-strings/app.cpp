#include "../common/base.h"
#include "../common/data.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        string reversedRst = "";
        int padding = 0;

        for(int i=0; i < num1.length() + num2.length(); ++i) {
            int numi = 0;
            for(int j=i; j>=0; j--) {
                int a = (j < num1.length()) ? (num1[num1.length()-j-1]-'0') : 0;
                int b = ((i-j) < num2.length()) ? (num2[num2.length()-(i-j)-1]-'0') : 0;
                numi += (a*b);
            }
            int fullNumi = numi + padding;
            reversedRst += to_string((fullNumi % 10));
            padding = (fullNumi / 10);
        }

        string rst = "";
        bool firstZero = true;
        for (int i = reversedRst.length()-1; i >= 0; --i)
        {
            if(firstZero && reversedRst[i] == '0') continue;
            else firstZero = false;
            rst += reversedRst[i];
        }
        if(rst == "") rst = "0";
        return rst;
    }
};

int main() {
    Solution solution;
    string num1 = InputData::inVectString[0];
    string num2 = InputData::inVectString[1];
    
    const string rst = solution.multiply(num1, num2);
    cout << "Result: " << num1 << "*" << num2 << " = " << rst << endl;
    return 0;
}
