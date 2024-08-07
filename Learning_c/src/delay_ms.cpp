#include <chrono>
#include <thread>

void delay_ms(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}