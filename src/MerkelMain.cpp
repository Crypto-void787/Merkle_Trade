// Implementation file
 
 #include<iostream>
 #include<vector>
 #include "MerkelMain.h"
 #include "OrderBookEntry.h"
 
 using namespace std ; 
  

    MerkelMain::MerkelMain()
     {

     }

     void MerkelMain::init()
     {
        LoadOrderBook() ; 
        int input ; 
      while(true)
      {
           Printmenu();
           input = GetUser();
           ProcessUserOption(input);
      }
     }

     void MerkelMain::LoadOrderBook()
       {
          Orders.push_back(OrderBookEntry{
                     "2020/03/17 17:01:24.884492",
                     "ETH/BTC",
                     OrderBookType :: bid,    
                     3.467434, 
                     0.02187307 }) ;
     
          Orders.push_back(OrderBookEntry{
                     "2020/03/17 17:01:24.884492",
                     "ETH/BTC",
                     OrderBookType :: bid ,     
                     0.02187305,
                     6.85567013 }) ; 
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
        cout << "6- Continue" << endl ;  

        // 7- exitprogram
        cout << "7- Exit" << endl ; 

        cout << "__________________________________" << endl ; 

   
     }
   

    int MerkelMain::GetUser()
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

    void MerkelMain::PrintHelp()
     { 
          cout << "Help-"<< endl ; 
            cout << "     ---->  Your aim is to make money. Analyse the market and make bids and offer." << endl ; 
            cout << "     ----> Further more you need to select an option and then follow the instruction that comes next." << endl ; 

     }
     
    //print market stats function 
    void MerkelMain::Marketstats()
     {
      cout << "OrderBook contains:  " << Orders.size() << " entries." << endl ;
     }

    //Offer making function
    void MerkelMain::OfferMaking()
     {
        cout << " Drop an offer, boss! How much ya flexin' : " << endl ; 
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
     void MerkelMain::PrintContinue()
     { 
         cout << "Fast-forwarding to the next timeframe... hang tight! " << endl ; 
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
        cout << "Invalid choice! Choose between 1-7  " << endl ; 
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
