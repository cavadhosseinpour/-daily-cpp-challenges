#include <iostream>
#include <vector>

int getMin(const std::vector<int> &lst, int &size);

int main(void)
{
    std::vector<int> lst = {6, 9, 1, 0, 3, 7};
    int size = lst.size();

    int result = getMin(lst, size);
    std::cout << "The minimum is: " << result << "\n";
    return 0;
}

int getMin(const std::vector<int> &lst, int &size)
{
    if (size < 1) return 0;

    int result = lst[0];
    for (int i = 0; i < size; ++i)
    {
        if (lst[i] < result)
        {
            result = lst[i];
        }
    }
    return result;

}