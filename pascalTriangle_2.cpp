#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex)
    {
        int numRows = rowIndex + 1;
        std::vector<std::vector<int>> result;
        if (rowIndex == 0) return {1};
        result.reserve(numRows);
        for (int i = 0; i < numRows; ++i)
        {
            result.emplace_back();
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
        return result[rowIndex];
    }
// This is a 1D version of Pascal Triangle to get the i'th row
    std::vector<int> getRow_2(int rowIndex)
    {
        // Initialize a 1D vector of size (rowIndex + 1) filled with 1s
        std::vector<int> row(rowIndex + 1, 1);
        
        // Loop through each row up to rowIndex
        for (int i = 1; i <= rowIndex; ++i) {
            // Loop backwards from the second-to-last element down to index 1
            for (int j = i - 1; j > 0; --j) {
                row[j] = row[j] + row[j - 1];
            }
        }
        
        return row;
    }
};

int main()
{
    Solution sol;
    std::vector<int> result;
    int rowIndex {5};
    result = sol.getRow_2(rowIndex);
    std::cout << "{";
    for (int i = 0; i < result.size(); ++i)
    {
        std::cout << result[i];
        if (i != result.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";

    return 0;
}