/*Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    All inputs will be in lowercase.
    The order of your output does not matter.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& S) {
        unordered_map<string, vector<string>> T;
        for(auto s : S)
        {
            string t = s;
            sort(t.begin(), t.end());
            T[t].push_back(s);
        }
        vector<vector<string>> anagram;
        for(auto i : T)
            anagram.push_back(i.second);
        return anagram;
    }
};

