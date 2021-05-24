//
// Created by danie on 24/05/2021.
//

#ifndef FOCALPOINT_HASHMAP_H
#define FOCALPOINT_HASHMAP_H
#include <functional>
#include <unordered_map>
#include <memory>
#include <iostream>
#include <forward_list>

struct bucket_list_base
{
    bucket_list_base* _next;
    bucket_list_base() noexcept : _next(nullptr) { }
    bucket_list_base(bucket_list_base* next) noexcept : _next(next) { }

    ~bucket_list_base() { delete _next; }
};

template<typename key_t, typename value_t>
struct bucket_list: public bucket_list_base
{
    bucket_list(bucket_list_base* next, key_t key, value_t value)
        : bucket_list_base(next), _key(key), _value(value)
    {
    }

    key_t _key;
    value_t _value;
};

// This is a hash map that does not allow duplicate keys.
template<typename key_t,
        typename value_t,
        typename _hash = std::hash<key_t>,
        typename _pred = std::equal_to<key_t> >
class hash_map
{
public:

    hash_map(const std::size_t bucket_count)
        :
        _bucket_count(bucket_count),
        _buckets(new bucket_list_base[bucket_count])
    {
    }

    ~hash_map()
    {
        delete[] _buckets;
    }

    std::optional<value_t> lookup(key_t key)
    {
        std::size_t hash = _hash()(key) % _bucket_count;
        bucket_list_base* step = (_buckets[hash]._next);

        while(step)
        {
            if(_pred()(static_cast<bucket_list<key_t, value_t>*>(step)->_key, key))
            {
                return static_cast<bucket_list<key_t, value_t>*>(step)->_value;
            }
            step = step->_next;
        }
        return std::nullopt;
    }

    bool insert(key_t key, value_t value)
    {
        // This is insert, not update.  Do not allow duplicates.
        if(lookup(key))
        {
            return false;
        }

        std::size_t hash = _hash()(key) % _bucket_count;
        auto new_element = new bucket_list<key_t, value_t>(_buckets[hash]._next, key, value);
        _buckets[hash]._next = new_element;

        ++_element_count;
        return true;
    }

    bool remove(key_t key)
    {
        // This initial code could be brought out into a new function (e.g. 'find').
        std::size_t hash = _hash()(key) % _bucket_count;
        bucket_list_base* step = (_buckets[hash]._next);

        while(step)
        {
            if(_pred()(static_cast<bucket_list<key_t, value_t>*>(step)->_key, key))
            {
                return static_cast<bucket_list<key_t, value_t>*>(step)->_value;
            }
            step = step->_next;
        }
    }

    std::size_t size()
    {
        return _element_count;
    }

private:
    std::size_t _bucket_count;
    std::size_t _element_count = 0;
    bucket_list_base* _buckets;

    std::forward_list<int> x;
};

#endif //FOCALPOINT_HASHMAP_H
