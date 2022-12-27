// Dontrez Hobbs
// CSCI 1010 001
// Product Management System
// Create a program that can store up to 100 product's information and gives the ability to display different type of information for those products.
#include <iostream>
using namespace std;

const int MAX = 100;
int pID[MAX];
string pName[MAX];
string pBrand[MAX];
double pCost[MAX];
double pSale[MAX];
int pCount[MAX];
int iter = 0;


void tempData(){
    pID[0] = iter += 1;
    pName[0] =  "Peanut Butter Cups";
    pBrand[0] = "Reese's";
    pCost[0] = .67;
    pSale[0] = 1.00;
    pCount[0] = 8;   

    pID[1] = iter += 1;
    pName[1] = "Chili";
    pBrand[1] = "Ruth's";
    pCost[1] = 2.34;
    pSale[1] = 3.99;
    pCount[1] = 128;

    pID[2] = iter += 1;
    pName[2] = "Chicken Salad";
    pBrand[2] = "Star's";
    pCost[2] = 2.00;
    pSale[2] = 3.29;
    pCount[2] = 100;

    pID[3] = iter += 1;
    pName[3] = "Beer";
    pBrand[3] = "Bud Light";
    pCost[3] = 3.00;
    pSale[3] = 5.00;
    pCount[3] = 1;

    pID[4] = iter += 1;
    pName[4] = "Beef Jerky";
    pBrand[4] = "Jack Link's";
    pCost[4] = 1.93;
    pSale[4] = 5.49;
    pCount[4] = 57;
}

void newPro(){
    for (int i = 0; i <= iter; i++){
        if(pID[i] == 0){
            iter++;
            pID[i] = iter;
            cout << "Enter the product's brand: ";
            cin >> pBrand[i];
            cout << "Enter the product's Name: ";
            cin >> pName[i];
            cout << "Enter the product's cost: ";
            cin >> pCost[i];
            cout << "Enter the product's sales price: ";
            cin >> pSale[i];
            cout << "Enter the product's count: ";
            cin >> pCount[i];  
            cout << endl << endl;
            break;
        }else if(pID[100] != 0){
            cout << "You're overstocked. Remove some products from your inventory to add more.";
            cout << endl << endl;
            break;
        }
    }
    
}

void removeData(){
    int id;

    cout << "Enter the product ID: ";
    cin >> id;
    
    for(int i=0; i<=id; i++){
        if(pID[i] > id){
            cout << "That ID does not exist.";
            cout << endl << endl;
            break; 
        }
        if(pID[i] == id){
            while(pID[i] != 0){
                pID[i] = pID[i + 1];
                pName[i] = pName[i + 1];
                pBrand[i] = pBrand[i + 1];
                pCost[i] = pCost[i + 1];
                pSale[i] = pSale[i + 1];
                pCount[i] = pCount[i + 1];
                i++;
            }
        }
    }
}

void updateCost(){
    int id;
    double cost;

    cout << "Enter the ID: ";
    cin >> id;
    for(int i = 0; i <= id; i++){
        if(pID[i] > id){
            cout << "That ID does not exist.";
            cout << endl << endl;
            break; 
        }
        if(pID[i] == id){
            cout << "Enter the new wholsesale price: ";
            cin >> cost;
            pCost[i] = cost;
            cout << endl << endl;
            break;
        }
    }
}

void updateSales(){
    int id;
    double sales;

    cout << "Enter the ID: ";
    cin >> id;
    
    for(int i = 0; i <= id; i++){
        if(pID[i] > id){
            cout << "That ID does not exist.";
            cout << endl << endl;
            break; 
        }
        if(pID[i] == id){
            cout << "Enter the new sales price: ";
            cin >> sales;
            pCost[i] = sales;
            cout << endl << endl;
            break;
        }
    }
}

void updateCount(){
    int id;
    double count;

    cout << "Enter the ID: ";
    cin >> id;
    for(int i = 0; i <= id; i++){
        if(pID[i] > id){
            cout << "That ID does not exist.";
            cout << endl << endl;
            break; 
        }
        if(pID[i] == id){
            cout << "Enter the new count: ";
            cin >> count;
            pCount[i] = count;
            cout << endl << endl;
            break;
        }
    }
}

void checkStock(){
    for(int i = 0; i < iter; i++){
        if(pCount[i] < 10){
            cout << pBrand[i] << " is low in stock.\n";
            cout << endl;
        }
    }
}

void displayData(){
    for(int i=0; i < pID[i]; i++){
        cout << "ID: " << pID[i] << " || ";
        cout << "Brand: " << pBrand[i] << " || ";
        cout << "Name: " << pName[i] << " || ";
        cout << "Cost: " << pCost[i] << "$" <<" || ";
        cout << "Sale: " <<pSale[i] << "$" << " || "; 
        cout << "Count: " << pCount[i] << endl;
        cout << endl;
    }
}

void sumProfit(){
    double total = 0;

    for(int i = 0; i < iter; i++){
        total += (pSale[i] * pCount[i]);
    }
    cout << "The total profit would be: " << total << "$"<< endl;
    cout << endl;
}

int main(){
    tempData();
    int choice;
    
    while(true){
        cout << "Choose an option from the menu.\n";
        cout << "1. Add a product.\n";
        cout << "2. Remove a product.\n";
        cout << "3. Update the wholesale price of a prodcut.\n";
        cout << "4. Update the sale price of a product.\n";
        cout << "5. Update the count of a prodcut.\n";
        cout << "6. Check for products low in stock.\n";
        cout << "7. Display all products.\n";
        cout << "8. Calculate the total profit for all products.\n";
        cout << "9. Exit.\n";
        cout << "Your Choice: ";
        cin >> choice;
        cout << endl;
        if(choice == 9){
            cout << "Goodbye.";
            break;
        }
        switch(choice){
        case 1:
            newPro();
            break;
        case 2:
            removeData();
            break;
        case 3:
            updateCost();
            break;
        case 4:
            updateSales();
            break;
        case 5:
            updateCount();
            break;
        case 6:
            checkStock();
            break;
        case 7:
            displayData();
            break;
        case 8:
            sumProfit();
            break;
        }
    }
}
