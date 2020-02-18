int Solution::search(const vector<int> &A, int B) {
    if(A.size() == 0) return -1;
    // Step-1: Find smallest element in sorted rotated array
    int left = 0, right = A.size() - 1;
    while(left < right){
        int mid = left + (right - left)/2;
        if(A[mid] > A[right]) left = mid + 1;
        else right = mid;
    }
    // Step-2: Decide which fragment to search in
    // and reassign boundaries
    int start = left;
    left = 0, right = A.size() - 1;
    if(B >= A[start] && B <= A[right]) left = start;
    else right = start;
    // Step-3: Vanilla Binary Search
    while(left <= right){
        int mid = left + (right - left)/2;
        if(A[mid] == B) return mid;
        else if(A[mid] > B) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}
