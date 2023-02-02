#include <iostream>
#include <fstream>
#include <string>

#define EXT ".txt"

using namespace std;

template <typename T>
class proccess {
private:
	T password;
	T username;

public:
	void init_proccess(int option) {
		if (option == 1) {
			fstream file;
			string content(password);

			file.open("Database/" + username + EXT, ios_base::app);

			if (file.is_open()) {
				file.write(content.data(), content.size());
			}

			file.close();
		}

		else {
			ifstream new_file("Database/" + username + EXT);

			if (new_file.good()) {
				string content;

				getline(new_file, content);

				if (content == password) {
					cout << "\n> Hello " << username << "!" << endl;
				}
				else {
					cout << "\n> Incorrect password" << endl;
				}

				new_file.close();
			}
			else {
				cout << "\n> Error trying to find user" << endl;
			}
		}
	}

	proccess(T n_password, T n_username) {
		this->password = n_password;
		this->username = n_username;
	}
};

int main(int argc, char* argv[]) {
	string username;
	string password;
	int option;

	cout << "1 - Login\n2 - Sign up\n> Option : ";
	cin >> option;

	cout << "\n> Username : ";
	cin >> username;

	cout << "> Password : ";
	cin >> password;

	proccess<string> my_proccess(password, username);
	my_proccess.init_proccess(option);

	return 0;
}