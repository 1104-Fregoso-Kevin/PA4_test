#include "event.h"
Event::Event() : bankCustomer(nullptr), eventType("UNKNOWN"), eventTime(0) {}

Event::Event(Customer* c, std::string e, int t) : bankCustomer(new Customer(*c)), eventType(e), eventTime(t) {}

Event::Event(const Event& rhs) : bankCustomer(rhs.bankCustomer), eventType(rhs.eventType), eventTime(rhs.eventTime) {}

Event& Event::operator=(const Event& rhs) {
    if (this != &rhs) {
        // Delete current bankCustomer to avoid memory leak
        delete bankCustomer;

        // Deep copy the bankCustomer
        bankCustomer = rhs.bankCustomer ? new Customer(*rhs.bankCustomer) : nullptr;

        // Copy the rest of the data members
        eventType = rhs.eventType;
        eventTime = rhs.eventTime;
    }
    return *this;
}

Event::~Event() {
    // If you dynamically allocated memory for bankCustomer, you may want to delete it here.
    //delete bankCustomer; // Uncomment if needed
}

Customer* Event::getCustomer()
{
    return bankCustomer;
}
std::string Event::getEventType()
{
    return eventType;
}
int Event::getEventTime()
{
    return eventTime;
}
bool Event::compareEventTime(const std::string&Type)
{
    return(Type == "ARRIVAL");
}
bool Event::operator<(const Event& other) const {
    return this->eventTime < other.eventTime;
}

bool Event::operator>(const Event& other) const {
    return this->eventTime > other.eventTime;
}