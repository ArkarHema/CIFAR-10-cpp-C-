#include "max_pooling.h"
#include <cmath>
#include <limits>

// Constructor to initialize pooling parameters
MaxPool2D::MaxPool2D(int pool_size, int stride)
    : pool_size(pool_size), stride(stride) {}

// Forward pass for max pooling
std::vector<std::vector<std::vector<float>>> MaxPool2D::forward(
    const std::vector<std::vector<std::vector<float>>>& input) {

    int input_depth = input.size();
    int input_height = input[0].size();
    int input_width = input[0][0].size();

    // Calculate output dimensions
    int output_height = (input_height - pool_size) / stride + 1;
    int output_width = (input_width - pool_size) / stride + 1;

    // Initialize output with appropriate dimensions
    std::vector<std::vector<std::vector<float>>> output(
        input_depth,
        std::vector<std::vector<float>>(output_height, std::vector<float>(output_width, 0)));

    // Perform max pooling
    for (int d = 0; d < input_depth; ++d) {
        for (int h = 0; h < output_height; ++h) {
            for (int w = 0; w < output_width; ++w) {
                float max_val = -std::numeric_limits<float>::infinity();

                // Pooling window
                for (int i = 0; i < pool_size; ++i) {
                    for (int j = 0; j < pool_size; ++j) {
                        int in_h = h * stride + i;
                        int in_w = w * stride + j;
                        if (in_h < input_height && in_w < input_width) {
                            max_val = std::max(max_val, input[d][in_h][in_w]);
                        }
                    }
                }
                output[d][h][w] = max_val;
            }
        }
    }

    return output;
}
