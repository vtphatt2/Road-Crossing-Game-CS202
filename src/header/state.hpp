#ifndef STATE_H
#define STATE_H

class State {
    public :
        virtual ~State() {};
        virtual void handleEvent() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
};

#endif