// Libraries:
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

// Namespaces Utilities:
using namespace std;
using namespace sf;

/// @author: R1TKILL => <antoniojunio402@gmail.com>
class ConfigWindow{

    private:

        // Attributes:
        int width;
        int height;
        string title;

        Uint32 style;
        ContextSettings settings;
        shared_ptr<RenderWindow> window;

    public:

        // Constructors: 
        ConfigWindow(int width, int height, string title){
            this -> width = width;
            this -> height = height;
            this -> title = title;
        }

        // Getters:
        int getWidth(){
            return (this -> width - 30);
        }

        int getHeight(){
            return (this -> height - 30);
        }

        string getTitle(){
            return this -> title;
        }

        shared_ptr<RenderWindow> getWindow(){
            return this -> window;
        }

        // Methods: 
        void createWindow(){
            this -> window = make_shared<RenderWindow>(VideoMode(this -> width, this -> height), this -> title, this -> style, this -> settings);
            this -> window -> setFramerateLimit(4); 
            this -> window -> setPosition(Vector2(250, 120));
        }

        Uint32 styleWindow(){
            this -> style = Style::Default;
            return style;
        }

        ContextSettings configsWindow(){
            this -> settings.depthBits = 24; 
            this -> settings.antialiasingLevel = 16; 
            this -> settings.stencilBits = 16;  
            return this -> settings; 
        }

        void drawObjects(CircleShape sprite){
            this -> window -> draw(sprite);
        }

};