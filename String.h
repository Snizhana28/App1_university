#include <iostream>
#include <sstream>

using namespace std;

class String {
private:
    string str;

public:
    String(const string& initialStr) : str(initialStr) {}
    void printFormat() const {
        cout << "String: " << str << "\n";
    }
    String& operator=(const String& other) {
        if (this != &other) {
			str = other.str;
		}
		return *this;
	}
    String& operator+=(const String& other) {
		str += other.str;
		return *this;
	}
    String operator+(const String& other) const {
		String result = *this;
		result += other;
		return result;
	}
    bool operator==(const String& other) const {
		return str == other.str;
	}
    bool operator!=(const String& other) const {
		return !(*this == other);
	}
    operator string() const {
		return str;
	}
	template <typename T>
	T toNumber() const {
		stringstream ss(str);
		T result;
		ss >> result;
		return result;
	}

};