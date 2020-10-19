namespace GEngine
{
    struct Event;
    struct Coords;
    struct Texture;
    struct Canvas;
    struct Container;
    struct Text;
    struct Font;
    struct PixelArray;

    class AWindow
    {
        Coords position_;
        Coords size_;

        Texture   texture_;
        Container container_;

        bool isHidden_;
        bool isFocus_;

    public:
        AWindow(Coords position, Coords size, Texture texture, bool isHidden, bool isFocus):
            position_ (position),
            size_     (size),
            texture_  (texture),
            container_(Container()),
            isHidden_ (isHidden),
            isFocus_  (isFocus)
            {}
        virtual ~AWindow() = default;

        virtual bool isFocus() const noexcept
        {
            return isFocus_;
        }
        virtual bool isHidden() const noexcept
        {
            return isHidden_;
        }

        virtual Coords getSize() const noexcept
        {
            return size_;
        }
        virtual Coords getPos() const noexcept
        {
            return position_;
        }

        virtual void draw() = 0;

        virtual bool testClick(Event event) = 0;

        virtual void onClick   (Event event) = 0;
        virtual void onHover   (Event event) = 0;
        virtual void onRelease (Event event) = 0;

        virtual void onKey     (Event event) = 0;

        virtual void onEvent   (Event event) = 0;
    };
    class AManager
    {
        std::vector<AWindow*> children_;
        std::vector<AWindow*> active_children_;

    public:
        AManager():
                children_(std::vector<AWindow*>())
        {}

        ~AManager()
        {
            for (auto & child : children_)
                child->~AWindow();
        }

        void AddChildren(AWindow* wnd)
        {
            children_.push_back(wnd);
        }

        void AnalyseEvent(Event event)
        {
            for (auto cur : children_)
            {
                if (event->type() == event.MOUSE_CLICK)
                    if (cur->testClick(event))
                    {
                        active_childre_.push_back(cur);
                        cur->onClick(event);
                    }

                if (event->type() == event.MOUSE_RELEASE)
                {
                    for (auto cur_active : active_children_)
                        cur_active->onRelease(event);
                    active_children_.clear();
                }
                if (event->type() == event.KEY)
                    if (cur->isFocus())
                        cur->onKey(event);

                if (event->type() == event.MOUSE_MOVE)
                    if (cur->testClick())
                        cur->onHover(event);
            }
        }

        void draw()
        {
            for (size_t i = 0; i < children_.size(); ++i)
            {
                children_[i]->draw();
            }
        }

        void operator<<(const AManager& mng, AWindow* wnd)
        {
            AddChildren(wnd);
        }
    };
    class AButton : public AWindow
    {
        Text    text_;
        Font    font_;

    public:
        Button(Texture texture, Coords position, Coords size, const std::string& text, const Font& font) :
            AWindow(position,
                    size,
                    Texture(Texture()),
                    Container(Container()),
                    isHidden(0),
                    isFocus(0)),
            text_   (Text(text)),
            font_   (Font())
                {}
        ~Button() override = default;

        void ChangeFont(const Font& new_font) {}
        void ChangeText(const std::string& new_text) {}
    };
    class Plot : public AWindow
    {
        PixelArray  array_;
        Text        name_;
        Font        font_;

    public:
        Plot(Coords position, Coords size, std::string name) :
            AWindow(position,
                    size,
                    Texture(Texture()),
                    Container(Container()),
                    isHidden(0),
                    isFocus(0)),
            text_   (Text(text)),
            font_   (Font())
            {}
        ~Plot() override = default;

        void updatePlot(PixelArray new_array) {}

        void onClick() override {}
        void onRelease() override {}

        void draw() override {}
    };

};
