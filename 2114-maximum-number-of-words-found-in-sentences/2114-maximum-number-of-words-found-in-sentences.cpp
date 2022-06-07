class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int i,j,len = sentences.size(),count=0,maxc=INT_MIN;
        for(i=0;i<len;i++){
            count = 1;
            for(j=0;j<sentences[i].length();j++){
                if(sentences[i][j]==' ')
                    count++;
            }
            if(maxc<count)
                maxc=count;
        }
        return maxc;
    }
};