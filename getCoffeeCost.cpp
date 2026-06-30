#include <iostream>

float getCostOfCoffee(int numberOfCoffees, float pricePerCoffee);

int main(void)
{
    std::cout << "Total cost: " << getCostOfCoffee(36, 2.5f) << "\n";
    return 0;
}

float getCostOfCoffee(int numberOfCoffees, float pricePerCoffee)
{
    if (numberOfCoffees <= 0) return 0.0f;

    int paid_cofee = 0;
    paid_cofee = ((numberOfCoffees / 9) * 8) + (numberOfCoffees % 9);

    return paid_cofee * pricePerCoffee;
}