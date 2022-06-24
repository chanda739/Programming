class Solution {
public:
    bool isPossible(vector<int>& target) {
        int length = target.size();
        long sum=0;
        if(length==1)return target[0]==1;
        priority_queue<int> pq;
        for(int i=0;i<length;i++){
           pq.push(target[i]);
            sum+=target[i];
        }
        while (pq.top() != 1) {
		int curr = pq.top();pq.pop();
		if (sum - curr == 1) return true;

		int x = curr % (sum - curr);
		sum = sum - curr + x;

		if (x == 0 || x == curr) return false;
		else pq.push(x);
	}
        return true;
    }
};