#ifndef FLATTEN_H
#define FLATTEN_H

#include <vector>

class Flatten {
public:
    std::vector<float> forward(const std::vector<std::vector<std::vector<float>>>& input);
};

#endif
