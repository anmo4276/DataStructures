/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
  head = NULL;
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
 void CountryNetwork::insertCountry(Country* previous, string countryName)
 {
     Country* temp = new Country;
     Country* temp2 = new Country;
     Country* temp3 = new Country;
     Country* temp4 = new Country;
     if(previous == NULL)
     {
     if (head == NULL){
       previous = new Country;
       previous -> name = countryName;
       head = previous;
       cout << "adding: " << countryName << " (HEAD)" << endl;
       }
      else{
          temp2 = head;
          head = new Country;
          head -> name = countryName;
          head -> next = temp2;
          cout << "adding: " << countryName << " (HEAD)" << endl;
      }
     }
     else{
       if(previous -> next == NULL){
       temp = previous;
       previous = new Country;
       previous -> name = countryName;
       cout << "adding: " << countryName << " (prev: " << temp->name <<")" << endl;
       temp -> next = previous;
       temp = previous;
     }
     else{
       temp4 = previous -> next;
       temp3 = previous;
       previous = new Country;
       previous -> name = countryName;
       temp3 -> next = previous;
       previous -> next = temp4;
       cout << "adding: " << countryName << " (prev: " << temp3->name <<")" << endl;
     }
   }
 }

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
  Country* previous = new Country;
  string countries[5] = {"United States", "Canada", "Brazil", "India", "China", "Austraila"}
  for(int a=0; a<6; a++){
    insertCountry(previous, countries[a]);
  }

}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
  Country* node = new Country;
  Country* temp = new Country;
  node = head;
  while(node != NULL)
  {
    temp = node -> next;
    if(node -> name == countryName){
      return node;
    }
    else{
      node = temp;
    }
  }
  return NULL;
}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
  Country* node = new Country;
  Country* temp = new Country;
  bool rec= false;
  node = head;
  if(node == NULL){
    cout << "Empty List" <<endl;
  }
  while(!rec)
  {
      if(node != NULL)
      {
        if(node -> name != receiver){
        temp = node -> next;
        node -> message = message;
        node -> numberMessages++;
        cout << node->name << " [# messages received: " << node->numberMessages << "] received: " << node->message << endl;
        node = temp;
        }
        else{
          node -> message = message;
          node -> numberMessages++;
          cout << node->name << " [# messages received: " << node->numberMessages << "] received: " << node->message << endl;
          rec = true;
        }
      }
      else{
        cout << "Country not found" <<endl;
      }
    
  }

}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{

}
