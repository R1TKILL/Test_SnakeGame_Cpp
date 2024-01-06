// Libraries:
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <vector>

// Namespaces Utilities:
using namespace std;
using namespace sf;

/// @author: R1TKILL => <antoniojunio402@gmail.com>
class Fruit{

    private:

        // Attributes:
        Texture fruitTexture;
        CircleShape fruit; 
        Vector2i fruit_pos;
        shared_ptr<ConfigWindow> cfw;

    public:

        // Constructor:
        Fruit(shared_ptr<ConfigWindow> cfw, string pathTexture){
            this -> cfw = cfw;
            this-> fruitTexture.loadFromFile(pathTexture);
            this -> fruit.setTexture(&this -> fruitTexture);
            this -> fruit.setRadius(13);
            
            srand(time(NULL));
            this -> fruit_pos.x = rand() % this -> cfw -> getWidth();
            this -> fruit_pos.y = rand() % this -> cfw -> getHeight();
            this -> fruit.setPosition(this -> fruit_pos.x, this -> fruit_pos.y);
        }

        // Getters:
        CircleShape getFruit(){
            return this -> fruit;
        }

        // Methods:
        void drawFruit(){
            this -> cfw -> drawObjects(this -> fruit);
        }

        void checkCollision(shared_ptr<Snake> snake){

            // Corrigir essa lógica, era pra ser só na posição 0, coloquei no corpo todo kkk.        
            if(abs(snake -> getSnake().getPosition().x - fruit.getPosition().x) + abs(
                snake -> getSnake().getPosition().y - fruit.getPosition().y) <= 25){

                // Create new part in snake body:
                snake -> incrementSize();

                //Generate fruit in new random position:
                srand(time(NULL));
                this -> fruit_pos.x = rand() % this -> cfw -> getWidth();
                this -> fruit_pos.y = rand() % this -> cfw -> getHeight();
                this -> fruit.setPosition(this -> fruit_pos.x, this -> fruit_pos.y);
            }
            
        }

};