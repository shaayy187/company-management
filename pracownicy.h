#ifndef PRACOWNICY_H
#define PRACOWNICY_H

#endif // PRACOWNICY_H

#include <iostream>
#include <vector>
#include <QString>
#pragma once
using namespace std;

//-----------------------------------------------------------------------------------*Exception class*--------------------------------------------------------------------------------//
/// @brief MyException class represents my own class for catching exceptions
/// It takes string with message of an error and stores it in "msg"
class MyException : public exception {
    /// Description
    ///
    /// Field used to store exception message.
    string msg;


public:
    MyException(const string& message) : msg(message) {}
    /// Description
    ///
    /// Function which returns exception message and converts string to pointer of chars array which contains whole message.
    /// This function overrides the what() method of the base exception class.
    /// It returns a pointer to the array.
    const char* what() const noexcept override {
        return msg.c_str();
    }
    ~MyException(){}

};
//-----------------------------------------------------------------------------------*helpful classes*--------------------------------------------------------------------------------//


/// @brief Address class represents address details of an object.
/// It has fields which contains post code, citry ,street and country.
class Address {
public:
    /// Description
    ///
    /// Field used to store street where does the object lives.
    string street;
    /// Description
    ///
    /// Field used to store post code of an object.
    string post_code;
    /// Description
    ///
    /// Field used to store city where does the object lives.
    string city;
    /// Description
    ///
    /// Field used to store country where does the object lives.
    string country;
    Address():street(""),post_code(""), city(""),country("") {}
    Address(string street, string post_code, string city, string country);
    ~Address();

};
/// @brief Leasing class represents hired cars for the company.
/// It has fields which contains name, brand and value of a car.
class Leasing {
public:
    /// Description
    ///
    /// Field used to store name of an object.
    string name;
    /// Description
    ///
    /// Field used to store brand of an object.
    string brand;
    /// Description
    ///
    /// Field used to store value of an object.
    double value;
    Leasing(string name, string brand, double value): name(name), brand(brand), value(value) {}
    ~Leasing(){}
};

//-----------------------------------------------------------------------------------*virtual class*--------------------------------------------------------------------------------//
/// @brief Person class represents just a person.
/// The Person class is an abstract base class that serves as a blueprint for creating objects representing individuals within the system.
/// It contains common attributes and methods that are shared by more specialized classes derived from it.
class Person {
protected:
    /// Description
    ///
    /// Field used to store name of an object.
    string name;
    /// Description
    ///
    /// Field used to store surname of an object.
    string surname;
    /// Description
    ///
    /// Field used to store pesel of an object.
    string pesel;
    /// Description
    ///
    /// Field used to store sex of an object.
    string sex;
    /// Description
    ///
    /// Data object which contains birthdate of an object. Not currently used in this project anymore...
public:
    Person(const string& name, const string& surname,string pesel, string sex);
    virtual ~Person();
    /// Description
    ///
    /// Function used to get info of an object.
    virtual void getInfo()=0;
    /// Description
    ///
    /// Function used to get name of an object.
    virtual string getName() = 0;
    /// Description
    ///
    /// Function used to get pesel of an object.
    virtual string getpesel()=0;
    /// Description
    ///
    /// Function used to get surname of an object.
    virtual string getSurname() = 0;
    /// Description
    ///
    /// Function used to get sex of an object.
    virtual string getsex()=0;


};

//-----------------------------------------------------------------------------------*general class*--------------------------------------------------------------------------------//
/// @brief Worker class represents default worker of the company. From here we start mostly all of the methods.
///
/// Worker contains fields like ID, salary, position. Aswell functions to get all of the info about object. In the code I often use this class for the polimorphism, rewriting many of the methods in further classes.

class Worker: public Person {
protected:
    /// Description
    ///
    /// Field used to store ID of an object.
    int ID;
    /// Description
    ///
    /// Field used to store salary of an object.
    double salary;
    /// Description
    ///
    /// Field used to store position of the object.
    string position;
public:
    /// Description
    ///
    /// Adress object in which we're storing info about objects' address details.
    Address address;
    Worker() : Person("","","",""),ID(0),salary(0),position("") {}
    Worker(const string& name, const string& surname, string pesel, string sex, int ID, double salary, string position);
    ~Worker();
    /// Description
    ///
    /// Function used to print all info about object into terminal.
    virtual void getInfo();
    /// Description
    ///
    /// Function used in Management class. More described there.
    virtual vector<Worker*> findWorker(string name);
    /// Description
    ///
    /// Function used in Management class. More described there.
    virtual vector<Worker*> findWorker(int ID);
    /// Description
    ///
    /// Function used in Management class. More described there.
    virtual vector<Worker*> findWorker(QString position);
    /// Description
    ///
    /// Returns name of an object.
    virtual string getName();
    /// Description
    ///
    /// Returns surname of an object.
    virtual string getSurname();
    /// Description
    ///
    /// Returns pesel of an object.
    virtual string getpesel();
    /// Description
    ///
    /// Returns salary of the object.
    virtual double getsalary();
    /// Description
    ///
    /// Returns sex of the object.
    virtual string getsex();
    /// Description
    ///
    /// Function mainly used in Financial class and described there.
    virtual void addLeasing(string name, string brand, double value);
    /// Description
    ///
    /// Function mainly used in Financial class and described there.
    virtual Leasing* getLeasing(int index);
    /// Description
    ///
    /// Function mainly used in Financial class and described there.
    virtual void addDemand(const string& name);
    /// Description
    ///
    /// Function mainly used in Financial class and described there.
     virtual void readDemand();
    /// Description
    ///
    /// Function mainly used in Financial class and described there.
    virtual void addQuant(int quant);
    /// Description
    ///
    /// Function mainly used in Financial class and described there.
    virtual void saveFile();
    /// Description
    ///
    /// Function mainly used in Financial class and described there.
    virtual void readFile();
    /// Description
    ///
    /// Returns working position of the object.
    virtual string getPos();
    /// Description
    ///
    /// Function used in Financial class and described there.
    virtual int leasing_size();
    /// Description
    ///
    /// Function mainly used in Financial class and described there.
    virtual void updateQuant(int pos, int many);
    /// Description
    ///
    /// Function used to set adress of an object.
    /// @param post_code {const string&} Post code of an object.
    /// @param city {const string&} City where does the object live.
    /// @param street {const string&} Street where does the object live.
    /// @param country {const string&} Country where does the object live.
    void setAddress(const string& post_code, const string& city, const string& street, const string& country);
    /// Description
    ///
    /// Returns salary of an object.
    double getSalary();
    /// Description
    ///
    /// Overload of the >= operator which compare 2 objects' salary and returns the one who earn more.
    /// @param rhs {Worker&} This is the object on the right side we're comparing with the left one.
    virtual bool operator>=(Worker& rhs) const;
    /// Description
    ///
    /// Returns ID of the object.
    int getID();
    /// Description
    ///
    /// Overload of the << operator used to write into terminal Name and Surname of the object.
    /// @param lhs {ostream&} Output stream from the left side.
    /// @param rhs {Worker*} Right side obect which names' and surname's we're showing in the console.
    friend ostream& operator<<(ostream& lhs, Worker* rhs);
    /// Description
    ///
    /// Function mainly used in Accountancy class and described there.
    virtual void addPostedData(const string& thing_name, long double value, int quantity, const string& info, const string& entry);

};

//-----------------------------------------------------------------------------------*funds class*--------------------------------------------------------------------------------//
/// @brief Funds template class represents funds at the company's disposal.
///
/// Funds contains a template, by which we're creating a class: field which store funds, with methods to update funds and return them. It is in friend with Management and Financial.

template<typename T>
class Funds {

private:
    /// Description
    ///
    /// Field used to store funds of the company.
    T available_funds;
public:
    /// Description
    ///
    /// Function which allows to return available funds which can be used when needed.
    T retFunds() {
        return available_funds;
    }
    /// Description
    ///
    /// Method used to update funds f.e. after buying some things by Financial department.
    void updateFunds(T value) {
        this->available_funds = value;
    }
};

//-----------------------------------------------------------------------------------*management class*--------------------------------------------------------------------------------//
/// @brief Management class represents the management department.
///
/// Management contains objects which can add other objects to the company, set their adress, see info about workers and fire them. They're the highest in the hierarchy.
class Management: public Worker, public Funds<double> {
private:
public:
    /// Description
    ///
    /// Vector used to store all the workers of the company.
    vector<Worker *> workers_array;
    /// Description
    ///
    /// Vector used to store all the workers found by specific field f.e. index, or name.
    vector<Worker*> results;
    Management(const string& name, const string& surname, string pesel, string sex, int ID, double salary, string position);
    ~Management();
    /// Description
    ///
    /// Function used to add worker into the company.
    void addWorker(Worker* person);
    /// Description
    ///
    /// Function used to print info about worker.
    void printWorker();
    /// Description
    ///
    /// Function used to print info about worker with the specific ID.
    void printWorker(int ID);
    /// Description
    ///
    /// Function used to set address of an object. In this case the Management object.
    /// @param post_code {const string&} Post code of an object.
    /// @param city {const string&} City where does the object live.
    /// @param street {const string&} Street where does the object live.
    /// @param country {const string&} Country where does the object live.
    void setAddress(const string& post_code, const string& city, const string& street, const string& country);
    /// Description
    ///
    /// Function used to print all info about object into terminal.
    void getInfo();
    /// Description
    ///
    /// Function used to find worker by a specific name.
    /// @param name {string} Name of a worker
    /// @return returns vector with found worker objects with a specific names.
    vector<Worker*> findWorker(string name);
    /// Description
    ///
    /// Function used to find worker by a specific ID.
    /// @param ID {int} ID of a worker
    /// @return returns vector with found worker objects with a specific IDs.
    vector<Worker*> findWorker(int ID);
    /// Description
    ///
    /// Function used to find worker by a specific position.
    /// @param position {QString} Position of a worker stored in QString - QT string variable
    /// @return returns vector with found worker objects with a specific position.
    vector<Worker*> findWorker(QString position);
    /// Description
    ///
    /// Returns name of an object.
    string getName();
    /// Description
    ///
    /// Returns surname of an object.
    string getSurname();
    /// Description
    ///
    /// Returns working position of the object.
    string getPos();
    /// Description
    ///
    /// Returns ID of an object.
    int getID();
    /// Description
    ///
    /// Returns pesel of an object.
    string getpesel();
    /// Description
    ///
    /// Returns salary of the object.
    double getsalary();
    /// Description
    ///
    /// Returns sex of the object.
    string getsex();
    /// Description
    ///
    /// Function used to set address of an object. In this case it is allowed to set adress of other objects by an ID.
    /// @param post_code {const string&} Post code of an object.
    /// @param city {const string&} City where does the object live.
    /// @param street {const string&} Street where does the object live.
    /// @param country {const string&} Country where does the object live.
    void setWorkerAddress(const string &post_code,const string &city, const string& street,const string& country, int ID);
    /// Description
    ///
    /// Overload of the >= operator which compare 2 objects' salary and returns the one who earn more.
    /// @param rhs {Worker&} This is the object on the right side we're comparing with the left one.
    bool operator>=(Worker& rhs) const;
    /// Description
    ///
    /// This method allows to fire a worker and delete it from workers_array.
    /// @param ID {int} ID of an object you want to fire.
    void fireWorker(int ID);
    /// Description
    ///
    /// Overload of the << operator used to write into terminal Name and Surname of the object.
    /// @param lhs {ostream&} Output stream from the left side.
    /// @param rhs {Worker*} Right side obect which names' and surname's we're showing in the console.
    friend ostream& operator<<(ostream& lhs, Worker* rhs);


};

//-----------------------------------------------------------------------------------*financial class*--------------------------------------------------------------------------------//
/// @brief Financial class represents the financial department.
///
/// Financial contains objects which can add demand, their quantity into file to signal what the company needs to buy. Aswell they can add leasing cars of the company.
class Financial : public Worker, public Funds<double> {
protected:
    /// Description
    ///
    /// Vector used to store demand of the company.
    vector <string> demand;
    /// Description
    ///
    /// Vector used to store leasing cars of the company.
    static vector <Leasing*> leasing_cars;
    /// Description
    ///
    /// Vector used to strone quantity of needed items from demand.
    vector <int> quantity;
public:
    Financial(const string& name, const string& surname, string pesel, string sex, int ID, double salary, string position);
    /// Description
    ///
    /// Function used to print all info about object into terminal.
    void getInfo();
    /// Description
    ///
    /// Returns name of an object.
    string getName();
    /// Description
    ///
    /// Returns surname of an object.
    string getSurname();
    /// Description
    ///
    /// Function which lets add leasing of the company.
    /// @param name {string} Name of a car.
    /// @param brand {string} Brand of a car.
    /// @param value {double} Value of a car.
    void addLeasing(string name, string brand, double value);
    /// Description
    ///
    /// Function used to get leasing cars vector size.
    int leasing_size();
    /// Description
    ///
    /// Function used to get a Leasing object at specific index
    Leasing* getLeasing(int index);
    /// Description
    ///
    /// Returns working position of the object.
    string getPos();
    /// Description
    ///
    /// Returns pesel of an object.
    string getpesel();
    /// Description
    ///
    /// Returns sex of the object.
    string getsex();
    /// Description
    ///
    /// Function used to update needed quant after buying item.
    /// @param pos {int} Position of a demand found in for loop.
    /// @param many {int} New Quantity after purchase.
    void updateQuant(int pos, int many);
    /// Description
    ///
    /// Returns ID of an object.
    int getID();
    /// Description
    ///
    /// Returns salary of the object.
    double getsalary();
    /// Description
    ///
    /// Allows to read needed demand for the company.
    void readDemand();
    /// Description
    ///
    /// Allows to add demand into vector.
    /// @param name {const string&} Name of the demand.
    void addDemand(const string& name);
    /// Description
    ///
    /// Function used to add quantity of thing needed in demand.
    /// @param quant {int} Quantity of an item.
    void addQuant(int quant);
    /// Description
    ///
    /// Function used to put all demands into binary file called "demand.bin".
    void saveFile();
    /// Description
    ///
    /// Function used to print all deamnds from binary file calles "demand.bin".
    void readFile();
        /// Description
        ///
        /// Overload of the >= operator which compare 2 objects' salary and returns the one who earn more.
        /// @param rhs {Worker&} This is the object on the right side we're comparing with the left one.
    bool operator>=(Worker& rhs) const;
    ~Financial();
    /// Description
    ///
    /// Overload of the << operator used to write into terminal Name and Surname of the object.
    /// @param lhs {ostream&} Output stream from the left side.
    /// @param rhs {Worker*} Right side obect which names' and surname's we're showing in the console.
    friend ostream& operator<<(ostream& lhs, Worker* rhs);

};

//-----------------------------------------------------------------------------------*accountancy class*--------------------------------------------------------------------------------//
/// @brief Accountancy class represents the accounting department.
///
/// Accountancy contains objects which can post invoices and have a look into the all-invoice file.
///
/// This class inherits methods from Financial, allowing access to basic information about the object.
/// It has 5 vectors and a Management object needed for funds update.
class Accountancy : public Financial {
protected:
    /// Description
    ///
    /// Manager object needed for funds update after buying items. Not used in GUI form. It was used in terminal mode.
    Management* manager;
    /// Description
    ///
    /// Vector used to storing bought items names. Not used in GUI form. It was used in terminal mode.
    vector <string> thing_name;
    /// Description
    ///
    /// Vector used to storing value of bought items. Not used in GUI form. It was used in terminal mode.
    vector <double> value;
    /// Description
    ///
    /// Vector used to storing quantity of bought items. Not used in GUI form. It was used in terminal mode.
    vector <int> quantity;
    /// Description
    ///
    /// Vector used for storing info about bought items. Not used in GUI form. It was used in terminal mode.
    vector <string> info;
    /// Description
    ///
    /// Vector used for storing name of person who did post the invoice. Not used in GUI form.
    vector <string> entry;
public:
    Accountancy(const string& name, const string& surname, string pesel, string sex, int ID, double salary, string position);
    Accountancy(const string& name, const string& surname, string pesel, string sex, int ID, double salary, string position, Management* manager);
    /// Description
    ///
    /// Function used to print all info about object into terminal.
    void getInfo();
    /// Description
    ///
    /// Function used to get Name of an object.
    string getName();
    /// Description
    ///
    /// Function used to get Surame of an object.
    string getSurname();
    /// Description
    ///
    /// Function used to get Pesel of an object.
    string getpesel();
    /// Description
    ///
    /// Function used to get Sex of an object.
    string getsex();
    /// Description
    ///
    /// Function used to get Salary of an object.
    double getsalary();
    /// Description
    ///
    /// Function used to get ID of an object.
    int getID();
    /// Description
    ///
    /// Returns working position of the object.
    string getPos();
     /// Description
     ///
     /// Overload of the >= operator which compare 2 objects' salary and returns the one who earn more.
     /// @param rhs {Worker&} This is the object on the right side we're comparing with the left one.
    bool operator>=(Worker& rhs) const;
    /// Description
    /// This function is used to store accountance data into vectors in class
    /// It takes name of thing to buy, value of these, their quantity, info and entry of person who did commit posting
    void addPostedData(const string& thing_name, long double value, int quantity, const string& info, const string& entry);
    ~Accountancy();
    /// Description
    ///
    /// Overload of the << operator used to write into terminal Name and Surname of the object.
    /// @param lhs {ostream&} Output stream from the left side.
    /// @param rhs {Worker*} Right side obect which names' and surname's we're showing in the console.
    friend ostream& operator<<(ostream& lhs, Worker* rhs);
};


