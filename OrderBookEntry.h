
#include<string>
using namespace std ; 

enum class OrderBookType{bid , ask} ;

   class OrderBookEntry
   {
       public:

       OrderBookEntry(
          string _Timestamp,
          string _Product,
          OrderBookType _OrderType,
          double _Price,
          double _Amount  );

      string Timestamp;
      string Product;
      OrderBookType OrderType;
      double Price;
      double Amount;

    
   };