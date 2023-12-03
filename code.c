#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void push(Stack* stack, int data);
int pop(Stack* stack);
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);

int displayMenu() {
    int choice;
    printf("\n*Tourism Management System*\n");
    printf("\n1. Sign Up\n");
    printf("2. Log In\n");
    printf("3. Book/Buy Travel Tickets\n");
    printf("4. Book Accommodation\n");
    printf("5. Cancel Booking\n");
    printf("6. View Itinerary Plan\n");
    printf("7. Payment and Invoice\n");
    printf("8. Ask for Help and Support\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to dynamically allocate memory for a string
char* getInputString() {
    char buffer[100]; 
    scanf("%99s", buffer); 
    return strdup(buffer); 
}

int main() {
    Stack paymentStack;  
    paymentStack.top = NULL;

    Queue bookingQueue;  
    bookingQueue.front = bookingQueue.rear = NULL;

    // Main loop
    while (1) {
        int choice = displayMenu();

        switch (choice) {
            case 1:
                // Sign Up
                printf("Enter your username: ");
                char* username = getInputString();
                printf("User '%s' signed up successfully.\n", username);
                free(username);
                break;

            case 2:
                // Log In
                printf("Enter your username: ");
                char* loginUsername = getInputString();
                printf("User '%s' logged in successfully.\n", loginUsername);
                free(loginUsername);
                break;

            case 3:
                // Book/Buy Travel Tickets
                printf("Enter the number of tickets to book: ");
                int numTickets;
                scanf("%d", &numTickets);
                enqueue(&bookingQueue, numTickets);
                printf("%d tickets added to the booking queue.\n", numTickets);
                break;

            case 4:
                // Book Accommodation
                printf("Enter details for accommodation booking:\n");
                printf("Enter location: ");
                char* location = getInputString();
                printf("Enter check-in date: ");
                char* checkInDate = getInputString();
                printf("Accommodation booked at %s for %s.\n", location, checkInDate);
                free(location);
                free(checkInDate);
                break;

            case 5:
                // Cancel Booking
                if (bookingQueue.front != NULL) {
                    int canceledTickets = dequeue(&bookingQueue);
                    printf("%d tickets canceled from the booking queue.\n", canceledTickets);
                } else {
                    printf("Booking queue is empty.\n");
                }
                break;

            case 6:
                // View Itinerary Plan
                printf("Enter the user's username: ");
                char* viewItineraryUsername = getInputString();
                printf("Itinerary plan for user '%s' is not implemented yet.\n", viewItineraryUsername);
                free(viewItineraryUsername);
                break;

            case 7:
                // Payment and Invoice
                printf("Enter the amount to pay: ");
                int amount;
                scanf("%d", &amount);
                push(&paymentStack, amount);
                printf("%d added to the payment stack.\n", amount);
                break;

            case 8:
                // Ask for Help and Support
                printf("Enter your support request: ");
                char* supportRequest = getInputString();
                printf("Support request '%s' received. Our team will assist you.\n", supportRequest);
                free(supportRequest);
                break;

            case 9:
                // Exit
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return -1;  
    }

    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1;  
    }

    Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}