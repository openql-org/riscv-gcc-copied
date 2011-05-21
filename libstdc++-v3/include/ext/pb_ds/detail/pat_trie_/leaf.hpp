// -*- C++ -*-

// Copyright (C) 2005, 2006, 2009, 2011 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the terms
// of the GNU General Public License as published by the Free Software
// Foundation; either version 3, or (at your option) any later
// version.

// This library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

// Copyright (C) 2004 Ami Tavory and Vladimir Dreizin, IBM-HRL.

// Permission to use, copy, modify, sell, and distribute this software
// is hereby granted without fee, provided that the above copyright
// notice appears in all copies, and that both that copyright notice
// and this permission notice appear in supporting documentation. None
// of the above authors, nor IBM Haifa Research Laboratories, make any
// representation about the suitability of this software for any
// purpose. It is provided "as is" without express or implied
// warranty.

/**
 * @file leaf.hpp
 * Contains a pat_trie_leaf for a patricia tree.
 */

#ifndef PB_DS_PAT_TRIE_LEAF_HPP
#define PB_DS_PAT_TRIE_LEAF_HPP

#include <debug/debug.h>

namespace __gnu_pbds
{
  namespace detail
  {

#define PB_DS_CLASS_T_DEC						\
    template<class Type_Traits,						\
	     class E_Access_Traits,					\
	     class Metadata,						\
	     class Allocator>

#define PB_DS_CLASS_C_DEC						\
    pat_trie_leaf<Type_Traits,						\
		  E_Access_Traits,					\
		  Metadata,						\
		  Allocator>

#define PB_DS_BASE_C_DEC						\
    pat_trie_node_base<Type_Traits,					\
		       E_Access_Traits,					\
		       Metadata,					\
		       Allocator>

#define PB_DS_PAT_TRIE_SUBTREE_DEBUG_INFO_C_DEC				\
    pat_trie_subtree_debug_info<Type_Traits,				\
				E_Access_Traits,			\
				Allocator>

    template<typename Type_Traits,
	     class E_Access_Traits,
	     class Metadata,
	     class Allocator>
    struct pat_trie_leaf : public PB_DS_BASE_C_DEC
    {
    private:
      typedef typename Type_Traits::value_type value_type;

      typedef typename Type_Traits::const_reference const_reference;

      typedef typename Type_Traits::reference reference;

      typedef
      typename Allocator::template rebind<
	E_Access_Traits>::other::const_pointer
      const_e_access_traits_pointer;

#ifdef _GLIBCXX_DEBUG
      typedef
      typename PB_DS_BASE_C_DEC::subtree_debug_info
      subtree_debug_info;
#endif 

      typedef PB_DS_BASE_C_DEC base_type;

    public:
      pat_trie_leaf(const_reference r_val);

      inline reference
      value();

      inline const_reference
      value() const;

#ifdef _GLIBCXX_DEBUG
      virtual subtree_debug_info
      assert_valid_imp(const_e_access_traits_pointer p_traits,
		       const char* file, int line) const;

      virtual
      ~pat_trie_leaf();
#endif 

    private:
      pat_trie_leaf(const PB_DS_CLASS_C_DEC& other);

      value_type m_value;
    };

    PB_DS_CLASS_T_DEC
    PB_DS_CLASS_C_DEC::
    pat_trie_leaf(const_reference r_val) :
    PB_DS_BASE_C_DEC(pat_trie_leaf_node_type), m_value(r_val)
    { }

    PB_DS_CLASS_T_DEC
    inline typename PB_DS_CLASS_C_DEC::reference
    PB_DS_CLASS_C_DEC::
    value()
    { return m_value; }

    PB_DS_CLASS_T_DEC
    inline typename PB_DS_CLASS_C_DEC::const_reference
    PB_DS_CLASS_C_DEC::
    value() const
    { return m_value; }

#ifdef _GLIBCXX_DEBUG
    PB_DS_CLASS_T_DEC
    typename PB_DS_CLASS_C_DEC::subtree_debug_info
    PB_DS_CLASS_C_DEC::
    assert_valid_imp(const_e_access_traits_pointer p_traits,
		     const char* __file, int __line) const
    {
      PB_DS_DEBUG_VERIFY(base_type::m_type == pat_trie_leaf_node_type);
      subtree_debug_info ret;
      const_reference r_val = value();
      return std::make_pair(p_traits->begin(p_traits->extract_key(r_val)),
			     p_traits->end(p_traits->extract_key(r_val)));
    }

    PB_DS_CLASS_T_DEC
    PB_DS_CLASS_C_DEC::
    ~pat_trie_leaf() { }
#endif 

#undef PB_DS_CLASS_T_DEC
#undef PB_DS_CLASS_C_DEC
#undef PB_DS_BASE_C_DEC
#undef PB_DS_PAT_TRIE_SUBTREE_DEBUG_INFO_C_DEC

  } // namespace detail
} // namespace __gnu_pbds

#endif 
