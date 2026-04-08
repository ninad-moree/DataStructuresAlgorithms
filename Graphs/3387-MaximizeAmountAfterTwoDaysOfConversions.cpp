/*
    You are given a string initialCurrency, and you start with 1.0 of initialCurrency. You are also given four arrays with currency pairs (strings) and rates (real numbers):
    pairs1[i] = [startCurrencyi, targetCurrencyi] denotes that you can convert from startCurrencyi to targetCurrencyi at a rate of rates1[i] on day 1.
    pairs2[i] = [startCurrencyi, targetCurrencyi] denotes that you can convert from startCurrencyi to targetCurrencyi at a rate of rates2[i] on day 2.
    Also, each targetCurrency can be converted back to its corresponding startCurrency at a rate of 1 / rate. You can perform any number of conversions, including zero, using 
    rates1 on day 1, followed by any number of additional conversions, including zero, using rates2 on day 2. Return the maximum amount of initialCurrency you can have after 
    performing any number of conversions on both days in order. Note: Conversion rates are valid, and there will be no contradictions in the rates for either day. The rates for 
    the days are independent of each other.

    Example 1:
    Input: initialCurrency = "EUR", pairs1 = [["EUR","USD"],["USD","JPY"]], rates1 = [2.0,3.0], pairs2 = [["JPY","USD"],["USD","CHF"],["CHF","EUR"]], rates2 = [4.0,5.0,6.0]
    Output: 720.00000
    Explanation: To get the maximum amount of EUR, starting with 1.0 EUR:
    On Day 1: Convert EUR to USD to get 2.0 USD. Convert USD to JPY to get 6.0 JPY.
    On Day 2: Convert JPY to USD to get 24.0 USD. Convert USD to CHF to get 120.0 CHF. Finally, convert CHF to EUR to get 720.0 EUR.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> createGraph(vector<vector<string>>& pairs, vector<double>& rates) {
        unordered_map<string, vector<pair<string, double>>> adj;

        for(int i=0; i<rates.size(); i++) {
            string from = pairs[i][0];
            string to = pairs[i][1];
            double rate = rates[i];

            adj[from].push_back({to, rate});
            adj[to].push_back({from, 1.0/rate});
        }

        return adj;
    }

    unordered_map<string, double> bfs(string start, unordered_map<string, vector<pair<string, double>>>& graph, double startAmt) {
        unordered_map<string, double> maxAmount;
        queue<pair<string, double>> q;
        q.push({start, startAmt});
        maxAmount[start] = startAmt;

        while(!q.empty()) {
            string curr = q.front().first;
            double amt = q.front().second;
            q.pop();

            for(auto i : graph[curr]) {
                string neigh = i.first;
                double rate = i.second;
                double newAmt = amt * rate;

                if(newAmt > maxAmount[neigh]) {
                    maxAmount[neigh] = newAmt;
                    q.push({neigh, newAmt});
                }
            }
        }

        return maxAmount;
    }

    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string, vector<pair<string, double>>> graph1 = createGraph(pairs1, rates1);
        unordered_map<string, vector<pair<string, double>>> graph2 = createGraph(pairs2, rates2);

        unordered_map<string, double> day1Amt = bfs(initialCurrency, graph1, 1.0);

        double ans = 0.0;

        for(auto i : day1Amt) {
            string curr = i.first;
            double amt = i.second;
            unordered_map<string, double> day2Amt = bfs(curr, graph2, amt);
            ans = max(ans, day2Amt[initialCurrency]);
        }

        return ans;
    }
};