#ifndef _COLLISION_H
#define	_COLLISION_H
 
 
#ifndef PI
    #define PI (3.14159265358979323846)
#endif
#define RADIANS_PER_DEGREE (PI/180.0)
 
 
class Collision {
public:
 
    virtual ~Collision();
 
    /**
     *  Test for a pixel perfect collision detection between
     *  two Sprites, Rotation and Scale is supported in this test
     *
     *  @param Object1 The first sprite
     *  @param Object2 The second sprite
     *  @AlphaLimit How opaque a pixel needs to be before a hit it registered
     */
     static bool PixelPerfectTest(const sf::Sprite& Object1 ,const sf::Sprite& Object2, sf::Uint8 AlphaLimit = 127);
 
    /**
     *  Test for collision using circle collision dection
     *  Radius is averaged from the dimesnions of the sprite so
     *  roughly circular objects will be much more accurate
     */
    static bool CircleTest(const sf::Sprite& Object1, const sf::Sprite& Object2);
 
    /**
     *  Test for bounding box collision using OBB Box.
     *  To test against AABB use PixelPerfectTest with AlphaLimit = 0
     *
     *  @see Collision::PixelPerfectTest
     */
    static bool BoundingBoxTest(const sf::Sprite& Object1, const sf::Sprite& Object2);
 
    /**
     *  Generate a Axis-Aligned Bounding Box for broad phase of
     *  Pixel Perfect detection.
     *
     *  @returns IntRect to round off Floating point positions.
     */
    static sf::IntRect GetAABB(const sf::Sprite& Object);
 
    /**
     *  Helper function in order to rotate a point by an Angle
     *
     *  Rotation is CounterClockwise in order to match SFML Sprite Rotation
     *
     *  @param Point a Vector2f representing a coordinate
     *  @param Angle angle in degrees
     */
    static sf::Vector2f RotatePoint(const sf::Vector2f& Point, float Angle);
 
    /**
     *  Helper function to get the minimum from a list of values
     */
    static float MinValue(float a, float b, float c, float d);
 
    /**
     *  Helper function to get the maximum from a list of values
     */
    static float MaxValue(float a, float b, float c, float d);
 
private:
 
    Collision();
};
 
#endif	/* _COLLISION_H */