void displayMenu();

int main(int argc, char* argv[])
{
  // Object representing our network of cities.
  // (Linked list representation is in CountryNetwork)
  CountryNetwork CountryNet;
  int choice=0;
  string rotate;
  string country;
  string message;
  string newCountry;
  string prevCountry;
  string deleteCountry;
  Country* lastCountry = new Country;
  while (choice != 8){
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
    case 4:
    cout << "Enter a country name:" <<endl;
    cin.ignore();
    getline(cin,deleteCountry);
    CountryNet.deleteCountry(deleteCountry);
    CountryNet.printPath();
    break;
    case 5:
    CountryNet.reverseEntireNetwork();
    CountryNet.printPath();
    break;
    case 6:
    cout << "Enter the count of values to be rotated:" <<endl;
    cin.ignore();
    getline(cin,rotate);
    CountryNet.rotateNetwork(stoi(rotate));
    CountryNet.printPath();
    break;
    case 7:
    cout << "Network before deletion" <<endl;
    CountryNet.printPath();

    CountryNet.deleteEntireNetwork();
    cout << "Network after deletion" <<endl;
    CountryNet.printPath();
    break;
    case 8:
    cout << "Quitting... cleaning up path:" << endl;
    CountryNet.printPath();
    CountryNet.deleteEntireNetwork();

    if(CountryNet.isEmpty()){
      cout << "Path cleaned" <<endl;
    }
    else{
      cout << "Error: Path NOT cleaned" <<endl;
    }
    cout << "Goodbye!" << endl;
    break;
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
    cout << " 3. Add Country " << endl;
    cout << " 4. Delete Country " << endl;
    cout << " 5. Reverse Network" << endl;
    cout << " 6. Rotate Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
