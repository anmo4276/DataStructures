#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
using namespace std;

struct Park {
  string parkname;
  string state;
  int area;
};

void addPark(Park parks[], string parkname, string state, int area, int length)
{
    parks[length].parkname = parkname;
    parks[length].state = state;
    parks[length].area = area;
}
void printList(const Park parks[], int length)
{
  for(int a=0; a<length; a++)
  {
    cout<< parks[a].parkname << " [" << parks[a].state << "]" << " area: " << parks[a].area << endl;
  }
}

int main(int argc, char *argv[])
{
  ifstream myFile;
  Park parks[100];
  string store;
  string parkname;
  string state;
  int area;
  int count=0;
  int index=0;
  myFile.open(argv[1]);

  if (myFile.is_open())
  {
  string line = "";

      while (getline(myFile, line))
      {
        stringstream ss(line);
        index=0;
        while (getline(ss, store, ','))
        {

              if(index==0){
                parkname = store;
              }
              else if (index ==1){
                state= store;
              }
              else if(index ==2){
                area = stoi(store);
              }
            index++;
        }
        addPark(parks, parkname, state, area, count);
        count++;
      }
    printList(parks, count);

  }
  else
  {
   cout<< "Failed to open the file." << endl;
  }
  int b= atoi(argv[3]);
  ofstream myfile;
  myfile.open (argv[2]);
  for(int j=0;j <count; j++){
    if(parks[j].area > b){
      myfile << parks[j].parkname << "," << parks[j].state << "," <<parks[j].area <<endl;
    }
  }
  myfile.close();
}
