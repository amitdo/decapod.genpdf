// -*- C++ -*-

// Copyright 2010-2011 Image Understanding and Token Recognition, University of Kaiserslautern, Germany
// or its licensors, as applicable.
//
// You may not use this file except under the terms of the accompanying license.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you
// may not use this file except in compliance with the License. You may
// obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Project: Decapod
// File: pattern.h
// Purpose: header file for abstract data type
// Responsible: Michael Patrick Cutter
// Reviewer: Joost van Beusekom
// Primary Repository: iupr1.cs.uni-kl.de/~shared/decapod/tiff2pdf
// Web Sites: www.iupr.org, www.ocropus.org


#ifndef h_pattern_
#define h_pattern_

#include "ocropus/ocr-utils.h"
#include "ocropus/glinerec.h"
#include "ocropus/glutils.h"
#include "ocropus/glclass.h"
#include "ocropus/bookstore.h"
#include <colib/colib.h>
#include <iulib/iulib.h>
#include <iulib/imgio.h>
#include "iulib/imgbits.h"


using namespace std;
using namespace colib;
using namespace iulib;
using namespace narray_io;
using namespace narray_ops;
using namespace ocropus;


class Token
{
    private:
        static int staticID;
        int tokenID;
        int count;
        bytearray img;
        narray<int> classes;

    public:
        Token();
        Token(bytearray &con_img, int cls);
        Token(const Token &tok);
        Token& operator=(const Token &tok);
        static int next_user_id(); //static ID for Token
        int get_tokenID() const;
        int sizeX() const; 
        int sizeY() const; 
        int getVal(int i, int j) const;
        int getCount() const;
        bytearray& get_img();
        int getClassAt(int i) const;
        int getClassesLength() const;
        int getMostFrequent();
        void add(bytearray &con_img, int cls);
        void mergeToken(Token&);
        void dshown();
        void mergeImage(bytearray &addedImg);
        void increaseGreaterThanThreshold(bytearray &image,float thresh);
        void nullLessThanThreshold(bytearray &img,float thresh);
};

#endif
