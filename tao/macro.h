#ifndef __TAO_MACRO_H__
#define __TAO_MACRO_H__

#include <string.h>
#include <assert.h>
#include "util.h"
#include "log.h"

#if defined __GNUC__ || defined __llvm__
/// LIKCLY 宏的封装, 告诉编译器优化,条件大概率成立
#   define TAO_LIKELY(x)       __builtin_expect(!!(x), 1)
/// LIKCLY 宏的封装, 告诉编译器优化,条件大概率不成立
#   define TAO_UNLIKELY(x)     __builtin_expect(!!(x), 0)
#else
#   define TAO_LIKELY(x)      (x)
#   define TAO_UNLIKELY(x)      (x)
#endif

/// 断言宏封装
#define TAO_ASSERT(x) \
    if(TAO_UNLIKELY(!(x))) { \
        TAO_LOG_ERROR(TAO_LOG_ROOT()) << "ASSERTION: " #x \
            << "\nbacktrace:\n" \
            << tao::BacktraceToString(100, 2, "    "); \
        assert(x); \
    }

/// 断言宏封装
#define TAO_ASSERT2(x, w) \
    if(TAO_UNLIKELY(!(x))) { \
        TAO_LOG_ERROR(TAO_LOG_ROOT()) << "ASSERTION: " #x \
            << "\n" << w \
            << "\nbacktrace:\n" \
            << tao::BacktraceToString(100, 2, "    "); \
        assert(x); \
    }


#endif