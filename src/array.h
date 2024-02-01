#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <iostream>

class StridedArray {
public:
    StridedArray(std::vector<int> dimensions, std::vector<int> strides)
        : dimensions(dimensions), strides(strides) {
        int totalSize = 1;
        for (int dim : dimensions) totalSize *= dim;
        data.resize(totalSize);
    }

    int& operator()(const std::vector<int>& indices) {
        int offset = 0;
        for (size_t i = 0; i < indices.size(); ++i) {
            offset += indices[i] * strides[i];
        }
        return data[offset];
    }

private:
    std::vector<int> data;
    std::vector<int> dimensions;
    std::vector<int> strides;
};

#endif
