class Solution {
    private:
    void palindrome(string& s,int i,int j,vector<int>& res){
        while(i>=0&&j<s.length()&&s[i]==s[j]){
            j++;i--;
        }
        //cout<<"palindrome "<<i+1<<" "<<j-1<<endl;
        res[0] = i+1;
        res[1] = j-1;
    }
    public:
    string longestPalindrome(string A) {
        int l = A.length(),ans=INT_MIN,longestLen=0;
        vector<int> res(2,0);vector<int> index(2,0);
        for(int i=0;i<l;i++){
            palindrome(A,i,i,res);
            longestLen = res[1]-res[0]+1;
            if(ans<longestLen){
                ans = longestLen;
                index[0] = res[0];
                index[1] = res[1];
            }
            palindrome(A,i,i+1,res);
            longestLen = res[1]-res[0]+1;        
            if(ans<longestLen){
                ans = longestLen;
                index[0] = res[0];
                index[1] = res[1];
            }
        }
        //cout<<"longestLen "<<ans;
        string lps="";
        for(int k =index[0];k<=index[1];k++)
            lps+=A[k];
        return lps;
    }

};