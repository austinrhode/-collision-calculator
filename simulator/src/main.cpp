#include <iostream>
#include <model/vect.hpp>
#include <view/GUI.hpp>
#include <model/wave.hpp>
#include <thread>

using namespace std;

int main()
{
    float liveTime = 0;
    GUI myGUI = GUI(640,480,1);

    thread thread1(&GUI::initWindow, std::ref(myGUI));
    thread1.detach();

    //                            head  vel    amp omega dbase drate
    //myGUI.waveList.push_back(wave(150,  -0.1,  5,  3,    2,    10));
    myGUI.waveList.push_back(wave(0,    0.5,  20, 3,   2,   8));
    myGUI.waveList.push_back(wave(170,    -0.3,  10, 2,   2,   10));
    //myGUI.waveList.push_back(wave(100,  0.30,  10, 7,    2,    5));

    while(!myGUI.closed) {
      for(int i = 0; i < myGUI.waveList.size(); i++) {
        float headPos = myGUI.waveList[i].headPosition;
        if(headPos > 640 || headPos < 0) {
          if(headPos > 640) {
            myGUI.waveList[i].headPosition = 640;
          } else {
            myGUI.waveList[i].headPosition = 0;
          }
          myGUI.waveList[i].velocity *= -0.8;
          myGUI.waveList[i].amplitude *= 0.8;
          myGUI.waveList[i].omega *= 1.3;
        }
        myGUI.waveList[i].headPosition += myGUI.waveList[i].velocity;
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
    }
    //thread1.join();
    return 0;
}
