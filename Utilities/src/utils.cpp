#include "utils.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

std::vector<float> read_weights_from_file(const std::string& file_path) {
    std::vector<float> weights;
    std::ifstream file(file_path);

    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + file_path);
    }

    float value;
    while (file >> value) {
        weights.push_back(value);
    }

    file.close();
    return weights;
}


// Utility function to print a 3D vector
void print_3d_vector(const std::vector<std::vector<std::vector<float>>> &vec) {
    for (const auto &matrix : vec) {
        for (const auto &row : matrix) {
            for (float val : row) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
        std::cout << "----\n";
    }
}

// Utility function to print a 2D vector
void print_2d_vector(const std::vector<std::vector<float>> &vec) {
    for (const auto &row : vec) {
        for (float val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
    std::cout << "----\n";
}

// Utility function to print a 1D vector
void print_1d_vector(const std::vector<float> &vec) {
    for (float val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

// Function to read the image data from the file and return as a 3D tensor
std::vector<std::vector<std::vector<float>>> read_image_from_file(const std::string& filename, int width, int height) {
    std::ifstream file(filename);
    std::vector<std::vector<std::vector<float>>> image_data(3, std::vector<std::vector<float>>(height, std::vector<float>(width)));

    if (file.is_open()) {
        std::string line;
        int row = 0;
        while (std::getline(file, line) && row < height) {
            std::istringstream iss(line);
            float r, g, b;
            int col = 0;
            while (iss >> r >> g >> b && col < width) {
                image_data[0][row][col] = r;  // Red channel
                image_data[1][row][col] = g;  // Green channel
                image_data[2][row][col] = b;  // Blue channel
                col++;
            }
            row++;
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open the file!" << std::endl;
    }

    return image_data;
}

std::vector<float> read_image_from_file_1d(const std::string& file_path) {
    std::ifstream file(file_path);
    std::vector<float> data;  // To store the values in a 1D tensor (vector)

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return data;
    }

    std::string line;
    float val;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        // Read each float from the line
        while (ss >> val) {
            data.push_back(val);
        }
    }

    file.close();
    return data;
}