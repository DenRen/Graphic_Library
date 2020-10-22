#include <iostream>

#include "MyOpenGLFramework/MyGLFWGeneral.hpp"

int main () {
    try {
        MyGLFW::Window window ({640, 480}, "Main window");
        MyGLFW::ConvexShape triangle { {
            MyGLFW::Point { {-0.6f, -0.4f}, MyGLFW::BColor::RED   },
            MyGLFW::Point { {0.6f, -0.4f},  MyGLFW::BColor::GREEN },
            MyGLFW::Point { {0.f, 0.6f},    MyGLFW::BColor::BLUE  },
            MyGLFW::Point { {0.6f, 0.4f},   MyGLFW::BColor::BLACK }
        } };
        window.AddDrawable (&triangle);
        MyGLFW::CircleShape circle { 0.2f, {0.5, 0.5} };
        window.AddDrawable (&circle);
        while (window.IsOpen ())
        {
            MyGLFW::Vector2i size = window.GetSize ();
            window.Clear ();
            window.Draw ();
            // A^32
            glfwPollEvents();
            // A^32
        }
    } catch (std::exception &ex) {
        std::cerr << ex.what () << std::endl;
    }
    return 0;
}