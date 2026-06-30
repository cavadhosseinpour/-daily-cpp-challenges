#include <iostream>
#include <vector>
#include <unordered_map>

// this file contains the code for merge-sorting, mediana & mode of a list.

template <typename T>
void merge(std::vector<T> &list, int left, int mid, int right);

template <typename T>
void mergeSort(std::vector<T> &list, int left, int right);

template <typename T>
T medianFunc(std::vector<T> &list);

template <typename T>
T modeList(std::vector<T> &list);

int main(void)
{
    std::vector<double> list = {1, 9, 2, 8, 3, 7, 4, 6, 5.5, 0, 2, 2};
    std::cout << "The median of the list is: " << std::format("{:.2f}", medianFunc(list)) << "\n";
    std::cout << "The mode of the list is: " << modeList(list) << "\n";
    return 0;
}

template <typename T>
void merge(std::vector<T> &list, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<T> leftArr(n1);
    std::vector<T> rightArr(n2);

    for (int i = 0; i < n1; ++i)
    {
        leftArr[i] = list[left + i];
    }

    for (int i = 0; i < n2; ++i)
    {
        rightArr[i] = list[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            list[k] = leftArr[i];
            i++;
        }
        else
        {
            list[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        list[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        list[k] = rightArr[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSort(std::vector<T> &list, int left, int right)
{
    if (left >= right) return;
    int mid = left + (right - left) / 2;

    // Recursively halve the first and second halves
    mergeSort(list, left, mid);
    mergeSort(list, mid + 1, right);

    // Merge the halved arrays back together
    merge(list, left, mid, right);
}

template <typename T>
T medianFunc(std::vector<T> &list)
{
    if (list.empty()) return 0;

    mergeSort(list, 0, list.size() - 1);

    int S = list.size();
    
    if (S % 2 != 0)
    {
        return list[S / 2];
    }
    else
    {
        return (list[S / 2] + list[(S / 2) - 1]) / 2;
    }
}

template <typename T>
T modeList(std::vector<T> &list)
{
    if (list.empty()) return 1;
    
    std::unordered_map<int,int> frequencyMap;

    T mostFrequentNum = list[0];
    int highestFrequency = 0;

    for (T num : list)
    {
        frequencyMap[num]++;
        if (frequencyMap[num] > highestFrequency)
        {
            mostFrequentNum = num;
            highestFrequency = frequencyMap[num];
        }
    }

    return mostFrequentNum;
}