class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        int sign = 1;
        int i=0,dig;
        while(i<s.size() && s[i]==' ')i++;
        
        if(i<s.size() && s[i]=='+'){
            sign = 1;
            i++;
        }else if(i<s.size() && s[i]=='-'){
            sign = -1;
            i++;
        }
        
        while(i<s.size() && isdigit(s[i])){
            dig = s[i]-'0';
            if((num> INT_MAX/10) || (num==INT_MAX/10 && dig>INT_MAX%10))
              return sign==1?INT_MAX:INT_MIN;
            num = num*10 + dig;
            i++;
        }
        return num*sign;
    }
};