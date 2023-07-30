#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if the key is valid
bool is_key_valid(string key);

// Function to encrypt the plaintext using the given key
void encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
// Check if the program is executed with exactly one command-line argument
if (argc != 2) // if it's not 2 arguments and not bigger than 2 arguments, then it's one argument as you can't supply 0 or less arguments, so return 1
{
    printf("Usage: %s key\n", argv[0]);
    return 1;
}
//argv[1] contains the user-provided key. argv[0] is the program name itself - when you provide arguments in c, you can add additional arguments to the command line passed as an array of strings
// the user's command line arguments, depending on how many they passed, get passed as - first argument argv[1],  second argument argv[2], third argument argv[3], etc - so think of it as normal counting instead of indexed based starting from 0 way of counting
string key = argv[1];

// Check if the key is valid by calling is_key_valid function implemented below 
if (!is_key_valid(key))
{
    printf("Invalid key. The key must contain 26 unique alphabetic characters.\n");
    return 1;
}

// Prompt the user for plaintext
string plaintext = get_string("plaintext: ");

// Encrypt the plaintext using the key
encrypt(plaintext, key);

return 0;
}
//actual implementation of the is_key_valid function is here:
bool is_key_valid(string key)
{
// key_length variable holds the length of the key passed in by the user as a command line argument 
int key_length = strlen(key);
    
// because strlen uses regular 1 based ways of counting instead of indexed based ways, we can compare the key_length variable directly to see if it has 26 characters or not
if (key_length != 26) 
{
    return false;
}

//declares an array named letters of boolean values, and it initializes all the elements of the array to false
//As the program processes the characters of the key, it will update the corresponding elements in the letters array to true to indicate that the letter has been used
//by setting it to true, we will be able to determine if it's a duplicate in the future
    
bool letters[26] = {false};
    
// looping through user provided key using 0 based indexing 
for (int i = 0; i < key_length; i++)
{
    //isalpha is a built in function in c
    if (!isalpha(key[i]))
    {
        return false;
    }
    // toupper ensures all mappings are case insensitive as 'A' and 'a' will be treated as the same. 
    // characters are represented by their ascii values in c
    int index = toupper(key[i]) - 'A';

    //perform a boolean check in the future on same index to determine if it's been used before
    // bascically says that the letter has been used before as the index corresponding evaluates to true (question says "or not containing each letter exactly once), your program should print an error message" aka if any letters are duplicates or appear more than once".
    if (letters[index])
    {
        return false; // return false because the key is not valid for subsitution cipher
    }
    
    letters[index] = true;
}

return true;
}

void encrypt(string plaintext, string key)
{
printf("ciphertext: ");

for (int i = 0, n = strlen(plaintext); i < n; i++)
{
    char c = plaintext[i];

    if (isalpha(c))
    {
        // Preserve case while encrypting
        char encrypted_char = isupper(c) ? toupper(key[c - 'A']) : tolower(key[c - 'a']);
        printf("%c", encrypted_char);
    }
    else
    {
        // Non-alphabetical characters are printed unchanged
        printf("%c", c);
    }
}

printf("\n");
}
