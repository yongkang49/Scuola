#include <stdio.h>
/// @brief copute the sum of the two number
/// @param a parameter int
/// @param b parameter int
/// @return the sum of two number
int add(int a, int b)
{
    return a+b;
}
/// @brief copute the multiplication of the two number
/// @param a parameter int
/// @param b parameter int
/// @return the multiplication of two number
int mul(int a, int b)
{
    return a*b;
}
/// @brief copute the sub of the two number
/// @param a parameter int
/// @param b parameter int
/// @return the sub of two number
int sub (int a, int b)
{
    return a-b;
}
/// @brief copute the division of the two number
/// @param a parameter int
/// @param b parameter int
/// @return the division of two number
double division(int a, int b)
{
    return a/b;
}
/// @brief this is the main function
void main(){
    printf("%d\n",add(6,3));
    printf("%d\n",mul(6,3));
    printf("%d\n",sub(6,3));
    printf("%f\n",division(6,3));
}
