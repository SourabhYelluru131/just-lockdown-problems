using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        int depth=0,count=0;
        bool flag = true;
        for(char& c : s){        // Add code to check if s is a string with only space
            if(c=='('){
                if(depth==0){
                    count = 0;
                }
                depth++;
            }
            else{
                if(c==')'){
                    depth--;
                    if(depth<0){
                        count--;
                        depth++;
                        if(count<0){
                            flag = false;
                            break;
                        }
                    }
                }
                else{
                        count++;
                }
            }
        }
        if(depth>0 && count < depth){
            flag = false;
        }
    return flag;
    }
};
