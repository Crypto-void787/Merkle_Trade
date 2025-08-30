// Specification file 

 #pragma once
 #include<vector>
 #include"OrderBookEntry.h"

 using namespace std ; 


class MerkelMain
{
  
       private: 

        vector<OrderBookEntry> Orders;
        void LoadOrderBook(); 
        void PrintHelp();
        void Printmenu();
        void Marketstats();
        void OfferMaking();
        void PlaceBid();
        void PrintWallet();
        void PrintContinue();
        void exitprogram();
        void InvalidChoice();
        int GetUser();
        void ProcessUserOption(int UserOption);
 
       public:
        MerkelMain(); 
        /** Call this to start the sim*/
        void init(); 

 }; 