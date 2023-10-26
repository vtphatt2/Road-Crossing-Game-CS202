class Game {
    public :
        Game();
        void run();

    protected :
        int level;
        int score;
        int highScore;

    private :         
        int widthWindow;
        int heightWindow;
};