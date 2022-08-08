class Solution {
public:
    int trap(vector<int>& height) {
        int l=height.size(),i;
        vector<int> LeftMax(l), RightMax(l);
        //generate Prefix Max array from left side
        for(i=0;i<l;i++){
            LeftMax[i]=height[i];
            if(i!=0)LeftMax[i] = max(LeftMax[i-1],height[i]);
        }
        //generate prefix max from right side
        for(i=l-1;i>=0;i--){
            RightMax[i]=height[i];
            if(i!=(l-1))RightMax[i] = max(RightMax[i+1],height[i]);
        }
        int AmtWtrTrp=0,t;
        //first and last building won't trap water so skip them, iterate for rest of the building
        //get max height from ⁵left and right side of the current building and get amount of water trapped
        for(i=1;i<l-1;i++){
            t = min(LeftMax[i-1],RightMax[i+1]) - height[i];
            AmtWtrTrp+= max(0,t);
        }
        return AmtWtrTrp;
    }
};