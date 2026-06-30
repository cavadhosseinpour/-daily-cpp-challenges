#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &my_list);

int main()
{
    std::vector<int> my_list = {6, 1, 9, 2, 7, 4, 0, 8, 5, 3};
    bubbleSort(my_list);
    std::cout << "{";
    for (int i = 0; i < my_list.size(); ++i)
    {
        std::cout << my_list[i];
        if (i != my_list.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
    return 0;
}

void bubbleSort(std::vector<int> &my_list)
{
    if (my_list.empty()) return;

    for (int i = 0; i < my_list.size() - 1; ++i)
    {
        for (int j = i + 1; j < my_list.size(); ++j)
        {
            if (my_list[i] > my_list[j])
            {
                int temp = my_list[i];
                my_list[i] = my_list[j];
                my_list[j] = temp;
            }
        }
    }
}