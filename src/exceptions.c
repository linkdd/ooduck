#include <ooduck/exceptions.h>

E4C_DEFINE_EXCEPTION (NotImplementedError, "Not implemented", RuntimeException);
E4C_DEFINE_EXCEPTION (AbstractError, "Cannot instantiate abstract class", RuntimeException);
