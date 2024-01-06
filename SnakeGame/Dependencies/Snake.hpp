// Libraries:
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

// Namespaces Utilities:
using namespace std;
using namespace sf;

/// @author: R1TKILL => <antoniojunio402@gmail.com>
class Snake{

    private:

        // Attributes:
        int snakeSize = 4;
        vector<Vector2i> snakeBody{(snakeSize)};
        CircleShape snake;
        shared_ptr<ConfigWindow> cfw;
        bool up, down, left, right;

    public:

        // Constructor:
        Snake(shared_ptr<ConfigWindow> cfw, string pathTexture){ // "Dependency Injection".
            this -> cfw = cfw;
            this -> snakeBody[0] = Vector2i(6, 2);
            this -> snakeBody[1] = Vector2i(5, 2);
            this -> snakeBody[2] = Vector2i(4, 2);
            this -> snakeBody[3] = Vector2i(3, 2);
            this -> snake.setFillColor(Color::Blue);
            this -> snake.setRadius(13);
            this -> right = true;      
        }

        // Getters:
        CircleShape getSnake(){
            return this -> snake;
        }

        vector<Vector2i> getSnakeBody(){
            return this -> snakeBody;
        }

        // Methods:
        void drawSnake(){
            for(int i = 0; i < this -> snakeBody.size(); i++){
                this -> snake.setPosition(this -> snakeBody[i].x*29, this -> snakeBody[i].y*29);
                this -> cfw -> drawObjects(this -> snake);
            }
        }

        void moveSnake(){

            //Movement the body snake following the head:

            /**Logic:
             * 1 - i receive the snake body in all positions.
             * 2 - while i is greater than 0, decrement the value of i in one.
             * 3 - the snake body in i position receives this snake body in i position minus one.
             */
            for(int i = this -> snakeBody.size(); i > 0; i--){
                this -> snakeBody[i] = this -> snakeBody[i - 1];
            }

            // For continuous movement:
            if(Keyboard::isKeyPressed(Keyboard::W)){
                if(this -> down){
                    // Don't move for this direction, avoiding one collision.
                }else{
                    this -> up = true;
                    this -> down = left = right = false;
                }
            }else if(Keyboard::isKeyPressed(Keyboard::A)){
                if(this -> right){
                    // Don't move for this direction, avoiding one collision.
                }else{
                    this -> left = true;
                    this -> up = down = right = false;
                }
            }else if(Keyboard::isKeyPressed(Keyboard::S)){
                if(this -> up){
                    // Don't move for this direction, avoiding one collision.
                }else{
                    this -> down = true;
                    this -> up = left = right = false;
                }
            }else if(Keyboard::isKeyPressed(Keyboard::D)){
                if(this -> left){
                    // Don't move for this direction, avoiding one collision.
                }else{
                    this -> right = true;
                    this -> up = down = left = false;
                }            
            }

            // Collisions in wall is here:
            if(this -> up){
                if(this -> snakeBody[0].y == 0){
                    this -> snakeBody[0].y = 0;
                }else{
                    this -> snakeBody[0].y--;
                }
            }

            if(this -> left){
                if(this -> snakeBody[0].x == 0){
                    this -> snakeBody[0].x = 0;
                }else{
                    this -> snakeBody[0].x--;
                }           
            }

            if(this -> down){
                if(this -> snakeBody[0].y == (this -> cfw -> getHeight() - 30)){
                    this -> snakeBody[0].y = (this -> cfw -> getHeight() - 30);
                }else{
                    this -> snakeBody[0].y++;
                }
            }

            if(this -> right){
                if(this -> snakeBody[0].x == (this -> cfw -> getWidth() - 30)){
                    this -> snakeBody[0].x = (this -> cfw -> getWidth() - 30);
                }else{
                    this -> snakeBody[0].x++;
                }
            }

        }

        void incrementSize(){
            this -> snakeBody.push_back(snakeBody[this -> snakeSize - 1]);
            this -> snakeSize++;
        }

};