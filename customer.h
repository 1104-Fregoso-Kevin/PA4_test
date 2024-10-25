#ifndef CUSTOMER_H
#define CUSTOMER_H
class Customer
{
    private:
    int arrivalTime;
    int transactionTime;


    public:
    Customer();
    Customer(int,int);
    Customer(const Customer& rhs);
    
    int getArrivalTime()const;
    int getTransactionTime()const;
    // int calculateDepartureTime(); 
    // this should not be handled by the customer class (needs the queue class to order events in order to calcualte)

    Customer& operator=(const Customer& rhs);

};
//#include "customer.cpp"
#endif