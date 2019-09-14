class Solution {
public:
    vector<int> plusOne(vector<int>& A) {
        int carry = 1, N = A.size();
        for(int i = N - 1; i >= 0; i--)
        {
            A[i] = A[i] + carry;
            carry = (A[i] > 9) ? 1 : 0;
            A[i] %= 10;
        }
        if(A[0] == 0){
            reverse(A.begin(), A.end());
            A.push_back(1);
            reverse(A.begin(), A.end());
        }
        return A;
    }
};
