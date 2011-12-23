// pch.h
// contains common includes
// is precompiled for increased compiler time
// only add files which rarely change (system includes)

#pragma once

// SFML headers
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// iostream headers
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <fstream>
#include <memory>
#include <hash_map>

// makes things a lot nicer
using namespace std;

// common typedefs
#include "typedefs.h"