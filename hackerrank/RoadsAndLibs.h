/**
* Roads and Libraries (graph theory)
*
* https://www.hackerrank.com/challenges/torque-and-development/problem
*
* Copyright 2017 Oleksii Diubankov
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef HACKERRANK_ROADSANDSLIBS_H
#define HACKERRANK_ROADSANDSLIBS_H

#include <iostream>
#include <vector>

namespace hackerrank
{
  struct HackerRoad
  {
  public:
    HackerRoad(unsigned cityA, unsigned cityB)
      : _cityA{ cityA }
      , _cityB{ cityB }
    {}

    HackerRoad() = default;

    unsigned _cityA = 0;
    unsigned _cityB = 0;
  };
  using HackerRoads = std::vector<HackerRoad>;


  struct HackerLand
  {
    unsigned _citiesCnt = 0;
    unsigned _libCost = 0;
    unsigned _roadCost = 0;
    HackerRoads _roads;
  };


  HackerRoad readRoad()
  {
    HackerRoad hackerRoad;
    std::cin >> hackerRoad._cityA >> hackerRoad._cityB;
    return hackerRoad;
  }


  HackerLand readLand()
  {
    HackerLand hackerLand;
    std::size_t roadsCnt = 0;
    std::cin >> hackerLand._citiesCnt >> roadsCnt >> hackerLand._libCost >> hackerLand._roadCost;
    hackerLand._roads.reserve(roadsCnt);
    for (std::size_t i = 0; i < roadsCnt; ++i)
      hackerLand._roads.push_back(readRoad());

    return hackerLand;
  }


  std::vector<HackerLand> readInput()
  {
    std::vector<HackerLand> lands;
    std::size_t queriesCnt = 0;
    std::cin >> queriesCnt;
    lands.reserve(queriesCnt);
    for (std::size_t i = 0; i < queriesCnt; ++i)
      lands.push_back(readLand());

    return lands;
  }


  class HackerLandGraph
  {
  public:
    HackerLandGraph(std::size_t citiesCnt, const HackerRoads& roads)
    {
      _cities.resize(citiesCnt);
      for (auto& road : roads)
      {
        _cities.at(road._cityA - 1).push_back(road._cityB - 1);
        _cities.at(road._cityB - 1).push_back(road._cityA - 1);
      }
    }


    std::size_t getMinLibAccessCost(std::size_t roadCost, std::size_t libCost)
    {
      if (libCost <= roadCost)
        return _cities.size() * libCost;

      std::size_t minLibAccessCost = 0;
      std::vector<bool> visitedCities(_cities.size(), false);
      for (std::size_t city = 0; city < visitedCities.size(); ++city)
      {
        if (!visitedCities.at(city))
        {
          buildLib(city, libCost, minLibAccessCost, visitedCities);
          buildRoads(city, roadCost, minLibAccessCost, visitedCities);
        }
      }

      return minLibAccessCost;
    }

  private:
    void buildLib(std::size_t city, std::size_t libCost, std::size_t& minLibAccessCost, std::vector<bool>& visitedCities)
    {
      minLibAccessCost += libCost;
      visitedCities.at(city) = true;
    }


    void buildRoads(std::size_t city, std::size_t roadCost, std::size_t& minLibAccessCost, std::vector<bool>& visitedCities)
    {
      for (auto& roadTo : _cities.at(city))
      {
        if (!visitedCities.at(roadTo))
        {
          minLibAccessCost += roadCost;
          visitedCities.at(roadTo) = true;
          buildRoads(roadTo, roadCost, minLibAccessCost, visitedCities);
        }
      }
    }

    std::vector<std::vector<std::size_t>> _cities;
  };


  std::size_t getMinLibAccessCost(const HackerLand& hackerLand)
  {
    HackerLandGraph hackerLandGraph{ hackerLand._citiesCnt, hackerLand._roads };
    return hackerLandGraph.getMinLibAccessCost(hackerLand._roadCost, hackerLand._libCost);
  }

}//namespace hackerrank

#endif //HACKERRANK_ROADSANDSLIBS_H
