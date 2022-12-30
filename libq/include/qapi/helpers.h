#ifndef LIBQ_HELPERS

#define LIBQ_HELPERS

#include <inttypes.h>

// TODO: rename to LIBQ_***
#define QEMU_BUILD_BUG_MSG(x, msg) _Static_assert(!(x), msg)
#define QEMU_BUILD_BUG_ON(x)       QEMU_BUILD_BUG_MSG(x, "not expecting: " #x)

struct Error;
typedef struct Error Error;

struct Visitor;
typedef struct Visitor Visitor;

#ifndef container_of
#define container_of(ptr, type, member)                      \
    ({                                                       \
        const typeof(((type *) 0)->member) *__mptr = (ptr);  \
        (type *) ((char *) __mptr - offsetof(type, member)); \
    })
#endif

#ifndef glue
#define xglue(x, y)  x##y
#define glue(x, y)   xglue(x, y)
#define stringify(s) tostring(s)
#define tostring(s)  #s
#endif

#endif
