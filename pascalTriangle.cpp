#include <iostream>
#include <vector>
#include <iomanip> // Needed for std::setw alignment

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> result;
        if (numRows == 0) return result;
        result.reserve(numRows);

        for (int i = 0; i < numRows; ++i)
        {
            result.emplace_back();
            // push_back works perfectly here too!
            // result.push_back(std::vector<int>()); 
            int col_size = i + 1;
            result.back().reserve(col_size);

            for (int j = 0; j < col_size; ++j)
            {
                if (j == 0 || j == i)
                {
                    result[i].push_back(1);
                }
                else
                {
                    result[i].push_back(result[i-1][j-1] + result[i-1][j]);
                }
            }
        }
        return result;
    }

    void printPascalTriangle(const std::vector<std::vector<int>>& triangle) {
    size_t rows = triangle.size();
    
    for (size_t i = 0; i < rows; ++i) {
        // 1. Print leading spaces to center the triangle nicely
        // Creates a pyramid look by shifting shorter rows to the right
        std::cout << std::string((rows - i - 1) * 2, ' ');

        // 2. Print the actual numbers in the row
        for (size_t j = 0; j < triangle[i].size(); ++j) {
            // std::setw(3) ensures every number takes up exactly 3 spaces
            std::cout << std::setw(3) << triangle[i][j] << " ";
        }
        
        std::cout << "\n";
    }
}
};

int main()
{
    Solution sol;
    sol.printPascalTriangle(sol.generate(10));

    return 0;
}

/*
This is to generate Pascal Triangle with indexing, easier but slower than above!

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    
        // 1. Instantiates with numRows actual rows immediately
        std::vector<std::vector<int>> result(num_rows); 

        for (size_t i = 0; i < num_rows; ++i)
        {
            size_t col_size = i + 1;
            
            // 2. Instantiates the columns immediately (Fills them with 0)
            result[i].resize(col_size); 

            // 3. Populate using direct bracket indexing
            for (int j = 0; j < col_size; ++j)
            {
                if (j == 0 || j == i)
                {
                    result[i][j] = 1;
                }
                else
                {
                    result[i][j] = result[i-1][j-1] + result[i-1][j];
                }
            }
        }
        return result;
}

*/