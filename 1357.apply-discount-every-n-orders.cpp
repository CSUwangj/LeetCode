/*
 * @lc app=leetcode id=1357 lang=cpp
 *
 * [1357] Apply Discount Every n Orders
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Cashier {
  unordered_map<int, int> prices;
  int discountOrder;
  int orderCount = 0;
  double discount;
public:
  Cashier(int n, int discount, vector<int>& products, vector<int>& prices): discountOrder(n) {
    this->discount = (100 - discount) / 100.0;
    for(int i = 0; i < products.size(); ++i) {
      this->prices[products[i]] = prices[i];
    }
  }
  
  double getBill(vector<int> product, vector<int> amount) {
    double answer = 0;
    for(int i = 0; i < product.size(); ++i) {
      answer += prices[product[i]] * amount[i];
    }
    if(++orderCount % discountOrder == 0) {
      answer *= discount;
    }
    return answer;
  }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
// @lc code=end

