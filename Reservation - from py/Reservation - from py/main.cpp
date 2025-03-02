#include <iostream>
#include <vector>
#include "./user.cpp"
#include <ctime>
#include <cstdio>
#include <stdexcept>

using namespace std;

struct Reservation { //similiar to python's dictionary
	string user;
	string room_name;
	string date;
	string start_time;
	string end_time;
	int reservation_id;
};

vector<Reservation> reservations;

int reservation_size = 0;
User user("", 0);
string room_name, date, start, end_time;
int reservation_id;
string separator = "-------------------";
int user_input;

bool while_true = true;

int temp;

bool occupied_Room(string room_name, string date, string start, string end);
bool is_future_date(string date);
bool is_valid_time_range(string start, string end);
void add_reservation(string user, string room_name, string date, string start, string end, int id);
void show_reservations();
void cancel_reservation(int reservation_id);

time_t conversion_To_Epoch(string date);
time_t conversion_To_Time(string time);

void input();
void menu();

int main() {

	while (while_true) {
		menu();
	}

	return 0;
}

bool occupied_Room(string room_name, string date, string start, string end) {
	for (const auto& res : reservations) {
		if (res.room_name == room_name && res.date == date &&
			!(end <= res.start_time || start >= res.end_time)) {
			return false;
		}
	}
	return true;
}

bool is_future_date(string date) {
	time_t now = time(0);
	tm currentTime;
	localtime_s(&currentTime, &now);

	currentTime.tm_hour = 0;
	currentTime.tm_min = 0;
	currentTime.tm_sec = 0;

	time_t today = mktime(&currentTime);
	time_t userTime = conversion_To_Epoch(date);

	return userTime > today;
}

bool is_valid_time_range(string start, string end) {

	time_t start_time = conversion_To_Time(start);
	time_t end_time = conversion_To_Time(end);

	return start_time < end_time;
}

void menu() {
	do {
		cout << separator << "\nMenu:\n" << separator << "\n[1] Add reservation\n[2] Show reservation\n[3] Cancel reservation\n[4] Exit\n> ";
		cin >> user_input;
	} while (user_input <= 0 || user_input > 4);
	input();
}

void input() {
	switch (user_input) {
	case 1:
		try {
			cin.ignore();
			cout << "Enter your name:\n> ";
			getline(cin, user.name);

			cout << "Enter your age:\n> ";
			cin >> user.age;
			if (cin.fail() || user.age <= 0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw "Invalid age. Please enter a positive number!";
			}
			cin.ignore();

			cout << "Enter room name:\n> ";
			getline(cin, room_name);

			cout << "Enter date (YYYY-MM-DD):\n> ";
			cin >> date;

			cout << "Enter start time (HH:MM):\n> ";
			cin >> start;
			cout << "Enter end time (HH:MM):\n> ";
			cin >> end_time;
		}
		catch (const char* e) {
			cout << "Error: " << e << "\nPlease try again.\n";
		}

		srand(time(0));
		reservation_id = rand() % 10000 + 1;

		add_reservation(user.name, room_name, date, start, end_time, reservation_id); break;
	case 2:
		show_reservations(); break;
	case 3:
		if (reservation_size != 0) {
			cout << "Available reservation IDs:" << endl;
			for (const auto& res : reservations) {
				cout << "{ID: " << res.reservation_id << ", Room: " << res.room_name << ", Date: " << res.date << "}" << endl;
			}
			cout << "Enter reservation ID to cancel:\n> "; cin >> temp;
			cancel_reservation(temp);
		}
		else {
			cout << "No reservations found to cancel!" << endl;
		}break;
	case 4:
		cout << "Exiting the system. Goodbye!";
		while_true = false;
		break;
	}
}

time_t conversion_To_Epoch(string date) {
	tm t = {};

	if (sscanf_s(date.c_str(), "%d-%d-%d", &t.tm_year, &t.tm_mon, &t.tm_mday) != 3) {
		throw runtime_error("Invalid date format. Use YYYY-MM-DD.");
	}

	t.tm_year -= 1900;
	t.tm_mon -= 1;
	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;

	time_t userTime = mktime(&t);

	return userTime;
}

time_t conversion_To_Time(string time) {
	tm t = {};

	if (sscanf_s(time.c_str(), "%d:%d", &t.tm_hour, &t.tm_min) != 2) {
		throw runtime_error("Invalid time format. Use HH:MM.");
	}

	t.tm_year = 70; // Any non-leap year
	t.tm_mon = 0;
	t.tm_mday = 1;
	t.tm_sec = 0;

	time_t userTime = mktime(&t);

	return userTime;
}

void add_reservation(string user, string room_name, string date, string start, string end, int id) {
	if (!is_future_date(date)) {
		cout << "Error: The date must be in the future!" << endl;
		return;
	}
	if (!is_valid_time_range(start, end)) {
		cout << "Error: Invalid time range! Start time must be before end time!" << endl;
		return;
	}
	if (!occupied_Room(room_name, date, start, end)) {
		cout << "Error: The room is already reserved for the selected time!" << endl;
		return;
	}

	reservations.push_back({ user, room_name, date, start, end, reservation_id });
	cout << "Reservation added successfully! Reservation ID: " << reservation_id << endl;
	reservation_size += 1;
}

void show_reservations() {

	if (reservations.size() == 0) {
		cout << "No reservation found!" << endl;
	}

	for (const auto& res : reservations) {
		cout << "{ID: " << res.reservation_id << ", reserved by " << res.user << ", Room: " << res.room_name << ", Date: " << res.date << ", Time: " << res.start_time << "-" << res.end_time << "}" << endl;
	}
}

void cancel_reservation(int reservation_id) {
	for (int i = 0; i < reservations.size(); i++) {
		if (reservations[i].reservation_id == reservation_id) {
			reservations.erase(reservations.begin() + i);
			cout << "Reservation with ID: " << reservation_id << " has been cancelled!" << endl;
			reservation_size -= 1;
			return;
		}
	}
	cout << "Reservation with ID: " << reservation_id << " was not found!" << endl;
}