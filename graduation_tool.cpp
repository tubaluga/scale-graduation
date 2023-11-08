#include "graduation_tool.h"

#include <array>
#include <cmath>

auto GraduationTool::graduationStep(double maximumValue, const std::pair<int, int> &rangeOfNumberMarks) -> double {

    double step{0.};

    if (rangeOfNumberMarks.first > rangeOfNumberMarks.second) {
        return step;
    }

    const std::array<double, 3> stepVariants{1, 2, 5};

    auto degree = std::floor(std::log10(maximumValue));

    auto markValue = maximumValue / std::pow(10, degree);

    bool math{false};
    short maximumDeep = 5;

    while (!math) {

        for (const auto stepVariant: stepVariants) {
            const int maximumMarkCount = static_cast<int>(std::floor(markValue / stepVariant));

            if (maximumMarkCount >= rangeOfNumberMarks.first && maximumMarkCount <= rangeOfNumberMarks.second) {
                step = stepVariant * std::pow(10, degree);
                math = true;
                break;
            }
        }

        if (!math) {

            if (maximumDeep == 0) {
                break;
            }

            markValue *= 10;
            --degree;
            --maximumDeep;
        }
    }

    return step;
}
