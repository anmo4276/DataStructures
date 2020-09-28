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
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
  if(head == NULL){
    return true;
  }
  return false;
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
  if (previous == NULL){
      cout << "adding: " << countryName << " (HEAD)" << endl;
      temp -> next = head;
      temp -> name = countryName;
      head = temp;
  }
  else{

      cout << "adding: " << countryName << " (prev: " << previous->name <<")" << endl;
      temp2 = previous -> next;
      previous -> next = temp;
      temp -> name = countryName;
      temp -> next = temp2;

  }
}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
 void CountryNetwork::deleteCountry(string countryName)
 {
     Country* temp = new Country;
     Country* previous = new Country;
     bool countryFound= false;
     previous = head;
     temp = previous;
     if(previous ->name == countryName)
     {
       head = head->next;
       delete temp;
       countryFound = true;
     }
     else
     {
         while (previous!= NULL)
         {
             temp = previous -> next;
             if(temp -> name == countryName)
             {
               countryFound= true;
               previous ->next = temp->next;
               delete temp;
               break;
             }
             else
             {
               previous = temp;
             }
             if(!countryFound && temp-> next == NULL){
               cout << "Country does not exist." <<endl;
               break;
             }
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
    Country* temp = new Country;
    string countries[6] = {"United States", "Canada", "Brazil", "India", "China", "Australia"};
    for(int a=0; a<6; a++){
    if(a==0)
    {
       insertCountry(NULL, countries[a]);
       previous -> name = countries[a];
       head = previous;
    }
    else{
      previous -> name = countries[a-1];
      insertCountry(previous, countries[a]);
      temp = previous -> next;
       previous = temp;
      }
    }
  }


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
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
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork() {
    Country* node = new Country;
    Country* temp = new Country;
  if(head != NULL){
    node = head;
    while(node != NULL){
      temp = node -> next;
      cout << "deleting: " << node->name << endl;
      deleteCountry(node -> name);
      node = temp;
    }
    cout << "Deleted network" << endl;

  }
}

/*
 * Purpose: Rotate the linked list i.e. move 'n' elements from
 * the back of the the linked to the front in the same order.
 * @param number elements to be moved from the end of the list to the beginning
 * @return none
 */

 void CountryNetwork :: rotateNetwork(int n)
 {
   int count=1;
   Country* temp = new Country;
   Country* test = new Country;
   Country* previous = new Country;
   Country* temp1= new Country;
   int index =0;
   bool restart = false;
   previous = head;
   test = head;
   temp = head;
   if(head == NULL)
   {
     cout << "Linked List is Empty" <<endl;
   }

   else
   {
     while (temp -> next!= NULL){
       temp = temp-> next;
       index++;

     }
     if (n < 1 || n > index){
       cout << "Rotate not possible" <<endl;
     }
     else{
       while(count != n){
         test = test -> next;
         count++;
       }
       temp-> next = head ;
       temp1= test -> next;
       test -> next = NULL;
       head = temp1;
     cout << "Rotate Complete" <<endl;
   }
   }
}

/*
 * Purpose: reverse the entire network
 * @param ptr head of list
 */
  void CountryNetwork::reverseEntireNetwork() {
   Country* previous = new Country;
   Country* temp = new Country;
   Country* temp1= new Country;
   previous = NULL;
   temp = head;
   temp1 = NULL;
   if(head != NULL)
   {
    while(temp !=NULL){
      temp1 = temp ->next;
      temp -> next = previous;
      previous = temp;
      temp = temp1;
    }
    head = previous;
   }
 }

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
 void CountryNetwork::printPath()
{
    Country* node = new Country;
    node = head;
    cout << "== CURRENT PATH ==" <<endl;
    if(node != NULL){
    while(node != NULL){
      cout<< node -> name << " -> ";
      node = node -> next;
    }
    cout << "NULL" << endl;

  }
  else{
    cout << "nothing in path" <<endl;
  }
  cout << "===" <<endl;
}
