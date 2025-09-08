 
 #include<fstream>
 #include<iostream>
 #include<string> 
 #include<vector>
 using namespace std ; 

 vector<string> tokenise(string CSVLine, char separator)
 { 
      vector<string> tokens ; 

       signed int start, end ; 
       string token ; 

       start = CSVLine.find_first_not_of(separator, 0) ; 

       do
       {
         end = CSVLine.find_first_of(separator, start) ; 

         if(start == CSVLine.length() || start == end) break ; 

         if(end >= 0 ) token = CSVLine.substr(start, end - start) ; 

         else token = CSVLine.substr(start, CSVLine.length() - start) ; 

         tokens.push_back(token) ; 
          
         start = end + 1 ; 

       } while (end > 0 );
       

      return tokens ; 
 }

  enum class OrderBookType{bid,ask};
  class TradeEntry
  {
  public:
    string Timestamp ;
    string Product ;
    OrderBookType orderType ; 
    double Price ; 
    double Amount ; 

    TradeEntry(string _Timestamp,
               string _Product,
               OrderBookType _orderType,
               double _Price,
               double _Amount)

              : Timestamp(_Timestamp),
                Product(_Product),
                orderType(_orderType),
                Price(_Price),
                Amount(_Amount)
            {
               // No need to declare now 
            }

  }; 

 int main()
 {
   
       ifstream CSVfile{"Data.csv"}; 

       string line ; 

       vector<string> tokens ;
        
       // MAking vector entries 
        vector<TradeEntry> entries ;        
       
       if(CSVfile.is_open())
       { 
          cout << "File open " << endl ; 
          
          while(getline(CSVfile , line))
         {
            cout << "Read line : " << line << endl ;       
            tokens = tokenise(line, ',') ; 

            if(tokens.size() != 5) //bad 
            {
               cout << "Bad line" << endl ; 
               continue ; 
            }

           try
           {
            double Price = stod(tokens[3]) ; 
            double Amount = stod(tokens[4]) ; 
            TradeEntry entry(tokens[0], 
                             tokens[1],
                             tokens[2] == "bid" ? OrderBookType::bid : OrderBookType::ask,
                             Price,
                             Amount );

            entries.push_back(entry); 
 
           }

           catch(exception& e)
           {
               cout << "Conversion failed: " << e.what() << endl ; 
               continue;  
           }    
    
          

            for(string& t : tokens)
            {
                cout << t << endl ; 
            }
            
           
          }
          
          CSVfile.close() ; 
          
        }
        else
        {
          cout << "isnt open " << endl ; 
        }

        cout << "Total valid entries: " << entries.size() << endl;

      


     return 0 ; 
 }