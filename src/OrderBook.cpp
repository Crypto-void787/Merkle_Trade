
#include "OrderBook.h"
#include "CSVReader.h"
#include<map>


    OrderBook::OrderBook(std::string Filename)
    {
        Orders = CSVReader::readCSV(Filename);
    }

    
    std::vector<std::string> OrderBook::GetKnownProducts()
    {

        std::vector<std::string> Products;
        std::map<std::string, bool> prodMap;

        // iterate through all Orders and store unique product names in map
        for (OrderBookEntry& e : Orders)
        {
             prodMap[e.Product] = true;
        }

        // now pull the unique keys out of the map
        for (auto const& e : prodMap)
        {
             Products.push_back(e.first);  
             // e.first is the key (product string)
        }

        return Products;  

      }

   
    std::vector<OrderBookEntry> OrderBook::GetOrders(
                                                OrderBookType Type,
                                                std::string Product,
                                                std::string Timestamp)
    {
        std::vector<OrderBookEntry> Orders_sub;
        for(OrderBookEntry& e : Orders)
        {
            if(e.OrderType == Type && 
               e.Product == Product &&
               e.Timestamp == Timestamp  )
               {
                  Orders_sub.push_back(e) ; 
               }
        }

        return Orders_sub;
    }

    double OrderBook::GetHighPrice(std::vector<OrderBookEntry>& Orders) 
    {
        double max = Orders[0].Price ; 

        for(OrderBookEntry& e : Orders)
        {
             if(e.Price > max)
             { 
                max = e.Price ; 
             }
        }

        return max ; 

    }

    double OrderBook::GetLowPrice(std::vector<OrderBookEntry>& Orders) 
    {
        double min = Orders[0].Price ; 

        for(OrderBookEntry& e : Orders)
        {
             if(e.Price < min)
             { 
                min = e.Price ; 
             }
        }

        return min ; 

    }

    std::string OrderBook::GetEarliestTime()
    {
        return Orders[0].Timestamp ; 
    }  

    std::string OrderBook::GetNextTime(std::string CurrentTimestamp)
    {
        std::string next_timestamp = "";

        for(OrderBookEntry& e : Orders)
        { 
            if(e.Timestamp > CurrentTimestamp)
            {
                 next_timestamp = e.Timestamp ;
                 break ;  
            }
        } 

        if(next_timestamp == "")
        { 
            next_timestamp = Orders[0].Timestamp ;
        }

        return next_timestamp;
    }

    double OrderBook::GetMeanPrice(std::vector<OrderBookEntry>& Orders )
    {
       if (Orders.size() == 0)
        return 0.0;

     double sum = 0.0;

    for (const OrderBookEntry& e : Orders)
    {
        sum += e.Price;
    }
    return sum / Orders.size();
    
    } 

  double OrderBook::GetPercentageChange(std::vector<OrderBookEntry>& Orders)
    {
         if (Orders.empty()) return 0.0;

         double FirstPrice = Orders.front().Price;
         double LastPrice = Orders.back().Price;

         if (FirstPrice == 0) return 0.0;

         double Change = ((LastPrice - FirstPrice) / FirstPrice) * 100.0;
         return Change ;
    }

   double OrderBook::GetVWAP(std::vector<OrderBookEntry>& Orders)
   {
       if (Orders.empty()) return 0.0;
       
       double pv_sum = 0.0;
       double vol_sum = 0.0;
       
       for (auto& e : Orders)
       {
           pv_sum += e.Price * e.Amount;
          vol_sum += e.Amount;
       }
       
       if (vol_sum == 0.0) return 0.0;
       return pv_sum / vol_sum;
   }


