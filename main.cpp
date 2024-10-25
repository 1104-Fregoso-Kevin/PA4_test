#include "linkedQueue.h"
#include "arrayQueue.h"
#include "priorityQueue.h"
#include "customer.h"
#include "event.h"

#include <iostream>
#include <string>
#include <fstream>

void simulateBank(const std::string& filename) {
    PriorityQueue<Event> eventListPQueue; // Priority queue for events
    ArrayQueue<Customer> bankQueue;            // Regular queue for customers

    bool tellerAvailable = true;
    int currentTime = 0;
    int totalCustomers = 0;
    int cumulativeWaitingTime = 0;

    std::cout << "Simulation Begins\n";

    // Read initial arrival events from the input file
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error: Unable to open file " << filename << "\n";
        return;
    }

    int arrivalTime, transactionTime;
    while (inputFile >> arrivalTime >> transactionTime) {
        // Create a new Customer for each arrival
        Customer* newCustomer = new Customer(arrivalTime, transactionTime);
        Event arrivalEvent(newCustomer, "ARRIVAL", arrivalTime);
        eventListPQueue.enqueue(arrivalEvent);
        totalCustomers++; // Count the total number of customers
    }
    inputFile.close();

    // Event loop
    while (!eventListPQueue.isEmpty()) {
        Event currentEvent = eventListPQueue.peekFront();
        eventListPQueue.dequeue();
        currentTime = currentEvent.getEventTime();

        if (currentEvent.getEventType() == "ARRIVAL") {
            std::cout << "Processing an arrival event at time: " << currentTime << "\n";

            // Process arrival
            if (bankQueue.isEmpty() && tellerAvailable) {
                // Teller is free, customer can start service immediately
                Customer* currentCustomer = currentEvent.getCustomer();
                int departureTime = currentTime + currentCustomer->getTransactionTime();
                Event departureEvent(currentCustomer, "DEPARTURE", departureTime);
                eventListPQueue.enqueue(departureEvent);
                tellerAvailable = false;
            } else {
                // Teller is busy, customer must wait in line
                Customer* currentCustomer = currentEvent.getCustomer();
                bankQueue.enqueue(*currentCustomer); // Copy customer into the queue
            }
        } else if (currentEvent.getEventType() == "DEPARTURE") {
            std::cout << "Processing a departure event at time: " << currentTime << "\n";

            // Process departure
            if (!bankQueue.isEmpty()) {
                // Get the next customer from the line
                Customer nextCustomer = bankQueue.peekFront();
                bankQueue.dequeue();
                int waitingTime = currentTime - nextCustomer.getArrivalTime();
                cumulativeWaitingTime += waitingTime;
                int departureTime = currentTime + nextCustomer.getTransactionTime();
                Customer* nextCustomerPtr = new Customer(nextCustomer); // Create a pointer to the customer
                Event departureEvent(nextCustomerPtr, "DEPARTURE", departureTime);
                eventListPQueue.enqueue(departureEvent);
            } else {
                // Teller is now available
                tellerAvailable = true;
            }
        }
    }

    // Compute average waiting time
    double averageWaitingTime = (totalCustomers > 0) ? static_cast<double>(cumulativeWaitingTime) / totalCustomers : 0.0;
    std::cout << "Simulation Ends\n";
    std::cout << "Final Statistics:\n";
    std::cout << "Total number of people processed: " << totalCustomers << "\n";
    std::cout << "Average amount of time spent waiting: " << averageWaitingTime << "\n";
}

int main() {
    std::string filename = "input.txt"; // Input file containing arrival and transaction times
    simulateBank(filename);
    return 0;
}
