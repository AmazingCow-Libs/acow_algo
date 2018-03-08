//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : something.h                                                   //
//  Project   : acow_algo                                                     //
//  Date      : Mar 08, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// std
#include <algorithm>
#include <iterator>

namespace acow { namespace algo {

//----------------------------------------------------------------------------//
// Copy                                                                       //
//----------------------------------------------------------------------------//
template <typename ContainerSource,
          typename ContainerDestination,
          typename Inserter = std::back_insert_iterator<ContainerDestination>>
inline void
copy(
    const ContainerSource &source,
    ContainerDestination  &destination) noexcept
{
    std::copy(std::begin(source), std::end(source), Inserter(destination));
}


//----------------------------------------------------------------------------//
// Find                                                                       //
//----------------------------------------------------------------------------//
template <typename Container, typename Predicate>
inline auto
find_if(
    Container &container,
    Predicate        predicate) noexcept -> typename Container::iterator
{
    return std::find_if(std::begin(container), std::end(container), predicate);
}


//----------------------------------------------------------------------------//
// For Each                                                                   //
//----------------------------------------------------------------------------//
template <typename Container, typename Func>
inline void
for_each(Container &container, Func func) noexcept
{
    std::for_each(std::begin(container), std::end(container), func);
}


//----------------------------------------------------------------------------//
// Sort                                                                       //
//----------------------------------------------------------------------------//
template <typename Container, typename Predicate>
inline void
sort(Container &container, Predicate predicate) noexcept
{
    std::sort(std::begin(container), std::end(container), predicate);
}


template <typename Container>
inline void
sort_and_unique(Container &container, bool autoErase = true) noexcept
{
    std::sort(std::begin(container), std::end(container));
    auto last_it = std::unique(std::begin(container), std::end(container));

    if(autoErase)
        container.erase(last_it, std::end(container));
}


//----------------------------------------------------------------------------//
// Remove                                                                     //
//----------------------------------------------------------------------------//
template <typename Container, typename Predicate>
inline auto
remove_if(
    Container &container,
    Predicate predicate,
    bool autoErase = true) noexcept -> typename Container::iterator
{
    auto it = std::remove_if(
        std::begin(container),
        std::end  (container),
        predicate
    );

    // We should not erase the stuff remove,
    // so let's the user do it himself.
    if(!autoErase)
        return it;

    // Erase the stuff remove, and return the
    // std::end(container) to indicate this.
    container.erase(it);
    return std::end(container);
}


} // namespace algo
} // namespace acow
