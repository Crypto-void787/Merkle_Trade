


 #pragma once 
 #include "OrderBookEntry.h"
 #include<vector>
 #include<string>


  class CSVReader
  {
      
      public:
      
      CSVReader() ; 
      
      static std::vector<OrderBookEntry> readCSV(std::string csvFile) ; 
      static std::vector<std::string> tokenise(std::string csvLine , char separator) ; 
     
      static OrderBookEntry StringsToOBE( std::string Timestamp,
                                          std::string Product, 
                                          OrderBookType orderType,
                                          std::string Amount, 
                                          std::string Price ) ; 
      
      private:
        
        static OrderBookEntry StringsToOBE(std::vector<std::string> strings) ; 

    } ; 