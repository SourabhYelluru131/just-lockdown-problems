// https://leetcode.com/problems/online-stock-span/
class StockSpanner {
public:
    stack<pair<int, int>> stak;
    StockSpanner() {
    }
    
    int next(int price) {
        int res = 1;
        while (!stak.empty() && stak.top().first <= price) {
            res += stak.top().second;
            stak.pop();
        }
        stak.push({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
