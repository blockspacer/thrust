/*
 *  Copyright 2008-2012 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include <thrust/detail/config.h>
#include <thrust/detail/type_traits/pointer_traits.h>
#include <thrust/system/detail/generic/memory.h>
#include <thrust/system/detail/generic/select_system.h>
#include <thrust/system/detail/adl/malloc_and_free.h>
#include <thrust/detail/static_assert.h>
#include <thrust/detail/malloc_and_free.h>

namespace thrust
{
namespace system
{
namespace detail
{
namespace generic
{


template<typename System, typename Size>
  void malloc(thrust::system::detail::state<System> &, Size)
{
  // unimplemented
  THRUST_STATIC_ASSERT( (thrust::detail::depend_on_instantiation<Size, false>::value) );
}


template<typename System, typename Pointer>
  void free(thrust::system::detail::state<System> &, Pointer)
{
  // unimplemented
  THRUST_STATIC_ASSERT( (thrust::detail::depend_on_instantiation<Pointer, false>::value) );
}


template<typename System, typename Pointer1, typename Pointer2>
__host__ __device__
void assign_value(thrust::system::detail::state<System> &, Pointer1, Pointer2)
{
  // unimplemented
  THRUST_STATIC_ASSERT( (thrust::detail::depend_on_instantiation<Pointer1, false>::value) );
}


template<typename System, typename Pointer>
__host__ __device__
void get_value(thrust::system::detail::state<System> &, Pointer)
{
  // unimplemented
  THRUST_STATIC_ASSERT( (thrust::detail::depend_on_instantiation<Pointer, false>::value) );
}


template<typename Pointer1, typename Pointer2>
__host__ __device__
void iter_swap(tag, Pointer1, Pointer2)
{
  // unimplemented
  THRUST_STATIC_ASSERT( (thrust::detail::depend_on_instantiation<Pointer1, false>::value) );
}


template<typename T, typename System>
  thrust::pair<thrust::pointer<T,System>, typename thrust::pointer<T,System>::difference_type>
    get_temporary_buffer(thrust::system::detail::state<System> &s, typename thrust::pointer<T,System>::difference_type n)
{
  thrust::pointer<void,System> void_ptr = thrust::malloc(s, sizeof(T) * n);

  typedef thrust::pointer<T,System> pointer;

  return thrust::make_pair(pointer(static_cast<T*>(void_ptr.get())), n);
} // end get_temporary_buffer()


template<typename System, typename Pointer>
  void return_temporary_buffer(thrust::system::detail::state<System> &s, Pointer p)
{
  thrust::free(s, p);
} // end return_temporary_buffer()


} // end generic
} // end detail
} // end system
} // end thrust

