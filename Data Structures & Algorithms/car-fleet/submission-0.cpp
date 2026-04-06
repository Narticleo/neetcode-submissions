class Solution {
private:
    bool catchUp(pair<int,int> rear, pair<int,int> front, int target){
        float timeFront = (float)(target - front.first) / (float)front.second;
        float timeRear = (float)(target - rear.first) / (float)rear.second;
        return timeRear <= timeFront;
    }

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int, int>> pq;
        int fleet = 1;
        int n = position.size();
        for(int i=0; i<n; i++)
            pq.push({position[i], speed[i]});
        
        pair<int, int> frontCar = pq.top();
        
        while(!pq.empty()){
            pair<int, int> curCar = pq.top();
            pq.pop();
            if(!catchUp(curCar, frontCar, target)){
                frontCar = curCar;        
                fleet++;
            }
        }
        return fleet;
    }
};