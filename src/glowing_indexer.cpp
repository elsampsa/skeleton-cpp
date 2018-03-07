/*
 * glowing_indexer.cpp :
 * 
 * Copyright 2018 Sampsa Riikonen
 * 
 * Authors: Sampsa Riikonen <sampsa.riikonen@iki.fi>
 * 
 * This file is part of the skeleton library.
 * 
 * Skeleton is free software: you can redistribute it and/or modify
 * it under the terms of the WTFPL license, either version 2 of the
 * License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the WTFPL license
 * along with this program.  If not, see <http://www.wtfpl.net/about/>
 *
 * According to international copyright law, this code needs a copyright notice, 
 * but if you remove it, I don't really mind.
 *
 */

/** 
 *  @file    glowing_indexer.cpp
 *  @author  Sampsa Riikonen
 *  @date    2018
 *  @version 0.1.0 
 *  
 *  @brief
 */ 

#include "glowing_indexer.h"

DerivedClass::DerivedClass() {
  std::cout << "Hello from Derived class constructor!" << std::endl;
}
  
DerivedClass::~DerivedClass() {
  std::cout << "Hello from Derived class destructor!" << std::endl;
}

void DerivedClass::useSql() {
  sqlite3_initialize();
  sqlite3_shutdown();
}
