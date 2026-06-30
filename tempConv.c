#include <stdio.h>

double fahrenheit_to_celsius(double fahrenheit);
float celsius_to_fahrenheit(float celsius);

int main()
{
    printf("Enter temperature in Fahrenheit: ");
    double fahrenheit;
    scanf("%lf", &fahrenheit);
    double celsius = fahrenheit_to_celsius(fahrenheit);
    printf("Temperature in Celsius: %lf\n", celsius);

    printf("Enter temperature in Celsius: ");
    float celsius_input;
    scanf("%f", &celsius_input);
    float fahrenheit_output = celsius_to_fahrenheit(celsius_input);
    printf("Temperature in Fahrenheit: %f\n", fahrenheit_output);
    return 0;
}

double fahrenheit_to_celsius(double fahrenheit)
{
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float celsius_to_fahrenheit(float celsius)
{
    return (celsius * 9.0 / 5.0) + 32;
}