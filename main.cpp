#include <iostream>

#include "graduation_tool.h"

void printScale(double maximumScaleValue, double step) {
    if (step > 0) {

        auto cursor = 0.;

        std::cout << std::endl
                  << "Scale [0..." << maximumScaleValue << "]"
                  << std::endl;

        while (cursor < maximumScaleValue) {

            std::cout << cursor << " -------- ";

            cursor += step;
        }

        std::cout << maximumScaleValue << std::endl;
    }
}


void testScale(double maximum, const std::pair<int, int> &range) {

    const auto step = GraduationTool::graduationStep(maximum, range);

    printScale(maximum, step);
}


int main() {

    const std::pair<int, int> rangeOfNumberMarks{2, 3};

    std::cout << "Range of number marks: " << rangeOfNumberMarks.first << " -> " << rangeOfNumberMarks.second << std::endl;

    testScale(10, rangeOfNumberMarks);
    testScale(85, rangeOfNumberMarks);
    testScale(198, rangeOfNumberMarks);
    testScale(1789, rangeOfNumberMarks);
    testScale(89030, rangeOfNumberMarks);
    testScale(0.58, rangeOfNumberMarks);

    return 0;
}
