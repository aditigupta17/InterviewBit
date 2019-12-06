vector<string> recurse(string A, unordered_set<string>& dict, unordered_map<string, vector<string>>& M){
    if(M.count(A)) return M[A];
    vector<string> result;
    for(int i = 1; i <= A.size(); i++){
        string prefix = A.substr(0, i);
        string suffix = A.substr(i);
        if(dict.find(prefix) != dict.end()){
            if(suffix.empty()) result.push_back(prefix);
            else{
                vector<string> foo = recurse(suffix, dict, M);
                for(int i = 0; i < foo.size(); i++)
                    result.push_back(prefix + " " + foo[i]);
            }
        }
    }
    M[A] = result;
    return result;
}
     
vector<string> Solution::wordBreak(string A, vector<string> &B) {
  unordered_map<string, vector<string>> M;
  unordered_set<string> dict(B.begin(), B.end());
  return recurse(A, dict, M);
}

