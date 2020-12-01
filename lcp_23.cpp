class Solution {
public:
    bool isMagic(vector<int>& target) {
        vector<int> cards;
        for (int i = 0; i < target.size(); i++) {
            cards.push_back(i + 1);
        }
        magicSort(cards, 0);

        int maxk = sameCnt(cards, target, 0);
        return (maxk != 0) && check(cards, target, maxk);
    }

    bool check(vector<int> cards, vector<int>& target, int k) {
        int start = k;
        while (start < (int)cards.size() - 1) {
            magicSort(cards, start);
            if (sameCnt(cards, target, start) < k) break;
            start += k;
        }
        return sameCnt(cards, target, 0) == target.size();
    }

    void magicSort(vector<int>& v, int start) {
        vector<int> temp;
        for (int i = 0; i < start; i++) {
            temp.push_back(v[i]);
        }
        for (int i = start + 1; i < v.size(); i += 2) {
            temp.push_back(v[i]);
        }
        for (int i = start; i < v.size(); i += 2) {
            temp.push_back(v[i]);
        }
        swap(temp, v);
    }

    int sameCnt(vector<int>& v, vector<int>& target, int start) {
        for (int i = start; i < target.size(); i++) {
            if (v[i] != target[i]) return i - start;
        }
        return target.size() - start;
    }
};
