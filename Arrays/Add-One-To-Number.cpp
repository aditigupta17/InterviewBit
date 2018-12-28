vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> B;
    int index = 0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]!=0)
        {
            index = i;
            break;
        }
    }
    for(int i=index; i<A.size(); i++)
        B.push_back(A[i]);
    int carry = 0;
    int n = A.size();
    if(B[n-1]<9)
    {
        B[n-1] = B[n-1]+1;
        return B;
    }
    else
    {
        B[n-1] = 0;
        carry = 1;
        for(int i=n-2; i>=index; i--)
        {
            if(B[i]+carry>9)
            {
                carry = 1;
                B[i] = (B[i]+carry)%10;
            }
            else
            {
                B[i] = B[i]+carry;
                carry = 0;
            }
        }
        if(carry==1)
        B.insert(B.begin(), 1);
    }
    return B;
}
