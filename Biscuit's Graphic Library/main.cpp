#include <iostream>

#include "MyOpenGLFramework/MyGLFWGeneral.hpp"

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void) {
    //glfwSetErrorCallback(error_callback);
    try {
        MyGLFW::Window window ({2*640, 480}, "Main window");
        MyGLFW::ConvexShape triangle { {
            MyGLFW::Point { {-0.6f, -0.4f, 0.f}, MyGLFW::BColor::RED   },
            MyGLFW::Point { {0.6f, -0.4f, 0.f},  MyGLFW::BColor::GREEN },
            MyGLFW::Point { {0.f, 0.6f, 0.f},    MyGLFW::BColor::BLUE  },
            MyGLFW::Point { {0.6f, 0.4f, 0.f},   MyGLFW::BColor::WHITE }
        } };
        window.AddDrawable (&triangle);
        MyGLFW::CircleShape circle { 0.2f };
        window.AddDrawable (&circle);
        //glfwSetKeyCallback(window, key_callback);
        while (window.IsOpen ())
        {
            MyGLFW::Vector2i size = window.GetSize ();
            //double ratio = size.x / (float) size.y;
            //glViewport(0, 0, size.x, size.y);
            glClear(GL_COLOR_BUFFER_BIT);
            //glMatrixMode(GL_PROJECTION);
            //glLoadIdentity();
            //glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
            //glMatrixMode(GL_MODELVIEW);
            //glLoadIdentity();
            //glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
            
            window.Draw ();
            std::cout << "isFocus: " <<  window.isFocus() 
                      << "isHidden: " << window.isHidden () << std::endl;
            //glfwPollEvents();
        }
    } catch (std::exception &ex) {
        std::cerr << ex.what () << std::endl;
    }
    return 0;
}