#ifndef ALGORITHMICCHALLENGES_1136_PARALLELCOURSES_H
#define ALGORITHMICCHALLENGES_1136_PARALLELCOURSES_H

#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

using CoursesT = unordered_set<int>;

struct CourseYear {
    CourseYear(int course, int year) : course_(course), year_(year) {}
    int course_ = 0;
    int year_ = 0;
};

int minimumSemesters(int N, vector<vector<int>> const& relations) {
    vector<CoursesT> preCourses(N);
    vector<CoursesT> postCourses(N);
    for (auto& relation : relations) {
        preCourses[relation.back() - 1].insert(relation.front() - 1);
        postCourses[relation.front() - 1].insert(relation.back() - 1);
    }

    queue<CourseYear> courseQueue;
    int studiedCoursesCnt = 0;
    int totalYears = 1;
    for (int i = 0; i != N; ++i) {
        if (preCourses.at(i).empty()) {
            courseQueue.emplace(i, totalYears);
            ++studiedCoursesCnt;
        }
    }

    while (!courseQueue.empty()) {
        auto nextCourse = courseQueue.front();
        courseQueue.pop();
        for (auto postCourse : postCourses.at(nextCourse.course_)) {
            preCourses[postCourse].erase(nextCourse.course_);
            if (preCourses.at(postCourse).empty()) {
                totalYears = nextCourse.year_ + 1;
                courseQueue.emplace(postCourse, totalYears);
                ++studiedCoursesCnt;
            }
        }
    }

    if (studiedCoursesCnt == N)
        return totalYears;
    return -1;
}

#endif //ALGORITHMICCHALLENGES_1136_PARALLELCOURSES_H
