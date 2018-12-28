void Solution::rotate(vector<vector<int> > &A) {
    int n = A[0].size();
    for(int i=0; i<n/2; i++)
    {
        for(int j=i; j<n-i-1; j++)
        {
            //store top
            int temp = A[i][j];
            //make top as left
            A[i][j] = A[n-j-1][i];
            //make left as bottom
            A[n-j-1][i] = A[n-i-1][n-j-1];
            //make bottom as right
            A[n-i-1][n-j-1] = A[j][n-i-1];
            //make right as top
            A[j][n-i-1] = temp;
        }
    }
}
