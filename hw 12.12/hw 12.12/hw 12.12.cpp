#include "settings.h"

class Counter {
    int actual_value = 0;
    int max_value = 99999;
    int min_value = 0;
    unsigned int step = 1;

public:
    void SetAcualV(int actual_value) {
        if (actual_value < min_value || actual_value > max_value) {
            throw "ERROR!";
        }
        this->actual_value = actual_value;
    }
    int GetActualV() const {
        return actual_value;
    }
    void SetMaxV(int max_value) {
        if (max_value < min_value) {
            throw "ERROR!";
        }
        this->max_value = max_value;
    }
    int GetMaxV() const {
        return max_value;
    }
    void SetMinV(int min_value) {
        if (min_value > max_value) {
            throw "ERROR!";
        }
        this->min_value = min_value;
        if (actual_value < this->min_value) {
            actual_value = this->min_value;
        }
    }
    int GetMinV() const {
        return min_value;
    }
    void SetStep(int step) {
        this->step = step;
    }
    int GetStep() const {
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
