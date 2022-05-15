class Solution {
public:
    int countPrimes(int n) {
        vector<bool> Prime(n,false);
        for(int i=2;i<n;i++){
            Prime[i] = true;
        }
        for(int i=2;i*i<n;i++){
            if(!Prime[i])continue;
            for(int j=i*i;j<n;j+=i)
                Prime[j] = false;
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(Prime[i])
                count++;
        }
        return count;
    }
};