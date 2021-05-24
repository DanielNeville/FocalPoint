#ifndef FOCALPOINT_RECURSION_H
#define FOCALPOINT_RECURSION_H

namespace Recursion
{
    using large_t = unsigned long long;

    const large_t magic_number = 123456789012345678;
    // Using 'f' as function name as per specification.
    large_t f(const large_t n);

    large_t f_cache(const large_t n);
}


#endif //FOCALPOINT_RECURSION_H
