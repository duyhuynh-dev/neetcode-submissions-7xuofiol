class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.rbegin(), cars.rend()); // descending sort

        int fleets = 0;
        double currentMaxTime = 0.0;

        for (int i = 0; i < n; i++) {
            if (cars[i].second > currentMaxTime) {
                fleets++;
                currentMaxTime = cars[i].second;
            }
        }

        return fleets;
    }
};
