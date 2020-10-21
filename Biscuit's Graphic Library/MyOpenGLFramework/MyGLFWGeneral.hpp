#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <cmath>

//  OpenGL LIBRARIES
#include <GLFW/glfw3.h>

//  EXTRA LIBRARIES
#include "MyGLFWVector.hpp"

namespace MyGLFW {

    class MyGLFWError : public std::runtime_error {
        public:
        MyGLFWError (const std::string& what_arg, int line, std::string pretty_function) :
            std::runtime_error (what_arg + "\nLine: " + std::to_string (line) +
                                "\nFunction: " + pretty_function)
                                {}
    };

    #define THROW(msg) throw MyGLFWError (msg, __LINE__, __PRETTY_FUNCTION__);

    class Color {
        public:
        //  RGB == Red, Green, Blue 
        float r = 0.f, g = 0.f, b = 0.f;
            Color (float newR, float newG, float newB):
                r (newR),
                g (newG),
                b (newB),
                isSet_ (true)
                {}
            Color (Vector3f vec):
                Color (vec.x, vec.y, vec.z)
                {}
            Color ():
                r (0.f),
                g (0.f),
                b (0.f),
                isSet_ (false)
                {}
        private:
            bool isSet_ = false;
    };

    //  Базовые цвета
    namespace BColor {
        Color RED   = {1, 0, 0};
        Color GREEN = {0, 1, 0};
        Color BLUE  = {0, 0, 1};
        Color WHITE = {1, 1, 1};
        Color BLACK = {0, 0, 0};    
    }
    
    class Drawable {
        public:
            virtual void Draw () const = 0;
    };

    class Window {
        public:
            Window (const Vector2i& size, std::string title):
                initValue_ (glfwInit ()),
                window_ (glfwCreateWindow (size.x, size.y, title.c_str(), nullptr, nullptr)),
                drawables ({})
                {
                    if (initValue_ == GLFW_FALSE || window_ == GLFW_FALSE) {
                        THROW ("Error opening window!");
                    }
                    glfwMakeContextCurrent(window_);
                }
            Window (const Vector2i& size):
                Window (size, "SampleText")
                {}
            Window (std::string title):
                Window ({640, 480}, title)
                {}
            Window ():
                Window ({640, 480}, "SampleText")
                {}
            ~Window () {
                glfwDestroyWindow (window_);
                glfwTerminate ();
            }
            //  Возвращает размер области для рисования, а не самого окна
            Vector2i GetSize () const {
                Vector2i ans = {};
                //!  TODO
                //glfwGetWindowSize (window_, &ans.x, &ans.y);
                glfwGetFramebufferSize (window_, &ans.x, &ans.y);
                return ans;
            }
            Vector2i GetPosition () const {
                Vector2i ans = {};
                glfwGetWindowPos (window_, &ans.x, &ans.y);
                return ans;
            }
            bool isFocus () const {
                //return GLFW_FOCUSED;
                return GLFW_FOCUS_ON_SHOW;
            }
            bool isHidden () const {
                return !GLFW_VISIBLE;
            }
            void Close () {
                glfwSetWindowShouldClose (window_, GLFW_TRUE);
            }
            bool IsOpen () const {
                return !glfwWindowShouldClose (window_);
            }
            void AddDrawable (const MyGLFW::Drawable* dr) {
                drawables.push_back (dr);
            }
            void Draw () {
                for (const MyGLFW::Drawable *dr : drawables)
                    dr->Draw ();
                glfwSwapBuffers (window_);
            }
        private:
            int initValue_ = GLFW_FALSE;
            GLFWwindow* window_ = nullptr;
            std::vector <const MyGLFW::Drawable *> drawables = {};
    };

    class Point : public MyGLFW::Drawable {
        public:
            Vector3f coords_ = {};
            Color color_ = {};
            Point (Vector3f coords, Color color):
                coords_ (coords),
                color_ (color)
                {}
            Point (Vector3f coords):
                Point (coords, BColor::WHITE)
                {}
            Point ():
                Point ({0, 0, 0}, BColor::WHITE)
                {}
            virtual void Draw () const override {}
    };

    class CircleShape : public MyGLFW::Drawable { 
        public:
            CircleShape (double rad, Vector2f center):
                rad_ (rad),
                center_ (center)
                {}
            CircleShape (double rad):
                CircleShape (rad, {0, 0})
                {}
            CircleShape (Vector2f center):
                CircleShape (1, center)
                {}
            CircleShape ():
                CircleShape (1, {0, 0})
                {}
            virtual void Draw () const override {
                
                glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.0f);

                GLfloat theta = 0;
                GLfloat pi = 3.1415f;
                GLfloat step   = 6.0f; 

                glBegin(GL_TRIANGLE_FAN);
                for(GLfloat a = 0.0f; a < 360.0f; a += step) {
                    theta = 2.0f * pi * a / 180.0f;
                    glColor4f(a / 360.0f, 1.0f, 1.0f - a / 360.0f, 1.0f);
                    glVertex3f(rad_ * cos(theta), rad_ * sin(theta), 0.0f);
                }
                glEnd();
                glPopMatrix();
                
            }
        private:
            double rad_ = 0;
            Vector2f center_ = { 0, 0 };
    };

    class ConvexShape : public MyGLFW::Drawable {
        public:
            ConvexShape (const std::vector <Point>& vertices):
                vertices_ (vertices)
                {}
            ConvexShape (const std::vector <Vector3f>& vertices):
                vertices_ ({})
                {
                    for (Vector3f vertex : vertices)
                        vertices_.push_back ({vertex, BColor::WHITE });
                }
            virtual void Draw () const override {
                glBegin (GL_TRIANGLES);
                for (Point vertex : vertices_) {
                    glColor3f ( vertex.color_.r,
                                vertex.color_.g,
                                vertex.color_.b );
                    glVertex3f (vertex.coords_.x,
                                vertex.coords_.y,
                                vertex.coords_.z);
                }
                glEnd ();
            }
        private:
            std::vector <Point> vertices_ = {};
    };

    /* Поскольку есть ConvexShape
    class RectangleShape : public MyGLFW::Drawable {
        
    };
    */

    class Keyboard {

    };
}

