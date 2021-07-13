class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder)
    {
        if(folder.empty()) {
            return{};
        }
        sort(folder.begin(), folder.end());

        vector<string> rst(1, folder[0]);
        for(int i = 1; i < folder.size(); i++) 
        {
            if(folder[i].compare(0, rst.back().length(), rst.back()) != 0 ||
                folder[i][rst.back().length()] != '/') {
                rst.push_back(folder[i]);
            }
        }
        return rst;
    }
};

