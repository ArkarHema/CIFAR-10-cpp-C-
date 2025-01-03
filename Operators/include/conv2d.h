#ifndef CONV2D_H
#define CONV2D_H

#include <vector>
#include <string>

class Conv2D {
public:
    Conv2D(int input_channels, int filters, int kernel_size, int stride = 1, int padding = 0);
    void load_weights(const std::vector<float>& weights, const std::vector<float>& bias);
    std::vector<std::vector<std::vector<float>>> forward(const std::vector<std::vector<std::vector<float>>>& input);

private:
    int input_channels;
    int filters;
    int kernel_size;
    int stride;
    int padding;
    std::vector<std::vector<std::vector<float>>> weights;
    std::vector<float> bias;
};

#endif
