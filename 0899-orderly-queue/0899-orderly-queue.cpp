class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1){
            string r = s;
            for(int i=0;i<s.size();i++){
                string t = s.substr(i) + s.substr(0,i);
                if(t.compare(r)<0)r = t;
            }
            return r;
        }else{
            sort(s.begin(), s.end());
            return s;
        }
    }
};