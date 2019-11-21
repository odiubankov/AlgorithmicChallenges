//https://leetcode.com/problems/design-search-autocomplete-system/
#ifndef ALGORITHMICCHALLENGES_642_DESIGNSEARCHAUTOCOMPLETESYSTEM_H
#define ALGORITHMICCHALLENGES_642_DESIGNSEARCHAUTOCOMPLETESYSTEM_H

#include <vector>
#include <string>
#include <memory>
#include <array>
using namespace std;

constexpr size_t getCharsCnt() { return 'z' - 'a' + 2; }

class AutocompleteSystem {
public:
    static constexpr size_t CNT = 3;
    static constexpr size_t charI(char c) {
        if (c == ' ')
            return 'z' - 'a' + 1;
        return c - 'a';
    }

    static struct OftenComparator {
        bool operator ()(const pair<size_t, string>& often1, const pair<size_t, string>& often2) {
            if(often1.first == often2.first) {
                auto itL = begin(often1.second);
                auto itR = begin(often2.second);
                if (*itL != *itR)
                    return *itL < *itR;
                ++itL, ++itR;
                for (;;++itL, ++itR) {
                    if (itL == end(often1.second))
                        return itR != end(often2.second);
                    if (itR == end(often2.second))
                        return false;
                    if (*itL != *itR)
                        return *itL < *itR;
                }
            }
            return often1.first > often2.first;
        }
    } comparator_;

    struct Trie {
        string str_;
        char val_ = 0;
        int cnt_ = 0;
        array<shared_ptr<Trie>, getCharsCnt()> next_;
        vector<pair<size_t, string>> often_;
        Trie* parent_ = nullptr;

        Trie* add(char val) {
            if (!next_[charI(val)])
                next_[charI(val)] = make_shared<Trie>(this, val, str_ + val);
            return next_[charI(val)].get();
        }

        void updateOften(const pair<size_t, string>& often) {
            if (often_.size() < CNT || comparator_(often, often_.back())) {
                auto it = lower_bound(begin(often_), end(often_), make_pair(often.first - 1, often.second), comparator_);
                if (it == end(often_) || it->second != often.second)
                    often_.push_back(often);
                else
                    it->first = often.first;
                sort(begin(often_), end(often_), comparator_);
                if (often_.size() == (CNT + 1))
                    often_.pop_back();
            }
            if (parent_)
                parent_->updateOften(often);
        }

        void setCnt(int cnt) {
            cnt_ = cnt;
            updateOften(make_pair(cnt_, str_));
        }

        Trie(Trie* parent, char val, string str) : val_(val), parent_(parent), str_{move(str)} {}
    };

    Trie trie_{nullptr, 0, ""};
    Trie* current_ = &trie_;

    AutocompleteSystem(const vector<string>& sentences, const vector<int>& times) {
        for (size_t i = 0; i < sentences.size(); ++i) {
            for (auto c : sentences[i])
                current_ = current_->add(c);
            current_->setCnt(times[i]);
            current_ = &trie_;
        }
    }

    vector<string> input(char c) {
        vector<string> res;
        if (c != '#') {
            current_ = current_->add(c);
            res.reserve(current_->often_.size());
            std::transform(begin(current_->often_), end(current_->often_), back_inserter(res),
                           [](const auto& often) { return often.second; });
        } else {
            current_->setCnt(current_->cnt_ + 1);
            current_ = &trie_;
        }
        return res;
    }
};

AutocompleteSystem::OftenComparator AutocompleteSystem::comparator_;

#endif //ALGORITHMICCHALLENGES_642_DESIGNSEARCHAUTOCOMPLETESYSTEM_H
