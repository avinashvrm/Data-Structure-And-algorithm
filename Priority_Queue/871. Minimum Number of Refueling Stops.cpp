/*
Example 1:

Input: target = 1, startFuel = 1, stations = []
Output: 0
Explanation: We can reach the target without refueling.
Example 2:

Input: target = 100, startFuel = 1, stations = [[10,100]]
Output: -1
Explanation: We can not reach the target (or even the first gas station).
Example 3:

Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation: We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.
*/


class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        priority_queue<int> pq;
        int stops = 0;
        int curr = startFuel;
        
          for(auto &x : stations)
          {
              int pos = x[0];
              int fuel = x[1];
              
              while(curr < pos)//when are unable to reach this particular gas station then sbse best vala se fuelup kr lenge
              {
                  if(pq.empty())
                      return -1;
                  int k  = pq.top();pq.pop();
                  curr+=k;
                  stops++;
              }
              pq.push(fuel);
          }
          while(curr < target)
          {
              if(pq.empty())
                  return -1;
              int k  = pq.top();pq.pop();
              curr+=k;
              stops++;
          }
        return stops;
    }
};
