#ifndef EVENT_H
#define EVENT_H
#include <iostream>  
#include <string>
#include "customer.h"
using namespace std;
class Event
{
    private:
    Customer* bankCustomer;
    std::string eventType;
    int eventTime;

    public:
    Event();
    Event(Customer*, std::string, int);
    Event(const Event&);
    ~Event();
    Customer* getCustomer();
    string getEventType();
    int getEventTime();
    bool compareEventTime(const std::string&);
    Event& operator=(const Event& rhs);
    bool operator<(const Event& other) const;
    bool operator>(const Event& other) const;
    
    

};
//#include "event.cpp"
#endif