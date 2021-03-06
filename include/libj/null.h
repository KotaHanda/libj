// Copyright (c) 2012 Plenluno All rights reserved.

#ifndef LIBJ_NULL_H_
#define LIBJ_NULL_H_

#include "libj/singleton.h"
#include "libj/string.h"

namespace libj {

class Null : LIBJ_SINGLETON(Null)
 public:
    String::CPtr toString() const {
        return String::create("null");
    }
};

}  // namespace libj

#endif  // LIBJ_NULL_H_
