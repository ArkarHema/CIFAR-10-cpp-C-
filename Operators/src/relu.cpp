#include "relu.h"
#include <algorithm>

std::vector<std::vector<std::vector<float>>> ReLU::forward(const std::vector<std::vector<std::vector<float>>>& input) {
    auto relu_fn = [](float x) { return std::max(0.0f, x); };

    std::vector<std::vector<std::vector<float>>> output = input;
    for (auto& channel : output) {
        for (auto& row : channel) {
            for (auto& value : row) {
                value = relu_fn(value);
            }
        }
    }
    return output;
}

std::vector<float> ReLU::forward(const std::vector<float>& input) {
    auto relu_fn = [](float x) { return std::max(0.0f, x); };

    std::vector<float> output = input;
    std::transform(output.begin(), output.end(), output.begin(), relu_fn);
    return output;
}
