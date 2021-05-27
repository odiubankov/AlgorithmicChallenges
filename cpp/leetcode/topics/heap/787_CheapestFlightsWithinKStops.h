// https://leetcode.com/problems/cheapest-flights-within-k-stops/

#ifndef ALGORITHMICCHALLENGES_787_CHEAPESTFLIGHTSWITHINKSTOPS_H
#define ALGORITHMICCHALLENGES_787_CHEAPESTFLIGHTSWITHINKSTOPS_H

#include <unordered_map>
#include <vector>
#include <queue>
#include <functional>

struct TicketTo {
    int city_ = 0;
    int price_ = 0;
};

using DestinationsT = std::vector<TicketTo>;
using CityFlightsT = std::unordered_map<int, DestinationsT>;

struct CityArrivalPrice {
    int city_ = 0;
    int price_ = 0;
    int stepsCnt_ = 0;
    friend bool operator>(const CityArrivalPrice& l, const CityArrivalPrice& r) {
        return l.price_ > r.price_;
    }

    CityArrivalPrice& operator=(const CityArrivalPrice& other) {
        city_ = other.city_;
        price_ = other.price_;
        stepsCnt_ = other.stepsCnt_;
        return *this;
    }
};

using TravelQueueT = std::priority_queue<
        CityArrivalPrice, std::vector<CityArrivalPrice>, std::greater<CityArrivalPrice>>;

using VisitedCitiesT = std::unordered_map<int, CityArrivalPrice>;

int findCheapestPrice(int n, const std::vector<std::vector<int>>& flights, int src, int dst, int k) {
    CityFlightsT cityFlights;
    for (auto f : flights) {
        cityFlights[f[0]].emplace_back(TicketTo{f[1], f[2]});
    }

    TravelQueueT travelQueue;
    travelQueue.emplace(CityArrivalPrice{src, 0, 0});
    VisitedCitiesT visitedCities;
    auto cheapestPrice = -1;
    while (!travelQueue.empty()) {
        auto arrival = travelQueue.top();
        travelQueue.pop();
        auto visitedIt = visitedCities.find(arrival.city_);
        if (visitedIt != end(visitedCities) &&
            visitedIt->second.price_ <= arrival.price_ &&
            visitedIt->second.stepsCnt_ <= arrival.stepsCnt_) {
            continue;
        }

        visitedCities[arrival.city_] = arrival;
        if (arrival.city_ == dst) {
            if (cheapestPrice == -1 || arrival.price_ < cheapestPrice) {
                cheapestPrice = arrival.price_;
            }
            continue;
        }
        if (arrival.stepsCnt_ == k + 1) {
            continue;
        }
        for (const auto& nextCity : cityFlights[arrival.city_]) {
            travelQueue.emplace(
                    CityArrivalPrice{nextCity.city_, arrival.price_ + nextCity.price_, arrival.stepsCnt_ + 1});
        }
    }

    return cheapestPrice;
}

#endif //ALGORITHMICCHALLENGES_787_CHEAPESTFLIGHTSWITHINKSTOPS_H
