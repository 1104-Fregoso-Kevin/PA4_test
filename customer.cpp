#include "customer.h"
Customer::Customer() : arrivalTime(0), transactionTime(0) {}

Customer::Customer(int a, int t) : arrivalTime(a), transactionTime(t) {}

Customer::Customer(const Customer& rhs) : arrivalTime(rhs.arrivalTime), transactionTime(rhs.transactionTime) {}

int Customer::getArrivalTime()const
{
    return arrivalTime;
}
int Customer::getTransactionTime()const
{
    return transactionTime;
}

Customer& Customer::operator=(const Customer& rhs) {
    if (this != &rhs) { // Prevent self-assignment
        arrivalTime = rhs.arrivalTime;
        transactionTime = rhs.transactionTime;
    }
    return *this;
}