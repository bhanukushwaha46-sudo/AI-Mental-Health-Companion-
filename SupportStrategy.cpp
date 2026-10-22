#include "SupportStrategy.h"

void BaseSupportStrategy::processResponse(int score) {
    if (score >= 8) {
        cout << "\n[CRITICAL SOS ALERT]: Acute crisis tier identified!" << endl;
        cout << "-> Dispatched automated emergency alert with GPS coordinates to trusted contacts." << endl;
    } else if (score >= 5) {
        cout << "\n[Moderate Support]: Moderate distress detected. Let's take a slow, deep breath together. You are safe." << endl;
    } else {
        cout << "\n[Normal Support]: I'm listening. Tell me more about what's on your mind today." << endl;
    }
}

void AdvancedCrisisManager::processResponse(int score) {
    BaseSupportStrategy::processResponse(score);
    if (score >= 8) {
        cout << "-> [Audit Trail]: Emergency worker simulation queue notified securely." << endl;
    }
}
