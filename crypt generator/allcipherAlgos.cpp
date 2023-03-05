#include<bits/stdc++.h>
using namespace std;

class CaesarCipher
{

public:
int idx;
    string Encrypt(string s, int key)
    {
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            if ('A' <= s[i] <= 'Z')
                res += (s[i] - 'A' + key) % 26 + 'A';
            else if ('a' <= s[i] <= 'z')
                res += (s[i] - 'a' + key) % 26 + 'a';
            else
            {
                res += s[i];
            }
        }

        return res;
    }

    string Decrypt(string c, int key)
    {
        string res = "";
        for (int i = 0; i < c.size(); i++)
        {
            if ('A' <= c[i] <= 'Z')
                res += (c[i] - 'A' - key + 26) % 26 + 'A';
            if ('a' <= c[i] <= 'z')
                res += (c[i] - 'a' - key) % 26 + 'a';
            else
            {
                res += c[i];
            }
        }
        return res;
    }
};

class AffineCipher
{
public:
int idx;
    string Encrypt(string msg, int a, int b) // ax + b
    {
        string cipher = "";
        for (int i = 0; i < msg.length(); i++)
        {

            if ('A' <= msg[i] <= 'Z')
            {
                cipher = cipher + (char)((((a * (msg[i] - 'A')) + b) % 26) + 'A');
            }
            else if ('a' <= msg[i] <= 'z')
            {
                cipher = cipher + (char)((((a * (msg[i] - 'a')) + b) % 26) + 'a');
            }
            else
            {
                cipher += msg[i];
            }
        }
        return cipher;
    }

    string Decrypt(string cipher, int a, int b)
    {
        string msg = "";
        int a_inv = 0;
        int flag = 0;

        // Find a^-1 (the multiplicative inverse of a
        // in the group of integers modulo m.)
        for (int i = 0; i < 26; i++)
        {
            flag = (a * i) % 26;

            // Check if (a*i)%26 == 1,
            // then i will be the multiplicative inverse of a
            if (flag == 1)
            {
                a_inv = i;
            }
        }
       
        for (int i = 0; i < cipher.length(); i++)
        {
            if ('A' <= cipher[i] <= 'Z')
            {
                msg = msg + (char)((((a_inv * (cipher[i] + 'A')) - b) % 26) + 'A');
            }
            else if ('a' <= cipher[i] <= 'z')
            {
                msg = msg + (char)((((a_inv * (cipher[i] + 'a')) - b) % 26) + 'a');
            }
            else
            {
                msg += cipher[i];
            }
        }

        return msg;
    }
};

class VignereCipher  ///handle uer lower case problem
{

public:
int idx;
    string Encrypt(string str, string key)
    {
        string cipher_text;

        for (int i = 0; i < str.size(); i++)
        {
            // converting in range 0-25
            char x = (str[i] + key[i]) % 26;

            // convert into alphabets(ASCII)
            x += 'A';

            cipher_text.push_back(x);
        }
        return cipher_text;
    }

    // This function decrypts the encrypted text
    // and returns the original text
    string Decrypt(string cipher_text, string key)
    {
        string orig_text;

        for (int i = 0; i < cipher_text.size(); i++)
        {
            // converting in range 0-25
            char x = (cipher_text[i] - key[i] + 26) % 26;

            // convert into alphabets(ASCII)
            x += 'A';
            orig_text.push_back(x);
        }
        return orig_text;
    }

};

class KreverseCipher
{
   public:
   int idx;
   string Encrypt(string msg ,int k)
   {
       reverse(msg.begin() ,msg.begin() + k +1);
       return msg;
   }

   string Decrypt(string msg,int k)
   {
       reverse(msg.begin() ,msg.begin() + k+1);
       return msg;
   }
   
};

class VernamCipher
{ //key len same as msg len
    public:
    int idx;
    string Encrypt(string text, string key)
{
 
    // Initializing cipherText
    string cipherText = "";
 
    // Initialize cipher array of key length
    // which stores the sum of corresponding no.'s
    // of plainText and key.
    int cipher[key.length()];
 
    for (int i = 0; i < key.length(); i++) {
        cipher[i] = text.at(i) - 'A' + key.at(i) - 'A';
    }
 
    // If the sum is greater than 25
    // subtract 26 from it
    // and store that resulting value
    for (int i = 0; i < key.length(); i++) {
        if (cipher[i] > 25) {
            cipher[i] = cipher[i] - 26;
        }
    }
 
    // Converting the no.'s into integers
 
    // Convert these integers to corresponding
    // characters and add them up to cipherText
    for (int i = 0; i < key.length(); i++) {
        int x = cipher[i] + 'A';
        cipherText += (char)x;
    }
 
    // Returning the cipherText
    return cipherText;
}
 
// Method 2
// Returning plain text
static string Decrypt(string s, string key)
{
    // Initializing plain text
    string plainText = "";
 
    // Initializing integer array of key length
    // which stores difference
    // of corresponding no.'s of
    // each character of cipherText and key
    int plain[key.length()];
 
    // Running for loop for each character
    // subtracting and storing in the array
    for (int i = 0; i < key.length(); i++) {
        plain[i] = s.at(i) - 'A' - (key.at(i) - 'A');
    }
 
    // If the difference is less than 0
    // add 26 and store it in the array.
    for (int i = 0; i < key.length(); i++) {
        if (plain[i] < 0) {
            plain[i] = plain[i] + 26;
        }
    }
 
    // Converting int to corresponding char
    // add them up to plainText
    for (int i = 0; i < key.length(); i++) {
        int x = plain[i] + 'A';
        plainText += (char)x;
    }
 
    // Returning plainText
    return plainText;
}
};