/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <iostream>
// you may include more libraries as needed

// declarations for main helper-functions
void displayMenu();

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;
    int choice=0;
    string country;
    string message;
    string newCountry;
    string prevCountry;
    Country* lastCountry = new Country;
    while (choice != 5){
    displayMenu();
    cin>> choice;
    switch (choice){
      case 1:
      CountryNet.loadDefaultSetup();
      CountryNet.printPath();
      break;
      case 2:
      CountryNet.printPath();
      break;
      case 3:
      cout<< "Enter name of the country to receive the message:" <<endl;
      cin.ignore();
      getline(cin,country);
      cout << "Enter the message to send:" <<endl;
      getline(cin,message);
      cout << endl;
        CountryNet.transmitMsg(country, message);


      break;
      case 4:
      cout << "Enter a new country name:" <<endl;
      cin.ignore();
      getline(cin,newCountry);
      cout << "Enter the previous country name (or First):" <<endl;
      getline(cin,prevCountry);
      if(prevCountry== "First"){
        CountryNet.insertCountry(NULL, newCountry);
      }
      else{
        lastCountry = CountryNet.searchNetwork(prevCountry);
          if(lastCountry!=NULL)
          {
              CountryNet.insertCountry(lastCountry, newCountry);
          }
            else
            {
              while(lastCountry== NULL){
              cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
              getline(cin,prevCountry);
              lastCountry = CountryNet.searchNetwork(prevCountry);
            }
            CountryNet.insertCountry(lastCountry, newCountry);
            }
      }
      CountryNet.printPath();

      break;
      case 5:
      cout << "Quitting..." << endl;
      cout << "Goodbye!" << endl;
      break;
      default:
      break;
    }
  }
    return 0;
}


/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{

    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
