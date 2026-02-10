#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;

    do
    {
        printf("Change owed: ");
        scanf("%f", &dollars);
    }
    while (dollars <= 0);

    int cents = round(dollars * 100);

    int n;
    printf("Number of coin types: ");
    scanf("%d", &n);

    int coins[n];

    for (int i = 0; i < n; i++)
    {
        printf("Coin %d value (cents): ", i + 1);
        scanf("%d", &coins[i]);
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        count += cents / coins[i];
        cents %= coins[i];
    }

    printf("Total coins: %d\n", count);
}
