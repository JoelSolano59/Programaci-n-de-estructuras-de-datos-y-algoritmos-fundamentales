#ifndef _IPREQUEST_H_
#define _IPREQUEST_H_

#include <iostream>
#include <string>

class IPFrequent {
  public:
    IPFrequent();
    IPFrequent(std::string, int);
    std::string getAll();
    int getIP();
  private:
    std::string ip;
    int frequent;
};

IPFrequent::IPFrequent(){
    ip = "";
    frequent = 0;
}

IPFrequent::IPFrequent(std::string i, int f){
    ip = i;
    frequent = f;
}

std::string IPFrequent::getAll(){
    return ip + " : " + std::to_string(frequent);
}

int IPFrequent::getIP(){
    return frequent;
}

#endif