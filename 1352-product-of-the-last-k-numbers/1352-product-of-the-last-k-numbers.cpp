class ProductOfNumbers {
public:
    vector<long> Product;
    ProductOfNumbers() {
        Product = {1};
    }
    
    void add(int num) {
        if(num==0)
            Product = {1};
        else
            Product.push_back(Product.back()*num);
    }
    
    int getProduct(int k) {
        if(k>=Product.size())
            return 0;
        return Product.back()/Product[Product.size()-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */