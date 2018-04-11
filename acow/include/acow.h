//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : acow.h                                                        //
//  Project   : acow_algo                                                     //
//  Date      : Apr 11, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//    Amazing Cow's custom algorithms.                                        //
//---------------------------------------------------------------------------~//

#pragma once

// std
#include <algorithm>
#include <iterator>

namespace acow { namespace algo {

//----------------------------------------------------------------------------//
// Find                                                                       //
//----------------------------------------------------------------------------//
template <typename Container, typename Type>
inline bool
contains(
    const Container &container,
    const Type      &searchItem) noexcept
{
    auto it = std::find(
        std::begin(container), 
        std::end  (container), 
        searchItem
    );
    return (it != std::end(container));
}

} // namespace algo
} // namespace acow
