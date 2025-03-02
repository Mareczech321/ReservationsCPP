# Room Reservation System

## Overview
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

4. **Error Handling**:
   - Ensures input is valid (e.g., correct date and time formats, valid reservation IDs).
   - Provides user-friendly error messages for invalid operations, such as entering invalid dates or times.

5. **Exit**:
   - Allows users to exit the application safely.

---

## How to Run

### Prerequisites
- A C++ compiler (e.g., GCC, Clang) installed on your system, or a Windows environment to run the precompiled `.exe` file.

### Files
1. `main.cpp`: The main script containing the application logic.
2. `user.cpp`: A simple module to represent the user making a reservation.
3. `reservations.exe`: The precompiled executable file for Windows (if you prefer not to compile the code yourself).

### Steps
1. **Option 1: Run the Executable (.exe) File (Recommended for Windows Users)**
   - Download the `reservations.exe` file from the repository.
   - Open a terminal (Command Prompt or PowerShell) and navigate to the directory where the `.exe` file is located.
   - Run the executable by typing:
     ```bash
     reservations.exe
     ```

2. **Option 2: Compile and Run the Source Code**
   - If you'd like to compile the source code yourself, follow these steps:
     - Open a terminal or command prompt and navigate to the project directory.
     - Compile the C++ code using a C++ compiler:
       ```bash
       g++ main.cpp -o reservations
       ```
     - Run the compiled application:
       ```bash
       ./reservations
       ```

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
