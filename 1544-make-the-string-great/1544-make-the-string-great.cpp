class Solution {
public:
    string makeGood(string s) {
        while(s.size()>1){
            bool flag = false;
            
            for(int i=0;i<s.size()-1;i++){
                char frst = s[i], snd = s[i+1];
                if(abs(frst - snd)==32){
                    s = s.substr(0,i) + s.substr(i+2);
                    flag = true;
                    break;
                }
            }
            if(!flag)break;
        }
        return s;
    }
};