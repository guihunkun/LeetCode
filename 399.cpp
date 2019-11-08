class Solution 
{
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        unordered_map<string, vector<pair<string, double>>> adj_list;
        vector<double> final_res;
        for (int i = 0; i < equations.size(); i++) {
            adj_list[equations[i][0]].push_back(pair<string, double>(equations[i][1], values[i]));
            adj_list[equations[i][1]].push_back(pair<string, double>(equations[i][0], 1 / values[i]));
        }
        for (auto q: queries) {
             
            bool found = false;
            unordered_set<string> visited;
            
            deque<pair<string, double>> dq;
            if (adj_list.count(q[0]) == 0 || adj_list.count(q[1]) == 0) {
                final_res.push_back(-1.0);
                continue;
            }
            if (q[0] == q[1]) {
                final_res.push_back(1.0);
                continue;
            }
            dq.push_back(pair<string, double>(q[0], 1.0));
            while (!dq.empty()) {
                 
                visited.insert(dq.front().first);
                string r_str = dq.front().first;
                double r_val = dq.front().second;
                dq.pop_front();
               
                for (auto p: adj_list[r_str]) {
                   if (visited.count(p.first) == 0) {
                       if (p.first == q[1]) {
                            final_res.push_back(r_val * p.second);
                            found = true;
                            break;
                        }
                       dq.push_back(pair<string, double>(p.first, p.second * r_val));
                       
                   }
                    
                }
                if (found) break;
            }
            if (!found) final_res.push_back(-1.0);
             
        }
        return final_res;
        
    }
};
