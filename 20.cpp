class Solution {
public:
    bool isValid(string A) {
        stack<char> S;
        for(int i = 0; i < A.size(); i++)
        {
            switch(A[i]){
                case '(': 
                case '{':                    
                case '[':
                    S.push(A[i]);
                    break;    
                    
                case ')':
                    if(S.empty()) return false;
                    if(S.top() == '(') S.pop();
                    else return false;
                    break;
                    
                case '}':
                    if(S.empty()) return false;
                    if(S.top() == '{') S.pop();
                    else return false;
                    break;
                    
                case ']':
                    if(S.empty()) return false;
                    if(S.top() == '[') S.pop();
                    else return false;
                    break;
            }
        }
        if(S.empty()) return true;
        return false;
    }
};
