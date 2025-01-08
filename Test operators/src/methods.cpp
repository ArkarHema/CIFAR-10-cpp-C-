#include "methods.h"
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>
#include <chrono>

std::ofstream result_file("test.txt", std::ios::app);

// Utility function to read a file into a 1D vector
std::vector<float> read_file_to_vector(const std::string& file_path) {
    std::vector<float> data;
    std::ifstream file(file_path);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << file_path << std::endl;
        return {};
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        float value;
        while (iss >> value) {
            data.push_back(value);
        }
    }

    file.close();
    return data;
}

// Function to compare the highest values (classification) from two output files
void model_test(const std::string& output_file, const std::string& expected_file) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    auto output_data = read_file_to_vector(output_file);
    auto expected_data = read_file_to_vector(expected_file);

    if (output_data.empty() || expected_data.empty()) {
        std::cerr << "Error: One or both files are empty or failed to load." << std::endl;
        return;
    }

    if (output_data.size() != expected_data.size()) {
        std::cerr << "Error: Size mismatch between output and expected data." << std::endl;
        return;
    }

    // Find the index of the maximum value in both vectors
    auto output_max_index = std::distance(output_data.begin(), std::max_element(output_data.begin(), output_data.end()));
    auto expected_max_index = std::distance(expected_data.begin(), std::max_element(expected_data.begin(), expected_data.end()));

    result_file << "Output Max Index: " << output_max_index << " with value " << output_data[output_max_index] << std::endl;
    result_file << "Expected Max Index: " << expected_max_index << " with value " << expected_data[expected_max_index] << std::endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    // Compare the indices
    if (output_max_index == expected_max_index) {
        result_file << "Test Passed: The classification results match." << std::endl;
        result_file << "Model Test Comparison Time: " << duration.count() << " ms" << std::endl;
    } else {
        std::cerr << "Test Failed: Classification results differ." << std::endl;
    }
}

// Function to compare two output files
void unit_test(const std::string layer,const std::string& output_file, const std::string& expected_file, float epsilon = 0.001) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    auto output_data = read_file_to_vector(output_file);
    auto expected_data = read_file_to_vector(expected_file);

    if (output_data.size() != expected_data.size()) {
        std::cerr << "Test Failed: Size mismatch between output (" << output_data.size() 
                  << ") and expected (" << expected_data.size() << ") data." << std::endl;
        return;
    }

    bool test_passed = true;
    if(layer=="conv1" || layer=="conv2" || layer=="conv3"){
    for (size_t i = 0; i < output_data.size(); ++i) {
        if(output_data[i]==0)
            continue;
        if (std::abs(output_data[i] - expected_data[i]) > epsilon) {
            std::cerr << "Mismatch at index " << i << ": output = " << output_data[i]
                      << ", expected = " << expected_data[i] << std::endl;
            test_passed = false;
        }
    }
    }
    else{
       for (size_t i = 0; i < output_data.size(); ++i) {
        if (std::abs(output_data[i] - expected_data[i]) > epsilon) {
            std::cerr << "Mismatch at index " << i << ": output = " << output_data[i]
                      << ", expected = " << expected_data[i] << std::endl;
            test_passed = false;
        }
    } 
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    
    if (test_passed) {
        result_file <<layer<< " Test Passed: All values match within tolerance (" << epsilon << ")." << std::endl;
        result_file << layer << " Comparison Time: " << duration.count() << " ms" << std::endl;
    } else {
        std::cerr << " Test Failed: Mismatched values found." << std::endl;
    }
}
