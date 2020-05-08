#include "waveController.hpp"
#include <view/GUI.hpp>

void waveController::updateWorld() {
  while(running) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
    if(gui == NULL) continue;
    else {
      updateWaves();
      updateBoats();
    }
  }
}

void waveController::updateWaves() {
  for(int i = 0; i < waveList.size(); i++) {
    float headPos = waveList[i].headPosition;
    if(headPos > gui->WIDTH/gui->RESOLUTION || headPos < 0) {
      if(headPos > gui->WIDTH/gui->RESOLUTION) {
        waveList[i].headPosition = gui->WIDTH/gui->RESOLUTION;
      } else {
        waveList[i].headPosition = 0;
      }
      waveList[i].velocity *= -0.8;
      waveList[i].amplitude *= 0.8;
      waveList[i].omega *= 1.3;
    }
    waveList[i].headPosition += waveList[i].velocity;
  }
}

void waveController::updateBoats() {
  for(int i = 0; i < boatList.size(); i++) {
    float height = 0;
    float height_front = 0;
    float height_back = 0;
    for (wave w : waveList){
      height += w.calculate_height(boatList[i].xPos / gui->RESOLUTION);
      height_front += w.calculate_height((boatList[i].xPos + (boatList[i].width/2)) / gui->RESOLUTION);
      height_back += w.calculate_height((boatList[i].xPos - (boatList[i].width/2)) / gui->RESOLUTION);
    }
    boatList[i].yPos = height + phi + 1.5*boatList[i].height + boatList[i].yOffset;
    boatList[i].angle = asin((height_front - height_back) / boatList[i].width) * (180 / acos(-1));
  }
}
