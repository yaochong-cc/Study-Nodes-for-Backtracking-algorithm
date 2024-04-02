#include <iostream>
#include <vector>
using namespace std;
class Solution{
//private:
//    vector<int> path;
//    vector<vector<int>> res;
//    void backtracking(int n, int k, int startIndex) {
//        if (path.size() == k) {
//            res.push_back(path);
//
//            return;
//        }
//        for (int i = startIndex; i <= n; i++) {
//            path.push_back(i);
//            backtracking(n, k, i + 1);
//            path.pop_back();
//        }
//    }
//public:
//    vector<vector<int>> combine(int n,int k) {
//        backtracking(n, k, 1);
//        return res;
//    }

    //优化
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            res.push_back(path);

            return;
        }
        for (int i = startIndex; i <= n-(k-path.size())+1; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();//这里要pop_back，因为每一次都要回溯到上一个状态，所以要pop_back
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }

};
int main(){
    Solution s;
    vector<vector<int>> res = s.combine(4, 2);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}