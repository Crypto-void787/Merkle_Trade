// Specification file 

 #pragma once
 #include<vector>
 #include "OrderBookEntry.h"
 #include "OrderBook.h"
 #include "Wallet.h"

 using namespace std ; 


class MerkelMain
{
  
       private: 
 
        OrderBook orderBook{"src/Data.csv"} ;
        std::string CurrentTime ; 
        

        void PrintHelp();
        void Printmenu();
        void Marketstats();
        void PrintVWAPStats();
        void MakeAsk();
        void PlaceBid();
        void PrintWallet();
        void GoToNextTimeframe();
        void exitprogram();
        void InvalidChoice();
        int GetUser();
        void ProcessUserOption(int UserOption);
        
        Wallet Wallet ; 

 
       public:
        MerkelMain(); 
        /** Call this to start the sim*/
        void init(); 

 }; 