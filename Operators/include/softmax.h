#ifndef SOFTMAX_H
#define SOFTMAX_H

#include <vector>

class Softmax {
public:
    static std::vector<float> forward(const std::vector<float>& input);
};

#endif
