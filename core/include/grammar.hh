#pragma once

#include <ostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>

#include <cstring>

using namespace std;

class Grammar
{
public:
    Grammar(){};

    string parse(string filename);
    float getAngle();

private:
    string expanded_;
    float angle_, steps_;
};