    #include <iostream>
    #include <fstream>
    #include <string>
    #include <sstream>
    #include "pracownicy.h"
    #include <QMessageBox>
    #include <qDebug>
    using namespace std;
    extern ostream& operator<<(ostream& lhs, Worker& rhs);


    //-----------------------------------------------------------------------------------*helpful classes*--------------------------------------------------------------------------------//

    Address::Address(string street, string post_code, string city, string country): street(street),post_code(post_code),city(city),country(country){}


    Address::~Address(){}

    //-----------------------------------------------------------------------------------*virtual class*--------------------------------------------------------------------------------//

    Person::Person(const string& name, const string& surname, string pesel, string sex) : name(name), surname(surname), pesel(pesel),sex(sex){}


    Person::~Person(){}


    //-----------------------------------------------------------------------------------*general class*--------------------------------------------------------------------------------//



    Worker::Worker(const string& name, const string& surname,string pesel, string sex, int ID, double salary, string position):Person(name,surname,pesel,sex),ID(ID),salary(salary),position(position){}



    void Worker::getInfo() {
        cout << "---------------------------" << endl;
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Pesel: " << pesel << endl;
        cout << "Salary: " << salary << endl;
        cout << "Position: " << position << endl;
        cout << "Code: " << address.post_code << endl;
        cout << "City: " << address.city << endl;
        cout << "Street: " << address.street << endl;
        cout << "Country: " << address.country << endl;
        cout << "---------------------------" << endl;
    }


    int Worker::getID() {
        return this->ID;
    }
    void Worker::setAddress(const string& street, const string& post_code, const string& city ,const string& country) {
        this->address.city = city;
        this->address.country = country;
        this->address.post_code = post_code;
        this->address.street = street;

    }
    double Worker::getSalary() {
        return this->salary;
    }
    string Worker::getName() {
        return this->name;
    }
    string Worker::getSurname() {
        return this->surname;
    }

    bool Worker::operator>=(Worker& rhs) const{
       // cout<<"Worker 1: "<<this->salary<<endl;
      //  cout<<"Worker 2: "<<rhs.getSalary()<<endl;
       // cout<<"Worker 1 >= Worker 2 :"<<(this->salary >= rhs.getSalary());
        return this->salary >= rhs.getSalary();
    }
    string Worker::getPos(){
        return this->position;
    }
    string Worker::getsex(){
        return this->sex;
    }
    double Worker::getsalary(){
        return this->salary;
    }
    string Worker::getpesel(){
        return this->pesel;
    }
    int Worker::leasing_size(){
    cout << "Not implemented in Worker class." << endl;
    }
    void Worker::addLeasing(string name, string brand, double value) {
    cout << "Not implemented in Worker class." << endl;
    }
    Leasing* Worker::getLeasing(int index){
    cout << "Not implemented in Worker class." << endl;
    }
    void Worker::addDemand(const string& name) {
    cout << "Not implemented in Worker class." << endl;
    }
    void Worker::readDemand() {
        cout << "Not implemented in Worker class." << endl;
    }
    void Worker::readFile() {
    cout << "Not implemented in Worker class." << endl;
    }
    void Worker::saveFile() {
    cout << "Not implemented in Worker class." << endl;
    }
    void Worker::addQuant(int quant){
    cout << "Not implemented in Worker class." << endl;
    }
    void Worker::updateQuant(int pos, int many){
    cout << "Not implemented in Worker class." << endl;
    }
    void Worker::addPostedData(const string& thing_name, long double value, int quantity, const string& info, const string& entry) {
    cout << "Not implemented in Worker class." << endl;
    }
    vector<Worker*> Worker::findWorker(string name){
     cout << "Not implemented in Worker class." << endl;
    }
    vector<Worker*> Worker::findWorker(QString position){
        cout << "Not implemented in Worker class." << endl;
    }
    vector<Worker*> Worker::findWorker(int ID){
        cout << "Not implemented in Worker class." << endl;
    }

    Worker::~Worker(){}

    //-----------------------------------------------------------------------------------*management class*--------------------------------------------------------------------------------//

    Management::Management(const string& name, const string& surname, string pesel, string sex, int ID, double salary, string position):
        Worker(name,surname,pesel,sex,ID,salary,position) {
    }

    void Management::fireWorker(int ID) {
        int foundIndex = -1;
        for (int i = 0; i < workers_array.size(); i++) {
            if (workers_array[i]->getID() == ID) {
                foundIndex = i;
                break;
            }
        }

        try {
            if (foundIndex != -1) {
                delete workers_array[foundIndex];
                workers_array.erase(workers_array.begin() + foundIndex);
                cout << "Worker with ID " << ID << " has been fired." << endl;
            }
            else {
                throw MyException("Worker with ID not found.");
            }
        }
        catch (const MyException& e) {
            QMessageBox::critical(nullptr, "Exception", QString::fromStdString(e.what()));
        }
        catch (...) {
             QMessageBox::critical(nullptr, "Unknown Exception", "Unknown exception occurred.");
        }
    }
    void Management::setWorkerAddress(const string& post_code, const string& street, const string& city, const string& country, int ID) {
        int foundIndex = -1;

        for (int i = 0; i < workers_array.size(); i++) {
            if (workers_array[i]->getID() == ID) {
                foundIndex = i;
                break;
            }
        }
        try {
            if (foundIndex != -1) {
                workers_array[foundIndex]->setAddress(street, post_code, city ,country);
            }
            else {
                throw MyException("Worker with ID not found.");
            }
        }
        catch (const MyException& e) {
            QMessageBox::critical(nullptr, "Exception", QString::fromStdString(e.what()));
        }
        catch (...) {
            QMessageBox::critical(nullptr, "Unknown Exception", "Unknown exception occurred.");
        }
    }
    void Management::setAddress(const string& street, const string& post_code, const string& city ,const string& country) {
        address.city = city;
        address.country = country;
        address.post_code = post_code;
        address.street = street;
    }

    bool Management::operator>=(Worker& rhs) const {
        cout<<"Worker 1: "<<this->salary<<endl;
        cout<<"Worker 2: "<<rhs.getSalary()<<endl;
        cout<<"Worker 1 >= Worker 2 :"<<(this->salary >= rhs.getSalary());
       return this->salary >= rhs.getSalary();
    }
    string Management::getName() {
        return this->name;
    }
    string Management::getSurname() {
        return this->surname;
    }
    string Management::getPos(){
        return this->position;
    }
    string Management::getpesel(){
        return this->pesel;
    }
    int Management::getID(){
        return this->ID;
    }
    double Management::getsalary(){
        return this->salary;
    }
    string Management::getsex(){
        return this->sex;
    }

    void Management::getInfo() {
        cout << "---------------------------" << endl;
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Pesel: " << pesel << endl;
        cout << "Salary: " << salary << endl;
        cout << "Position: " << position << endl;
        cout << "Code: " << address.post_code << endl;
        cout << "City: " << address.city << endl;
        cout << "Street: " << address.street << endl;
        cout << "Country: " << address.country << endl;
        cout << "---------------------------" << endl;
    }


    void Management::addWorker(Worker* person) {
        workers_array.push_back(person);

    }
    void Management::printWorker() {
        cout << "--------Workers list--------" << endl;

        for (int i = 0; i < workers_array.size(); i++) {
            workers_array[i]->getInfo();
        }
    }
    void Management::printWorker(int ID) {
        cout << "--------Worker info--------" << endl;
        int foundIndex = -1;
        for (int i = 0; i < workers_array.size(); i++) {
            if (workers_array[i]->getID() == ID) {
                foundIndex = i;
                break;
            }
        }
        try {
            if (foundIndex != -1) {
                workers_array[foundIndex]->getInfo();
            }
            else
                throw MyException("Worker with ID not found.");
        }
        catch(const MyException& e){
           QMessageBox::critical(nullptr, "Exception", QString::fromStdString(e.what()));
        }
        catch (...) {
            QMessageBox::critical(nullptr, "Unknown Exception", "Unknown exception occurred.");
        }
    }
    vector<Worker*> Management::findWorker(string name){
        if(results.size()!=0)
        results.clear();
        int size = workers_array.size();
        for(int i=0;i<size;i++){
            if(workers_array[i]->getName()==name){
                this->results.push_back(workers_array[i]);
            }
        }
        return this->results;
    }
    vector<Worker*> Management::findWorker(int ID){
        if(results.size()!=0)
        results.clear();
        int size = workers_array.size();

        for(int i=0;i<size;i++){
            if(workers_array[i]->getID()==ID){
                this->results.push_back(workers_array[i]);
            }
        }
        return this->results;
    }
    vector<Worker*> Management::findWorker(QString position){
        string pos = position.toStdString();
        if(results.size()!=0)
        results.clear();
        int size = workers_array.size();

        for(int i=0;i<size;i++){
            if(workers_array[i]->getPos()==pos){
                this->results.push_back(workers_array[i]);
            }
        }
        return this->results;
    }
    Management::~Management() {

        int size = workers_array.size();
        for (int i = 0; i < size; i++) {
            if (workers_array[i]) {

                delete workers_array[i];
                workers_array[i] = nullptr;
            }
        }
         workers_array.clear();
         results.clear();
    }


    //-----------------------------------------------------------------------------------*financial class*--------------------------------------------------------------------------------//

    Financial::Financial(const string & name, const string & surname, string pesel, string sex, int ID, double salary, string position)
        : Worker(name, surname, pesel, sex, ID, salary, position) {}
    vector<Leasing*> Financial::leasing_cars;
    void Financial::getInfo() {
        cout << "---------------------------" << endl;
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Pesel: " << pesel << endl;
        cout << "Salary: " << salary << endl;
        cout << "Position: " << position << endl;
        cout << "Code: " << address.post_code << endl;
        cout << "City: " << address.city << endl;
        cout << "Street: " << address.street << endl;
        cout << "Country: " << address.country << endl;
        cout << "---------------------------" << endl;
    }
    void Financial::addLeasing(string name, string brand, double value) {
        Leasing* car = new Leasing(name, brand, value);
        leasing_cars.push_back(car);
       // cout<<leasing_cars.at(0)->name;
    }
    string Financial::getName() {
        return this->name;
    }
    string Financial::getSurname() {
        return this->surname;
    }
    string Financial::getPos(){
        return this->position;
    }

    string Financial::getpesel(){
        return this->pesel;
    }
    int Financial::getID(){
        return this->ID;
    }
    double Financial::getsalary(){
        return this->salary;
    }
    string Financial::getsex(){
        return this->sex;
    }

    bool Financial::operator>=(Worker& rhs) const {
      //  cout<<"Worker 1: "<<this->salary<<endl;
     //   cout<<"Worker 2: "<<rhs.getSalary()<<endl;
     //   cout<<"Worker 1 >= Worker 2 :"<<(this->salary >= rhs.getSalary());
        return this->salary >= rhs.getSalary();
    }
    void Financial::readDemand() {
        int size = this->demand.size();
        for (int i = 0; i < size; i++)
            cout << demand[i] << endl;
    }
    void Financial::addDemand(const string& name){
        this->demand.push_back(name);
    }
    void Financial::addQuant(int quant){
        this->quantity.push_back(quant);
    }
    void Financial::updateQuant(int pos, int many){
        try{
        if(quantity.size()!=0)
        this->quantity[pos]=many;
        else{

        }
        }
       catch (...) {
         QMessageBox::critical(nullptr, "Unknown Exception", "Unknown exception occurred.");
        }
    }
    void Financial::saveFile() {
        try {
            ofstream out("demand.bin", ios::out | ios::binary);
            if (!out.is_open()) {
                throw MyException("Error opening demand.bin for writing.");
            }

            int size = demand.size();
            for (int i = 0; i < size; i++) {
                double quant = quantity[i];
                if (quant < 0 || (int)quant != quant) {
                    throw MyException("Invalid input. Please enter a valid integer.");
                } else {
                    out.write(reinterpret_cast<char*>(&quant), sizeof(quant));

                    unsigned int wielkosc = demand[i].size();
                    out.write(reinterpret_cast<char*>(&wielkosc), sizeof(wielkosc));
                    out.write(this->demand[i].c_str(), wielkosc);
                }
            }

            out.close();
            cout << "Data saved!" << endl;
        } catch (const MyException& e) {
            QMessageBox::critical(nullptr, "Exception", QString::fromStdString(e.what()));
        } catch (...) {
             QMessageBox::critical(nullptr, "Unknown Exception", "Unknown exception occurred.");
        }
    }
    void Financial::readFile() {
        try {
            ifstream in("demand.bin", ios::in | ios::binary);
            if (!in.is_open()) {
                throw MyException("Error opening demand.bin for reading.");
            }
            else if (in.peek() == ifstream::traits_type::eof()) {
                throw MyException("File is empty!");
            }
            else {
                int size = demand.size();
                cout << "From demand file: " << endl;
                for (int i = 0; i < size; i++) {
                    double quant;
                    in.read(reinterpret_cast<char*>(&quant), sizeof(quant));

                    int wielkosc = 0;
                    in.read(reinterpret_cast<char*>(&wielkosc), sizeof(wielkosc));
                    string buffer;
                    buffer.resize(wielkosc);
                    in.read(&buffer[0], buffer.size());
                    cout << "Our demand:" << endl;
                    cout << "| Thing : " << buffer << " | Quantity  " << quant << " |" << endl;
                }

                in.close();
            }
        }
        catch (const MyException& e) {
             QMessageBox::critical(nullptr, "Exception", QString::fromStdString(e.what()));
        }
        catch (...) {
           QMessageBox::critical(nullptr, "Unknown Exception", "Unknown exception occurred.");
        }
    }
    Leasing* Financial::getLeasing(int index) {
        try{
        if (index >= 0 && index < leasing_size()) {
            return leasing_cars[index];
        } else {

            throw MyException("Invalid index when accessing leasing.");
        }
        }
        catch(const MyException& e){
             QMessageBox::critical(nullptr, "Exception", QString::fromStdString(e.what()));
        }
        catch (...) {
             QMessageBox::critical(nullptr, "Unknown Exception", "Unknown exception occurred.");
        }
    }
    int Financial::leasing_size(){
        return this->leasing_cars.size();
    }
    Financial::~Financial() {

        int size = leasing_cars.size();
        for (int i = 0; i < size; i++) {
            if (leasing_cars[i]) {
                delete leasing_cars[i];
                leasing_cars[i] = nullptr;
            }
        }
        leasing_cars.clear();
    }

    //-------------------------------------------------------------------------------*accountancy class*--------------------------------------------------------------------------------//

    Accountancy::Accountancy(const string & name, const string & surname, string pesel, string sex, int ID, double salary, string position)
        : Financial(name, surname, pesel, sex, ID, salary, position) {}
    Accountancy::Accountancy(const string& name, const string& surname, string pesel, string sex, int ID, double salary, string position, Management* manager)
        : Financial(name, surname, pesel, sex, ID, salary, position) ,manager(manager){}
    void Accountancy::getInfo() {
        cout << "---------------------------" << endl;
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Pesel: " << pesel << endl;
        cout << "Salary: " << salary << endl;
        cout << "Position: " << position << endl;
        cout << "Code: " << address.post_code << endl;
        cout << "City: " << address.city << endl;
        cout << "Street: " << address.street << endl;
        cout << "Country: " << address.country << endl;
        cout << "---------------------------" << endl;
    }

    bool Accountancy::operator>=(Worker& rhs) const{
      //  cout<<"Worker 1: "<<this->salary<<endl;
      //  cout<<"Worker 2: "<<rhs.getSalary()<<endl;
       // cout<<"Worker 1 >= Worker 2 :"<<(this->salary >= rhs.getSalary());
        return this->salary >= rhs.getSalary();
    }
    string Accountancy::getName() {
        return this->name;
    }
    string Accountancy::getSurname() {
        return this->surname;
    }
    string Accountancy::getPos(){
        return this->position;
    }

    string Accountancy::getpesel(){
        return this->pesel;
    }
    int Accountancy::getID(){
        return this->ID;
    }
    void Accountancy::addPostedData(const string& thing_name, long double value, int quantity, const string& info, const string& entry) {
        this->thing_name.push_back(thing_name);
        this->value.push_back(value);
        this->quantity.push_back(quantity);
        this->info.push_back(info);
        this->entry.push_back(entry);
    }
    double Accountancy::getsalary(){
        return this->salary;
    }
    string Accountancy::getsex(){
        return this->sex;
    }

    Accountancy::~Accountancy(){}

    ostream& operator<<(ostream& lhs, Worker* rhs) {
        return lhs <<" " << rhs->getSurname()<<" "<<rhs->getName();
    }
