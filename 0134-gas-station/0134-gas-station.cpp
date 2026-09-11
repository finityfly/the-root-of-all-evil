class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas = 0, sumCost = 0, curStart = 0, curGas = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sumGas += gas[i];
            sumCost += cost[i];
            curGas += gas[i] - cost[i];
            if (curGas < 0) {
                // breakdown
                curStart = i + 1;
                curGas = 0;
            }
        }
        if (sumGas < sumCost) return -1;
        else return curStart;
    }
};