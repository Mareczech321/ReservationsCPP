# Room Reservation System

## Overview
Basically just manual import from the python version!

The Room Reservation System is a C++-based application that allows users to:
- Add room reservations for specific dates and time slots.
- View all existing reservations.
- Cancel a reservation by providing its ID.

The system ensures that reservations are validated and conflict-free.

---

## Features
1. **Add Reservation**: 
   - Users can book a room by entering their name, the room name, date, and time slot.
   - The system validates the reservation to ensure:
     - The date is in the future.
     - The time slot is valid (start time is before end time).
     - The room is available during the specified time slot.

2. **Show Reservations**:
   - Displays a list of all reservations with details such as ID, room name, date, time, and the person who booked it.
   - Each reservation is shown with its reservation ID.

3. **Cancel Reservation**:
   - Users can cancel a reservation by entering its reservation ID.
   - Before prompting for an ID, the system displays all available reservation IDs along with their details for easy reference.

4. **Exit**:
   - Allows users to exit the application safely.

---

## How to Run

### Prerequisites
- A C++ compiler (e.g., GCC, Clang) installed on your system, or a Windows environment to run the precompiled `.exe` file.

### Files
1. `main.cpp`: The main script containing the application logic.
2. `user.cpp`: A simple module to represent the user making a reservation.
3. `Reservation - from py.exe`: The precompiled executable file for Windows (if you prefer not to compile the code yourself).

### Steps
1. **Option 1: Run the Executable (.exe) File (Recommended for Windows Users)**
   - Download the `Reservation - from py.exe` file from the repository.
   - Open a terminal (Command Prompt or PowerShell) and navigate to the directory where the `.exe` file is located.
   - Run the executable by typing:
     ```bash
     Reservation - from py.exe
     ```

2. **Option 2: Compile and Run the Source Code
If you'd like to compile the source code yourself, follow these steps:

**Option 2A: Compile and Run on Linux/macOS

   -Open a terminal and navigate to the project directory.
   -Compile the C++ code using the g++ compiler:
   ```bash
   g++ main.cpp user.cpp -o room_reservation_system
   ```
   Run the compiled application:
   ```bash
   ./room_reservation_system
   ```

**Option 2B: Compile and Run on Windows

   -Open Developer Command Prompt for Visual Studio (available after you install Visual Studio).
   -Navigate to the project folder.
   -Compile the code using the cl compiler:
   ```bash
   cl main.cpp user.cpp
   ```
This will generate the room_reservation_system.exe file in your project folder.

**Option 3: Import the Project into Visual Studio 2022
If you prefer to work in Visual Studio 2022, you can import the project and build it within the IDE.

   -Download the Project:

   -Clone or download the repository from GitHub.
   -Open Visual ###Studio 2022:

   -Launch Visual Studio 2022.
###Import the Project:

   -Click on Open a project or solution.
   -Navigate to the folder where you downloaded the repository.
   -Select the main.cpp or any of the source files you want to import.
   -Create a New Project (Optional):

   -Alternatively, you can create a new project in Visual Studio:
   -Choose File > New > Project.
   -Select the Console App template under C++.
   -Name your project and set its location.
   -Add the existing main.cpp and user.cpp files to your new project by right-clicking Source Files in Solution Explorer, selecting Add > Existing Item, and choosing the .cpp files.
   -Build and Run the Project:

   After importing or creating a project, click Build > Build Solution to compile the code.
   Once the build is successful, click Debug > Start Without Debugging (or press Ctrl + F5) to run the project.


---

## Usage

### Menu Options
1. **Add Reservation**:
   - Enter your name, room name, date (in YYYY-MM-DD format), start time, and end time (in HH:MM format).
   - The system will confirm if the reservation was successful or display an error message if the room is already booked, the time range is invalid, or the date is not in the future.
   
2. **Show Reservations**:
   - Displays all reservations sorted by date.
   
3. **Cancel Reservation**:
   - The system shows all existing reservation IDs.
   - Enter a valid ID to cancel the corresponding reservation.
   
4. **Exit**:
   - Terminates the program.

---

## Notes
- Reservations are stored in memory during the runtime of the program.
- The reservation IDs are randomly generated, ensuring each reservation has a unique identifier.
- The system ensures that room bookings do not overlap in terms of time and date.
