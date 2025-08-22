#include<iostream>
using namespace std ; 

int main()
{ 
    while(true)
    { 
        //  1- Print help 
        cout << "1- Print help" << endl ;
        
        // 2- Print exchange stats
        cout << "2- Print exchange stats" << endl ; 

        // 3- Make an offer 
        cout << "3- Make an offer" << endl ; 

        // 4- Make a bid 
        cout << "4- Make a bid" << endl ; 

        // 5- Print wallet 
        cout << "5- Print wallet" << endl ; 

        //  6- continue 
        cout << "6- Continue" << endl ;  

        // 7- exit
        cout << "7- Exit" << endl ; 

        cout << "__________________________________" << endl ; 

        int UserOption ; 
        
        cout << "Type in 1 to 7 : " ; 
        cin >> UserOption ;  
        cout << "You choose option " << UserOption << " to proceed." << endl ; 

        cout << "__________________________________" << endl ; 


        if(UserOption == 1)
            { 
            cout << "Help- Your aim is to make money. Analyse the market and make bids and offer." << endl ; 
            }

        else if(UserOption == 2)
            {
                cout << "Market looks terrific! " << endl ;
            }
        
        else if(UserOption == 3)
            {
                cout << "Mark an offer - enter the amount : " << endl ; 
            }

        else if(UserOption == 4)
            {
                cout << "Make a bid - enter the amount : " << endl ; 
            }

        else if(UserOption == 5)
            {
                cout << "Your wallet is empty. " << endl ;
            }

        else if(UserOption == 6)
            {
                cout << "Going to next time fram. " ; 
            }
        else if (UserOption == 7)
            {  
               cout << "Exiting program... Bye!" << endl;
               break;  // breaks the loop -> program ends
            }
        else
            {
                cout << "Invalid choice! Choose between 1-6  " << endl ; 
                
            }

    }
     return 0 ; 
}