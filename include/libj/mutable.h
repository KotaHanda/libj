// Copyright (c) 2012 Plenluno All rights reserved.

#ifndef LIBJ_MUTABLE_H_
#define LIBJ_MUTABLE_H_

#include "libj/gc_base.h"
#include "libj/object.h"

namespace libj {

class Mutable
    : public Object
    , public GCBase
    , public MutableBase {
 public:
    typedef LIBJ_PTR(Mutable) Ptr;
    typedef LIBJ_CPTR(Mutable) CPtr;

    Boolean instanceof(TypeId id) const {
        return id == Type<Mutable>::id()
            || Object::instanceof(id);
    }
};

#define LIBJ_MUTABLE_METHODS(T, B) public: \
    Ptr clone() const; \
    libj::TypeId type() const { \
        return libj::Type<T >::id(); \
    } \
    Boolean instanceof(libj::TypeId id) const { \
        return id == libj::Type<T >::id() \
            || B::instanceof(id); \
    }

#define LIBJ_MUTABLE_DECLS(T, B) public: \
    typedef LIBJ_PTR(T) Ptr; \
    typedef LIBJ_CPTR(T) CPtr; \
    LIBJ_MUTABLE_METHODS(T, B)

#define LIBJ_MUTABLE_TEMPLATE_DECLS(T, B) public: \
    typedef LIBJ_PTR_TYPE(T) Ptr; \
    typedef LIBJ_CPTR_TYPE(T) CPtr; \
    LIBJ_MUTABLE_METHODS(T, B)

#define LIBJ_MUTABLE(T) public libj::Mutable { \
    LIBJ_MUTABLE_DECLS(T, libj::Mutable)

}  // namespace libj

#endif  // LIBJ_MUTABLE_H_
