#include<iostream>
#include<string>
#include<vector>
using namespace std ; 

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
      enum class OrderBookType{bid , ask} ; 
 
    //  // Modelling an order book 
    //  double price{5319.450228} ; 
    //  double amount{0.00020075} ;   
    //  string Timestamp{"2020/03/17 17:01:24.884492"} ; 
    //  string Product{"BTC/USDT"} ; 
    // //  string OrderType{"Anything"} ; 
     // OrderBookType orderType = OrderBookType :: bid ;
     
    //  int x {-5} ;  // It is signed 
    //  cout << x << endl ; 

     vector<double> price ; 
     vector<double> amount ; 
     vector<string> Timestamp ; 
     vector<string> Product ; 
     vector<OrderBookType> OrderType ; 


     price.push_back(500.01); 
     amount.push_back(0.00001); 
     Timestamp.push_back("2020/03/17 17:01:24.884492") ; 
     Product.push_back("BTC/USDT") ; 
     OrderType.push_back(OrderBookType :: bid) ; 


     price.push_back(100.02); 
     amount.push_back(0.00003); 
     Timestamp.push_back("2020/03/17 17:01:24.884492") ; 
     Product.push_back("BTC/USDT") ; 
     OrderType.push_back(OrderBookType :: ask) ; 

    //  int n = 10 ; 
    //   for (int i = 0 ; i < n ; ++i)

     for (size_t i = 0; i < price.size(); i++) {
         
         cout << "Row " << i + 1 << ": "  ; 
         cout << "Price: " << price[i] << " | "  ; 
         cout << "Amount: " << amount[i] << " | "  ; 
         cout << "Time: " << Timestamp[i] << " | "  ; 
         cout << "Product: " << Product[i] << " | " ; 
         cout << "Type: " << (OrderType[i] == OrderBookType::bid ? "bid" : "ask") << endl ; 
         
     }





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
      return 0 ; 
}