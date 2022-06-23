class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(), courses.end(), comp);
        priority_queue<int> pq;
        int count = 0;
        for(auto course : courses){
            count += course[0];
            pq.push(course[0]);
            if(count > course[1]){
                count -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
