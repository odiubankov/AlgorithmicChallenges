#pragma once

#include <unordered_map>

using ULL = unsigned long long;

namespace hackerrank {

    ULL getAllWallCnt(ULL w, ULL h) {
	    if (w == 0)
            return 0;

	    static std::unordered_map<ULL, std::unordered_map<ULL, ULL>> cache;
	    auto cacheIt1 = cache.find(w);
	    if (cacheIt1 != end(cache)){
	        auto cacheIt2 = cacheIt1->second.find(h);
	        if (cacheIt2 != std::end(cacheIt1->second))
                return cacheIt2->second;
	    }

		if (h == 1) {
            ULL result = 0;
            const ULL MaxBlockLength = 4;
			for (ULL i = 1; i <= MaxBlockLength; ++i) {
			    if (w > i)
                    result += getAllWallCnt(w - i, 1);
			    else if (w == i)
			        result += 1;
			}

			cache[w][h] = result;
            return result;
		}

		auto height1Cnt = getAllWallCnt(w, 1);
        ULL result = height1Cnt;
		for (int i = 1; i < h; ++i) {
            result *= (height1Cnt);
		}

        cache[w][h] = result;
        return result;
	}

    ULL getAllGapCnt(ULL w, ULL h);

    ULL getGapCnt(ULL w, ULL h, ULL n) {
        if (w <= 1)
            return 0;

        static std::unordered_map<ULL,
            std::unordered_map<ULL,
                               std::unordered_map<ULL, ULL>>> cache;

        auto cacheIt1 = cache.find(w);
        if (cacheIt1 != end(cache)){
            auto cacheIt2 = cacheIt1->second.find(h);
            if (cacheIt2 != std::end(cacheIt1->second)){
                auto cacheIt3 = cacheIt2->second.find(n);
                if (cacheIt3 != std::end(cacheIt2->second))
                    return cacheIt3->second;
            }
        }

        ULL result = 0;
        for (int i = 1; i <= w - 1; ++i) {
            auto leftCnt = getAllWallCnt(i, h) - getAllGapCnt(i, h);
            ULL rightCnt = 0;
            if (n == 1)
                rightCnt = getAllWallCnt(w - i, h) - getAllGapCnt(w - i, h);
            else
                rightCnt = getGapCnt(w - i, h, n - 1);

            result += (leftCnt) * (rightCnt);
        }

        cache[w][h][n] = result;
        return result;
    }

    ULL getAllGapCnt(ULL w, ULL h) {
	    if (w <= 1)
            return 0;

        ULL result = 0;
	    for (ULL i = 1; i <= w - 1; ++i) {
            result += getGapCnt(w, h, i);
	    }

        return result;
	}

    ULL getStableWallCnt(ULL w, ULL h) {
		auto result = getAllWallCnt(w, h);
		auto gapCnt = getAllGapCnt(w, h);
		result -= gapCnt;
		result %= 1000000007;
        return result;
	}

}
