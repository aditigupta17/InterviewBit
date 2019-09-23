class Solution {
public:
    bool reachingPoints(int x1, int y1, int x2, int y2) {
        while(x2 >= x1 && y2 >= y1)
        {
            if(x2 > y2)
            {
                if(y1 == y2) return (x2 - x1) % y1 == 0;
                x2 %= y2;
            }
            else
            {
                if(x1 == x2) return (y2 - y1) % x1 == 0;
                y2 %= x2;
            }
        }
        return false;
    }
};
