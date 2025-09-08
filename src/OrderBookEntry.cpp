

#include <string>
#include "OrderBookEntry.h"
using namespace std ;

OrderBookEntry::OrderBookEntry(const string& _Timestamp, 
                               const string& _Product, 
                               OrderBookType _OrderType, 
                               double _Price, 
                               double _Amount)
    : Timestamp(_Timestamp),
      Product(_Product),
      OrderType(_OrderType),
      Price(_Price),
      Amount(_Amount)
{
}


OrderBookType OrderBookEntry::StringToOrderBookType(const std::string& s)
{
    if (s == "bid")
    return OrderBookType::bid;

    if (s == "ask")
    return OrderBookType::ask;

    return OrderBookType::unknown;
}
