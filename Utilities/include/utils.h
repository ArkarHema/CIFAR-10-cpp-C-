#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>

std::vector<float> read_weights_from_file(const std::string& file_path);
void print_3d_vector(const std::vector<std::vector<std::vector<float>>> &vec);
void print_2d_vector(const std::vector<std::vector<float>> &vec);
void print_1d_vector(const std::vector<float> &vec);
std::vector<std::vector<std::vector<float>>> read_image_from_file(const std::string& filename, int width, int height);
std::vector<float> read_image_from_file_1d(const std::string& file_path);
#endif
