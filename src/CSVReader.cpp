
 
  #include "CSVReader.h" 
  #include<iostream>
  #include<fstream> 


  CSVReader::CSVReader()
  {
     
  }

     std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFilename) 
     {
         std::vector<OrderBookEntry> entries; 

         std::fstream csvFile{csvFilename}; 
         std::string line ; 
         if(csvFile.is_open())
         { 
           
           while(std::getline(csvFile, line))
           {
               try
               {                 
                  OrderBookEntry obe = StringsToOBE(tokenise(line , ',')) ; 
                  entries.push_back(obe) ; 
               }
               catch(const std::exception& e)
               {
                   std::cout << "CSVReader::readCSV bad data " << std::endl ;  
                }
 
           }

         }

         std::cout << "CSVReader::readCSV read " << entries.size() << " entries" << std::endl ;  
         return entries ; 
     }      


     std::vector<std::string> CSVReader::tokenise(std::string csvLine , char separator) 
     { 
 
         std::vector<std::string> tokens ; 
       
         signed int start, end ; 

         std::string token ;

         start = csvLine.find_first_not_of(separator, 0) ; 

         do
         {
            
             end = csvLine.find_first_of(separator, start) ; 

             if(start == csvLine.length() || start == end) break ; 

             if(end >= 0) token = csvLine.substr(start, end - start) ; 

             else token = csvLine.substr(start, csvLine.length() - start) ;
            
             tokens.push_back(token) ; 

             start = end + 1 ; 
             
         } while (end > 0);
         
         return tokens ; 

     }
       
     OrderBookEntry CSVReader::StringsToOBE(std::vector<std::string> tokens) 
      {
           double Price, Amount ; 

         if(tokens.size() != 5)
         { 

           std::cout <<"Bad line " << std::endl ; 
           throw std::exception{} ;

         }  

         try
         {
             Price = std::stod(tokens[3]) ; 
             Amount = std::stod(tokens[4]) ; 
 
         }
         catch(const std::exception& e)
         {
 
          std::cout << "Bad float! " << tokens[3] << std::endl ; 
          std::cout << "Bad float! " << tokens[4] << std::endl ; 
          throw ; 
 
         }
         

         OrderBookEntry obe{
                            tokens[0],                       // timestamp
                            tokens[1],                       // product
                            OrderBookEntry::StringToOrderBookType(tokens[2]), // bid/ask
                            Price,
                            Amount}; 
          
      return obe ; 

      }
      
  