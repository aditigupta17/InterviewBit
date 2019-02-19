class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> A;
        for(int i=0; i<J.size(); i++)
            A.insert(J[i]);
        int count = 0;
        for(int i=0; i<S.size(); i++)
        {
            if(A.find(S[i]) != A.end())
                count++;
        }
        return count;
    }
};
