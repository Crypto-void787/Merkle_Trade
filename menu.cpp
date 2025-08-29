
#include<iostream>
#include<string>
#include<vector>
enum class OrderBookType{bid , ask} ;

using namespace std ; 
    class OrderBookEntry
     { 
      public: 
      double Price ; 
      double Amount ; 
      string Timestamp ; 
      string Product ; 
      OrderBookType OrderType ; 

     OrderBookEntry
      (
      double Price,
      double Amount,
      string Timestamp,
      string Product,
      OrderBookType OrderType
      )
       : Price(Price),
       Amount(Amount),
       Timestamp(Timestamp),
       Product(Product), 
       OrderType(OrderType)
       {  
            // No need to assign again, member initializer list does it
        }
       
    }; 


     // We are making function to make our code modular 
     //Print menu function  
    void Printmenu()
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

        // 7- exitprogram
        cout << "7- Exit" << endl ; 

        cout << "__________________________________" << endl ; 

   
     }
   

    int GetUser()
     {
        cout << "Type in 1 to 7 : " ; 

        int UserOption ; 
        cin >> UserOption ;  
        cout << "You choose option " << UserOption << " to proceed." << endl ;  

        cout << "\n###################################################" << endl ; 
        cout << endl ;
        
        return UserOption ; 
     }

     //Print help function 

    void PrintHelp()
     { 
          cout << "Help-"<< endl ; 
            cout << "     ---->  Your aim is to make money. Analyse the market and make bids and offer." << endl ; 
            cout << "     ----> Further more you need to select an option and then follow the instruction that comes next." << endl ; 

     }
     
    //print market stats function 
    void Marketstats()
     {
        cout << " Market's poppin' off! Prices look wild  " << endl ;
     }

    //Offer making function
    void OfferMaking()
     {
        cout << " Drop an offer, boss! How much ya flexin' : " << endl ; 
     }

    //  Bid placing function 
    void PlaceBid()
     {
         cout << "Time to place a bid! Make a bid buddy : " << endl ; 
     }

    //Wallet printing function 
    void  PrintWallet()
     {
          cout << " Wallet lookin' empty... time to stack some coins fam. " << endl ;
     }

     // Continue printing function 
     void PrintContinue()
     { 
         cout << "Fast-forwarding to the next timeframe... hang tight! " << endl ; 
     }

     // Exit function 

     void exitprogram()
     { 
            cout << "Exiting program... Bye!" << endl;
     }

     // Invalid choice print function 
     void InvalidChoice()
     { 
        cout << "Invalid choice! Choose between 1-7  " << endl ; 
     }
     // Process user option 
    
     void ProcessUserOption(int UserOption)
     { 
         
         if(UserOption == 1)
            { 
                 PrintHelp() ;
            }

         else if(UserOption == 2)
            {
               Marketstats() ;
            }
        
         else if(UserOption == 3)
            {
               OfferMaking() ; 
            }

         else if(UserOption == 4)
            {
              PlaceBid() ; 
            }

         else if(UserOption == 5)
            {
               PrintWallet(); 
            }

         else if(UserOption == 6)
            {
               PrintContinue(); 
            }
         else if (UserOption == 7)
            {  
             exitprogram() ;
             
            }
         else
            {
                InvalidChoice() ;
                
            }
               
            cout << "\n###################################################" << endl ; 
    
            
        } 
        


        
 int main()
 {
    
    // while(true)
    // {  
    
    //     Printmenu(); // Calling our function  to print the menu 
       
    //     int UserOption = GetUser() ; // function to take user's input 
    //     ProcessUserOption(UserOption); //funtion to proceed with user option 
    
    //     if(UserOption == 7)
    //     { 
    //         break ;  // breaks the loop -> program ends
    //          cout << "\n###################################################" << endl ; 
    
    //     }
          
    // }          
    

     vector<double> price ; 
     vector<double> Amount ; 
     vector<string> Timestamp ; 
     vector<string> Product ; 
     vector<OrderBookType> OrderType ; 

   

     vector<OrderBookEntry> Orders ;
     
     Orders.push_back(OrderBookEntry{
             0.003,
             20.00 ,
             "Fri 29 Aug, 1:40 PM",
             "BTC/USDT",
             OrderBookType :: bid    }) ; 


     for(OrderBookEntry Orders : Orders)
     {     
         cout << "Order price : " << Orders.Price << endl ;  
         cout << "Order price : " << Orders.Amount<< endl ;  
         cout << "Order price : " << Orders.Timestamp << endl ;  
         cout << "Order  price : " << Orders.Product << endl ;    
     }
                    
                 

    return 0 ; 
 }