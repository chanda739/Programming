class Solution {
    void merge(vector<pair<int,int>> &A,int s,int m, int e, vector<int> &res){
        int p1= s,p2=m+1,p3=0;
        int count=0;
        vector<pair<int,int>> temp(e-s+1);
        while(p1<=m&&p2<=e){
            if(A[p1].first<=A[p2].first){
                res[A[p1].second]+=count;
                temp[p3++] = A[p1++];
            }
            else{
                count++;
                temp[p3++] = A[p2++];
            }
        }
        while(p1<=m){
            res[A[p1].second]+=count;
            temp[p3++] = A[p1++];       
        }
        while(p2<=e){
            temp[p3++] = A[p2++];
        }
        for(int i=0;i<(e-s+1);i++){
            A[s+i] = temp[i];
        }
    }
void MergeSort(vector<pair<int,int>> &A,int s,int e, vector<int> &res){
    if(s>=e)
        return;
    int m = s +(e-s)/2;
    MergeSort(A,s,m,res);
    MergeSort(A,m+1,e,res);
    merge(A,s,m,e,res);
}

public:
    vector<int> countSmaller(vector<int>& nums) {
        int l = nums.size();
        vector<pair<int,int>> A(l);
        for(int i=0;i<l;i++)
            A[i] = make_pair(nums[i],i);
        vector<int> res(l,0);
        MergeSort(A,0,A.size()-1,res);
        return res;
    }
};