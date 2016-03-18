class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        DFS(s, calc(s), 0);
        return ans;
    }
    set<string> visitedString;
private:
    vector<string> ans;
    int calc(string s) {
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left ++;
            } else if (s[i] == ')') {
                if (left > 0) {
                    left --;
                } else {
                    right ++;
                }
            }
        }
        return left + right;
    }

    void DFS(string s, int unMatchedCnt, int start) {
        if (unMatchedCnt == 0) {
            ans.push_back(s);
        } else {
            for (int i = start; i < s.size(); i ++) {
                if (s[i] != '(' && s[i] != ')') continue;
                string newString = s.substr(0, i) + s.substr(i + 1);
                if (visitedString.find(newString) == visitedString.end()) {
                    visitedString.insert(newString);
                    int num = calc(newString);
                    if (num < unMatchedCnt) {
                        DFS(newString, num, i);
                    }
                }
            }

        }
    }
};