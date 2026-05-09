// prompts the user for a credit card number and then reports (via printf)
// whether it is a valid American Express, MasterCard, or Visa card number
/*
    Credit card numbers have a “checksum” built into them, a mathematical 
    relationship between at least one number and others. That checksum enables 
    to detect typos (e.g., transpositions), if not fraudulent numbers.

    Luhn’s Algorithm: most cards use an algorithm invented by Hans Peter Luhn
    of IBM. According to Luhn’s algorithm, you can determine if a credit card 
    number is (syntactically) valid
*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// functions prototypes
void check_length(long card_number);
// void print_result(string result);

int main(void)
{
    long card_number = get_long("Number: ");

    check_length(card_number);

    // string card_type = check_card_type(card_number)

    // call luhns_algo_checksum(card_type)
}


// define print_result(string result) function
void print_result(string result)
{
    // strcmp returns 0 if strings are identical
    if (strcmp(result, "invalid") == 0)
    {
        printf("INVALID\n");
        // terminate program with an error exit code
        exit(1);
    }
    printf("%s\n", result);
    // terminate program with success exit code
    exit(0);
}


// define check_length to check validity of length
void check_length(long card_number)
{
    const long CARD_MIN_LEN = 1000000000000;
    const long CARD_MAX_LEN = 1000000000000000;
    
    if (card_number <= CARD_MIN_LEN || card_number >= CARD_MAX_LEN)
    {
        print_result("invalid");
    }
    printf("valid length");
}


// define check_card_type(card_number) to check type of credit card
    // if numbers start with 34 or 37 return AMEX 
    // else if numbers start with 51-55 return MASTERCARD 
    // else if numbers start with 4 return VISA 
    // else call print_result("invalid")


// define luhns_algo_checksum(string card_type) to check validity
    // int sum = 0

    // loop through every other digit, starting from second-to-last digit
        // int multiplied_by_two = 2 * i
        // if  multiplied_by_two > 10
            // sum += multiplied_by_two[0] + multiplied_by_two[1]  
        // else
            // sum += multiplied_by_two
            
    // loop through every other digit, starting from last digit
        // sum += j

    // If the total’s last digit is 0 (total modulo 10 is congruent to 0)
        // call print_result(card_type)
    // call print_result("invalid")
        