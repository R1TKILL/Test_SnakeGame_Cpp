// Libraries:
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>
#include "Dependencies/ConfigWindow.hpp"
#include "Dependencies/Snake.hpp"
#include "Dependencies/Fruit.hpp"

// Namespaces Utilities:
using namespace std;
using namespace sf;

// Function Prototypes:
void mainLoop(shared_ptr<ConfigWindow> objWindow, shared_ptr<Snake> objSnake, shared_ptr<Fruit> objFruit);

/// @author: R1TKILL => <antoniojunio402@gmail.com>
int main(int argc, char **argv){

    // Variables:
    string fruitTexture = "./images/apple.png";
    string snakeTexture = "./images/snake.png";

    // Objects:
    shared_ptr<ConfigWindow> objWindow(new ConfigWindow(840, 480, "Snake Game"));
    shared_ptr<Snake> objSnake(new Snake(objWindow, snakeTexture));
    shared_ptr<Fruit> objFruit(new Fruit(objWindow, fruitTexture));

    mainLoop(objWindow, objSnake, objFruit);
    
    return 0;

}

void mainLoop(shared_ptr<ConfigWindow> objWindow, shared_ptr<Snake> objSnake, shared_ptr<Fruit> objFruit){

    // Variables:
    Event event;

    objWindow -> styleWindow();
    objWindow -> configsWindow();
    objWindow -> createWindow();
       
    while (objWindow -> getWindow() -> isOpen()){

        while (objWindow -> getWindow() -> pollEvent(event)){

            if(event.type == Event::Closed){
                objWindow -> getWindow() -> close();
            }
            
        }
      
        objWindow -> getWindow() -> clear();

        objSnake -> moveSnake();
        objSnake -> drawSnake();

        objFruit -> checkCollision(objSnake);
        objFruit -> drawFruit();

        objWindow -> getWindow() -> display();

    }
}