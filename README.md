****Zoo Management System****
This is a C++ console-based application that simulates a Zoo Management System. The system allows users to manage zoo habitats, animals, and ticket issuance interactively.

Features
Manage Animals: Add animals to specific habitats and view their details.
Habitat Management: Manage different habitats with unique types and ticket prices.
Ticket Issuance: Issue tickets to visitors for specific habitats and view ticket details.
Interactive User Interface: Users can select habitats and animals and view detailed information.
How It Works
The zoo contains predefined habitats (e.g., Aquatic, Terrestrial, Aviary).
Each habitat has specific animals added to it.
The user can:
View available habitats.
Select a habitat and see the animals within it.
Select an animal to view its details.
Issue a ticket for visiting the selected habitat.
All issued tickets are stored and can be viewed.
Classes Used
Animal:
Stores animal details such as name, species, age, diet, and feeding time.
Includes a friend function to modify the animal's name.
Habitat:
Manages a list of animals, habitat ID, type, and ticket price.
Ticket:
Stores details of issued tickets, including ticket ID, visitor name, date, and price.
ZooManager:
Handles the entire zoo system, including habitats, tickets, and overall management.
Prerequisites
A C++ compiler (e.g., g++) to compile and run the code.
How to Run
Compile the code using the following command:

g++ -o zoo_management_system main.cpp


Run the compiled executable:

./zoo_management_system


Follow the on-screen instructions to interact with the system.

Future Improvements
Add dynamic input for habitats and animals.
Implement file handling to save and load zoo data.
Enhance the ticketing system to support multiple ticket types.
Add graphical elements using libraries like SFML or SDL.
License
This project is released under the MIT License. Feel free to use and modify it for educational purposes.
