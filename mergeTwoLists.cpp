#include <iostream>
#include <vector>

std::vector<int> mergeTwoLists(const std::vector<int> &list1, const std::vector<int> &list2);

int main()
{
    std::vector<int> list1 = {1, 3, 3, 6};
    std::vector<int> list2 = {1, 2, 5, 6, 7, 8, 9};
    std::vector<int> result = mergeTwoLists(list1, list2);
    
    std::cout << "The sorted list is: {";
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

std::vector<int> mergeTwoLists(const std::vector<int> &list1, const std::vector<int> &list2)
{
    int size1 = list1.size();
    int size2 = list2.size();

    std::vector<int> result = {};
    // if I defined the vector size then I wouldn't be able to use push_back as
    // predefining its size fills up the vector
    result.reserve(size1 + size2);

    int i1 = 0, i2 = 0;

    while (i1 < size1 && i2 < size2)
    {
        if (list1[i1] < list2[i2])
        {
            result.push_back(list1[i1++]);
            // ++i1;
        }
        else
        {
            result.push_back(list2[i2++]);
            // ++i2;
        }
    }

    while (i1 < size1)
    {
        result.push_back(list1[i1++]);
        // ++i1;
    }

    while (i2 < size2)
    {
        result.push_back(list2[i2++]);
        //++i2;
    }

    return result;
}