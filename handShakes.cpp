#include <iostream>
#include <vector>
#include <format>

int handShakesCount(const std::vector<std::string> &people);

int main(void)
{
    std::vector<std::string> people;
    std::string name;

    std::cout << "How many people? ";
    int people_count;
    std::cin >> people_count;

    people.reserve(people_count); // Reserve enough memory to avoid reallocating internal heap memory multiple times as it grows

    // Crucial: Clear the leftover newline (\n) in the buffer from std::cin >> people_count
    std::cin.ignore();

    for (int i = 0; i < people_count; ++i)
    {
        std::cout << std::format("Person number {}: ", i + 1);
        std::getline(std::cin, name);
        people.push_back(name);
    }

    std::cout << "\n";

    int count = handShakesCount(people);

    std::cout << "The number of handshakes: " << count << "\n";

    return 0;
}

int handShakesCount(const std::vector<std::string> &people)
{
    int people_count = people.size();
    int count = 0;

    for (int i = 0; i < people_count - 1; ++i)
    {
        for (int j = i + 1; j < people_count; ++j)
        {
            std::cout << std::format("{} shakes hand with {}\n", people[i], people[j]);
            count++; // I could also use N*(N-1)/2 to get the count
        }
    }

    return count;
}