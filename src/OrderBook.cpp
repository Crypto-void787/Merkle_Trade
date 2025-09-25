
#include "OrderBook.h"
#include "CSVReader.h"
#include<map>
#include<algorithm>


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

    void OrderBook::InsertOrder(OrderBookEntry& order)
    {
        Orders.push_back(order) ;
         std::sort(Orders.begin(), Orders.end(), OrderBookEntry::CompareByTimestamp) ; 
    }

    std::vector<OrderBookEntry> OrderBook::MatchAsksToBids(std::string Product, std::string Timestamp)
    {
         /**asks = OrderBook.asks */
        std::vector<OrderBookEntry> asks = GetOrders(OrderBookType::ask,
                                                     Product,
                                                     Timestamp); 
      
         /**bids = OrderBook.bids */
        std::vector<OrderBookEntry> bids = GetOrders(OrderBookType::bid,
                                                     Product,
                                                     Timestamp); 
      
           
         //Sales =  []                                    
         std::vector<OrderBookEntry> sales ; 
          
         // sorting ask lowest first
         std::sort(asks.begin(), asks.end(), OrderBookEntry::CompareByPriceAsc) ; 
         
         //sorting bids highest first 
         std::sort(bids.begin(), bids.end(), OrderBookEntry::CompareByPriceDecs) ; 

        //  for ask in asks
         for(OrderBookEntry& ask : asks)
         { 
            // for bids in bids
            for(OrderBookEntry& bid : bids)
            { 
                if(bid.Price >= ask.Price){  
                                            OrderBookEntry sale{ Timestamp , 
                                            Product, 
                                            OrderBookType::asksale, 
                                            ask.Price, 
                                             0 } ; 


            
            if(bid.username == "simuser")
            {  
                sale.username = "simuser" ;
                sale.OrderType = OrderBookType::bidsale ; 
            }
            if(ask.username == "simuser")
            { 
                sale.username = "simuser" ;  
                sale.OrderType = OrderBookType::asksale  ; 
            }



                   // 1. Bid amount == ask amount 
                   if(bid.Amount == ask.Amount)
                   { 
                      sale.Amount = ask.Amount ; 
                      sales.push_back(sale) ; 
                      bid.Amount = 0 ; 
                      break ; 
                   }

                  // 2. Bid amount > ask amount 
                   if(bid.Amount > ask.Amount)
                   {
                      sale.Amount = ask.Amount ; 
                      sales.push_back(sale) ; 
                      bid.Amount = bid.Amount - ask.Amount ;
                      break ; 
                   }

                  //  3. Bid amount < ask amount 
                   if(bid.Amount < ask.Amount && bid.Amount > 0)
                   {
                     sale.Amount = bid.Amount ;
                     sales.push_back(sale) ; 
                     ask.Amount = ask.Amount - bid.Amount ;
                     bid.Amount = 0 ; 
                     continue ; 
                   }

                }

            }

         }
         
        return sales ; 
    }