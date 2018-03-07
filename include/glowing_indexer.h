#ifndef glowing_indexer_HEADER_GUARD 
#define glowing_indexer_HEADER_GUARD

/*
 * glowing_indexer.h : A brief description
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
 *  @file    glowing_indexer.h
 *  @author  Sampsa Riikonen
 *  @date    2018
 *  @version 0.1.0 
 *  
 *  @brief A brief description
 */ 

#include <iostream>
#include "demo.h"
#include "sqlite3.h"

/** This is demo class derived from a static library
 * 
 * - Does pretty much nothing
 * - Uses a also a dynamically linked library: sqlite3
 * 
 * @ingroup some_tag
 */
class DerivedClass : public DemoClass {
  
public:
  /** Default constructor
   * 
   * @param nothing no parameters here
   * 
   */
  DerivedClass();
  /** Default destructor
   * 
   */
  ~DerivedClass();

  void useSql();
  
};

#endif
