class Solution {
public:
    int divide(int A, int B) {
    long a = abs(A*1LL), b = abs(B*1LL), temp =0,res=0;
    int sign = ((A<0)^(B<0));
    //cout<<"sign "<<sign<<endl;
    for(int i=31;i>=0;i--){
        if((temp+(b<<i))<= a){
            temp = temp + (b<<i);
            res|=(1LL<<i);
              //  cout<<res<<" result "<<endl;
            if(res>=INT_MAX){
                   // cout<<res<<endl;
                return (sign?(-1*res):INT_MAX);
            }
        }
    }
    if(sign){
        return (-1)*res;
    }
    return res;
    }
};