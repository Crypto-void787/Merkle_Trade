
#include<iostream>
#include<string>
#include<vector>
enum class OrderBookType{bid , ask} ;

using namespace std ; 
   class OrderBookEntry
   {
      public:
      string Timestamp;
      string Product;
      OrderBookType OrderType;
      double Price;
      double Amount;

      OrderBookEntry(
         string Timestamp,
         string Product,
         OrderBookType OrderType,
         double Price,
         double Amount
      )
      : Timestamp(Timestamp),
        Product(Product),
        OrderType(OrderType),
        Price(Price),
        Amount(Amount)
      {
         // No need to assign again, member initializer list does it
      }
   };
    
     double computeAveragePrice(const vector<OrderBookEntry>& entries) {
     
      double sum = 0.0;
      for (const auto& e : entries)
        {
             sum += e.Price;
        }
         return sum / entries.size();
       }

     double computeLowPrice(const vector<OrderBookEntry>& entries) {
        
       double low = entries[0].Price;
       for (const auto& e : entries)
        {
         if (e.Price < low)
            {
                  low = e.Price;
            }
        }
          return low;
       }

     double computeHighPrice(const vector<OrderBookEntry>& entries) 
     {
     
       double high = entries[0].Price;
       for (const auto& e : entries) 
       {
        if (e.Price > high) {
            high = e.Price;
        }
       }
             return high;
      }

     double computePriceSpread(const vector<OrderBookEntry>& entries)
      {
    
       double low = computeLowPrice(entries);
       double high = computeHighPrice(entries);
         return high - low;
      }

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
    
   //  while(true)
   //  {  
    
   //      Printmenu(); // Calling our function  to print the menu 
       
   //      int UserOption = GetUser() ; // function to take user's input 
   //      ProcessUserOption(UserOption); //funtion to proceed with user option 
    
   //      if(UserOption == 7)
   //      { 
   //          break ;  // breaks the loop -> program ends
   //           cout << "\n###################################################" << endl ; 
    
   //      }
          
   //  }          

     vector<OrderBookEntry> Orders ;
     
     Orders.push_back(OrderBookEntry{
            "2020/03/17 17:01:24.884492",
            "ETH/BTC",
             OrderBookType :: bid,    
             3.467434, 
             0.02187307, }) ;
     
     Orders.push_back(OrderBookEntry{
            "2020/03/17 17:01:24.884492",
            "ETH/BTC",
            OrderBookType :: bid ,     
            0.02187305,
            6.85567013  }) ;

      // method 3 to iterate 

     for(unsigned int i = 0 ; i < Orders.size() ; ++i)
      {
            cout << Orders.at(i).Timestamp << "," << 
            Orders.at(i).Product << "," <<
            (Orders.at(i).OrderType == OrderBookType::bid ? "bid" : "ask") <<  "," << 
            Orders.at(i).Price << "," << 
            Orders.at(i).Amount << endl ; 
            
      } 

         // Print stats
         cout << "\nBasic Price Stats:\n";

         cout << "Average Price: " << computeAveragePrice(Orders) << endl ;
         cout << "Lowest Price: " << computeLowPrice(Orders) << endl ;
         cout << "Highest Price: " << computeHighPrice(Orders) << endl ;
         cout << "Price Spread: " << computePriceSpread(Orders) << endl ;

         cout << "\n<----------------BYE--------------->" << endl ;                 

    return 0 ; 
 }