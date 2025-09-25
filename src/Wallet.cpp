
 #include "Wallet.h"
 #include<iostream> 
 #include"CSVReader.h"

 Wallet::Wallet()
 {
     
 }

  /** Insert currency to the wallet */
  void Wallet::InsertCurrency(std::string Type, double Amount) 
  {
    double Balance ; 

    if(Amount < 0) 
      { 
        throw std::exception{} ; 
      }

      if(Currencies.count(Type) == 0)   //Not there yet 
      { 
          Balance = 0 ; 
      }
      else  // is there 
      { 
        Balance = Currencies[Type] ; 
      }

      Balance += Amount ;
      Currencies[Type] = Balance ; 

  } 

  /** Remove currency fromm the wallet  */
  bool Wallet::RemoveCurrency(std::string Type, double Amount) 
  {
    if (Amount < 0) {
      try 
      {
          throw std::invalid_argument("Amount cannot be negative");
      }
      catch (const std::invalid_argument& e) 
      {
          std::cout << "yoo error!(" << Amount << ") : " << e.what() << std::endl;
          return false;
      }

      
  }

    if (Currencies.count(Type) == 0) 
    {
        std::cout << "No currency " << Type << " in wallet." << std::endl;
        return true; 
    }

    if (ContainsCurrency(Type, Amount))
     {
        std::cout << "Removing " << Amount << " of " << Type << " from wallet." << std::endl;
        Currencies[Type] -= Amount;
        return true;
     }

      std::cout << "Not enough " << Type << " to remove " << Amount << std::endl;
      return true;   // requirement: return true, do not change wallet
}


  /** Check if wallet contains this much currency */
  bool Wallet::ContainsCurrency(std::string Type, double Amount) 
  {
     if(Currencies.count(Type) == 0) 
     
      return 0 ; 
     

     else 
     
       return Currencies[Type] >= Amount ; 
     

  }


  std::string Wallet::ToString()
  {
     std::string S ; 

     for(std::pair<std::string,double> Pair : Currencies)
     {
        std::string Currency = Pair.first ; 
        double Amount = Pair.second ; 
        S += Currency + " : " + std::to_string(Amount) + "\n" ;
     }
    return S ;
  }

  bool Wallet::CanFulfillOrder(OrderBookEntry order) 
  { 
     std::vector<std::string> currs = CSVReader::tokenise(order.Product, '/') ; 
   
     //ask 
     if(order.OrderType == OrderBookType::ask)
     { 
       double Amount = order.Amount  ;
       std::string Currency =  currs[0] ;
       std::cout << "Wallet::CanFulfillOrder " << Currency << " : " << Amount << std::endl ; 
       return ContainsCurrency(Currency, Amount) ; 
        
     }

     // Bid 
     if(order.OrderType == OrderBookType::bid)
     { 
        double Amount = order.Amount * order.Price ; 
        std::string Currency = currs[1] ; 
        std::cout << "Wallet::CanFulfillOrder " << Currency << " : " << Amount << std::endl ; 
        return ContainsCurrency(Currency, Amount) ; 
     }

     return false ; 
  } 

  void Wallet::ProcessSale(OrderBookEntry& sale) 
   {
    
    std::vector<std::string> currs = CSVReader::tokenise(sale.Product, '/') ; 
   
     //ask 
     if(sale.OrderType == OrderBookType::asksale)
     { 
        double OutGoingAmount = sale.Amount  ;
        std::string OutGoingCurrency =  currs[0] ;

        double IncomingAmount = sale.Amount * sale.Price ; 
        std::string IncomingCurrency = currs[1] ; 

        Currencies[IncomingCurrency] += IncomingAmount ; 
        Currencies[OutGoingCurrency] -= OutGoingAmount ;  
        
     }

     // Bid 
     if(sale.OrderType == OrderBookType::bidsale)
     { 
        double IncomingAmount = sale.Amount  ;
        std::string IncomingCurrency =  currs[0] ;

        double OutgoingAmount = sale.Amount * sale.Price ; 
        std::string OutgoingCurrency = currs[1] ; 

        Currencies[IncomingCurrency] += IncomingAmount ; 
        Currencies[OutgoingCurrency] -= OutgoingAmount ;  
    
      }
   
    }