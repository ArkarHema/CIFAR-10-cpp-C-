#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include "methods.cpp"

std::ofstream result_file("test.txt", std::ios::app); 

int main() {
    std::string output_file1 = "D:/Documents_personal/Multicoreware/assignments/assignment 2/cpp cifar-10/report/conv.txt";
    std::string expected_file1 = "D:/Documents_personal/Multicoreware/assignments/assignment 2/cpp cifar-10/data/output/conv2d_output.txt";
    std::string output_file2 = "D:/Documents_personal/Multicoreware/assignments/assignment 2/cpp cifar-10/report/pooling.txt";
    std::string expected_file2 = "D:/Documents_personal/Multicoreware/assignments/assignment 2/cpp cifar-10/data/output/max_pooling2d_output.txt";
    std::string output_file3 = "D:/Documents_personal/Multicoreware/assignments/assignment 2/cpp cifar-10/report/conv1.txt";
    std::string expected_file3 = "D:/Documents_personal/Multicoreware/assignments/assignment 2/cpp cifar-10/data/output/conv2d_1_output.txt";
    std::string output_file4 = "D:/Documents_personal/Multicoreware/assignments/assignment 2/cpp cifar-10/report/pooling1.txt";
    std::string expected_file4 = "D:/Documents_personal/Multicoreware/assignments/assignment 2/cpp cifar-10/data/output/max_pooling2d_1_output.txt";
    std::string output_file5 = "D:/Documents_personal/Multicoreware/assignments/assignment 2/cpp cifar-10/report/conv2.txt";
    std::string expected_file5 = "D:/Documents_personal/Multicoreware/assignments/assignment 2/cpp cifar-10/data/output/conv2d_2_output.txt";
    std::string output_file6 = "D:/Documents_personal/Multicoreware/assignments/assignment 2/cpp cifar-10/report/flatten.txt";
    std::string expected_file6 = "D:/Documents_personal/Multicoreware/assignments/assignment 2/cpp cifar-10/data/output/flatten_output.txt";
    std::string output_file7 = "D:/Documents_personal/Multicoreware/assignments/assignment 2/cpp cifar-10/report/dense.txt";
    std::string expected_file7 = "D:/Documents_personal/Multicoreware/assignments/assignment 2/cpp cifar-10/data/output/dense_output.txt";
    std::string output_file8 = "D:/Documents_personal/Multicoreware/assignments/assignment 2/cpp cifar-10/report/dense1.txt";
    std::string expected_file8 = "D:/Documents_personal/Multicoreware/assignments/assignment 2/cpp cifar-10/data/output/dense_1_output.txt";

    // Compare the files
    unit_test("conv1",output_file1, expected_file1);
    unit_test("pool1",output_file2, expected_file2);
    unit_test("conv2",output_file3, expected_file3);
    unit_test("pool2",output_file4, expected_file4);
    unit_test("conv3",output_file5, expected_file5);
    unit_test("flatten",output_file6, expected_file6);
    unit_test("dense1",output_file7, expected_file7);
    unit_test("dense2",output_file8, expected_file8);
    model_test(output_file8, expected_file8);

    return 0;
}
