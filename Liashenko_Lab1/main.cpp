#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char applyRotor(char c, const string& rotor) {
    return rotor[c - 'A'];  
}

char reverseRotor(char c, const string& rotor) {
    return 'A' + find(rotor.begin(), rotor.end(), c) - rotor.begin();
}

string encode(const string& message, int shift, const vector<string>& rotors) {
    string result;
    for (size_t i = 0; i < message.length(); ++i) {
        char c = message[i];
        c = 'A' + (c - 'A' + shift + i) % 26;
        for (const auto& rotor : rotors) {
            c = applyRotor(c, rotor);
        }
        result += c;
    }
    return result;
}

string decode(const string& message, int shift, const vector<string>& rotors) {
    string result;
    for (size_t i = 0; i < message.length(); ++i) {
        char c = message[i];
        for (auto it = rotors.rbegin(); it != rotors.rend(); ++it) {
            c = reverseRotor(c, *it);
        }
        c = 'A' + (c - 'A' - shift - i + 26 * 100) % 26;
        result += c;
    }
    return result;
}

int main() {
    string operation;
    getline(cin, operation);

    int pseudo_random_number;
    cin >> pseudo_random_number;
    cin.ignore();

    vector<string> rotors(3);
    for (int i = 0; i < 3; i++) {
        getline(cin, rotors[i]);
    }

    string message;
    getline(cin, message);

    string result;
    if (operation == "ENCODE") {
        result = encode(message, pseudo_random_number, rotors);
    }
    else if (operation == "DECODE") {
        result = decode(message, pseudo_random_number, rotors);
    }

    cout << result << endl;

    return 0;
}