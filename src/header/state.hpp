#ifndef STATE_HPP
#define STATE_HPP

class State {
    public :
        virtual ~State() {};
        virtual void handleEvent() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
};

#endif