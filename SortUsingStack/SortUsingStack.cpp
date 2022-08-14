vector<int> Solution::solve(vector<int>& A) {
    vector<int> res;
    stack<int> s1, s2;
    for (int i = 0; i < A.size(); i++) {
        if (s1.empty())s1.push(A[i]);
        else if (!s1.empty() && s1.top() >= A[i]) {
            s1.push(A[i]);
        }
        else {
            while (!s1.empty() && s1.top() < A[i]) {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(A[i]);
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    while (!s1.empty()) {
        res.push_back(s1.top());
        s1.pop();
    }
    return res;
}