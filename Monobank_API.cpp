// bank_project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <nlohmann/json.hpp>
using json = nlohmann::json;
#include <fstream>

#pragma comment(lib, "Urlmon.lib")
#include <windows.h>
#include <cstdio>
using namespace std;




int main()
{

    // URL of the monobank json.
    const wchar_t* sURL = L"https://api.monobank.ua/bank/currency";
    // Name of the Destination file 
    const wchar_t* dFile = L"monobank.json";
    if (S_OK == URLDownloadToFile(NULL, sURL, dFile, 0, NULL))
    {
        cout << "Data download succesfull." << endl;

    }
    else
    {
        cout << "Unable to Download the file. Too many requests. Try later.";
        return -1;
    }

    ifstream f("monobank.json");//open json file
    json data = json::parse(f);//read json file
    remove("monobank.json");//delete json file

    //cout << setw(4) << data[0]["rateBuy"] << endl;


    float ratebuy = data[0]["rateBuy"];//dollar buy
    cout << "Dollar buying rate now is " << ratebuy << endl;;
    float ratesell = data[0]["rateSell"];//dollar sell
    cout << "Dollar selling rate now is " << ratesell << endl;

    float num;
    int menu;
    float count;
    while (true)
    {
        cout << "What do you want to?\n Enter number of operation.\n 1 - Buy dollars.\n 2 - Sell dollars.\n 0 - Exit." << endl;
        cin >> menu;
        if (menu == 0)
        {
            cout << "Exit";
            return 0;
        }
        else if (menu == 1)
        {
            cout << "Enter the amount of hryvnia: ";
            cin >> count;
            num = count / ratesell;
            cout << "You get " << num << " dollars" << endl;
        }
        else if (menu == 2)
        {
            cout << "Enter the amount of dollars: ";
            cin >> count;
            num = count * ratebuy;
            cout << "You get " << num << " hryvnia" << endl;
        }
        else
        {
            cout << "Non-correct information!" << endl;
        }
    }




    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
