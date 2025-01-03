#include "softmax.h"
#include <cmath>

std::vector<float> Softmax::forward(const std::vector<float>& input) {
    std::vector<float> output(input.size());
    float sum = 0.0;

    for (float val : input) {
        sum += std::exp(val);
    }

    for (int i = 0; i < input.size(); ++i) {
        output[i] = std::exp(input[i]) / sum;
    }

    return output;
}
