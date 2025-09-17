// Implementation file
 
 #include<iostream>
 #include<vector>
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

        // 3- Make an offer 
        cout << "3- Make an offer" << endl ; 

        // 4- Make a bid 
        cout << "4- Make a bid" << endl ; 

        // 5- Print wallet 
        cout << "5- Print wallet" << endl ; 

        //  6- continue 
        cout << "6- Go to next timeframe" << endl ;  
      
        // 7- exitprogram
        cout << "7- Exit" << endl ; 
        
        // 8- VWAP stats
        cout << "8- Print VWAP price stats" << endl ;
        
        //Current time 
        cout << "Current time is : " << CurrentTime << endl ; 

        cout << "__________________________________" << endl ; 

   
     } 
   

    int MerkelMain::GetUser()
     {
        cout << "Type in 1 to 8 : " ; 

        int UserOption ; 
        cin >> UserOption ;  
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
               //  std::cout << std::endl ; 

                std::cout << "Avg ask : " << OrderBook::GetMeanPrice(ask) << std::endl ; 
               //  std::cout << std::endl ;

                std::cout << "Ask change (within timeframe) % : " << OrderBook::GetPercentageChange(ask) << std::endl ; 
                std::cout << std::endl ; 



               std::vector<OrderBookEntry> bid = orderBook.GetOrders(OrderBookType::bid,
                                                                          p,
                                                                          CurrentTime   ) ;

                std::cout << "Bid seen : " << bid.size() << std::endl ;
                std::cout << "Max bid : " << OrderBook::GetHighPrice(bid) << std::endl ;
                std::cout << "Min bid : " << OrderBook::GetLowPrice(bid) << std::endl ;
               //  std::cout << std::endl ; 

                std::cout << "Avg bid : " << OrderBook::GetMeanPrice(bid) << std::endl ; 
               //  std::cout << std::endl ;

                std::cout <<  "Bid change (within timeframe) % : " << OrderBook::GetPercentageChange(bid) << std::endl ; 
               //  std::cout << std::endl ;
               
                double spread = OrderBook::GetLowPrice(ask) - OrderBook::GetHighPrice(bid) ;
                std::cout << "Spread   : " << spread << std::endl;
               //  std::cout << std::endl ; 

                std::cout << "<---------------------->" << std::endl ;

                std::cout << std::endl ;
                

         }


       std::cout << "=== END MARKET STATISTICS ===" << std::endl;
    
       
      }

    //Offer making function
    void MerkelMain::OfferMaking()
     {
        cout << " Drop an offer, boss! How much ya flexin' : " << endl ; 
     }

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

    //  Bid placing function 
    void MerkelMain::PlaceBid()
     {
         cout << "Time to place a bid! Make a bid buddy : " << endl ; 
     }

    //Wallet printing function 
    void  MerkelMain::PrintWallet()
     {
          cout << " Wallet lookin' empty... time to stack some coins fam. " << endl ;
     }

     // Continue printing function 
     void MerkelMain::GoToNextTimeframe()
     { 
         cout << "Fast-forwarding to the next timeframe... hang tight! " << endl ; 
         CurrentTime = orderBook.GetNextTime(CurrentTime) ; 
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
