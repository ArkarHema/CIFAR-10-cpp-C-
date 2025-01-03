#include "dense.h"
#include <stdexcept>
#include <algorithm>
#include <cmath>

Dense::Dense(int input_size, int output_size) : input_size(input_size), output_size(output_size) {}

void Dense::load_weights(const std::vector<float>& flat_weights, const std::vector<float>& flat_bias) {
    if (flat_weights.size() != input_size * output_size) {
        throw std::runtime_error("Invalid weights size for Dense layer");
    }

    if (flat_bias.size() != output_size) {
        throw std::runtime_error("Invalid bias size for Dense layer");
    }

    weights.resize(output_size, std::vector<float>(input_size));
    bias = flat_bias;

    size_t idx = 0;
    for (int i = 0; i < output_size; ++i) {
        for (int j = 0; j < input_size; ++j) {
            weights[i][j] = flat_weights[idx++];
        }
    }
}

// Softmax function applied only at the final layer
std::vector<float> Dense::softmax(const std::vector<float>& input) {
    std::vector<float> output(input.size());
    float max_val = *std::max_element(input.begin(), input.end());
    float sum = 0.0f;

    for (int i = 0; i < input.size(); ++i) {
        output[i] = exp(input[i] - max_val);  // Subtract max to improve numerical stability
        sum += output[i];
    }

    for (int i = 0; i < output.size(); ++i) {
        output[i] /= sum;  // Normalize to get probabilities
    }

    return output;
}

// Forward pass function with option for softmax
std::vector<float> Dense::forward(const std::vector<float>& input, bool apply_softmax) {
    std::vector<float> output(output_size, 0.0f);

    // Calculate the raw output of the dense layer (W * x + b)
    for (int i = 0; i < output_size; ++i) {
        for (int j = 0; j < input_size; ++j) {
            output[i] += weights[i][j] * input[i];
        }
        output[i] += bias[i];
    }

    // Apply ReLU activation for hidden layers
    // for (float& val : output) {
    //     val = std::max(0.0f, val);  // ReLU activation
    // }

    // If Softmax is requested (i.e., this is the last layer), apply it
    if (apply_softmax) {
        output = softmax(output);
    }

    return output;
}
