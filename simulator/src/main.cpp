#include <iostream>
#include <model/vect.hpp>
#include <view/GUI.hpp>
#include <model/waveController.cpp>
#include <thread>
#include <model/boat.hpp>

using namespace std;

int main()
{

    waveController wc = waveController();
    GUI myGUI = GUI(640, 480, 1, &wc);
    wc.gui = &myGUI;

    wc.waveList.push_back(wave(200, 0.9, 10, 10, 2, 0.0005));
    wc.waveList.push_back(wave(50, 1.2, 3, 2, 2, 0.0005));

    wc.boatList.push_back(boat(32,32,50,400,0));
    wc.boatList.push_back(boat(32,32,320,400,0));

    thread thread1(&GUI::initWindow, std::ref(myGUI));
    thread thread2(&waveController::updateWorld, std::ref(wc));

    thread1.join();
    thread2.join();
    return 0;
}
