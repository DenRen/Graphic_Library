#ifndef GLFVECTOR_HPP_
#define GLFVECTOR_HPP_

namespace MyGLFW {

    template <typename T>
    struct Vector2 {
        //  METHODS
            Vector2 ():
                x (0),
                y (0)
                {}
            Vector2 (T newX, T newY):
                x (newX),
                y (newY)
                {}
            Vector2 (const Vector2 <T>& vec2) = default;
            ~Vector2 () = default;
        //  DATA
            T x = 0, y = 0;
    };

    template <typename T>
    Vector2 <T> operator - (Vector2 <T>& vec) {
        return { -vec.x, -vec.y };
    }

    template <typename T>
    Vector2 <T> operator + (const Vector2 <T>& lhs, const Vector2 <T>& rhs) {
        return { lhs.x + rhs.x, lhs.y + rhs.y };
    }

    template <typename T>
    Vector2 <T> operator - (const Vector2 <T>& lhs, const Vector2 <T>& rhs) {
        return { lhs.x - rhs.x, lhs.y - rhs.y };
    }

    template <typename T, typename U>
    Vector2 <T> operator * (const Vector2 <T>& vec, U num) {
        return { vec.x * num, vec.y * num };
    }

    template <typename T, typename U>
    Vector2 <T> operator * (U num, const Vector2 <T>& vec) {
        return vec * num;
    }

    template <typename T>
    bool operator == (const Vector2 <T>& lhs, const Vector2 <T>& rhs) {
        return (lhs.x == rhs.x && lhs.y == rhs.y);
    }

    template <typename T>
    bool operator != (const Vector2 <T>& lhs, const Vector2 <T>& rhs) {
        return !(lhs == rhs);
    }

    //  COMMON TYPES
    typedef Vector2 <int>       Vector2i;
    typedef Vector2 <unsigned>  Vector2u;
    typedef Vector2 <float>     Vector2f;

    template <typename T>
    struct Vector3 {
        //  METHODS
            Vector3 ():
                x (0),
                y (0),
                z (0)
                {}
            Vector3 (T newX, T newY, T newZ):
                x (newX),
                y (newY),
                z (newZ)
                {}
            Vector3 (const Vector3 <T>& vec3) = default;
            ~Vector3 () = default;
        //  DATA
            T x = 0, y = 0, z = 0;
    };

    template <typename T>
    Vector3 <T> operator - (Vector3 <T>& vec) {
        return { -vec.x, -vec.y, -vec.z };
    }

    template <typename T>
    Vector3 <T> operator + (const Vector3 <T>& lhs, const Vector3 <T>& rhs) {
        return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
    }

    template <typename T>
    Vector3 <T> operator - (const Vector3 <T>& lhs, const Vector3 <T>& rhs) {
        return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
    }

    template <typename T, typename U>
    Vector3 <T> operator * (const Vector3 <T>& vec, U num) {
        return { vec.x * num, vec.y * num, vec.z * num };
    }

    template <typename T, typename U>
    Vector3 <T> operator * (U num, const Vector3 <T>& vec) {
        return vec * num;
    }

    template <typename T>
    bool operator == (const Vector3 <T>& lhs, const Vector3 <T>& rhs) {
        return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z);
    }

    template <typename T>
    bool operator != (const Vector3 <T>& lhs, const Vector3 <T>& rhs) {
        return !(lhs == rhs);
    }

    //  COMMON TYPES
    typedef Vector3 <int>       Vector3i;
    typedef Vector3 <unsigned>  Vector3u;
    typedef Vector3 <float>     Vector3f;

}

#endif //GLFVECTOR_HPP_