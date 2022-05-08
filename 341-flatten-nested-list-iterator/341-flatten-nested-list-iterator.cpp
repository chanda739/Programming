/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> res;
    int index = 0;
public:
    void flattenNestedList(vector<NestedInteger> &nestedList) {
        for(auto x: nestedList)
            if(x.isInteger())
                res.push_back(x.getInteger());
            else
                flattenNestedList(x.getList());
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattenNestedList(nestedList);
    }
    
    int next() {
        return res[index++];
    }
    
    bool hasNext() {
        return index < res.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */