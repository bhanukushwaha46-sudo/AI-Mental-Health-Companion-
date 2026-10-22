#ifndef CHAT_SESSION_H
#define CHAT_SESSION_H

#include <string>
#include <iostream>

using namespace std;

class ChatSession {
private:
    string userInput;
    int distressScore;
    string timestamp;

public:
    ChatSession(string input, int score); // Must match .cpp parameters exactly
    void displayLog() const;
};

#endif
