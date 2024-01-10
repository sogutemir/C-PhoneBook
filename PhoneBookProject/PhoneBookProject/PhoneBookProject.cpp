#include <iostream>
#include <map>
#include <string>
#include <iterator>

class Phonebook {
private:
    std::map<std::string, std::string> contacts;

public:
    void insert(const std::string& name, const std::string& number) {
        auto result = contacts.insert({ name, number });
        if (result.second) {
            std::cout << name << " added to the directory." << std::endl;
        }
        else {
            std::cout << name << " already in the directory." << std::endl;
        }
    }

    void updateNumber(const std::string& name, const std::string& newNumber) {
        auto it = contacts.find(name);
        if (it != contacts.end()) {
            it->second = newNumber;
            std::cout << name << " phone number has been updated: " << newNumber << std::endl;
        }
        else {
            std::cout << name << " could not be updated because it could not be found in the directory. " << std::endl;
        }
    }

    void searchByName(const std::string& name) const {
        auto it = contacts.find(name);
        if (it != contacts.end()) {
            std::cout << name << " for the phone number: " << it->second << std::endl;
        }
        else {
            std::cout << name << " not found in the directory." << std::endl;
        }
    }

    void listPersonCount() const {
        std::cout << "Number of people in the directory: " << contacts.size() << std::endl;
    }

    void listAll() const {
        for (const auto& contact : contacts) {
            std::cout << "It's called: " << contact.first << " - Number: " << contact.second << std::endl;
        }
    }

    void listCount() const {
        std::cout << "Total number of people in the directory: " << contacts.size() << std::endl;
    }

    void listInRange(const std::string& start, const std::string& end) const {
        auto itLow = contacts.lower_bound(start);
        auto itHigh = contacts.upper_bound(end);

        for (auto it = itLow; it != itHigh; ++it) {
            std::cout << "It's called: " << it->first << " - Number: " << it->second << std::endl;
        }
    }

    void remove(const std::string& name) {
        auto it = contacts.find(name);
        if (it != contacts.end()) {
            contacts.erase(it);
            std::cout << name << " deleted from the contacts." << std::endl;
        }
        else {
            std::cout << name << " not found in the directory." << std::endl;
        }
    }
};

int main() {
    Phonebook phonebook;

    // Adding contacts to contacts
    phonebook.insert("Zeynep Bayrak", "+905553216789");
    phonebook.insert("Mehmet Gündüz", "+905558765432");

    // Adding contacts to contacts
    phonebook.insert("Ahmet Yılmaz", "+905551234567");
    phonebook.insert("Elif Korkmaz", "+905559876543");

    // Updating a contact's phone number
    phonebook.updateNumber("Ahmet Yılmaz", "+905553213214");

    // Trying to update the number of a person who has not been updated
    phonebook.updateNumber("Mehmet Gündüz", "+905550987654");


    // Delete a contact from the contacts
    phonebook.remove("Elif Korkmaz");
    // Do not try to delete the deleted person again
    phonebook.remove("Elif Korkmaz");

    // List the number of contacts in the directory
    phonebook.listPersonCount();

    // List all directories in alphabetical order
    phonebook.listAll();

    // List the number of contacts in the directory
    phonebook.listCount();

    return 0;
}
