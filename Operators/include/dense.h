#ifndef DENSE_H
#define DENSE_H

#include <vector>

class Dense {
public:
    // Constructor to initialize the layer with input size and output size
    Dense(int input_size, int output_size);

    // Function to load weights and biases
    void load_weights(const std::vector<float>& flat_weights, const std::vector<float>& flat_bias);

    // Forward pass function (with an option to apply Softmax on the final layer)
    std::vector<float> forward(const std::vector<float>& input, bool apply_softmax = false);

private:
    int input_size;
    int output_size;
    std::vector<std::vector<float>> weights;
    std::vector<float> bias;

    // Softmax function to normalize the output
    std::vector<float> softmax(const std::vector<float>& input);
};

#endif  // DENSE_H

