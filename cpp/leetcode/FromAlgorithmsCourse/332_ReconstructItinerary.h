//https://leetcode.com/problems/reconstruct-itinerary/
#ifndef ALGORITHMICCHALLENGES_332_RECONSTRUCTITINERARY_H
#define ALGORITHMICCHALLENGES_332_RECONSTRUCTITINERARY_H

#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

using CitiesQueueT = priority_queue<string, vector<string>, greater<string>>;
using ConnectionsT = unordered_map<string, CitiesQueueT>;
using ItineraryT = vector<string>;

void visitCity(
        string city,
        ItineraryT& itinerary,
        ConnectionsT& connections) {
    auto cityConnections = connections.find(city);
    if (cityConnections != end(connections)) {
        while (!cityConnections->second.empty()) {
            auto nextCity = cityConnections->second.top();
            cityConnections->second.pop();
            visitCity(move(nextCity), itinerary, connections);
        }
    }
    itinerary.push_back(move(city));
}

ItineraryT findItinerary(vector<vector<string>> const& tickets) {
    ConnectionsT connections;
    for (auto& ticket : tickets) {
        connections[ticket.front()].push(ticket.back());
    }

    ItineraryT itinerary;
    visitCity("JFK", itinerary, connections);
    reverse(begin(itinerary), end(itinerary));
    return itinerary;
}

#endif //ALGORITHMICCHALLENGES_332_RECONSTRUCTITINERARY_H
