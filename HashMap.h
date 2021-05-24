//
// Created by danie on 24/05/2021.
//

#ifndef FOCALPOINT_HASHMAP_H
#define FOCALPOINT_HASHMAP_H
#include <unordered_map>
#include <memory>

struct bucket_list_base
{
    bucket_list_base* _next;
    bucket_list_base() noexcept : _next(nullptr) { }
    bucket_list_base(bucket_list_base* next) noexcept : _next(next) { }
};

template<typename key_t, typename value_t>
struct bucket_list: public bucket_list_base
{
    key_t key;
    value_t value;
};

// This is a hash map that does not allow duplicate keys.
template<typename key_t,
        typename value_t,
        typename _hash = std::hash<key_t>,
        typename _pred = std::equal_to<key_t> >
class hash_map
{
public:
    hash_map(std::size_t bucket_count) :
     _bucket_count(bucket_count),
     _buckets(std::make_unique<bucket_list_base*[]>(bucket_count))
    {
    }

    ~hash_map() {
        // unique_ptr handles delete/
    }

    std::optional<value_t> lookup(key_t key);

    bool insert(key_t key, value_t value);

    bool remove(key_t key);

    std::size_t size();

private:
    std::size_t _bucket_count;
    std::unique_ptr<bucket_list_base*[]> _buckets;
};




#endif //FOCALPOINT_HASHMAP_H
