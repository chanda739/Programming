class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int hr = horizontalCuts[0], vr = verticalCuts[0];
        int m = 1e9+7;
        for(int i=1;i<horizontalCuts.size();i++){
            hr = max(hr, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        for(int i=1;i<verticalCuts.size();i++){
            vr = max(vr, verticalCuts[i] - verticalCuts[i-1]);
        }
        return (1LL*hr*vr)%m;
    }
    /*
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long hr = horizontalCuts[0], vr = verticalCuts[0];
        int m = 1e9+7;long t;
        for(int i=0;i<horizontalCuts.size()-1;i++){
            t = horizontalCuts[i+1] - horizontalCuts[i];
            hr = max(hr, t);
        }
        for(int i=0;i<verticalCuts.size()-1;i++){
            t = verticalCuts[i+1] - verticalCuts[i];
            vr = max(vr, t);
        }
        t = (h-horizontalCuts[horizontalCuts.size()-1]);
        hr = max(hr, t);
        t = (w-verticalCuts[verticalCuts.size()-1]);
        vr = max(vr, t);
        return (hr%m*vr%m)%m;
    }
    */
};