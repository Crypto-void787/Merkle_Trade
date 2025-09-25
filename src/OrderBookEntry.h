
#pragma once
#include<string> 


enum class OrderBookType{bid , ask, unknown, asksale, bidsale } ;
 
   class OrderBookEntry
   {
       public:

       OrderBookEntry(
                        std::string _Timestamp,
                        std::string  _Product,
                        OrderBookType _OrderType,
                        double _Price,
                        double _Amount,
                        std::string _username = "dataset" ) ; 

   static OrderBookType StringToOrderBookType(const std::string& s) ;  
   
   static bool CompareByTimestamp(OrderBookEntry& e1, OrderBookEntry& e2) 
   {
       return e1.Timestamp < e2.Timestamp ; 
   }

   static bool CompareByPriceAsc(OrderBookEntry& e1, OrderBookEntry& e2) 
   {
       return e1.Price < e2.Price ; 
   }

   static bool CompareByPriceDecs(OrderBookEntry& e1, OrderBookEntry& e2) 
   {
       return e1.Price > e2.Price ; 
   }

      std::string Timestamp ;
      std::string Product ;
      OrderBookType OrderType ;
      double Price ;
      double Amount ;
      std::string username ; 

    
   };