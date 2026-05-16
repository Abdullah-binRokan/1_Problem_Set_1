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
int check_length(long card_number);
string check_card_type(long card_number);
int get_first_two_digits(long card_number);
void luhns_algo_checksum(int card_len, string card_type, long card_number);
// void print_result(string result);

int main(void)
{
    long card_number = get_long("Number: ");
    int card_len = check_length(card_number);
    string card_type = check_card_type(card_number);
    luhns_algo_checksum(card_len, card_type, card_number);
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
int check_length(long card_number)
{
    // min short_len is 13 digits, max short_len is 13 digits
    const long CARD_MIN_SHORT_LEN = 1000000000000;
    const long CARD_MAX_SHORT_LEN = 9999999999999;
    // min long_len is 15 digits, max long_len is 16 digits
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

    // calculate length
    int len = 0;
    while (card_number > 1)
    {
        card_number /= 10;
        len++;
    }
    return len;
}

// define check_card_type(card_number) to check type of credit card
string check_card_type(long card_number)
{
    int first_two_digits = get_first_two_digits(card_number);
    int first_digit = first_two_digits / 10;

    switch (first_two_digits)
    {
        // if starts with 34 or 37 return AMEX 
        case 34:
        case 37:
            return "AMEX";
        // if starts with 51-55 return MASTERCARD
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            return "MASTERCARD";

        default:
            // if starts with 4 return VISA 
            if (first_digit == 4)
            {
                return "VISA";
            }
            // else call print_result("invalid")
            print_result("invalid");
    }
}

// define luhns_algo_checksum to check validity
void luhns_algo_checksum(int card_len, string card_type, long card_number)
{
    int sum = 0;

    // loop through every other digit, starting from second_to_last digit
    long start_from_2nd_to_last_digit = card_number / 10;
    int multiplied_by_two;
    for (int i = 0, len = card_len / 2; i < len; i++)
    {
        // extract the last digit by modulus operator then multiply by 2
        multiplied_by_two = 2 * (start_from_2nd_to_last_digit % 10);
        printf("multiplied by two =  %i\n", multiplied_by_two);
        if (multiplied_by_two >= 10)
        {
            // add products digits not the product itself (12 -> 1 + 2)
            for (int digit = 0; digit < 2; digit++)
            {
                sum += multiplied_by_two % 10;
                multiplied_by_two /= 10;
            }
        } 
        else
        {
            sum += multiplied_by_two;
        }
        // remove the last two digits using division
        start_from_2nd_to_last_digit /= 100;
    }

    // loop through every other digit, starting from last digit
    long start_from_last_digit = card_number;
    for (int j =0, len = card_len / 2; j < len; j++)
    {
        // extract the last digit by modulus operator & add it to sum
        sum += start_from_last_digit % 10;
        // remove the last tow digit using division
        start_from_last_digit /= 100;
    }
    // If the total’s last digit is 0 (total modulo 10 is congruent to 0)
        // call print_result(card_type)
    // call print_result("invalid")
}


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