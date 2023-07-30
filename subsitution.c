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
if (argc != 2)
{
    printf("Usage: %s key\n", argv[0]);
    return 1;
}

string key = argv[1];

// Check if the key is valid
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

bool is_key_valid(string key)
{
int key_length = strlen(key);

if (key_length != 26)
{
    return false;
}

bool letters[26] = {false};

for (int i = 0; i < key_length; i++)
{
    if (!isalpha(key[i]))
    {
        return false;
    }

    int index = toupper(key[i]) - 'A';

    if (letters[index])
    {
        return false;
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
