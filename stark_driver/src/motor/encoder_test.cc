
#include <cstdio>
#include "fsleep.hh"
#include "MotorController.hh"

void test(std::string dev) {
    int left_count, right_count;
    printf("Testing motor controller @ %s\n", dev.c_str());

    MotorController mc(dev);
    // reset encoder counts
    left_count = mc.get_left_ticks();
    right_count = mc.get_right_ticks();
    printf("Left: %d Right: %d\n", left_count, right_count);
    //fsleep(0.1);
    left_count = mc.get_left_ticks(); 
    right_count = mc.get_right_ticks();
    printf("Left: %d Right: %d\n", left_count, right_count);
    printf("Above result should be Left: 0 Right: 0\n");
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Usage: ./motor_test /dev/ttyUSBXX\n");
        return 1;
    }

    test(argv[1]);
    return 0;
}

