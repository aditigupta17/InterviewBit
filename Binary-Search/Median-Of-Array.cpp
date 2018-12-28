double foo(const vector<int> &A, int m, const vector<int> &B, int n)
{
    int minIndex = 0, maxIndex = m, halfLen = (n+m+1)/2;
    while(minIndex <= maxIndex)
    {
        int i = (minIndex+maxIndex)/2;
        int j = halfLen - i;
        if(i < maxIndex && B[j-1]>A[i]) minIndex = i+1;
        else if(i > minIndex && A[i-1]>B[j]) maxIndex = i-1;
        else
        {
            int maxLeft = 0;
            if(i==0) maxLeft = B[j-1];
            else if(j==0) maxLeft = A[i-1];
            else maxLeft = max(A[i-1], B[j-1]);
            if((m+n)%2) return maxLeft;
            
            int minRight = 0;
            if(i==m) minRight = B[j];
            else if(j==n) minRight = A[i];
            else minRight = min(B[j], A[i]);
            
            return (maxLeft+minRight)/2.0;
        }
    }
}

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int m = A.size();
    int n = B.size();
    if(m < n) return foo(A, m, B, n);
    else return foo(B, n, A, m);
}
