#include <iostream>
#include <vector>

using namespace std;

class StockSpanner {
private:
    vector<int> prices;
    vector<int> spans;
    int length;
public:
    StockSpanner() {
        length = 0;
    }

    int next(int price) {
        prices.push_back(price);
        int span = 1;
        int date = length - 1;
        while (date >= 0 && prices[date] <= price) {
            span += spans[date];
            date -= spans[date];
        }
        spans.push_back(span);
        length++;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main()
{
    StockSpanner* obj = new StockSpanner();
    cout << obj->next(100) << endl;
    cout << obj->next(80) << endl;
    cout << obj->next(60) << endl;
    cout << obj->next(70) << endl;
    cout << obj->next(60) << endl;
    cout << obj->next(75) << endl;
    cout << obj->next(85) << endl;

    return 0;
}
