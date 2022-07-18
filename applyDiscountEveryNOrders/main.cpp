#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Cashier {

private:
    int n;
    int discount;
    double discount_rate;
    unordered_map<int, int> product2price;
    int timer; // used to calculate which customer to discount

public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        timer = 0;
        this->n = n;
        this->discount = discount;
        this->discount_rate = (double)(100 - discount) / 100;
        this->product2price = unordered_map<int, int>();
        int n_products = products.size();
        for (int i = 0; i < n_products; ++i)
        {
            this->product2price.insert(make_pair(products[i], prices[i]));
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        timer += 1;
        int n_products = product.size();
        double bill = 0.0;
        for (int j = 0; j < n_products; ++j)
        {
            bill += amount[j] * this->product2price[product[j]];
        }

        if (timer == n)
        {
            bill = bill * this->discount_rate;
            timer = 0;
        }

        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */

void print(double item)
{
    cout << item << endl;
}

int main()
{
    vector<int> products = {1, 2, 3, 4, 5, 6, 7};
    vector<int> prices = {100, 200, 300, 400, 300, 200, 100};
    Cashier* cashier = new Cashier(3, 50, products, prices);
    print(cashier->getBill({1, 2},{1, 2}));                        // return 500.0. 1st customer, no discount.
                                                        // bill = 1 * 100 + 2 * 200 = 500.
    print(cashier->getBill({3, 7}, {10, 10}));                      // return 4000.0. 2nd customer, no discount.
                                                        // bill = 10 * 300 + 10 * 100 = 4000.
    print(cashier->getBill({1,2,3,4,5,6,7}, {1,1,1,1,1,1,1}));    // return 800.0. 3rd customer, 50% discount.
                                                        // Original bill = 1600
                                                        // Actual bill = 1600 * ((100 - 50) / 100) = 800.
    print(cashier->getBill({4}, {10}));                           // return 4000.0. 4th customer, no discount.
    print(cashier->getBill({7, 3}, {10, 10}));                      // return 4000.0. 5th customer, no discount.
    print(cashier->getBill({7,5,3,1,6,4,2}, {10,10,10,9,9,9,7})); // return 7350.0. 6th customer, 50% discount.
                                                        // Original bill = 14700, but with
                                                        // Actual bill = 14700 * ((100 - 50) / 100) = 7350.
    print(cashier->getBill({2,3,5}, {5,3,2}));                    // return 2500.0.  6th customer, no discount.

    return 0;
}
