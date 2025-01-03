About


This project uses a CNN based (3 convolution + 2 dense) trained tensorflow model on cifar-10 dataset to test a image through layer-by-layer execution in C++. Model Layers attributes like channels, units, weights, filters, kernel sizes, bias are extracted and used in custom C++ implementations of each layer. During execution, intermediate outputs and details such as layer names and outputs for execution of each layer are logged. Outputs from the custom implementation are compared with the Python keras model to ensure the correct prediction.



OS and Tools used


Operating System : Windows 11


Version : 23H2


Architecture : 64 bit OS



IDE : Visual Studio Code (1.96.2)


Build System : CMake (3.31.3)


Compiler : MinGW (14.2.0)


Library : nlohmann/json (3.11.3)


Version Control : Git (2.45.1)



Run the project


Clone this repository


git clone https://github.com/ArkarHema/CIFAR-10-cpp-C-.git

cd cpp cifar-10


Create Build Directory

mkdir build


cd build


Run CMake and executable

cmake ..

./Model.exe



How to Interpret the Results


Intermediate Layer Outputs:


Check the data/output directory for results from each layer for the tested image.


Dual Test Results:


View the Reports/results.txt for comparisons between unit and model test outputs and also the final predictions for the input image.


