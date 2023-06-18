#ifndef __Key__
#define __Key__
struct Key {
    char direction;
    int times;
    Key(char dir, int wantedTimes) : direction {dir}, times {wantedTimes} {}
};
#endif