int Solution::repeatedNumber(const vector<int> &A) {
    vector<int> ans;
    int numA = 0, numB = 0, countA = 0, countB = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == numA) countA++;
        else if(A[i] == numB) countB++;
        else if(countA == 0){
            numA = A[i];
            ++countA;
        }
        else if(countB == 0){
            numB = A[i];
            ++countB;
        }
        else{
            --countA;
            --countB;
        }
    }
    countA = 0, countB = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == numA) ++countA;
        if(A[i] == numB) ++countB;
    }
    if(countA > A.size()/3) return numA;
    if(countB > A.size()/3) return numB;
    return -1;
}
