//The program accepts a ticker value, daily trading frequency
//and returns the N requested max tickers that were traded
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <list>

struct Stock
{
  std::string Ticker;
  int         Volume;

  Stock(std::string ticker, int vol):
  Ticker(ticker), Volume(vol)
  {

  }

  Stock():Ticker(""),Volume(0){}
};

int main()
{
  std::list<Stock>Stocks;
  Stocks.push_back(Stock(std::string("INTC"), 1000));
  Stocks.push_back(Stock(std::string("AAPL"), 100));

  for(Stock iter: Stocks)
    std::cout << iter.Ticker << ":" << iter.Volume << std::endl;
}
