
#pragma once
#include<string> 


enum class OrderBookType{bid , ask, unknown } ;
 
   class OrderBookEntry
   {
       public:

       OrderBookEntry(
          const std::string& _Timestamp,
          const std::string& _Product,
          OrderBookType _OrderType,
          double _Price,
          double _Amount  );

   static OrderBookType StringToOrderBookType(const std::string& s) ;  

      std::string Timestamp;
      std::string Product;
      OrderBookType OrderType;
      double Price;
      double Amount;

    
   };