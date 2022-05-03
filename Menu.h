#ifndef MENU_H
#define MENU_H

class Menu 
{
#define DEFAULT_STATE 6
    int state = DEFAULT_STATE;
    String greet = "0 up\t1 right\t2 left\t3 down\t4 fire\t5 fire2\t7 special keys";
    String question = "Type new mapping key: ";
    char * keys;
  public:
    void processInput(String input);
    void mainMenu();
    void availSpecialKeys();
    Menu(char * keys);
};

#endif //MENU_H