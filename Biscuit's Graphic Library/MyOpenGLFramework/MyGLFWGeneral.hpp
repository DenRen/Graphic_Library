#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

//  OpenGL LIBRARIES
#include <GLFW/glfw3.h>

//  EXTRA LIBRARIES
#include "MyGLFWVector.hpp"

namespace MyGLFW {

    const float CIRCLE_STEP = 6.0f;

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

    enum class EventType {
        ErrorType           = 0,
        MouseButtonPressed  = 1,
        MouseButtonReleased = 2,
        MouseOnZone         = 3,
        KeyPressed          = 4,
        KeyReleased         = 5
    };

    class Event {
        public:
            EventType type = EventType::ErrorType;
        private:
            

    };

    class Window {
        public:
            //  ВНИМАНИЕ! Friend - функции!
            friend void SetMouseButtonCallback (Window& window);
            friend void SetKeyCallback (Window& window);

            Window (const Vector2i& size, std::string title):
                initValue_ (glfwInit ()),
                window_ (glfwCreateWindow (size.x, size.y, title.c_str(), nullptr, nullptr)),
                drawables_ ({})
                {
                    if (initValue_ == GLFW_FALSE || window_ == GLFW_FALSE) {
                        THROW ("Error opening window!");
                    }
                    glfwMakeContextCurrent (window_);
                    SetMouseButtonCallback (*this);
                    SetKeyCallback (*this);
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
            //  TODO не совсем понятно, что должны возвращать
            bool IsFocus () const {
                //return GLFW_FOCUSED;
                return GLFW_FOCUS_ON_SHOW;
            }
            bool IsHidden () const {
                return !GLFW_VISIBLE;
            }
            void Close () {
                glfwSetWindowShouldClose (window_, GLFW_TRUE);
            }
            bool IsOpen () const {
                return !glfwWindowShouldClose (window_);
            }
            void Clear () {
                glClear(GL_COLOR_BUFFER_BIT);
            }
            void AddDrawable (const MyGLFW::Drawable* dr) {
                drawables_.push_back (dr);
            }
            /*  TODO А нужно ли это?...
                    1. События обрабатываются в несколько раз дольше, тк оно сначала ловится в window, 
                        потом передаётся Callback функции, которая снова кладёт его в Window и оно
                        обрабатывается еще раз в основном цикле (что-то как-то не очень эффеективно)))
                    2. У пользователя есть возможность самому создать Event (то есть симулировать нажатие
                        клавиши, даже если она не была нажата)! С одной стороны, это хорошо, но может
                        привести к непредсказуемому поведению изза отсутствия контроля

            */
            void AddEvent (const Event event) {
                events_.push (event);
            }
            void Draw () {
                for (const MyGLFW::Drawable *dr : drawables_)
                    dr->Draw ();
                glfwSwapBuffers (window_);
            }
        private:
            int initValue_ = GLFW_FALSE;
            GLFWwindow* window_ = nullptr;
            std::vector <const MyGLFW::Drawable *> drawables_ = {};
            std::queue <Event> events_ = {};
    };

    //!         TODO
    //!         Этот интерфейс было бы неплохо куда нибудь спрятать
    void MouseButtonCallback (GLFWwindow* window, int button, int action, int mods) {
        
    }

    void SetMouseButtonCallback (Window& window) {
        glfwSetMouseButtonCallback (window.window_, MouseButtonCallback);
        //  TODO тут всякие обработки ошибок
    }

    void KeyCallback (GLFWwindow* window, int key, int scancode, int action, int mods) {
        //  TODO Тестовая функция Callback для клавиатуры
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose (window, GL_TRUE);

        /*  Как работает на самом деле:
                1. Создаётся эвент в зависимости от нажатой кнопки на клавиатуре или мыши
                2. Эвент добавляется в очередь в Window (пока неясно как, тк эта функция
                    не имеет ссылки на Window и вообще ничего не знает о нём)
                3. Далее в конце основного цикла программы вызывается обработчик Event-ов, 
                    который просматривает все эвенты из очереди и проверяет, нужно ли что-нибудь
                    делать (этот обработчик пишет сам юзер)
            Альтернативный вариант (чтобы меньше за****ваться):
                1. ...
                А ЕГО НЕТ АХАХАХАХАХАХАХ
                Потому что в OpenGL можно вызвать обработку event-ов только с помощью glfwPollEvents
                    при этом обрабатываться они будут исключительно внутри GLFWwindow, который будет 
                    вызывать именно вот эту вот функцию, и делать то, что вот тут написано

                Итог: нужно либо придумать очень хитрую собственную систему event-ов, либо забить на эту
                    часть и использовать каждому свои библиотеки, но тогда сделать СОВСЕМ базовый класс не
                    выйдет :(
        */

    }

    void SetKeyCallback (Window& window) {
        glfwSetKeyCallback (window.window_, KeyCallback);
        //  TODO тут всякие обработки ошибок
    }

    //!
    //!         Конец секретной секции

    class Point : public MyGLFW::Drawable {
        public:
            Vector2f coords_ = {};
            Color color_ = {};
            Point (Vector2f coords, Color color):
                coords_ (coords),
                color_ (color)
                {}
            Point (Vector2f coords):
                Point (coords, BColor::WHITE)
                {}
            Point ():
                Point ({0, 0}, BColor::WHITE)
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
                //  TODO тоже тестовая функция отрисовки
                glPushMatrix ();
                glTranslatef (center_.x, center_.y, 0.0f);

                GLfloat theta = 0;
                float step = CIRCLE_STEP / 180.0f; 

                glBegin(GL_TRIANGLE_FAN);
                for (float a = 0.0f; a < 2.0f; a += step) {
                    theta = 2.0f * M_PI * a ;
                    glColor3f (a / 2, 1.0f, 1.0f - a / 2);
                    glVertex2f (rad_ * cos(theta), rad_ * sin(theta));
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
            ConvexShape (const std::vector <Vector2f>& vertices):
                vertices_ ({})
                {
                    for (Vector2f vertex : vertices)
                        vertices_.push_back ({vertex, BColor::WHITE });
                }
            virtual void Draw () const override {
                //  TODO Пока что работает только для треугольников
                glBegin (GL_TRIANGLE_FAN); // можешь затестить GL_TRIANGES
                for (Point vertex : vertices_) {
                    glColor3f ( vertex.color_.r,
                                vertex.color_.g,
                                vertex.color_.b );
                    glVertex2f (vertex.coords_.x,
                                vertex.coords_.y);
                }
                glEnd ();
            }
        private:
            std::vector <Point> vertices_ = {};
    };

    /*  TODO
        Не нужен поскольку есть ConvexShape
        Но с другой стороны нужен, чтобы проверять onHover
    class RectangleShape : public MyGLFW::Drawable {
        
    };
    */

}

