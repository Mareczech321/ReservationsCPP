#include <string>

class User {
	public:
		std::string name;
		int age;
		User(std::string x, int y) {
			name = x;
			age = y;
		}
};