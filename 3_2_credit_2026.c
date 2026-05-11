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
string check_card_type(long card_number);
int get_first_two_digits(long card_number);
// void print_result(string result);

int main(void)
{
    long card_number = get_long("Number: ");

    check_length(card_number);

    string card_type = check_card_type(card_number);

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
    const long CARD_MIN_SHORT_LEN = 1000000000000;
    const long CARD_MAX_SHORT_LEN = 9999999999999;
    const long CARD_MIN_LONG_LEN = 100000000000000;
    const long CARD_MAX_LONG_LEN = 9999999999999999;
    bool is_valid_short_len = (card_number >= CARD_MIN_SHORT_LEN && 
                               card_number <= CARD_MAX_SHORT_LEN);
    bool is_valid_long_len = (card_number >= CARD_MIN_LONG_LEN && 
                              card_number <= CARD_MAX_LONG_LEN);
    if (!is_valid_short_len && !is_valid_long_len)
    {
        print_result("invalid");
    }
    printf("Valid length\n");
}

// define check_card_type(card_number) to check type of credit card
string check_card_type(long card_number)
{
    int first_two_digits = get_first_two_digits(card_number);
    printf("first two digits = %i ", first_two_digits);
    // if numbers start with 34 or 37 return AMEX 
    // else if numbers start with 51-55 return MASTERCARD 
    // else if numbers start with 4 return VISA 
    // else call print_result("invalid")
}

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

/* check_card_type helper functions */
int get_first_two_digits(long card_number)
{
    while (card_number > 99)
    {
        card_number /= 10;
    }
    // return the first two digits
    return card_number;
}