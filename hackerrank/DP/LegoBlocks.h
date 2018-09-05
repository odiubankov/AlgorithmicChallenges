#pragma once

namespace hackerrank {
	long long getAllWallCnt(long long w, long long h) {
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
		for (i = 1; i < h; ++i)
			result *= height1Cnt;
	}

	long long getGapCnt(long long w, long long h, long long n) {
		auto result = getAllWallCnt(n, h) * getAllWallCnt(w - n, h);
		result -= getStableWallCnt(w - n, h);
		return result;
	}

	long long getStableWallCnt(long long w, long long h) {
		auto result = getAllWallCnt(w, h);
		for (int i = 1; i < w - 1; ++i) {
			result -= getGapCnt(w, h, i);
		}
	}
}
