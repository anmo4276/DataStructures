#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <iomanip>
using namespace std;

struct wordItem
{
    string word;
    int count;
};

void getStopWords(const char *ignoreWordFileName, string ignoreWords[])
{
  ifstream myFile;
  myFile.open(ignoreWordFileName);
  int count=0;
  if (myFile.is_open())
  {
  string line1 = "";

      while (getline(myFile, line1))
      {
          ignoreWords[count] = line1;
          count++;
      }
  }
  else
  {
   cout<< "Failed to open "<< ignoreWordFileName << endl;
  }
  myFile.close();
}

bool isStopWord(string word, string ignoreWords[]){
  for(int a=0; a<50;a++){
    if(word == ignoreWords[a]){
      return true;
    }
  }
  return false;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length)
{
    int totalWords=0;
    for(int b=0; b< length; b++){
      totalWords = totalWords + uniqueWords[b].count;
    }
    return totalWords;
}

void arraySort(wordItem uniqueWords[], int length)
{
  wordItem holder;
  for(int a =0;a< length-1; a++){
    for(int b=a+1; b<length;b++){
      if(uniqueWords[a].count<uniqueWords[b].count){
        holder = uniqueWords[a];
        uniqueWords[a]= uniqueWords[b];
        uniqueWords[b]= holder;
      }
    }
  }
}

void printNext10(wordItem wordItemList[], int startRank, int totalWords)
{
    float probabilityOfOccurrence;
    for(int c=startRank; c<startRank+10; c++){
      probabilityOfOccurrence = (float) wordItemList[c].count / totalWords;
      cout << fixed << setprecision(4) << probabilityOfOccurrence << " - " << wordItemList[c].word << endl;
    }
}

void resize(wordItem *&arrayPtr, int &capacity)
{
	// TODO increase the capacity by two times
  int newCapacity = capacity * 2;
//  cout<<"Resizing from "<< capacity<<" to "<<newCapacity<<endl;

	// TODO dynamically allocate an array of size newCapacity
	wordItem *newArray = new wordItem[newCapacity];

	// TODO copy all data from oldArray to newArray
  for(int a = 0; a < capacity; a++)
  {
      newArray[a].word = arrayPtr[a].word;
      newArray[a].count = arrayPtr[a].count;
  }

	// TODO free the memory associated with oldArray
  delete [] arrayPtr;

	arrayPtr = newArray;
	capacity = newCapacity;


}

int main(int argc, char *argv[])
{
  string ignoreWords[50];
  wordItem *newWords;
  newWords = new wordItem[100];
  int capacity=100;
  bool oldWord=false;
  int numDoubled = 0;
  getStopWords(argv[3], ignoreWords);
  int numOfElement = 0;
  ifstream myFile;
  myFile.open(argv[2]);
  string holder = "";
  if (myFile.is_open())
  {
  string line = "";

  while (getline(myFile, line))
      {
        stringstream ss(line);
        if(!line.empty())
        {

          while(getline(ss, holder, ' '))
          {
            if(!isStopWord(holder, ignoreWords))
            {
              for(int a =0; a< numOfElement; a++)
              {
                if(holder == newWords[a].word)
                {
                  newWords[a].count++;
                  oldWord=true;
                  break;
                }

              }
              if(!oldWord){
                newWords[numOfElement].word = holder;
                newWords[numOfElement].count = 1;
                numOfElement++;
              }

            }

            if(numOfElement==capacity)
            {
              resize(newWords,capacity);
              numDoubled++;
            }
            oldWord=false;
          }

        }
      }
  }
arraySort(newWords, numOfElement);

    cout<< "Array doubled: " << numDoubled <<endl;
    cout << "#" <<endl;
    cout << "Unique non-common words: " << numOfElement <<endl;
    cout << "#" <<endl;
    cout << "Total non-common words: "<< getTotalNumberNonStopWords(newWords, numOfElement) << endl;
    cout << "#" <<endl;
    cout << "Probability of next 10 words from rank " << argv[1] <<endl;
    cout << "---------------------------------------" <<endl;
    printNext10(newWords,atoi(argv[1]), getTotalNumberNonStopWords(newWords, numOfElement));

}
