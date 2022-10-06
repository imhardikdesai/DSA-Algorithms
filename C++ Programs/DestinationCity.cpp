class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int>m;
        int k=0;
        for(int i=0;i<paths.size();i++)
        {
            for(int j=0;j<paths[i].size();j++)
            {
                if(m.find(paths[i][j])==m.end())
                {
                    m[paths[i][j]]=k;
                    k++;
                }
                else continue;
            }
        }
        vector<int>adj[m.size()];
        for(int i=0;i<paths.size();i++)
        {
            adj[m[paths[i][0]]].push_back(m[paths[i][1]]);
        }
      for (int d = 0; d < m.size(); ++d) {
          if(adj[d].size()==0)
          {
              for(auto x:m)
              {
                  if(x.second==d)
                  {
                      return x.first;
                  }
              }
          }
      }
        return "";
    }
};
