//  https://leetcode.com/problems/dungeon-game/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<pair<int,int>>> dp(dungeon.size(),vector<pair<int,int>>(dungeon[0].size()));
        dp[0][0] = make_pair(dungeon[0][0],dungeon[0][0]);
        for(int i=0;i<dungeon.size();i++){
            int sum = dp[i-1][0].second + dungeon[i][0];
            int ll = min(dp[i-1][0].first,sum);
            dp[i][0] = make_pair(ll,sum);
        }
        for(int i=1;i<dungeon[0].size();i++){
            int sum = dp[0][i-1].second + dungeon[0][i];
            int ll = min(dp[0][i-1].first,sum);
            dp[0][i] = make_pair(ll,sum);
        }
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                int sum,ll;
                pair<int,int> pr1 = dp[i][j-1];
                pair<int,int> pr2 = dp[i-1][j];
                if(pr1.first < pr2.first){
                    sum = pr2.second;
                    ll = pr2.first;
                }
                else{
                    if(pr1.first > pr2.second){
                        sum = pr1.second;
                        ll = pr1.first;
                    }
                    else{
                        if(pr1.second>pr2.second){
                            sum = pr1.second;
                            ll = pr1.first;
                        }
                        else{
                            sum = pr2.second;
                            ll = pr2.first;
                        }
                    }
                }
                sum += dungeon[i-1][j-1];
                ll = min(ll,sum);
                dp[i][j] = make_pair(ll,sum);
            }
        }
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                cout << "{" << dp[i][j].first << "," << dp[i][j].second << "}  ";
            }
            cout << endl;
        }
        int fin = dp[dp.size()-1][dp[0].size()-1].first;
        if(fin>=0) return 1;
        else return 1-fin;
    }
};
