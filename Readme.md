# CIFAR-10 C++ Model Execution

This project demonstrates the execution of a CNN-based TensorFlow model (3 convolutional layers + 2 dense layers) trained on the CIFAR-10 dataset, implemented in C++. The project enables layer-by-layer execution of the model using custom C++ implementations, ensuring correctness by comparing results with the original Python Keras model.

---

## About

The core objectives of this project are:

1. **Model Execution**:
   - The TensorFlow model trained on the CIFAR-10 dataset is executed layer-by-layer in C++.
   - Model attributes such as channels, units, weights, filters, kernel sizes, and biases are extracted from the TensorFlow model and utilized in custom C++ implementations.

2. **Logging Intermediate Outputs**:
   - Intermediate outputs, layer names, and details are logged during execution for analysis.

3. **Validation**:
   - The outputs from the custom C++ implementation are compared with the Python Keras model outputs to ensure the correctness of predictions.

---

## OS and Tools Used

- **Operating System**: Windows 11  
  - **Version**: 23H2  
  - **Architecture**: 64-bit  

- **IDE**: Visual Studio Code (1.96.2)  
- **Build System**: CMake (3.31.3)  
- **Compiler**: MinGW (14.2.0)  
- **Library**: nlohmann/json (3.11.3)  
- **Version Control**: Git (2.45.1)  

---

## Project directory structure

CIFAR-10-cpp
├── README.md                # Project documentation
├──.gitignore                # Avoids commiting unnnecessary log files
├──configs                   # Directory containing a config json file having the details for each layers
|  └──json
|    └── model_config.json     
├── data                     # Directory containing input and output data
│   ├── input                # Subdirectory for input files (e.g., test images)
│   ├── reference            # Subdirectory for attributes of each layer
|   ├── weights              # Subdirectory for weights files of each layer
|   └── output               # Subdirectory for storing layer-by-layer output logs
├── include                  # Header files for the project
├── Operators
|  ├── include                  # Header of the various layers
|    ├──conv2d.h
|    ├──dense.h
|    ├──flatten.h
|    ├──max_pooling.h
|    └──softmax.h
|  ├── src                      # Implemetation of layers used in the project
|    ├──conv2d.cpp
|    ├──dense.cpp
|    ├──flatten.cpp
|    ├──max_pooling.cpp
|    └──softmax.cpp  
├── src                      # Source files for the project
│   └── main.cpp             # Implementation of the model and all layers
├── Test Operators
|  ├── include                  # Header of the functions used during testing various layers
|    └──methods.h
|  ├── src                      # Implemetation of functions and testing the layers used in the project
|    ├──methods.cpp
|    └──test.cpp  
├── Reports                  # Directory containing result comparisons and there are also layer wise output wise results
│   └── results.txt          # Text file with overall test and comparison results
└── Utilities                # Directory for header files for the project
├── include                  # Header of the most used functions in the project
|   └──utils.h
├── src                      # Implemetation of most used functions in the project
    └── utils.cpp                 


## Run the Project

### Clone the Repository
```bash
git clone https://github.com/ArkarHema/CIFAR-10-cpp-C-.git
cd cpp-cifar-10

---

## Create build directory

```bash
mkdir build
cd build

```

## Run CMake and executables

```bash
cmake ..
./Model.exe

```

## How to interpret the results:

- Intermediate layer outputs
  Check the data/output directory for results from each layer for the tested image
- Dual test results
  View the Reports/results.txt file for comparisons between the unit and model test outputs and also the final predictions for the input image.

```
