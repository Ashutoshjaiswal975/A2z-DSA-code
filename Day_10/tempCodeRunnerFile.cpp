 void solve(string& str, string output, int index, vector<string>& ans) {
        if (index >= str.size()) {
            ans.push_back(output);
            return;
        }
        // exclude
        solve(str, output, index + 1, ans);

        // include
        output.push_back(str[index]);
        solve(str, output, index + 1, ans);
        output.pop_back(); // backtrack to remove the last included character
    }