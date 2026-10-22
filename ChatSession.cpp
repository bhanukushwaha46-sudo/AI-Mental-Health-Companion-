#include "ChatSession.h"
#include <ctime>

ChatSession::ChatSession(string input, int score) {
    userInput = input;
    distressScore = score;
    time_t now = time(0);
    timestamp = ctime(&now);
}

void ChatSession::displayLog() const {
    cout << "[Log Record] Input: \"" << userInput 
             << "\" | Evaluated Distress Score: " << distressScore << "/10" << endl;
}
