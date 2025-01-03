#include <iostream>
#include <fstream>
#include "conv2d.h"
#include "dense.h"
#include "max_pooling.h"
#include "softmax.h"
#include "flatten.h"
#include "relu.h"
#include "utils.h"

// Function to redirect console output to a file
std::ofstream result_file("results.txt", std::ios::app); // Open in append mode


template <typename T>
void print_dimensions(const std::string& layer_name, const T& tensor) {
    if constexpr (std::is_same_v<T, std::vector<std::vector<std::vector<float>>>>) {
        // For 3D tensors
        result_file << layer_name << " Output Dimensions: "
                  << tensor.size() << "x" << tensor[0].size() << "x" << tensor[0][0].size()
                  << std::endl;
    } else if constexpr (std::is_same_v<T, std::vector<float>>) {
        // For 1D tensors
        result_file << layer_name << " Output Dimensions: " << tensor.size() << std::endl;
    }
}

int main() {
    // Initialize layers
    Conv2D conv1(3, 128, 3);
    Conv2D conv2(128, 128, 3);
    Conv2D conv3(128, 128, 3);
    Dense fc1(2048, 128);
    Dense fc2(128, 10);

    // Activation and Flatten Layers
    ReLU relu;
    Flatten flatten;
    MaxPool2D maxpool;

    // Load weights and biases
    conv1.load_weights(read_weights_from_file("D:/Documents_personal/Multicoreware/assignments/assignment 2/Model_test/weights/weights/conv2d_kernel.txt"), read_weights_from_file("D:/Documents_personal/Multicoreware/assignments/assignment 2/Model_test/weights/weights/conv2d_bias.txt"));
    conv2.load_weights(read_weights_from_file("D:/Documents_personal/Multicoreware/assignments/assignment 2/Model_test/weights/weights/conv2d_1_kernel.txt"), read_weights_from_file("D:/Documents_personal/Multicoreware/assignments/assignment 2/Model_test/weights/weights/conv2d_1_bias.txt"));
    conv3.load_weights(read_weights_from_file("D:/Documents_personal/Multicoreware/assignments/assignment 2/Model_test/weights/weights/conv2d_2_kernel.txt"), read_weights_from_file("D:/Documents_personal/Multicoreware/assignments/assignment 2/Model_test/weights/weights/conv2d_2_bias.txt"));
    fc1.load_weights(read_weights_from_file("D:/Documents_personal/Multicoreware/assignments/assignment 2/Model_test/weights/weights/dense_kernel.txt"), read_weights_from_file("D:/Documents_personal/Multicoreware/assignments/assignment 2/Model_test/weights/weights/dense_bias.txt"));
    fc2.load_weights(read_weights_from_file("D:/Documents_personal/Multicoreware/assignments/assignment 2/Model_test/weights/weights/dense_1_kernel.txt"), read_weights_from_file("D:/Documents_personal/Multicoreware/assignments/assignment 2/Model_test/weights/weights/dense_1_bias.txt"));

    std::vector<std::vector<std::vector<float>>> input = read_image_from_file("D:/Documents_personal/Multicoreware/assignments/assignment 2/Model_test/input/conv2d_input.txt", 32, 32);  // Adjust the path and size as needed

    // // Forward pass
    std::cout<< "Input:\n";
    print_dimensions("Input", input);
    print_3d_vector(input);

    // // Forward pass
    auto conv1_output = conv1.forward(input);
    auto relu1_output = relu.forward(conv1_output);
    std::cout << "Conv Output:\n";
    print_dimensions("ReLU1", relu1_output);
    print_3d_vector(relu1_output);

    auto pooled1_output = maxpool.forward(relu1_output);
    std::cout << "Pooled1 Output:\n";
    print_dimensions("Pooled1", pooled1_output);
    print_3d_vector(pooled1_output);

    auto conv2_output = conv2.forward(pooled1_output);
    auto relu2_output = relu.forward(conv2_output);
    std::cout << "ReLU2 Output:\n";
    print_dimensions("ReLU2", relu2_output);
    print_3d_vector(relu2_output);

    auto pooled2_output = maxpool.forward(relu2_output);
    std::cout << "Pooled2 Output:\n";
    print_dimensions("Pooled2", pooled2_output);
    print_3d_vector(pooled2_output);

    auto conv3_output = conv3.forward(pooled2_output);
    auto relu3_output = relu.forward(conv3_output);
    std::cout << "ReLU3 Output:\n";
    print_dimensions("ReLU3", relu3_output);
    print_3d_vector(relu3_output);

    auto flattened_output = flatten.forward(relu3_output);
    std::cout << "Flattened Output:\n";
    print_dimensions("Flattened", flattened_output);
    print_1d_vector(flattened_output);

    
    auto fc1_output = fc1.forward(flattened_output);
    std::cout << "FC1 Output:\n";
    print_dimensions("FC1", fc1_output);
    print_1d_vector(fc1_output);

    auto relu_fc1_output = relu.forward(fc1_output);
    std::cout << "ReLU FC1 Output:\n";
    print_dimensions("ReLU FC1", relu_fc1_output);
    print_1d_vector(relu_fc1_output);
    
    auto fc2_output = fc2.forward(relu_fc1_output);
    std::cout << "FC2 Output:\n";
    print_dimensions("FC2", fc2_output);
    print_1d_vector(fc2_output);

    auto final_output = Softmax::forward(fc2_output);
    print_dimensions("Softmax Final Output", final_output);
    std::cout << "Final Output:\n";
    print_1d_vector(final_output);

    return 0;
}