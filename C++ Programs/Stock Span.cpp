vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<pair<int,int>>s;
       vector<int>v;
       for(int i=0;i<n;i++)
       {
           if(s.empty())
           {
               v.push_back(-1);
           }
           else if(!s.empty() and s.top().first>price[i])
           {
               v.push_back(s.top().second);
           }
           else if(!s.empty() and s.top().first<=price[i])
           {
               while(!s.empty() and s.top().first<=price[i])
               {
                   s.pop();
               }
               if(!s.empty())
               {
                   v.push_back(s.top().second);
               }
               else
               {
                   v.push_back(-1);
               }
           }
           s.push({price[i],i});
       }
       vector<int>ans;
       for(int i=0;i<n;i++)
       {
           ans.push_back(i-v[i]);
       }
       return ans;
    }
