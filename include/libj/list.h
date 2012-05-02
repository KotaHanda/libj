// Copyright (c) 2012 Plenluno All rights reserved.

#ifndef LIBJ_LIST_H_
#define LIBJ_LIST_H_

#include "libj/collection.h"

namespace libj {

class List : LIBJ_COLLECTION(List)
 public:
    virtual bool add(Value) = 0;
    virtual bool add(Size, Value) = 0;
    virtual bool set(Size, Value) = 0;
    virtual Value get(Size) = 0;
    virtual Value remove(Size) = 0;
    // and so on
};

#define LIBJ_LIST(T) public libj::List { \
    LIBJ_MUTABLE_DECLS(T, libj::List)

}  // namespace libj

#endif  // LIBJ_LIST_H_