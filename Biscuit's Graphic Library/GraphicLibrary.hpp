class GraphicLibrary {

    //  Векторы (для удобства)
    //  можно реализовать в базовом классе, т.к. одинаковый функционал

    template <typename T>
    struct Vector2 {};

    template <typename T>
    struct Vector3 {};

    //  Окно + текстура

    class RenderWindow {};
    class Texture {};

    //  Стандартные фигуры (необходимо) + картинки в окне

    class Drawable {
        public:
            virtual void Draw ();
    };

    class Pixel : public Drawable {}; // ???
    class Sprite : public Drawable {};
    class CircleShape : public Drawable {};
    class RectangleShape : public Drawable {};
    class ConvexShape : public Drawable {};    

    //  Интерфейсы для работы с внешними устройствами
    //  (с помощью событий)

    enum EventType {
        isKeyPressed = 0,
        isMouseButtonClicked = 1,
        isMouseButtoReleased = 2,
        isMouseOnZone = 3
    };

    class Key {};

    class Event {
        public:
            EventType type_;
            union data_ {
                Key key_;             //    if type == isKeyPressed
                RectangleShape zone_; //    if type == isMouseOnZone
            };
        //...
    };
}