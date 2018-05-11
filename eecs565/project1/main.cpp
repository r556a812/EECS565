/**
*	@file : main.cpp
*	@author :  Richard Aviles
*	@date : 2016.08.26
*	Purpose: The main that interacts with the user.
*/

#include "VigenereCipher.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

using namespace std;

//array used to know which letter to use in the key. letters[0] = A ... letters[25] = Z
std::string letters[26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };

/** Takes in a string and a Node double pointer
*** to a dictionary.  Uses the string and the
*** dictionary to see if the decrypted word
*** is an actual word in the dictionary. Returns
*** true if the word is in the dictionary, false
*** otherwise.
**/
bool wordMatch(string s, Node** dict)
{
  int l = s.length();
  bool found = false;
  Node* temp = dict[l];
  string s2 = temp->data;

  //While loop to iterate through the dictionary and see if the word matches any of the words
  while (temp->getNext() != nullptr && !found)
  {
    if (s.compare(s2) == 0)
    {
        found = true;
    }
    else
    {
      temp = temp->getNext();
      s2 = temp->data;
    }
  }

  return found;
}

/** Takes in an int array and the length of the
*** array.  Iterates the key array by one.
**/
void updateKeys(int keys[], int length)
{
  int l = length-1;
  while(l>=0)
  {
    if(keys[l] == 25)
    {
      keys[l] = 0;
      l--;
    }
    else
    {
      keys[l]++;
      return;
    }
  }
}

int main()
{
  clock_t t;
  string ciphertext;
  int keylength;
  int wordlength;
  int totalkeys;
  int i = 0;
  VigenereCipher vc;

  cout << "Loading the dictionary...\n";
  Node** dict = new Node*[16];
  for(; i<16; i++)
  {
    dict[i] = nullptr;
  }

  ifstream file("dict.txt");
  string s = "";
  int length = 0;
  //While loop to add the dictionary words into the array dict
  while (file.good())
  {
    file>>s;
    length = s.length();
    Node* n = new Node(s);

    if(dict[length] == nullptr)
    {
      dict[length] = n;
    }
    else
    {
      Node* temp = dict[length];
      while(temp->getNext() != nullptr)
      {
        temp = temp->getNext();
      }
      temp->setNext(n);
    }
  }

  cout << "Input the ciphertext: ";
  cin >> ciphertext;
  cout << "\nInput the key length: ";
  cin >> keylength;
  cout << "\nInput the length of the first word: ";
  cin >> wordlength;

  t = clock(); //Start the timing

  totalkeys = pow(26, keylength); //Total possible keys

  //Extract the first word, only need to decipher this part first to find a match
  string temp = "";
  for(i=0; i<wordlength; i++)
  {
    temp+=ciphertext[i];
  }

  //Create and initialize the key array responsible for knowing which key is next to be used
  int* keys = new int[keylength];
  for(i=0; i<keylength; i++)
  {
    keys[i]=0;
  }

  string mykey = ""; //String holding current key being used
  s = ""; //String holding the decrypted word made by current key

  bool found = false;
  for(i=0; i<totalkeys; i++) //Iterate through all possible keys
  {
    mykey = ""; //Reset the key to nothing
    //Add the letters for the key
    for(int j=0; j<keylength; j++)
    {
      mykey+=letters[keys[j]];
    }

    vc.setKey(mykey);
    s = vc.decrypt(temp);
    found = wordMatch(s, dict);
    //If a word is found, decrypt the entire message
    if(found)
    {
      s = vc.decrypt(ciphertext);
      cout <<"Key: " << mykey << "\n"
            << "Plaintext: " << s << "\n";
    }

    updateKeys(keys, keylength);
  }

  t = clock() - t; //Stop the timer

  cout << "Total Time: " << ((float)t)/CLOCKS_PER_SEC << " seconds\n";

  delete keys;
  keys = nullptr;

  for(i=0; i<16; i++)
  {
    delete[] dict[i];
  }
  delete [] dict;
  dict = nullptr;
}
