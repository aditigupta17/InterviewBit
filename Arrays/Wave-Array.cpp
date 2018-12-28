vector<int> Solution::wave(vector<int> &A) {
        sort(A.begin(), A.end());
    if(A.size()%2) {
        int num = A[A.size()-1];
        for(int i=0; i<A.size(); i+=2)
        {
            int temp = A[i];
            A[i] = A[i+1];
            A[i+1] = temp;
        }
        A[A.size()-1] = num;
        return A;
    }
    else{
        for(int i=0; i<A.size(); i+=2)
        {
            int temp = A[i];
            A[i] = A[i+1];
            A[i+1] = temp;
        }
        return A;
    }
}
