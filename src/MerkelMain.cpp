// Implementation file
 
#include<iostream>
#include<vector>
#include <limits>
 #include "MerkelMain.h"
 #include "OrderBookEntry.h"
 #include "CSVReader.h"
 
 using namespace std ; 
  

    MerkelMain::MerkelMain()
     {

     }

     void MerkelMain::init()
     {
     
        int input ; 
        CurrentTime = orderBook.GetEarliestTime() ;
        Wallet.InsertCurrency("BTC" , 10) ;
        while(true)
         {
            Printmenu();
            input = GetUser();
            ProcessUserOption(input);
         }
     }


    void MerkelMain::Printmenu()
     {
     //  1- Print help 
        cout << "1- Print help" << endl ;
        
        // 2- Print exchange stats
        cout << "2- Print exchange stats" << endl ; 

        // 3- Make an ask
        cout << "3- Make an ask" << endl ;

        // 4- Make a bid 
        cout << "4- Make a bid" << endl ; 

        // 5- Print wallet 
        cout << "5- Print wallet" << endl ; 

        //  6- continue 
        cout << "6- Go to next timeframe" << endl ;  
      
        // 7- VWAP stats
        cout << "7- Print VWAP price stats" << endl ;
        
        // 8- exitprogram
        cout << "8- Exit" << endl ; 
        
        //Current time 
        cout << "Current time is : " << CurrentTime << endl ; 

        cout << "__________________________________" << endl ; 

   
     } 
   

    int MerkelMain::GetUser()
     {
        cout << "Type in 1 to 8 : " ; 

        int UserOption = 0  ; 
        string Line ; 
        getline(cin, Line) ; 
        try
        {
           UserOption = stoi(Line) ;
        }
        catch(const exception& e)
         {
            cout << "(MerkelMain::GetUser) Bad line! " << endl ; 
         }

        cout << "You choose option " << UserOption << " to proceed." << endl ;  

        cout << "\n###################################################" << endl ; 
        cout << endl ;
        
        return UserOption ; 
     }

     //Print help function 

    void MerkelMain::PrintHelp()
     { 
          cout << "Help-"<< endl ; 
            cout << "     ---->  Your aim is to make money. Analyse the market and make bids and offer." << endl ; 
            cout << "     ----> Further more you need to select an option and then follow the instruction that comes next." << endl ; 

     }
     
    //print market stats function 
    void MerkelMain::Marketstats()
     {
       std::cout << "=== MARKET STATISTICS (asks and bids) === " << std::endl;
        
        
        for (std::string const& p : orderBook.GetKnownProducts())
         {
             std::cout << "Product: " << p << std::endl;
             std::cout << std::endl ;

               std::vector<OrderBookEntry> ask = orderBook.GetOrders(OrderBookType::ask,
                                                                          p,
                                                                         CurrentTime    ) ; 
                                    
                std::cout << "Ask seen : " << ask.size() << std::endl ; 
                std::cout << "Max ask : " << OrderBook::GetHighPrice(ask) << std::endl ; 
                std::cout << "Min ask : " << OrderBook::GetLowPrice(ask) << std::endl ;

                std::cout << "Avg ask : " << OrderBook::GetMeanPrice(ask) << std::endl ; 

                         
                std::cout << std::endl ; 



               std::vector<OrderBookEntry> bid = orderBook.GetOrders(OrderBookType::bid,
                                                                          p,
                                                                          CurrentTime   ) ;

                std::cout << "Bid seen : " << bid.size() << std::endl ;
                std::cout << "Max bid : " << OrderBook::GetHighPrice(bid) << std::endl ;
                std::cout << "Min bid : " << OrderBook::GetLowPrice(bid) << std::endl ;

                std::cout << "Avg bid : " << OrderBook::GetMeanPrice(bid) << std::endl ; 

               
                double spread = OrderBook::GetLowPrice(ask) - OrderBook::GetHighPrice(bid) ;
                std::cout << "Spread   : " << spread << std::endl;

                std::cout << "<---------------------->" << std::endl ;

                std::cout << std::endl ;
                

         }


       std::cout << "=== END MARKET STATISTICS ===" << std::endl;
    
       
      }

    //Offer making function
    void MerkelMain::MakeAsk()
     {
       cout << "Drop an ask, boss! How much ya flexin'[Product, Price, Amount (eg: ETH/BTC,200,0.56)]: " ; 
       string input ; 
       
       getline(cin , input) ;

       vector<string> Tokens = CSVReader::tokenise(input , ',') ;
       
       if(Tokens.size() != 3)
       { 
          cout << "Bad input! " << input << endl ; 
       }
       else 
       { 
          try 
          {
            OrderBookEntry obe = CSVReader::StringsToOBE(
                                                           CurrentTime , 
                                                           Tokens[0],
                                                           OrderBookType::ask ,
                                                           Tokens[2] , 
                                                           Tokens[1] ) ;       
            
            obe.username = "simuser" ; 
            
            if(Wallet.CanFulfillOrder(obe))
            { 
               cout << "Wallet Looks good. " << endl ; 
               orderBook.InsertOrder(obe) ;         
            } 
            else 
             {
               cout << "Wallet has insufficient funds. " << endl ; 
             }   

         }
         catch(const exception& e)
         { 
             cout << "(MerkelMain::MakeAsk) Bad input! " << endl ; 
         }

       }

       cout << "You typed : " << input << endl ; 

     }

     
    //Bid making function
    void MerkelMain::PlaceBid()
     {
       cout << "Drop a bid, boss! Whatchu offerin' [Product, Price, Amount (eg: ETH/BTC,200,0.56)]: " ; 
       string input ; 
       
       getline(cin , input) ;

       vector<string> Tokens = CSVReader::tokenise(input , ',') ;
       
       if(Tokens.size() != 3)
       { 
          cout << "Bad input! " << input << endl ; 
       }
       else 
       { 
          try 
          {
            OrderBookEntry obe = CSVReader::StringsToOBE(
                                                           CurrentTime , 
                                                           Tokens[0],
                                                           OrderBookType::bid ,
                                                           Tokens[2] , 
                                                           Tokens[1] ) ;       

            obe.username = "simuser" ; 

             if(Wallet.CanFulfillOrder(obe))
             { 
               cout << "Wallet Looks good. " << endl ; 
               orderBook.InsertOrder(obe) ;         
             } 
             else 
             {
               cout << "Wallet has insufficient funds. " << endl ; 
             }   

         }
         catch(const exception& e)
         { 
             cout << "(MerkelMain::PlaceBid) Bad input! " << endl ; 
         }

       }

       cout << "You typed : " << input << endl ; 

     }

     
    //Wallet printing function 
    void  MerkelMain::PrintWallet()
     {
          cout << Wallet.ToString() << endl ; 
     }

     // Continue printing function 
     void MerkelMain::GoToNextTimeframe()
     { 
         cout << "Fast-forwarding to the next timeframe... hang tight! " << endl ;
         std::vector<OrderBookEntry> sales = orderBook.MatchAsksToBids("ETH/BTC" , CurrentTime) ;   
         std::cout << "Sales : " << sales.size() << std::endl ; 

         for(OrderBookEntry& sale: sales)
         { 
             std::cout << "Sale Price: " << sale.Price << ", Amount : " << sale.Amount << std::endl ; 

             if(sale.username =="simuser")
             { 
                Wallet.ProcessSale(sale) ;  

             }

         }

         CurrentTime = orderBook.GetNextTime(CurrentTime) ; 

     }

   // VWAP stats printing function
   void MerkelMain::PrintVWAPStats()
   {
      std::cout << "=== VWAP PRICE STATS === " << std::endl;
      for (std::string const& p : orderBook.GetKnownProducts())
      {
         auto asks = orderBook.GetOrders(OrderBookType::ask,
                                          p,
                                          CurrentTime);
         auto bids = orderBook.GetOrders(OrderBookType::bid,
                                          p,
                                          CurrentTime);
         
         std::cout << "Product: " << p << std::endl;
         std::cout << "VWAP ask: " << OrderBook::GetVWAP(asks) << std::endl;
         std::cout << "VWAP bid: " << OrderBook::GetVWAP(bids) << std::endl;
         std::cout << "<---------------------->" << std::endl ;
      }
      std::cout << "=== END VWAP PRICE STATS === " << std::endl;
   }


     // Exit function 

     void MerkelMain::exitprogram()
     { 
            cout << "Exiting program... Bye!" << endl;
            exit(0); 
     }

     // Invalid choice print function 
     void MerkelMain::InvalidChoice()
     { 
        cout << "Invalid choice! Choose between 1-8  " << endl ; 
     }
     // Process user option 
    
     void MerkelMain::ProcessUserOption(int UserOption)
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
               MakeAsk() ; 
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
               GoToNextTimeframe(); 
            }
        else if(UserOption == 7)
           {
              PrintVWAPStats();
           }
         else if (UserOption == 8)
            {  
             exitprogram() ;
             
            }
         else
            {
                InvalidChoice() ;
                
            }
               
            cout << "\n###################################################" << endl ; 
    
            
        } 
