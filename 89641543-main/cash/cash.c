#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    // calculate how many cents are left
    cents = cents - quarters * 25;
    // printf("quarters, %i \n", quarters);

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;
    // printf("dimes, %i \n", dimes);

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;
    // printf("nickels, %i \n", nickels);

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;
    // printf("pennies, %i \n", pennies);

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}


int get_cents(void)
{
    int cents;
    do{
    cents = get_int("Enter number of cents ");
    }
    // ask again if cents are less that 0
    while(cents < 0);
    return cents;
}



int calculate_quarters(int cents)
{
    // If cents are 25 return 1, if 50 return 2, etc
    // as long as r is > 0 return r
    int quarter = 25;
    int r = cents / quarter;
    while(r > 0){
        // printf("%i \n", r);
        return r;

    }
    return 0;
}

int calculate_dimes(int cents)
{

    int dime = 10;
    int r = cents / dime;
    while(r > 0){
        return r;
    }

    return 0;
}

int calculate_nickels(int cents)
{
    int nickel = 5;
    int r = cents / nickel;
    while(r > 0){
        return r;
    }
    return 0;
}

int calculate_pennies(int cents)
{
    int pennie = 1;
    int r = cents / pennie;
    while(r > 0){
        return r;
    }

    return 0;
}
