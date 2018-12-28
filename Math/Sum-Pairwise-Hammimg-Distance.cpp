int Solution::hammingDistance(const vector<int> &A) {
    int sum = 0;
    for(int i=0; i<32; i++)
    {
        int count = 0;
        for(int j=0; j<A.size(); j++)
            if(A[j] & (1<<i)) count++;
        sum += count*(A.size()-count)*2;
    }
    return sum;
}
