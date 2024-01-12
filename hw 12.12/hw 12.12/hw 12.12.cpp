#include "settings.h"

class Counter {
    int actual_value = 0;
    int max_value = 99999;
    int min_value = 0;
    unsigned int step = 1;

public:
    void SetAcualV(int av) {
        if (av < min_value || av > max_value) {
            throw "ERROR!";
        }
        actual_value = av;
    }
    int GetActualV() {
        return actual_value;
    }
    void SetMaxV(int mv) {
        if (mv < min_value) {
            throw "ERROR!";
        }
        max_value = mv;
    }
    int GetMaxV() {
        return max_value;
    }
    void SetMinV(int mv) {
        if (mv > max_value) {
            throw "ERROR!";
        }
        min_value = mv;
        if (actual_value < min_value) {
            actual_value = min_value;
        }
    }
    int GetMinV() {
        return min_value;
    }
    void SetStep(int s) {
        step = s;
    }
    int GetStep() {
        return step;
    }
    void VPlusStep() {
        if (actual_value + step <= max_value) {
            actual_value += step;
        }
        else {
            actual_value = min_value + (step - (max_value - actual_value) - 1);
        }
    }
    void CounterReset() {
        actual_value = min_value;
    }
};

int main()
{
    Counter c;
    cout << c.GetMinV() << "   " << c.GetMaxV() << "   " << c.GetActualV() << "   " << c.GetStep() << "\n";
    c.SetMinV(10);
    c.SetMaxV(100);
    c.SetStep(12);
    c.VPlusStep();
    c.VPlusStep();
    c.VPlusStep();
    c.VPlusStep();
    c.VPlusStep();
    c.VPlusStep();
    c.VPlusStep();
    c.VPlusStep();
    cout << c.GetMinV() << "   " << c.GetMaxV() << "   " << c.GetActualV() << "   " << c.GetStep() << "\n";
    c.CounterReset();
    cout << c.GetMinV() << "   " << c.GetMaxV() << "   " << c.GetActualV() << "   " << c.GetStep() << "\n";
}