class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaA = (ay2-ay1)*(ax2-ax1), areaB = (by2-by1)*(bx2-bx1);
        int left = max(ax1,bx1);
        int right = min(ax2,bx2);
        int xoverlap = right - left;
        
        int top = min(ay2,by2);
        int bottom = max(ay1,by1);
        int yoverlap = top - bottom;
        int overlap = 0;
        
        if(xoverlap>0 and yoverlap>0)overlap = xoverlap * yoverlap;
        
        return (areaA + areaB - overlap);
    }
};