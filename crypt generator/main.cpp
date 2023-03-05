#include <bits/stdc++.h>
#include "allcipherAlgos.h"
#define N 5

using namespace std;

class Header
{
public:
    Header()
    {
    }

    void MENU()
    {
    }
};

class allkeys
{
public:
};

class AllAlgosEncyrption : public allkeys
{
public:
    CaesarCipher ccobj;
    AffineCipher acobj;
    VignereCipher vicobj;
    KreverseCipher krcobj;
    VernamCipher vcobj;

    AllAlgosEncyrption()
    {};

    string GenerateCipher(string msg , string key)
    {
         for(int i = 0;i<key.size();i++)
         {
            int index =key[i] -'0';
            if(ccobj.idx ==index)
            {
                msg = ccobj.Encrypt(msg);
            }
            else if
         }
    }

};

class AllAlgosDecryption : public allkeys
{
public:
};

class RandomisedKeyGenerator
{
public:
    /// all algos
    string key = "01234";
    RandomisedKeyGenerator()
    {
    }

    string Randomiser()
    {
        for(int i =0;i<=N/2;i++)
        {
            int idx1 = rand()%N;
            int idx2  =rand()%N;
            swap(key[idx1] ,key[idx2]);
        }
        string nkey = key;
        return nkey;
    }

    string Randomiser(string k1)
    {

        //preprocess
        string k ="";
        for(int i = 0;i<N;i++)
        {
            if(isalpha(k1[i]))
            {
                k+=((k1[i] -'a')%N + '0');
            }
            else if(isdigit(k1[i])){k+=((k1[i]-'0')%N + '0');}
            else{continue;}
        }

        //randomisation
        for(int i =0;i<=N/2;i++)
        {
            int idx1 = rand()%N;
            int idx2  =rand()%N;
            swap(k[idx1] ,k[idx2]);
        }
        string nkey = k;
        return nkey;
    }

    string EncryptMsg(string smsg)
    {
    }
};

class Decryptor
{
public:
    Decryptor()
    {
    }

    string decryptmsg(string rmsg)
    {
    }
};

main()
{

    string msg;
    getline(cin, msg);

    // text file
}