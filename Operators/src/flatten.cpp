#include "flatten.h"

std::vector<float> Flatten::forward(const std::vector<std::vector<std::vector<float>>>& input) {
    std::vector<float> flattened;
    for (const auto& channel : input) {
        for (const auto& row : channel) {
            flattened.insert(flattened.end(), row.begin(), row.end());
        }
    }
    return flattened;
}
