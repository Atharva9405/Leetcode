class StockSpanner {
    stack<pair<int,int>> s;
    int index;
public:
    StockSpanner() {
        index = -1;
    }
    
    int next(int price) {
        index++;
        while(!s.empty() && s.top().second <= price){
            s.pop();
        }
        if(s.empty()){
            s.push({index,price});
            return index+1;
        }
        int res = s.top().first;
        s.push({index,price});
        return index-res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */