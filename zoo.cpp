#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Forward declaration of ZooManager
class ZooManager;  

// Animal Class
class Animal {
private:
    string name;
    string species;
    int age;
    string diet;
    string feedingTime;

public:
    Animal(string n, string s, int a, string d, string f)
        : name(n), species(s), age(a), diet(d), feedingTime(f) {}

    // Friend function declaration
    friend void changeAnimalName(Animal &animal, const string &newName);

    void displayDetails() const {
        cout << "Name: " << name << "\nSpecies: " << species
             << "\nAge: " << age << "\nDiet: " << diet
             << "\nFeeding Time: " << feedingTime << endl;
    }

    string getName() const { return name; }
    string getSpecies() const { return species; }
    int getAge() const { return age; }
    string getDiet() const { return diet; }
    string getFeedingTime() const { return feedingTime; }
};

// Friend function definition
void changeAnimalName(Animal &animal, const string &newName) {
    animal.name = newName;  // Directly modify the private member 'name'
}

// Habitat Class
class Habitat {
private:
    int habitatID;
    string type;
    double ticketPrice;
    vector<Animal> animals;

public:
    Habitat(int id, string t, double price)
        : habitatID(id), type(t), ticketPrice(price) {}

    void viewHabitatDetails() const {
        cout << "\nHabitat ID: " << habitatID << ", Type: " << type
             << ", Ticket Price: $" << ticketPrice << endl;
    }

    void addAnimal(const Animal &animal) {
        animals.push_back(animal);
    }

    vector<Animal> getAnimals() const {
        return animals;
    }

    int getHabitatID() const { return habitatID; }
    double getTicketPrice() const { return ticketPrice; }
};

// Ticket Class
class Ticket {
private:
    int ticketID;
    string visitorName;
    string visitDate;
    double ticketPrice;

public:
    Ticket(int id, string name, string date, double price)
        : ticketID(id), visitorName(name), visitDate(date), ticketPrice(price) {}

    void viewTicketDetails() const {
        cout << "\nTicket ID: " << ticketID << ", Visitor Name: " << visitorName
             << ", Visit Date: " << visitDate << ", Ticket Price: $" << ticketPrice << endl;
    }
};

// ZooManager Class
class ZooManager {
private:
    string zooName;
    string location;
    vector<Habitat> habitats;
    vector<Ticket> tickets;

public:
    ZooManager(string name, string loc)
        : zooName(name), location(loc) {}

    void addHabitat(const Habitat &habitat) {
        habitats.push_back(habitat);
    }

    void displayHabitats() const {
        cout << "\nAvailable Habitats:\n";
        for (const auto &habitat : habitats) {
            habitat.viewHabitatDetails();
        }
    }

    const Habitat* findHabitatByID(int id) const {
        for (const auto &habitat : habitats) {
            if (habitat.getHabitatID() == id) {
                return &habitat;
            }
        }
        return nullptr;
    }

    void issueTicketForHabitat(int habitatID, int ticketID, const string &visitorName, const string &visitDate) {
        const Habitat *habitat = findHabitatByID(habitatID);
        if (habitat) {
            Ticket ticket(ticketID, visitorName, visitDate, habitat->getTicketPrice());
            tickets.push_back(ticket);
            cout << "\nTicket issued successfully for " << visitorName
                 << " to Habitat ID " << habitatID
                 << " at price $" << habitat->getTicketPrice() << endl;
        } else {
            cout << "\nHabitat not found!" << endl;
        }
    }

    void viewZooDetails() const {
        cout << "\nZoo Name: " << zooName << ", Location: " << location << endl;
        cout << "\nTickets issued:" << endl;
        for (const auto &ticket : tickets) {
            ticket.viewTicketDetails();
        }
    }
};

int main() {
    ZooManager zoo("Virtual Zoo", "Online");

    // Predefined habitats
    Habitat aquatic(1, "Aquatic", 15.0);
    Habitat terrestrial(2, "Terrestrial", 10.0);
    Habitat aviary(3, "Aviary", 12.0);
    Habitat reptilian(4, "Reptilian", 8.0);
    Habitat nocturnal(5, "Nocturnal", 20.0);

    // Add animals to habitats
    aquatic.addAnimal(Animal("Shark", "Fish", 5, "Carnivore", "12:00 PM"));
    terrestrial.addAnimal(Animal("Lion", "Mammal", 8, "Carnivore", "10:00 AM"));
    aviary.addAnimal(Animal("Parrot", "Bird", 2, "Omnivore", "9:00 AM"));

    // Add habitats to the zoo
    zoo.addHabitat(aquatic);
    zoo.addHabitat(terrestrial);
    zoo.addHabitat(aviary);

    // Step 1: Ask for Ticket ID, Visitor Name, and Visit Date
    int ticketID;
    string visitorName, visitDate;
    cout << "Enter Ticket ID: ";
    cin >> ticketID;
    cin.ignore();
    cout << "Enter Visitor Name: ";
    getline(cin, visitorName);
    cout << "Enter Visit Date (YYYY-MM-DD): ";
    getline(cin, visitDate);

    // Step 2: Display habitats
    zoo.displayHabitats();

    // Step 3: User selects a habitat
    int habitatID;
    cout << "\nSelect a habitat by entering its ID: ";
    cin >> habitatID;

    const Habitat *selectedHabitat = zoo.findHabitatByID(habitatID);
    if (selectedHabitat) {
        selectedHabitat->viewHabitatDetails();

        // Show list of animals in the selected habitat
        vector<Animal> animals = selectedHabitat->getAnimals();
        cout << "\nAnimals in this habitat:\n";
        for (int i = 0; i < animals.size(); ++i) {
            cout << i + 1 << ". " << animals[i].getName() << endl;
        }

        // Step 4: User selects an animal
        int animalChoice;
        cout << "\nSelect an animal by entering its number: ";
        cin >> animalChoice;

        if (animalChoice > 0 && animalChoice <= animals.size()) {
            cout << "\nYou selected " << animals[animalChoice - 1].getName() << "!\n";
            animals[animalChoice - 1].displayDetails();
        } else {
            cout << "Invalid animal choice." << endl;
            return 1;
        }

        // Issue the ticket
        zoo.issueTicketForHabitat(habitatID, ticketID, visitorName, visitDate);
    } else {
        cout << "Invalid habitat ID." << endl;
        return 1;
    }

    // Step 5: View the issued tickets
    zoo.viewZooDetails();

    return 0;
}