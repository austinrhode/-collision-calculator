#ifndef BOAT_H
#define BOAT_H

class boat : public rigid_body {
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
  const float yOffset = 3;
};

#endif
