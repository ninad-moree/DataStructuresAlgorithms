/*
    A ride sharing system manages ride requests from riders and availability from drivers. Riders request rides, and drivers become available over time. The system should 
    match riders and drivers in the order they arrive. Implement the RideSharingSystem class: RideSharingSystem() Initializes the system. void addRider(int riderId) Adds a new 
    rider with the given riderId. void addDriver(int driverId) Adds a new driver with the given driverId. int[] matchDriverWithRider() Matches the earliest available driver 
    with the earliest waiting rider and removes both of them from the system. Returns an integer array of size 2 where result = [driverId, riderId] if a match is made. If no 
    match is available, returns [-1, -1]. void cancelRider(int riderId) Cancels the ride request of the rider with the given riderId that has not yet been 
    matched.
    
    Example 1:
    Input: ["RideSharingSystem", "addRider", "addDriver", "addRider", "matchDriverWithRider", "addDriver", "cancelRider", "matchDriverWithRider", "matchDriverWithRider"]
    [[], [3], [2], [1], [], [5], [3], [], []]
    Output: [null, null, null, null, [2, 3], null, null, [5, 1], [-1, -1]]
    Explanation RideSharingSystem rideSharingSystem = new RideSharingSystem(); // Initializes the system
    rideSharingSystem.addRider(3); // rider 3 joins the queue, rideSharingSystem.addDriver(2); // driver 2 joins the queue
    rideSharingSystem.addRider(1); // rider 1 joins the queue, rideSharingSystem.matchDriverWithRider(); // returns [2, 3]
    rideSharingSystem.addDriver(5); // driver 5 becomes available, rideSharingSystem.cancelRider(3); // rider 3 is already matched, cancel has no effect
    rideSharingSystem.matchDriverWithRider(); // returns [5, 1], rideSharingSystem.matchDriverWithRider(); // returns [-1, -1]
*/

#include<bits/stdc++.h>
using namespace std;

class RideSharingSystem {
public:
    queue<int> rider;
    queue<int> driver;
    unordered_set<int> waiting;

    RideSharingSystem() {}
    
    void addRider(int riderId) {
        rider.push(riderId);
        waiting.insert(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while (!rider.empty() && waiting.find(rider.front()) == waiting.end()) 
            rider.pop();

        if (rider.empty() || driver.empty()) 
            return {-1, -1};

        int r = rider.front();
        rider.pop();
        waiting.erase(r);

        int d = driver.front();
        driver.pop();

        return {d, r};
    }
    
    void cancelRider(int riderId) {
        waiting.erase(riderId);
    }
};