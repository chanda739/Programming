vector<int> Solution::solve(vector<int>& A) {
    int n = A.size();
    vector<int> res(n, 1), left(n, 1), right(n, 1);
    for (int i = 0; i < n; i++) {
        if (i == 0)left[i] = A[i];
        else
            left[i] = left[i - 1] * A[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1)right[i] = A[i];
        else
            right[i] = right[i + 1] * A[i];
    }
    for (int i = 0; i < n; i++) {
        if (i == 0)res[i] = right[i + 1];
        else if (i == n - 1)res[i] = left[i - 1];
        else res[i] = left[i - 1] * right[i + 1];
    }
    return res;
}