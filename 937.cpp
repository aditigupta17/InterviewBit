class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLogs, digitLogs;
        for(string &S : logs)
        {
            int j = S.find(" ");
            if(isalpha(S[j+1])) letterLogs.push_back(S.substr(j+1) + " " + S.substr(0, j));
            else digitLogs.push_back(S);
        }
        sort(letterLogs.begin(), letterLogs.end());
        for(string &S : letterLogs)
        {
            int j = S.rfind(" ");
            S = S.substr(j+1) + " " + S.substr(0, j);
        }
        for(string &S : digitLogs)
            letterLogs.push_back(S);
        return letterLogs;
    }
};
