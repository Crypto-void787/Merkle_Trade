

#pragma once
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"

class OrderBook
{
    public:

        /** Construct, reading a CSV data file */
        OrderBook(std::string Filename);

        /** return vector of all known products in the dataset */
        std::vector<std::string> GetKnownProducts();

        /** return vector of orders according to the sent filters */
        std::vector<OrderBookEntry> GetOrders(
                                        OrderBookType Type,
                                        std::string Product,
                                        std::string Timestamp  );
      
         /**Returns the earliest time in the order book */
         std::string GetEarliestTime();         
         /**Returns next time after the sim time in the order book */
         std::string GetNextTime(std::string CurrentTimestamp) ;                       

         static double GetHighPrice(std::vector<OrderBookEntry>& Orders) ;

         static double GetLowPrice(std::vector<OrderBookEntry>& Orders) ;

         /**Returns the avg of asks n bids of every unique timeframes */
         static double GetMeanPrice(std::vector<OrderBookEntry>& Orders ) ; 

         /**Return Change in stats during 24 hrs  */
         static double GetPercentageChange(std::vector<OrderBookEntry>& Orders);

         /**Volume-weighted average price */
          static double GetVWAP(std::vector<OrderBookEntry>& Orders);

         
    private:
        std::vector<OrderBookEntry> Orders;

};
