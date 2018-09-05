#pragma once

namespace hackerrank {

	long long getAllWallCnt(long long w, long long h) {
	    if (w == 0)
            return 0;

		if (h == 1) {
			long long result = 0;
			if (w > 4)
				result += getAllWallCnt(w - 4, 1);
			if (w > 3)
				result += getAllWallCnt(w - 3, 1);
			if (w > 2)
				result += getAllWallCnt(w - 2, 1);
			if (w > 1)
				result += getAllWallCnt(w - 1, 1);
			if (w == 1 || w == 2 || w == 3 || w == 4)
				result += 1;
			return result;
		}

		auto height1Cnt = getAllWallCnt(w, 1);
		long long result = height1Cnt;
		for (int i = 1; i < h; ++i)
			result *= height1Cnt;

        return result;
	}

	long long getStableWallCnt(long long w, long long h);

	long long getGapCnt(long long w, long long h) {
	    if (w <= 1)
            return 0;

	    long long result = 0;
	    for (int i = 1; i <= w - 1; ++i) {
            auto leftCnt = getAllWallCnt(i, h) - getGapCnt(i, h);
            auto rightCnt = getAllWallCnt(w - i, h) - getGapCnt(w - i, h);
            result += leftCnt * rightCnt;
        }

        return result;
	}

	long long getStableWallCnt(long long w, long long h) {
		auto result = getAllWallCnt(w, h);
		result -= getGapCnt(w, h);
        return result;
	}

}
