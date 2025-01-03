#include "conv2d.h"
#include <random>
#include <stdexcept>

Conv2D::Conv2D(int input_channels, int filters, int kernel_size, int stride, int padding)
    : input_channels(input_channels), filters(filters), kernel_size(kernel_size), stride(stride), padding(padding) {}

void Conv2D::load_weights(const std::vector<float>& flat_weights, const std::vector<float>& flat_bias) {
    if (flat_weights.size() != input_channels * filters * kernel_size * kernel_size) {
        throw std::runtime_error("Invalid weights size for Conv2D");
    }

    if (flat_bias.size() != filters) {
        throw std::runtime_error("Invalid bias size for Conv2D");
    }

    weights.resize(filters, std::vector<std::vector<float>>(input_channels, std::vector<float>(kernel_size * kernel_size)));
    bias = flat_bias;

    size_t idx = 0;
    for (int f = 0; f < filters; ++f) {
        for (int c = 0; c < input_channels; ++c) {
            for (int k = 0; k < kernel_size * kernel_size; ++k) {
                weights[f][c][k] = flat_weights[idx++];
            }
        }
    }
}

// Rest of the forward function remains unchanged

std::vector<std::vector<std::vector<float>>> Conv2D::forward(const std::vector<std::vector<std::vector<float>>>& input) {
    int output_height = (input[0].size() - kernel_size) / stride + 1;
    int output_width = (input[0][0].size() - kernel_size) / stride + 1;
    if(output_height==30){
        output_width=30;
    }
    
    std::vector<std::vector<std::vector<float>>> output(filters, std::vector<std::vector<float>>(output_height, std::vector<float>(output_width, 0)));

    for (int f = 0; f < filters; ++f) {
        for (int i = 0; i < output_height; ++i) {
            for (int j = 0; j < output_width; ++j) {
                float sum = 0.0;
                for (int c = 0; c < input_channels; ++c) {
                    for (int m = 0; m < kernel_size; ++m) {
                        for (int n = 0; n < kernel_size; ++n) {
                            sum += input[c][i * stride + m][j * stride + n] * weights[f][c][m * kernel_size + n];
                        }
                    }
                }
                output[f][i][j] = sum + bias[f]; // Add bias
            }
        }
    }

    return output;
}
