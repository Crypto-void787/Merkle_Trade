  

  #include<string>
  #include<map>
  #include "OrderBookEntry.h"
   
  class Wallet 
  { 
     public: 
        
         Wallet() ; 

         /** Insert currency to the wallet */
         void InsertCurrency(std::string Type, double Amount) ; 
     
         /** Remove currency to the wallet */
         bool RemoveCurrency(std::string Type, double Amount) ; 

         /** Check if wallet contains this much currency */
         bool ContainsCurrency(std::string Type, double Amount) ; 

         /**  Checks if a the wallet canm cope with this ask or bids*/
         bool CanFulfillOrder(OrderBookEntry order) ; 

          /** Assume the order was made by the owner of the wallet */
          void ProcessSale(OrderBookEntry& sale) ; 
         
          /**Generate string representation of whatever in wallet */
          std::string ToString() ; 
          
     private: 
          std::map<std::string, double> Currencies ;  
          
   }; 