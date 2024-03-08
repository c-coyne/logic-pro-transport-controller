#ifndef SWITCH_H
#define SWITCH_H

class Switch {
    private:
        int id;
        int pin;
    public:
        Switch(int idValue, int pinValue);
        ~Switch();
        bool isPressed();
};

#endif // SWITCH_H