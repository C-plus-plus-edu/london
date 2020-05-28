#include <iostream>
#include <string>
#include <map>

using namespace std;

void change_capital(map<string, string>& world, const string& country, const string& new_capital) {
	if (world[country].size() == 0) {
		world[country] = new_capital;
		cout << "Introduce new country " << country << " with capital " << new_capital << endl;
	} else if (world[country] == new_capital) {
		cout << "Country " << country << " hasn't changed its capital" << endl;
	} else {
		string old_capital = world[country];
		world[country] = new_capital;
		cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
	}
}

void rename_country(map<string, string>& world, const string& old_country_name, const string& new_country_name) {
	if (world[old_country_name].size() == 0) {
		cout << "Incorrect rename, skip" << endl;
		world.erase(old_country_name);
	} else if (world[old_country_name] == new_country_name) {
		cout << "Incorrect rename, skip" << endl;
	} else if (world[new_country_name].size() == 0 && world[old_country_name].size() != 0) {
		string capital = world[old_country_name];
		world.erase(old_country_name);
		world[new_country_name] = capital;
		cout << "Country " << old_country_name << " with capital " << capital << " has been renamed to " << new_country_name << endl;
	} else {
		cout << "Incorrect rename, skip" << endl;
	}
}

void about_country(map<string, string>& world, const string& country) {
	if (world[country].size() == 0) {
		cout << "Country " << country << " doesn't exist" << endl;
		world.erase(country);
	} else {
		cout << "Country " << country << " has capital " << world[country] << endl;
	}
}

void print_capitals(map<string, string>& world) {
	if (world.size() == 0) {
		cout << "There are no countries in the world";
	} else {
		for (auto x : world) {
			cout << x.first << "/" << x.second << " ";
		}
	}
	cout << endl;
}

int main() {
	map<string, string> world;
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string cmd;
		cin >> cmd;
		if (cmd == "CHANGE_CAPITAL") {
			string country, new_capital;
			cin >> country >> new_capital;
			change_capital(world, country, new_capital);
		} else if (cmd == "RENAME") {
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;
			rename_country(world, old_country_name, new_country_name);
		} else if (cmd == "ABOUT") {
			string country;
			cin >> country;
			about_country(world, country);
		} else if (cmd == "DUMP") {
			print_capitals(world);
		}
	}
	return 0;
}
