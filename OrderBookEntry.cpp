#include"OrderBookEntry.h"

OrderBookEntry::OrderBookEntry( string _Timestamp, 
                           string _Product, 
                           OrderBookType _OrderType, 
                           double _Price, 
                           double _Amount )

                         : Timestamp(_Timestamp),
                            Product(_Product),
                            OrderType(_OrderType),
                            Price(_Price),
                            Amount(_Amount)

                                {

                                }