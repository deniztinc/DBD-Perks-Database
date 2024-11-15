# DBD-Perks-Database

This project is a C++ application that implements a database system to manage a tiered perk list from the game Dead by Daylight with attributes like name, type, and tier. Here’s a breakdown of the main components and functions:


Classes and Structures:

* Database: Manages an array of perk records, with features for resizing, reading, appending, and printing records.
* Perk: Represents an individual record with name, type, and tier attributes.
* Menu: Provides an interface for user interactions, enabling record searches, additions, deletions, and listings.


Key Functionalities:

* Database Initialization and File Handling: The database reads records from a text file (database.txt) each time it's opened, using the readThis() function to populate perk data.
* Adding New Records: Users can add new perks with unique name, type, and tier
