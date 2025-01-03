#ifndef RELU_H
#define RELU_H

#include <vector>

class ReLU {
public:
    std::vector<std::vector<std::vector<float>>> forward(const std::vector<std::vector<std::vector<float>>>& input);
    std::vector<float> forward(const std::vector<float>& input);
};

#endif
