#include <gtest/gtest.h>
#include <libj/js_array_buffer.h>
#include <libj/error.h>
#include <libj/string.h>

namespace libj {

TEST(GTestJsArrayBuffer, TestCreate) {
    JsArrayBuffer::Ptr a = JsArrayBuffer::create();
    ASSERT_EQ(a->length(), 0);
}

TEST(GTestJsArrayBuffer, TestSize) {
    JsArrayBuffer::Ptr a = JsArrayBuffer::create(0);
    ASSERT_EQ(a->length(), 0);
    a = JsArrayBuffer::create(10);
    ASSERT_EQ(a->length(), 10);
    a = JsArrayBuffer::create(100);
    ASSERT_EQ(a->length(), 100);
}

TEST(GTestJsArrayBuffer, TestInt8) {
    JsArrayBuffer::Ptr a = JsArrayBuffer::create(20);
    for (int i = 0; i < a->length(); i++) {
        Byte v = -5 * i;
        a->setInt8(i, v);
    }
    for (int i = 0; i < a->length(); i++) {
        Byte v = a->getInt8(i);
        ASSERT_EQ(v, -5 * i);
    }
}

TEST(GTestJsArrayBuffer, TestUInt8) {
    JsArrayBuffer::Ptr a = JsArrayBuffer::create(20);
    for (int i = 0; i < a->length(); i++) {
        UByte v = 10 * i;
        a->setInt8(i, v);
    }
    for (int i = 0; i < a->length(); i++) {
        UByte v = a->getInt8(i);
        ASSERT_EQ(v, 10 * i);
    }
}

TEST(GTestJsArrayBuffer, TestAlignedInt16) {
    JsArrayBuffer::Ptr a = JsArrayBuffer::create(20);
    for (int i = 0; i + 1 < a->length(); i += 2) {
        Short v = -300 * i;
        a->setInt16(i, v, true);
    }
    for (int i = 0; i + 1 < a->length(); i += 2) {
        Short v = a->getInt16(i, true);
        ASSERT_EQ(v, -300 * i);
    }
    for (int i = 0; i + 1 < a->length(); i += 2) {
        Short v = -400 * i;
        a->setInt16(i, v, false);
    }
    for (int i = 0; i + 1 < a->length(); i += 2) {
        Short v = a->getInt16(i, false);
        ASSERT_EQ(v, -400 * i);
    }
}

TEST(GTestJsArrayBuffer, TestNonAlignedInt16) {
    JsArrayBuffer::Ptr a = JsArrayBuffer::create(20);
    for (int i = 1; i + 1 < a->length(); i += 2) {
        Short v = -300 * i;
        a->setInt16(i, v, true);
    }
    for (int i = 1; i + 1 < a->length(); i += 2) {
        Short v = a->getInt16(i, true);
        ASSERT_EQ(v, -300 * i);
    }
    for (int i = 1; i + 1 < a->length(); i += 2) {
        Short v = -400 * i;
        a->setInt16(i, v, false);
    }
    for (int i = 1; i + 1 < a->length(); i += 2) {
        Short v = a->getInt16(i, false);
        ASSERT_EQ(v, -400 * i);
    }
}

TEST(GTestJsArrayBuffer, TestAlignedUInt16) {
    JsArrayBuffer::Ptr a = JsArrayBuffer::create(20);
    for (int i = 0; i < a->length(); i += 2) {
        UShort v = 300 * i;
        a->setUInt16(i, v, true);
    }
    for (int i = 0; i < a->length(); i += 2) {
        UShort v = a->getUInt16(i, true);
        ASSERT_EQ(v, 300 * i);
    }
    for (int i = 0; i < a->length(); i += 2) {
        UShort v = 400 * i;
        a->setUInt16(i, v, false);
    }
    for (int i = 0; i < a->length(); i += 2) {
        UShort v = a->getUInt16(i, false);
        ASSERT_EQ(v, 400 * i);
    }
}

TEST(GTestJsArrayBuffer, TestNonAlignedUInt16) {
    JsArrayBuffer::Ptr a = JsArrayBuffer::create(20);
    for (int i = 1; i + 1 < a->length(); i += 2) {
        UShort v = 300 * i;
        a->setUInt16(i, v, true);
    }
    for (int i = 1; i + 1 < a->length(); i += 2) {
        UShort v = a->getUInt16(i, true);
        ASSERT_EQ(v, 300 * i);
    }
    for (int i = 1; i + 1 < a->length(); i += 2) {
        UShort v = 400 * i;
        a->setUInt16(i, v, false);
    }
    for (int i = 1; i + 1 < a->length(); i += 2) {
        UShort v = a->getUInt16(i, false);
        ASSERT_EQ(v, 400 * i);
    }
}

TEST(GTestJsArrayBuffer, TestAlignedInt32) {
    JsArrayBuffer::Ptr a = JsArrayBuffer::create(20);
    for (int i = 0; i + 3 < a->length(); i += 4) {
        Int v = -70000 * i;
        a->setInt32(i, v, true);
    }
    for (int i = 0; i + 3 < a->length(); i += 4) {
        Int v = a->getInt32(i, true);
        ASSERT_EQ(v, -70000 * i);
    }
    for (int i = 0; i + 3 < a->length(); i += 4) {
        Int v = -80000 * i;
        a->setInt32(i, v, false);
    }
    for (int i = 0; i + 3 < a->length(); i += 4) {
        Int v = a->getInt32(i, false);
        ASSERT_EQ(v, -80000 * i);
    }
}

TEST(GTestJsArrayBuffer, TestNonAlignedInt32) {
    JsArrayBuffer::Ptr a = JsArrayBuffer::create(20);
    for (int ofs = 1; ofs < 4; ofs++) {
        for (int i = ofs; i + 3 < a->length(); i += 4) {
            Int v = -70000 * i;
            a->setInt32(i, v, true);
        }
        for (int i = ofs; i + 3 < a->length(); i += 4) {
            Int v = a->getInt32(i, true);
            ASSERT_EQ(v, -70000 * i);
        }
        for (int i = ofs; i + 3 < a->length(); i += 4) {
            Int v = -80000 * i;
            a->setInt32(i, v, false);
        }
        for (int i = ofs; i + 3 < a->length(); i += 4) {
            Int v = a->getInt32(i, false);
            ASSERT_EQ(v, -80000 * i);
        }
    }
}

TEST(GTestJsArrayBuffer, TestAlignedUInt32) {
    JsArrayBuffer::Ptr a = JsArrayBuffer::create(20);
    for (int i = 0; i + 3 < a->length(); i += 4) {
        UInt v = 70000 * i;
        a->setInt32(i, v, true);
    }
    for (int i = 0; i + 3 < a->length(); i += 4) {
        UInt v = a->getInt32(i, true);
        ASSERT_EQ(v, 70000 * i);
    }
    for (int i = 0; i + 3 < a->length(); i += 4) {
        UInt v = 80000 * i;
        a->setInt32(i, v, false);
    }
    for (int i = 0; i + 3 < a->length(); i += 4) {
        UInt v = a->getInt32(i, false);
        ASSERT_EQ(v, 80000 * i);
    }
}

TEST(GTestJsArrayBuffer, TestNonAlignedUInt32) {
    JsArrayBuffer::Ptr a = JsArrayBuffer::create(20);
    for (int ofs = 1; ofs < 4; ofs++) {
        for (int i = ofs; i + 3 < a->length(); i += 4) {
            UInt v = 70000 * i;
            a->setInt32(i, v, true);
        }
        for (int i = ofs; i + 3 < a->length(); i += 4) {
            UInt v = a->getInt32(i, true);
            ASSERT_EQ(v, 70000 * i);
        }
        for (int i = ofs; i + 3 < a->length(); i += 4) {
            UInt v = 80000 * i;
            a->setInt32(i, v, false);
        }
        for (int i = ofs; i + 3 < a->length(); i += 4) {
            UInt v = a->getInt32(i, false);
            ASSERT_EQ(v, 80000 * i);
        }
    }
}

TEST(GTestJsArrayBuffer, TestAlignedFloat32) {
    JsArrayBuffer::Ptr a = JsArrayBuffer::create(20);
    for (int i = 0; i + 3 < a->length(); i += 4) {
        Float v = 1.23f * i;
        a->setFloat32(i, v, true);
    }
    for (int i = 0; i + 3 < a->length(); i += 4) {
        Float v = a->getFloat32(i, true);
        ASSERT_EQ(v, 1.23f * i);
    }
    for (int i = 0; i + 3 < a->length(); i += 4) {
        Float v = -45.6f * i;
        a->setFloat32(i, v, false);
    }
    for (int i = 0; i + 3 < a->length(); i += 4) {
        Float v = a->getFloat32(i, false);
        ASSERT_EQ(v, -45.6f * i);
    }
}

TEST(GTestJsArrayBuffer, TestNonAlignedFloat32) {
    JsArrayBuffer::Ptr a = JsArrayBuffer::create(20);
    for (int ofs = 1; ofs < 4; ofs++) {
        for (int i = ofs; i + 3 < a->length(); i += 4) {
            Float v = 12.3f * i;
            a->setFloat32(i, v, true);
        }
        for (int i = ofs; i + 3 < a->length(); i += 4) {
            Float v = a->getFloat32(i, true);
            ASSERT_EQ(v, 12.3f * i);
        }
        for (int i = ofs; i + 3 < a->length(); i += 4) {
            Float v = -4.56f * i;
            a->setFloat32(i, v, false);
        }
        for (int i = ofs; i + 3 < a->length(); i += 4) {
            Float v = a->getFloat32(i, false);
            ASSERT_EQ(v, -4.56f * i);
        }
    }
}

TEST(GTestJsArrayBuffer, TestAlignedFloat64) {
    JsArrayBuffer::Ptr a = JsArrayBuffer::create(20);
    for (int i = 0; i + 7 < a->length(); i += 8) {
        Double v = 1.23 * i;
        a->setFloat64(i, v, true);
    }
    for (int i = 0; i + 7 < a->length(); i += 8) {
        Double v = a->getFloat64(i, true);
        ASSERT_EQ(v, 1.23 * i);
    }
    for (int i = 0; i + 7 < a->length(); i += 8) {
        Double v = -45.6 * i;
        a->setFloat64(i, v, false);
    }
    for (int i = 0; i + 7 < a->length(); i += 8) {
        Double v = a->getFloat64(i, false);
        ASSERT_EQ(v, -45.6 * i);
    }
}

TEST(GTestJsArrayBuffer, TestNonAlignedFloat64) {
    JsArrayBuffer::Ptr a = JsArrayBuffer::create(20);
    for (int ofs = 1; ofs < 8; ofs++) {
        for (int i = ofs; i + 7 < a->length(); i += 8) {
            Double v = 12.3 * i;
            a->setFloat64(i, v, true);
        }
        for (int i = ofs; i + 7 < a->length(); i += 8) {
            Double v = a->getFloat64(i, true);
            ASSERT_EQ(v, 12.3 * i);
        }
        for (int i = ofs; i + 7 < a->length(); i += 8) {
            Double v = -4.56 * i;
            a->setFloat64(i, v, false);
        }
        for (int i = ofs; i + 7 < a->length(); i += 8) {
            Double v = a->getFloat64(i, false);
            ASSERT_EQ(v, -4.56 * i);
        }
    }
}

}   // namespace libj
