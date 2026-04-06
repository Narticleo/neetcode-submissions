#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    bool finishInTime(vector<int>& piles, int bananas, int h){
        long time = 0;
        int n = piles.size();
        for(int i=0; i<n; i++)
            time += (piles[i]/bananas + ((piles[i]%bananas)? 1 : 0));
        return time <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int upper = 1;
        int lower = 1;
        int n = piles.size();
        for(int i=0; i<n; i++)
            upper = max(piles[i], upper);
        int result = upper;
        while(upper>=lower){
            int middle = (upper + lower)/2;
            bool inTime = finishInTime(piles, middle, h);
            if(inTime)result = middle;
            if(inTime)
                upper = middle - 1;
            else 
                lower = middle + 1;
        }
        return result;   
    }
};
