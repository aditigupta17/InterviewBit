/*
Given a char array representing tasks CPU need to do. 
It contains capital letters A to Z where different letters represent different tasks. 
Tasks could be done without original order. Each task could be done in one interval. 
For each interval, CPU could finish one task or just be idle.
However, there is a non-negative cooling interval n that means between two same tasks, 
there must be at least n intervals that CPU are doing different tasks or just be idle.
You need to return the least number of intervals the CPU will take to finish all the given tasks.
*/

class Solution {
public:
    int leastInterval(vector<char>& A, int N) {
        int count[26] = {0}, maxCount = 0, withMaxCount = 0;
        for(int i = 0; i < A.size(); i++)
        {
            count[A[i]-'A']++;
            maxCount = max(maxCount, count[A[i]-'A']);
        }
        for(int i = 0; i < 26; i++)
            if(count[i] == maxCount) withMaxCount++;
        int parts = maxCount - 1;
        int partLength = N - (withMaxCount - 1);
        int emptySlots = parts * partLength;
        int taskToFill = (int) A.size() - (maxCount * withMaxCount);
        int idleSlots = max(0, emptySlots - taskToFill);
        return (int)A.size() + idleSlots;
    }
};
