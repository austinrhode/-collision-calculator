#ifndef BOAT_H
#define BOAT_H

class boat {
public:
  boat(float width, float height, float xPos, float yPos, float angle):
    width(width),
    height(height),
    xPos(xPos),
    yPos(yPos),
    angle(angle) {}

  float width;
  float height;
  float xPos;
  float yPos;
  float angle;
  float xVel;
  float yVel;
  const float yOffset = 3;
};

#endif
