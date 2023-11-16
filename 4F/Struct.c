#include <stdio.h>
struct coordinate
{
    int x;
    int y;
    int z;
} co1,co2;
void stampa_punto(int x, int y, int z)
{
    printf("x:%d y:%d z:%d \n", x, y, z);
}
void punto_modificato(int n)
{
    co2.x = co1.x + n;
    co2.y = co1.y + n;
    co2.z = co1.z + n;
}
int main(int argc, char *argv[])
{
    co1.x = 12;
    co1.y = 2;
    co1.z = 15;
    printf("il primo punto è presente nelle sequenti coordinate:\n");
    stampa_punto(co1.x,co1.y,co1.z);
    printf("il secondo punto è presente nelle sequenti coordinate:\n");
    punto_modificato(5);
    stampa_punto(co2.x,co2.y,co2.z);
    return 0;
}