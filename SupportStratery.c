#ifndef SUPPORT_STRATEGY_H
#define SUPPORT_STRATEGY_H

#include <iostream>

using namespace std;

class BaseSupportStrategy {
public:
    virtual void processResponse(int score);
    virtual ~BaseSupportStrategy() {}
};

class AdvancedCrisisManager : public BaseSupportStrategy {
public:
    void processResponse(int score) override;
};

#endif
