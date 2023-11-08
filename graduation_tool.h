#pragma once

#include <utility>

class GraduationTool {
public:
    static auto graduationStep(double maximumValue, const std::pair<int, int> &rangeOfNumberMarks = {3, 5}) -> double;
};
