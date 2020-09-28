#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{
  int holder;
  myArray[numEntries]= newValue;
  numEntries++;
  if(numEntries==0){

  }
  else{
  for(int a =0;a< numEntries-1; a++){
    for(int b=a+1; b<numEntries;b++){
      if(myArray[a]>myArray[b]){
        holder = myArray[a];
        myArray[a]= myArray[b];
        myArray[b]= holder;

      }
    }
  }
}
  return numEntries;
}



int main(int argc, char *argv[])
{
  int array[100];
  int count=0;
  ifstream myFile;
  myFile.open(argv[1]);

  if (myFile.is_open())
  {
  string line = "";

  while (getline(myFile, line))
  {

      insertIntoSortedArray(array,count, stoi(line));
      count++;
      for(int i=0; i < count; i++){
        cout << array[i];
        if((i+1)!=count){
          cout<< ",";
        }
      }
        cout<<endl;
  }

  }
  else
  {
   cout<< "Failed to open the file." << endl;
  }
}
