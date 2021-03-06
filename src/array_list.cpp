// Copyright (c) 2012 Plenluno All rights reserved.

#include <vector>
#include "libj/array_list.h"
#include "libj/error.h"
#include "libj/exception.h"
#include "libj/string.h"

namespace libj {

class ArrayListImpl : public ArrayList {
 public:
    Size size() const {
        return vec_.size();
    }

    Boolean add(const Value& v) {
        vec_.push_back(v);
        return true;
    }

    Boolean add(Size i, const Value& v) {
        if (i > vec_.size()) {
            return false;
        } else {
            vec_.insert(vec_.begin() + i, v);
            return true;
        }
    }

    Boolean set(Size i, const Value& v) {
        if (i >= vec_.size()) {
            return false;
        } else {
            vec_[i] = v;
            return true;
        }
    }

    Value get(Size i) const {
        if (i >= vec_.size()) {
#ifdef LIBJ_USE_EXCEPTION
            LIBJ_THROW(Error::INDEX_OUT_OF_BOUNDS);
#else
            return Error::create(Error::INDEX_OUT_OF_BOUNDS);
#endif  // LIBJ_USE_EXCEPTION
        } else {
            return vec_[i];
        }
    }

    Value remove(Size i) {
        if (i >= vec_.size()) {
#ifdef LIBJ_USE_EXCEPTION
            LIBJ_THROW(Error::INDEX_OUT_OF_BOUNDS);
#else
            return Error::create(Error::INDEX_OUT_OF_BOUNDS);
#endif  // LIBJ_USE_EXCEPTION
        } else {
            return *vec_.erase(vec_.begin() + i);
        }
    }

    Boolean remove(const Value& v) {
        Size n = size();
        for (Size i = 0; i < n; i++) {
            if (!vec_[i].compareTo(v)) {
                remove(i);
                return true;
            }
        }
        return false;
    }

    void clear() {
        vec_.clear();
    }

    ArrayList::Ptr clone() const {
        // TODO(plenluno): implement
        ArrayList::Ptr p(new ArrayListImpl());
        return p;
    }

 private:
    class IteratorImpl : public Iterator {
        friend class ArrayListImpl;

        IteratorImpl(const std::vector<Value>* v)
            : vec_(v)
            , itr_(v->begin()) {}

     public:
        Boolean hasNext() const {
            return itr_ != vec_->end();
        }

        Value next() {
            if (itr_ == vec_->end()) {
#ifdef LIBJ_USE_EXCEPTION
                LIBJ_THROW(Error::NO_SUCH_ELEMENT);
#else
                return Error::create(Error::NO_SUCH_ELEMENT);
#endif  // LIBJ_USE_EXCEPTION
            } else {
                Value v = *itr_;
                ++itr_;
                return v;
            }
        }

        String::CPtr toString() const {
            return String::create();
        }

     private:
        const std::vector<Value>* vec_;
        std::vector<Value>::const_iterator itr_;
    };

 public:
    Iterator::Ptr iterator() const {
        Iterator::Ptr p(new IteratorImpl(&vec_));
        return p;
    }

 private:
    std::vector<Value> vec_;
};

ArrayList::Ptr ArrayList::create() {
    ArrayList::Ptr p(new ArrayListImpl());
    return p;
}

}  // namespace libj
