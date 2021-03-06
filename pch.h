// pch.h
// contains common includes
// is pre-compiled for increased compiler time
// only add files which rarely change (system includes)

#pragma once

// SFML headers
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

// iostream headers
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <fstream>
#include <memory>
#include <sstream>
#include <hash_map>

// box 2d physics library
#include <Box2D/Box2D.h>

// makes things a lot nicer
using namespace std;

// common typedefs
#include "typedefs.h"