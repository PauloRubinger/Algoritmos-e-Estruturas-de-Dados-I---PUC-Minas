#include <iostream>
#include <string>
using namespace std;

// Superclasse
class Vehicle {
    private:
        short year_manufacture;
        string license_plate;
        int km;
    public:
        Vehicle(short year_manufacture, string license_plate, int km) {
            this->setYear(year_manufacture);
            this->setLicensePlate(license_plate);
            this->setKm(km);
        }
        short getYear() {
            return this->year_manufacture;
        }
        string getLicensePlate() {
            return this->license_plate;
        }
        int getKm() {
            return this->km;
        }
        void setYear(short year_manufacture) {
            this->year_manufacture = year_manufacture;
        }
        void setLicensePlate(string license_plate) {
            this->license_plate = license_plate;
        }
        void setKm(int km) {
            this->km = km;
        }
        void print() {
            cout<<this->getYear()<<", "<<this->getLicensePlate()<<", "<<this->getKm()<<endl;
        }
};

class Auto:public Vehicle {
    private:
        short num_doors;
        int km_last_revision;
    public:
        Auto(short year_manufacture, string license_plate, int km, short num_doors, int km_last_revision):Vehicle(year_manufacture, license_plate, km) {
            this->setNumDoors(num_doors);
            this->setKmLastRevision(km_last_revision);
        }
        short getNumDoors() {
            return this->num_doors;
        }
        int getKmLastRevision() {
            return this->km_last_revision;
        }
        void setNumDoors(short num_doors) {
            this->num_doors = num_doors;
        }
        void setKmLastRevision(int km_last_revision) {
            this->km_last_revision = km_last_revision;
        }
        void print() {
            cout<<this->getYear()<<", "<<this->getLicensePlate()<<", "<<this->getKm()<<", "<<this->getNumDoors()<<", "<<this->getKmLastRevision()<<endl;
        }
};

class Truck:public Vehicle {
    private:
        short num_tires;
        int capacity;
        string shipping_price;
    public:
        Truck(short year_manufacture, string license_plate, int km, short num_tires, int capacity, string shipping_price):Vehicle(year_manufacture, license_plate, km) {
            this->setNumTires(num_tires);
            this->setCapacity(capacity);
            this->setShippingPrice(shipping_price);
        }
        short getNumTires() {
            return this->num_tires;
        }
        int getCapacity() {
            return this->capacity;
        }
        string getShippingPrice() {
            return this->shipping_price;
        }
        void setNumTires(short num_tires) {
            this->num_tires = num_tires;
        }
        void setCapacity(int capacity) {
            this->capacity = capacity;
        }
        void setShippingPrice(string shipping_price) {
            this->shipping_price = shipping_price;
        }
        void print() {
            cout<<this->getYear()<<", "<<this->getLicensePlate()<<", "<<this->getKm()<<", "<<this->getNumTires()<<", "<<this->getCapacity()<<", "<<this->getShippingPrice()<<endl;
        }
};

// Superclasse
class Bike {
    private:
        short rim_size;
        string manufacturer;
    public:
        Bike(short rim_size, string manufacturer) {
            this->setRimSize(rim_size);
            this->setManufacturer(manufacturer);
        }
        short getRimSize() {
            return this->rim_size;
        }
        string getManufacturer() {
            return this->manufacturer;
        }
        void setRimSize(short rim_size) {
            this->rim_size = rim_size;
        }
        void setManufacturer(string manufacturer) {
            this->manufacturer = manufacturer;
        }
        void print() {
            cout<<this->getRimSize()<<", "<<this->getManufacturer()<<endl;
        }
};

class Urban:public Bike {
    private:
        int insurance_number;
    public:
        Urban(short rim_size, string manufacturer, int insurance_number):Bike(rim_size, manufacturer) {
            this->setInsuranceNumber(insurance_number);
        }
        int getInsuranceNumber() {
            return this->insurance_number;
        }
        void setInsuranceNumber(int insurance_number) {
            this->insurance_number = insurance_number;
        }
        void print() {
            cout<<this->getRimSize()<<", "<<this->getManufacturer()<<", "<<this->getInsuranceNumber()<<endl;
        }
};

class Eletric:public Urban {
    private:
        float power;
    public:
        Eletric(short rim_size, string manufacturer, int insurance_number, float power):Urban(rim_size, manufacturer, insurance_number) {
            this->setPower(power);
        }
        float getPower() {
            return this->power;
        }
        void setPower(float power) {
            this->power = power;
        }
        void print() {
            cout<<this->getRimSize()<<", "<<this->getManufacturer()<<", "<<this->getInsuranceNumber()<<", "<<this->getPower()<<endl;
        }
};

class Pedal:public Urban {
    private:
        short gears;
    public:
        Pedal(short rim_size, string manufacturer, int insurance_number, short gears):Urban(rim_size, manufacturer, insurance_number) {
            this->setGears(gears);
        }
        short getGears() {
            return gears;
        }
        void setGears(short gears) {
            this->gears = gears;
        }
        void print() {
            cout<<this->getRimSize()<<", "<<this->getManufacturer()<<", "<<this->getInsuranceNumber()<<", "<<this->getGears()<<endl;
        }
};