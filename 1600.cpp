class ThroneInheritance {
private:
    unordered_map<string, vector<string>> edges;
    unordered_set<string> dead;
    string king;

public:
    ThroneInheritance(string kingName): king{move(kingName)} {}
    
    void birth(string parentName, string childName) {
        edges[move(parentName)].push_back(move(childName));
    }
    
    void death(string name) {
        dead.insert(move(name));
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;

        function<void(const string&)> preorder = [&](const string& name) {
            if (!dead.count(name)) {
                ans.push_back(name);
            }
            if (edges.count(name)) {
                for (const string& childName: edges[name]) {
                    preorder(childName);
                }
            }
        };

        preorder(king);
        return ans;
    }
};
