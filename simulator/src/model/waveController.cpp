#include "waveController.hpp"
#include <view/GUI.hpp>

void waveController::updateWaves() {
  while(running) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
    if(gui == NULL || waveList.size() == 0) continue;
    else {
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
  }
}
