/*
703. Kth Largest Element in a Stream

Design a class to find the kth largest element in a stream. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, 
which contains initial elements from the stream. For each call to the method KthLargest.add, 
return the element representing the kth largest element in the stream.
*/

class KthLargest {
public:
    // Using a min-heap of size k
    priority_queue<int, vector<int>, greater<int>> Q;
    int num;
    KthLargest(int k, vector<int> A) {
        num = k;
        for(int i = 0; i < A.size(); i++)
        {
            Q.push(A[i]);
            if(Q.size() > k) Q.pop();
        }
    }
    
    int add(int val) {
        Q.push(val);
        if(Q.size() > num) Q.pop();
        return Q.top();
    }
};
