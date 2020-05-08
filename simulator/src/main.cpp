#include <iostream>
#include <model/vect.hpp>
#include <view/GUI.hpp>
#include <model/waveController.cpp>
#include <thread>

using namespace std;

int main()
{
    waveController wc = waveController();
    GUI myGUI = GUI(640, 480, 3, &wc);
    wc.gui = &myGUI;

    wc.waveList.push_back(wave(0,    0.5, 20, 3, 2, 8));
    wc.waveList.push_back(wave(170, -0.3, 10, 2, 2, 10));

    thread thread1(&GUI::initWindow, std::ref(myGUI));
    thread thread2(&waveController::updateWaves, std::ref(wc));

    thread1.join();
    thread2.join();
    return 0;
}
