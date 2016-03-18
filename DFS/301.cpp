#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        DFS(s, calc(s));
        return ans;
    }
private:
    vector<string> visitedString;
    bool isVisited(string s) {

        for (int i = 0; i < visitedString.size(); i ++)
            if (visitedString[i] == s) {
                return true;
            }

        return false;

    }
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

    void DFS(string s, int unMatchedCnt) {
        if (unMatchedCnt == 0) {
            ans.push_back(s);
        } else {
            for (int i = 0; i < s.size(); i ++) {
                if (s[i] != '(' && s[i] != ')') continue;
                string newString = s.substr(0, i) + s.substr(i + 1);
                if (!isVisited(newString)) {
                    visitedString.push_back(newString);
                    int num = calc(newString);
                    if (num < unMatchedCnt) {
                        DFS(newString, num);
                    }
                }
            }

        }
    }
};
