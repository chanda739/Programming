class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res=0,l=operations.size();
        for(int i=0;i<l;i++){
            if(operations[i][1]=='-')
                res--;
            else
                res++;
        }
        return res;
    }
};