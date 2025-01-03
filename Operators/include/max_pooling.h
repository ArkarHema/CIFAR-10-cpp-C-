#ifndef MAXPOOL2D_H
#define MAXPOOL2D_H

#include <vector>

class MaxPool2D {
public:
    MaxPool2D(int pool_size = 2, int stride = 2);
    std::vector<std::vector<std::vector<float>>> forward(const std::vector<std::vector<std::vector<float>>>& input);

private:
    int pool_size;
    int stride;
};

#endif
