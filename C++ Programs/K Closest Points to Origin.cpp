class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>max_heap;
        for(int i=0; i<points.size(); i++){
            vector<int>v;
            v.push_back(points[i][0]);
            v.push_back(points[i][1]);
            int distance = pow(v[0],2)+pow(v[1],2);
            max_heap.push({distance,v});
            if(max_heap.size()>k)
                max_heap.pop();
        }
        vector<vector<int>>p;
        while(max_heap.size()>0){
            p.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return p;
    }
};
