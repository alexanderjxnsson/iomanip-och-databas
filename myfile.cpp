#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
/* declarations start */
std::string seperator = "*==========================================================================================*\n";
std::string ID = "| ID", name = " Name", city = " City", state = " State", lastVisit = " Last visit", totalSales = " Total sales";
std::string nameToFile, stateToFile, cityToFile, dateToFile;
double salesToFile;
int choice, cusIDtracker = 0;
bool isRunning = true;
enum showOptions {ADD = 1,UPDATECUS, SHOWCUSTOMER, DELETECUSTOMER, SHOWTOTALSALES, EXITPROGRAM};
void columnBanner();
void displayCustomers();
struct tTable{
    double get_total_sales();   //Redovisar värdet av sammanlagd försäljning
    int get_max_id();           //Redovisar antalet kunder genom att hämta högsta angedda siffer-ID
    int write_date();           //Anger Dagens datum
    int read_date();            //Avläser dagens datum
    void print_table();         //Skapar tabellen som uppvisar datan
    int insert_row();           //Skapar en ny rad på tabellen
}table;
struct tInterface{
    void showInterface();       //Visualiserar interface
    void showOptions();         //Visar användarens olika interaktions alternativ
    void AddCus();              //Adderar en ny kund till listan
    void updateCus();           //Uppdaterar data om valfri kund baserat på id
    void deleteCus();           //Raderar data om valfri kund baserat på id
    void showCus();             //Visar upp individuell kund baserat på id
}interface;
struct Customer{
    int cusID;
    std::string cusName;
    std::string cusCity;
    std::string cusState;
    double totalSales;
    int lastVisit;
    std::string format_date(int date);       //Datum för input
}tCus;
std::vector<Customer> vCus {{0, "Alexander Jonsson", "Malmo", "Skane", 1337, 20211122},
                            {1, "Adam Kusnierz", "Malmo", "Skane", 1337, 20211122},
                            {2, "Melina Bertosa", "Malmo", "Skane", 1337, 20211122}
                            };
/* declarations end */
std::fstream myFile;


int main(){
    /* init start */
    myFile.open("TheFile.csv");
    if (myFile.is_open())
    {
        int sec = 3;
        std::cout<<"File is good!\n";
        system("pause");
        system("cls");
    }
    else
    {
        std::cout<<"File is not OK\n";
        system("pause");
        system("cls");
        isRunning = false;
    }
    /* init end */
    while (isRunning == true)
    {
        columnBanner();
        interface.showInterface();
        interface.showOptions();
        
    }

    if (isRunning == false)
    {   
        std::cout<<"\nFile is closing\n";
        myFile.close();
    }
    
}

/* functions start */
void columnBanner()
{
    std::cout<<seperator
        <<std::right
        <<ID<<std::setw(2)<<"|"
        <<name<<std::setw(15)<<"|"
        <<city<<std::setw(12)<<"|"
        <<state<<std::setw(7)<<"|"
        <<lastVisit<<std::setw(5)<<"|"
        <<totalSales<<"|"<<std::endl
        <<seperator;
}

void tInterface::showInterface()
{
    for (int i = 0; i < vCus.size(); i++)
    {   
        std::cout<<
            std::left
            <<"| "<<std::setw(2)<<vCus[i].cusID+1
            <<" | "<<std::setw(15)<<vCus[i].cusName
            <<" | "<<std::setw(15)<<vCus[i].cusCity
            <<" | "<<std::setw(13)<<vCus[i].cusState
            <<" | "<<std::setw(8)<<vCus[i].lastVisit
            <<" | "<<std::setw(5)<<vCus[i].totalSales<<" |\n"
            <<seperator;
    }
    
/*     std::fstream myFile ("TheFile.csv");
    std::string value;
    while (getline(myFile, value))
    {
        std::cout << value;
        std::cout<<std::endl;
    } */
}

void tInterface::showOptions()
{
    std::cout<<"\nWhat do you want to do?\n";
    std::cout<<"1. Add customer\n2. Update customer\n3. Show customer table\n4. Delete customer\n5. Show total sales\n6. Exit program\n";
    std::cin>>choice;
    switch (choice)
    {
    case ADD:
        AddCus();
        break;
    case UPDATECUS:
        
        break;
    case SHOWCUSTOMER:
        
        break;
    case DELETECUSTOMER:
        
        break;
    case SHOWTOTALSALES:
        
        break;
    case EXITPROGRAM:
        std::cout<<"\nExiting program!\n";
        
        isRunning = false;
    default:
        std::cout<<"\nPlease enter a valid number!\n";
        break;
    }
    
}

void tInterface::AddCus()
{
    myFile.open("TheFile.csv");
    if (myFile.is_open())
    {
        std::fstream myFile ("TheFile.csv");
        std::cout<<"Enter customer first and last name: ";
        std::cin.ignore();
        std::getline(std::cin, tCus.cusName);
        std::cout<<"Enter customer city: ";
        std::getline(std::cin, tCus.cusCity);
        std::cout<<"Enter customer state: ";
        std::getline(std::cin, tCus.cusState);
        std::cout<<"Enter customer total sales: ";
        std::cin>>tCus.totalSales; 
        std::cout<<"Enter last visit date(YYYYMMDD)";
        tCus.cusID = cusIDtracker;
        std::cin>> tCus.lastVisit;
        nameToFile = tCus.cusName;cityToFile = tCus.cusCity;stateToFile = tCus.cusState;salesToFile = tCus.totalSales;dateToFile = tCus.lastVisit;
        myFile << nameToFile << ", " << cityToFile << ", " << stateToFile << ", " << salesToFile << ", "<< dateToFile<<"\n";
        vCus.push_back(tCus);
        cusIDtracker++;
        std::cout<<"\nThank you, your account has been created!\n";
        myFile.close();
        system("cls");
    }
    else
    {
        std::cout<<"File is not OK!\n";
    }
}

double tTable::get_total_sales()
{
    return 0;
}
/* functions end */