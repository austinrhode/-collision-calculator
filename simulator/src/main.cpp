#include <iostream>
#include <model/vect.hpp>
#include <view/GUI.hpp>
#include <thread>

using namespace std;

int main()
{
    float liveTime = 0;
    GUI myGUI = GUI(640,480,3);
    //             head vel amp omega phi  dbase drate   color     alpha
    wave w1 = wave(0,  0.10,  15, 10,   125, 2,      40,   0x36ffe7, 100);
    wave w2 = wave(150,  -0.1,  5,  3,    125, 2,    10, 0x36ffe7, 125);
    myGUI.waveList.push_back(w1);
    myGUI.waveList.push_back(w2);
    thread thread1(&GUI::initWindow, std::ref(myGUI));
    thread1.detach();

    auto deltaTime = std::chrono::high_resolution_clock::now();
    while(!myGUI.closed) {
      //if it gets choppy we might want to track time difference
      /*auto newDelta = std::chrono::high_resolution_clock::now();
      auto difference = std::chrono::duration_cast<std::chrono::microseconds>(newDelta - deltaTime);
      float diffMilli =  difference.count()/float(1000000);
      deltaTime = newDelta;
      liveTime += diffMilli;*/

      for(int i = 0; i < myGUI.waveList.size(); i++) {
        myGUI.waveList[i].headPosition += myGUI.waveList[i].velocity;
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
    }
    //thread1.join();
    return 0;
}
